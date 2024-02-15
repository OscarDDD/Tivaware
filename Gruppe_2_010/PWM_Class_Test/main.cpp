/*
 * main.cpp
 *
 *    Author: Zeyu Li
 *     Email: uegyy@student.kit.edu
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
#include "PWM.h"
#include "driverlib/pwm.h"

#define PWM_BASE_FREQ (100) //Hz


int main(void)
{

    // Construct all objects
    System system;
    PWM pwm;

    // Start system and run at 40 MHz.
    system.init(40000000);
    system.setPWMClockDiv(64);    //set pwm clock 64
    pwm.init(&system, GPIO_PORTF_BASE, GPIO_PIN_2, GPIO_PIN_3, false, PWM_BASE_FREQ);


    int duty = -100;
    bool up=1, down=0;

    pwm.setFreq(PWM_BASE_FREQ);

    while (1)
    {
        pwm.setDuty((float) duty / 100);
        if (duty == -100)
        {
            up = 1;
            down = 0;
        }
        if (duty == 100)
        {
            up = 0;
            down = 1;
        }
        if (up) {
            duty += 1;
        }
        if (down) {
            duty -= 1;
        }
        for(int i = 0; i< 40000; i++);
    }
}
