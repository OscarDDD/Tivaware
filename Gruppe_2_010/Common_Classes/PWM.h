/*
 * PWM.h
 *
 *    Author: Zeyu Li
 *     Email: uegyy@student.kit.edu
 */

#ifndef PWM_H_
#define PWM_H_


/*
 * stdbool.h:               Boolean definitions for the C99 standard
 * stdint.h:                Variable definitions for the C99 standard
 * System.h:                Access to current CPU clock and other functions.
 */
#include <stdbool.h>
#include <stdint.h>
#include "driverlib/pwm.h"
#include "System.h"


class PWM
{
public:
    PWM();
    virtual ~PWM();
    void init(System *sys,uint32_t portBase, uint32_t pin1, uint32_t pin2,
              bool invert = false, uint32_t freq = 5000);
    void setFreq(uint32_t freq);
    void setDuty(float duty);

private:
    /*
     * The following array is needed to let the compiler know that the
     * precompiled class library needs space for its private variables.
     * Or in shorter terms: simply ignore it.
     */
    uint32_t spaceForLib[92];


    System *sys;
    uint32_t portBase;
    uint32_t pin1;
    uint32_t pin2;
    // PWM Generator
    uint32_t gen;
    // PWM Module
    uint32_t module;

    // PWM Output Bits
    uint32_t pwmBit1;
    uint32_t pwmBit2;
    // Bit-wise ID for PWM Bits
    uint32_t pwmOutBit1;
    uint32_t pwmOutBit2;

    uint32_t ui32PWMClock;
    uint32_t ui32Load;

};

#endif /* PWM_H_ */
