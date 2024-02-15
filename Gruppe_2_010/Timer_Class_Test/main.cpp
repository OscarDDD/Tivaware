/*
 * main.cpp
 *
 *    Author: Yang Zhou
 *     Email: ugvxu@student.kit.edu
 */

/*
 * stdbool.h:           Boolean definitions for the C99 standard
 * stdint.h:            Variable definitions for the C99 standard
 * System.h:            Header file for the System class
 *                      (needed for example for clock settings)
 * GPIO.h:              Header file for the GPIO class
 * Timer.h:             Header file for the Timer class
 */
#include <stdbool.h>
#include <stdint.h>
#include "System.h"
#include "GPIO.h"
#include "Timer.h"

    System system;
    Timer timerx;
    GPIO blueLed, sw1, sw2;

void ISRx()
{
    timerx.clearInterruptFlag();
    blueLed.write(!blueLed.read());
}

int main(void)
{

    system.init(40000000);

    // Blue LED on pin PF2
    blueLed.init(&system, GPIO_PORTF_BASE, GPIO_PIN_2, GPIO_DIR_MODE_OUT);

    // Switch SW1 on pin PF4
    sw1.init(&system, GPIO_PORTF_BASE, GPIO_PIN_4, GPIO_DIR_MODE_IN);
    // Switch SW2 on pin PF0
    sw2.init(&system, GPIO_PORTF_BASE, GPIO_PIN_0, GPIO_DIR_MODE_IN);

    sw1.setPullup(true);
    sw2.setPullup(true);

    timerx.init(&system, TIMER0_BASE, ISRx, 0);
    timerx.setPeriodUS(1500000);

    while (1)
    {
        // sw1 open or close the LED.
        if (!sw1.read())
        {
            system.delayUS(50000);
            while (!sw1.read());

            if (!timerx.getRunning()){
                timerx.start();
            } else
            {
                timerx.stop();
                blueLed.write(false);
            }

            system.delayUS(50000);
         }

        if (!sw2.read())
        {
            system.delayUS(50000);
            while (!sw2.read());

            if (timerx.getRunning()){
                uint32_t period = timerx.getPeriodUS() == 1500000 ? 2500000 : 1500000;
                timerx.setPeriodUS(period);
                timerx.start();
            }

            system.delayUS(50000);
         }
    }
}
