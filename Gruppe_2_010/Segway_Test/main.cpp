/*
 * main.cpp
 *
 *    Author: Henri Hornburg
 *     Email: henri.hornburg@student.kit.edu
 * Co-author: Max Zuidberg
 *     Email: m.zuidberg@icloud.com
 *
 * Run a Segway.
 */


/*
 * Config.h: Header file containing all configurable parameters of the segway,
 *           as for example its pinout.
 *           Note: all constants are prefixed by CFG_.
 * System.h: Header file for the System class (needed for example for clock
 *           settings).
 * Segway.h: Header file for the Segway class which contains all the code for
 *           controlling a segway.
 * Timer.h:  Header file for the Timer class (used for periodic tasks).
 */
#include "Config.h"
#include "System.h"
#include "Segway.h"
#include "Timer.h"


// These objects are used inside the global ISR mainTimerISR, thus must be
// global, too.

/**
 *  global objects are declared static to avoid external import,
 *  if only heap are available, the objects will be declared inside the Segway,
 *  which looks more object-oriented
 */
static System system;
static Segway segway;
static Timer mainTimer;
static Timer debugTimer;
static Timer countdownTimer;


void mainTimerISR()
{
    /*
     * This ISR is periodically called by the updateTimer. It causes the
     * segway class to update all inputs and set the corresponding new outputs.
     *
     * Note: it is not possible to set a class method as ISR. Therefore this
     *       "helper-function" is needed.
     */

    mainTimer.clearInterruptFlag();

    // Update segway
    segway.update();
}

void sendDebugISR()
{
    /*
     * This ISR is periodically called by the debugTimer. It causes the system
     * class to transmit the latest debug values.
     *
     * Note: it is not possible to set a class method as ISR. Therefore this
     *       "helper-function" is needed.
     */

	debugTimer.clearInterruptFlag();

	// Transmit debug values
	system.sendDebugVals();
}

void stopISR()
{
    /**
     *  This ISR is one-off called by the countdownTimer. It causes
     *  the timer and segway to stop running
     */
    countdownTimer.clearInterruptFlag();
    countdownTimer.stop();

    // Apply to stop the segway
    segway.pause();

}

int main(void)
{
    // Initialize objects according to the values in Config.h
    system.init(CFG_SYS_FREQ);

    mainTimer.init(&system,
                   CFG_MAIN_TIMER_BASE,
                   mainTimerISR,
                   CFG_CTLR_UPDATE_FREQ);
    debugTimer.init(&system,
                    CFG_DEBUG_TIMER_BASE,
                    sendDebugISR,
                    CFG_DEBUG_TIMER_FREQ);

    // Initialize and start segway
    segway.init(&system, &countdownTimer);
    mainTimer.start();
    debugTimer.start();

	while (42)
	{
	    // Some monitoring tasks can run silently in background while the
	    // critical parts run inside the ISR
	    segway.backgroundTasks();
	}
}
