/*
 * ADC.cpp
 *
 *    Author:Dong Sicheng
 *    Email:udwbi@student.kit.edu
 */


// Uncomment following #define to use the precompiled ADC library instead of
// the code in this file.
// #define USE_ADC_LIBRARY
#ifndef USE_ADC_LIBRARY


#include "ADC.h"


ADC::ADC()
{
    /*
     * Default empty constructor
     */
}

ADC::~ADC()
{
    /*
     * Default empty destructor
     */
}

void ADC::init(System *sys, uint32_t base, uint32_t sampleSeq, uint32_t analogInput)
{

    /*
        * Initializes a GPIO-pin object by enabling the corresponding peripheral
        * and configuring the relative ports and pin.
        *
        *
        * sys:         Pointer to the current System instance. Needed for error
        *              handling.
        * base:        base address of the ADC module, like ADC0_BASE.
        * sampleSeq:   Sample Sequencer which is used in the ADC-Module (0, 1,
        *              2 oder 3).
        * analogInput: Analog input, like ADC_CTL_CH0.
        *
        */

    // Save system, base, sampleSeq and analogInput.
    this->sys = sys;
    this->base = base;
    this->sampleSeq=sampleSeq;
    this->analogInput=analogInput;

    uint32_t adc_gpio;
    uint32_t gpio_base;
    uint32_t pin;

    // determine which port and which pin should be used according to the given analogInput.
    switch(analogInput)
        {
            case ADC_CTL_CH0:
            {
                adc_gpio = SYSCTL_PERIPH_GPIOE;
                gpio_base = GPIO_PORTE_BASE;
                pin = GPIO_PIN_3;
                break;
            }
            case ADC_CTL_CH1  :
            {
                adc_gpio = SYSCTL_PERIPH_GPIOE;
                gpio_base = GPIO_PORTE_BASE;
                pin = GPIO_PIN_2;
                break;
            }
            case ADC_CTL_CH2:
            {
                adc_gpio = SYSCTL_PERIPH_GPIOE;
                gpio_base = GPIO_PORTE_BASE;
                pin = GPIO_PIN_1;
                break;
            }
            case ADC_CTL_CH3:
            {
                adc_gpio = SYSCTL_PERIPH_GPIOE;
                gpio_base = GPIO_PORTE_BASE;
                pin = GPIO_PIN_0;
                break;
            }
            case ADC_CTL_CH4:
            {
                adc_gpio = SYSCTL_PERIPH_GPIOD;
                gpio_base = GPIO_PORTD_BASE;
                pin = GPIO_PIN_3;
                break;
            }
            case ADC_CTL_CH5:
            {
                adc_gpio = SYSCTL_PERIPH_GPIOD;
                gpio_base = GPIO_PORTD_BASE;
                pin = GPIO_PIN_2;
                break;
            }
            case ADC_CTL_CH6:
            {
                adc_gpio = SYSCTL_PERIPH_GPIOD;
                gpio_base = GPIO_PORTD_BASE;
                pin = GPIO_PIN_1;
                break;
            }
            case ADC_CTL_CH7:
            {
                adc_gpio = SYSCTL_PERIPH_GPIOD;
                gpio_base = GPIO_PORTD_BASE;
                pin = GPIO_PIN_0;
                break;
            }
            case ADC_CTL_CH8:
            {
                adc_gpio = SYSCTL_PERIPH_GPIOE;
                gpio_base = GPIO_PORTE_BASE;
                pin = GPIO_PIN_5;
                break;
            }
            case ADC_CTL_CH9:
            {
                adc_gpio = SYSCTL_PERIPH_GPIOE;
                gpio_base = GPIO_PORTE_BASE;
                pin = GPIO_PIN_4;
                break;
            }
            case ADC_CTL_CH10:
            {
                adc_gpio = SYSCTL_PERIPH_GPIOB;
                gpio_base = GPIO_PORTB_BASE;
                pin = GPIO_PIN_4;
                break;
            }
            case ADC_CTL_CH11:
            {
                adc_gpio = SYSCTL_PERIPH_GPIOB;
                gpio_base = GPIO_PORTB_BASE;
                pin = GPIO_PIN_5;
                break;
            }
            default:
                sys->error(ADCWrongConfig, &base, &sampleSeq, &analogInput);
        }

    // save the pin which will be used.
        this->pin=pin;

    // enable the ADC0 module, if the base address matches the ADC0_BASE.
        if(base == ADC0_BASE)
    {
            SysCtlPeripheralEnable(SYSCTL_PERIPH_ADC0);

   //  Wait for the ADC0 module to be ready.
            while(!SysCtlPeripheralReady(SYSCTL_PERIPH_ADC0))
               {
               }

    }

    // enable the ADC1 module, if the base address matches the ADC1_BASE.
        if(base == ADC1_BASE)
    {
            SysCtlPeripheralEnable(SYSCTL_PERIPH_ADC1);
    // Wait for the ADC1 module to be ready.
            while(!SysCtlPeripheralReady(SYSCTL_PERIPH_ADC1))
                   {
                   }
    }

        // Enable the port that should be used.
        SysCtlPeripheralEnable(adc_gpio);
        // Configures pin(s) for use as analog-to-digital converter inputs.
        GPIOPinTypeADC(gpio_base, pin);
        // Disable the sequencer before configuring it.
        ADCSequenceDisable(base, sampleSeq);
        // set the clock.
        SysCtlClockSet(SYSCTL_SYSDIV_5|SYSCTL_USE_PLL|SYSCTL_OSC_MAIN|SYSCTL_XTAL_16MHZ);
        // Configures the trigger source and priority of a sample sequence.
        ADCSequenceConfigure(base, sampleSeq, ADC_TRIGGER_PROCESSOR, sampleSeq);
        // Configure a step of the sample sequencer.
        ADCSequenceStepConfigure(base, sampleSeq, 0, analogInput|ADC_CTL_IE | ADC_CTL_END);
        // Enable the sequencer after configuring it.
        ADCSequenceEnable(base, sampleSeq);
        // Clears sample sequence interrupt source.
        ADCIntClear(base, sampleSeq);
}

void ADC::setHWAveraging(uint32_t averaging)
{
   // Configures the hardware oversampling factor of the ADC.
      ADCHardwareOversampleConfigure(base,averaging);
}

uint32_t ADC::read()
{
   // read the analog voltage value on the configured pin. It should be a value from 0 to 4095(which represents the 0 - 3.3v).
    uint32_t Value[1];
    IntMasterDisable();

    // Causes a processor trigger for a sample sequence.
    ADCProcessorTrigger(base, sampleSeq);
    while(!ADCIntStatus(base, sampleSeq, false)){}

    // Gets the captured data for a sample sequence.
    ADCSequenceDataGet(base, sampleSeq, Value);
    IntMasterEnable();
    ADCIntClear(base, sampleSeq);
    return Value[0];
}

float ADC::readVolt()
{
   // return the voltage value according to the analog value we've read through the ADC::read() method.
    uint32_t value = read();
    return ADC_MAX_VOLT * value / ADC_ANALOG_VOLT_LENGTH;
    }

#endif
