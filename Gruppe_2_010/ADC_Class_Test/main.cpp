/*
 * main.cpp
 *
 *    Author:
 *     Email:
 */



/*
 * stdbool.h:           Boolean definitions for the C99 standard
 * stdint.h:            Variable definitions for the C99 standard
 * System.h:            Header file for the System class
 *                      (needed for example for clock settings)
 * GPIO.h:              Header file for the GPIO class
 * ADC.h:               Header file for the ADC class
 */
#include <stdbool.h>
#include <stdint.h>
#include "System.h"
#include "GPIO.h"
#include "ADC.h"


int main(void)
{
    System system;
    system.init(40000000);
    ADC adc1,adc2;
    GPIO greenLed, redLed;
    float test,reference;

    //initialize the green led.
    greenLed.init(&system, GPIO_PORTF_BASE, GPIO_PIN_3, GPIO_DIR_MODE_OUT);
    //initialize the red led.
    redLed.init(&system, GPIO_PORTF_BASE, GPIO_PIN_1, GPIO_DIR_MODE_OUT);

    adc1.init(&system, ADC0_BASE, 0,  ADC_CTL_CH1);
    adc2.init(&system, ADC1_BASE, 1,  ADC_CTL_CH2);
    adc2.setHWAveraging(64);
    while (1)
    {
      test = adc1.readVolt();
      reference = adc2.readVolt();

      if (test > reference)
      {
        redLed.write(false);
        greenLed.write(true);
       }
      else
      {
         greenLed.write(false);
         redLed.write(true);
       }
    }
}
