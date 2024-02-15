/*
 * Timer.cpp
 *
 *    Author: Yang Zhou
 *     Email: ugvxu@student.kit.edu
 */


// Uncomment following #define to use the precompiled Timer library instead of
// the code in this file.
// #define USE_TIMER_LIBRARY

#ifndef USE_TIMER_LIBRARY


#include <Timer.h>


Timer::Timer()
{
    /*
     * Default empty constructor
     */
}

Timer::~Timer()
{
    /*
     * Default empty destructor
     */
}

void Timer::init(System* sys, uint32_t base, void (*ISR) (void), uint32_t freq)
{
    /*
     * This method initializes the timer by enabling the corresponding peripheral,
     * configuring it as a half-width or full-width timer and enabling the interrupt register.
     * This method must be called before using a timer.
     */
    this->sys = sys;
    this->base = base;
    this->freq = freq;
    this->periodUS = (freq == 0) ? 0 : 1000000 / freq;
    this->isRunning = false;

    int32_t baseNumber = base - TIMER0_BASE;
    // valid base address
    if (baseNumber % 0x1000 == 0)
    {
        // half-width timer
        if (baseNumber / 0x1000 >= 0 && baseNumber / 0x1000 <= 5)
        {
            SysCtlPeripheralEnable(SYSCTL_PERIPH_TIMER0 + baseNumber / 0x1000);
            TimerConfigure(base, TIMER_CFG_PERIODIC);
            TimerIntEnable(base, TIMER_TIMA_TIMEOUT);
            TimerIntRegister(base, TIMER_A, ISR);
        // full-width timer
        } else if (baseNumber / 0x1000 == 6 || baseNumber / 0x1000 == 7 || ((int32_t)(base - WTIMER2_BASE) / 0x1000 >= 0 && (base - WTIMER2_BASE) / 0x1000 <= 3))
        {
            SysCtlPeripheralEnable(SYSCTL_PERIPH_WTIMER0 + baseNumber / 0x1000);
            TimerConfigure(base, TIMER_CFG_PERIODIC);
            TimerIntEnable(base, TIMER_TIMA_TIMEOUT | TIMER_TIMB_TIMEOUT);
            TimerIntRegister(base, TIMER_BOTH, ISR);
        } else
        {
            sys->error(TimerWrongConfig, &base);
        }
    } else
    {
            sys->error(TimerWrongConfig, &base);
    }

    sys->delayCycles(5);

}

void Timer::start()
{
    /*
     * Start the timer.
     */
    uint32_t value;
    if (this->periodUS <= 1000000) {
        value = sys->getClockFreq() / (float)(1000000 / this->periodUS);
    }
    else
    {
        value = sys->getClockFreq() * (float)(this->periodUS / 1000000);
    }
    TimerLoadSet(this->base, TIMER_A, value);
    TimerEnable(this->base, TIMER_BOTH);
    this->isRunning = true;
}

void Timer::stop()
{
    /*
     * Stop the timer.
     */
    TimerDisable(this->base, TIMER_BOTH);
    this->isRunning = false;
}

void Timer::setFreq(uint32_t freq)
{
    /*
     * Set the frequency of the timer.
     */
    TimerLoadSet(this->base, TIMER_A, 0);
    this->freq = freq;
    this->periodUS = 1000000 / freq;
    this->isRunning = false;
}

void Timer::setPeriodUS(uint32_t period)
{
    /*
     * Set the period (in us) of the timer by setting its frequency.
     */
    TimerLoadSet(this->base, TIMER_A, 0);
    this->freq = (period == 0) ? 0 : (uint32_t) (1000000 / period);
    this->periodUS = period;
    this->isRunning = false;
}

uint32_t Timer::getFreq()
{
    /*
     * Get the frequency of the timer.
     */
    if (this->isRunning) {
        return this->freq;
    }
    else
    {
        return 0;
    }
}

uint32_t Timer::getPeriodUS()
{
    /*
     * Get the period (in us) of the timer.
     */
    if (this->isRunning){
        return this->periodUS;
    }
    else
    {
        return 0;
    }
}

void Timer::clearInterruptFlag()
{
    /*
     * Clear all interrupt flags, which are in this case TIMEOUT interrupt.
     */
    TimerIntClear(this->base, TIMER_TIMA_TIMEOUT | TIMER_TIMB_TIMEOUT);
}

bool Timer::getRunning()
{
    /*
     * Return whether the timer is running.
     */
    return this->isRunning;
}

#endif
