/*
 * PWM.cpp
 *
 *    Author: Zeyu Li
 *     Email: uegyy@student.kit.edu
 */


// Uncomment following #define to use the precompiled PWM library instead of
// the code in this file.
// #define USE_PWM_LIBRARY

#ifndef USE_PWM_LIBRARY


#include <PWM.h>


PWM::PWM()
{
    /*
     * Default empty constructor
     */
}

PWM::~PWM()
{
    /*
     * Default empty destructor
     */
}

void PWM::init(System *sys,uint32_t portBase, uint32_t pin1, uint32_t pin2, bool invert, uint32_t freq)
{

    /**
     * Initializes a PWM object by enabling the corresponding peripheral
     * (the port which contains two pins, the PWM Generator), and configuring the pin as PWM type.
     *
     *
     * sys:      Pointer to the current System instance. Needed for error
     *           handling.
     * portBase: Base address of the GPIO port. Use the constants provided by
     *           the TivaWare API (inc/hw_memmap.h line 53-56, 73-76).
     * pin1:     Pin number in the GPIO port. Use the constants provided by
     *           the TivaWare API (driverlib/gpio.h line 60-67).
     * pin2:     Pin number in the GPIO port. Use the constants provided by
     *           the TivaWare API (driverlib/gpio.h line 60-67).
     * invert:   Optional declaration if the output signal needs to be inverted.
     *           The default value is false.
     * freq:     Optional declaration of PWM-Frequency in Hz. The default value is 5kHz.
     */

    /**
     *  Enable GPIO peripherals if available. (see "TivaWare(TM) TM4C123GH6PM Datenblatt" page 1233).
     */
    switch (portBase|pin1|pin2)
    {
    case GPIO_PORTA_BASE|GPIO_PIN_6|GPIO_PIN_7 :
        SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOA);
        GPIOPinTypePWM(GPIO_PORTA_BASE, GPIO_PIN_6);
        GPIOPinTypePWM(GPIO_PORTA_BASE, GPIO_PIN_7);


        // Module 1 PWM Generator 1
        SysCtlPeripheralEnable(SYSCTL_PERIPH_PWM1); //enable pwm1 module
        GPIOPinConfigure(GPIO_PA6_M1PWM2);
        GPIOPinConfigure(GPIO_PA7_M1PWM3);
        gen = PWM_GEN_1;
        module = PWM1_BASE;
        break;
    case GPIO_PORTB_BASE|GPIO_PIN_6|GPIO_PIN_7:
        SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOB);
        GPIOPinTypePWM(GPIO_PORTB_BASE, GPIO_PIN_6);
        GPIOPinTypePWM(GPIO_PORTB_BASE, GPIO_PIN_7);


        // Module 0 PWM Generator 0
        SysCtlPeripheralEnable(SYSCTL_PERIPH_PWM0); //enable pwm0 module
        GPIOPinConfigure(GPIO_PB6_M0PWM0);
        GPIOPinConfigure(GPIO_PB7_M0PWM1);

        gen = PWM_GEN_0;
        module = PWM0_BASE;
        break;
    case GPIO_PORTB_BASE|GPIO_PIN_4|GPIO_PIN_5:

        SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOB);
        GPIOPinTypePWM(GPIO_PORTB_BASE, GPIO_PIN_4);
        GPIOPinTypePWM(GPIO_PORTB_BASE, GPIO_PIN_5);


        // Module 0 PWM Generator 1
        SysCtlPeripheralEnable(SYSCTL_PERIPH_PWM0); //enable pwm0 module
        GPIOPinConfigure(GPIO_PB4_M0PWM2);
        GPIOPinConfigure(GPIO_PB5_M0PWM3);

        gen = PWM_GEN_1;
        module = PWM0_BASE;
        break;
    case GPIO_PORTC_BASE|GPIO_PIN_4|GPIO_PIN_5:
        SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOC);
        GPIOPinTypePWM(GPIO_PORTC_BASE, GPIO_PIN_4);
        GPIOPinTypePWM(GPIO_PORTC_BASE, GPIO_PIN_5);


        // Module 0 PWM Generator 3
        SysCtlPeripheralEnable(SYSCTL_PERIPH_PWM0); //enable pwm0 module
        GPIOPinConfigure(GPIO_PC4_M0PWM6);
        GPIOPinConfigure(GPIO_PC5_M0PWM7);

        gen = PWM_GEN_3;
        module = PWM0_BASE;
        break;
    case GPIO_PORTD_BASE|GPIO_PIN_0|GPIO_PIN_1:
        SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOD);
        GPIOPinTypePWM(GPIO_PORTD_BASE, GPIO_PIN_0);
        GPIOPinTypePWM(GPIO_PORTD_BASE, GPIO_PIN_1);


        // Module 1 PWM Generator 0
        SysCtlPeripheralEnable(SYSCTL_PERIPH_PWM1); //enable pwm1 module
        GPIOPinConfigure(GPIO_PD0_M1PWM0);
        GPIOPinConfigure(GPIO_PD1_M1PWM1);

        gen = PWM_GEN_0;
        module = PWM1_BASE;

        // Module 0 PWM Generator 3
        // GPIOPinConfigure(GPIO_PD0_M0PWM6);
        // GPIOPinConfigure(GPIO_PD1_M0PWM7);
        // gen = PWM_GEN_3;
        // module = PWM0_BASE;
        break;
    case GPIO_PORTE_BASE|GPIO_PIN_4|GPIO_PIN_5:
        SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOE);
        GPIOPinTypePWM(GPIO_PORTE_BASE, GPIO_PIN_5);
        GPIOPinTypePWM(GPIO_PORTE_BASE, GPIO_PIN_4);

        // Module 1 PWM Generator 1
        SysCtlPeripheralEnable(SYSCTL_PERIPH_PWM1); //enable pwm1 module
        GPIOPinConfigure(GPIO_PE4_M1PWM2);
        GPIOPinConfigure(GPIO_PE5_M1PWM3);

        gen = PWM_GEN_1;
        module = PWM1_BASE;

        // Module 0 PWM Generator 1
        // SysCtlPeripheralEnable(SYSCTL_PERIPH_PWM0); //enable pwm0 module
        // GPIOPinConfigure(GPIO_PE4_M0PWM4);
        // GPIOPinConfigure(GPIO_PE5_M0PWM5);

        // gen = PWM_GEN_1;
        // module = PWM0_BASE;
        break;
    case GPIO_PORTF_BASE|GPIO_PIN_0|GPIO_PIN_1:
        SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);
        SysCtlPeripheralEnable(SYSCTL_PERIPH_PWM1); //enable pwm1 module
        GPIOPinTypePWM(GPIO_PORTF_BASE, GPIO_PIN_0);
        GPIOPinTypePWM(GPIO_PORTF_BASE, GPIO_PIN_1);

        // Module 1 PWM Generator 2
        GPIOPinConfigure(GPIO_PF0_M1PWM4);
        GPIOPinConfigure(GPIO_PF1_M1PWM5);

        gen = PWM_GEN_2;
        module = PWM1_BASE;
        break;
    case GPIO_PORTF_BASE|GPIO_PIN_2|GPIO_PIN_3:
        SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);
        SysCtlPeripheralEnable(SYSCTL_PERIPH_PWM1); //enable pwm1 module
        GPIOPinTypePWM(GPIO_PORTF_BASE, GPIO_PIN_2);
        GPIOPinTypePWM(GPIO_PORTF_BASE, GPIO_PIN_3);

        // Module 1 PWM Generator 3
        GPIOPinConfigure(GPIO_PF2_M1PWM6);
        GPIOPinConfigure(GPIO_PF3_M1PWM7);

        gen = PWM_GEN_3;
        module = PWM1_BASE;
        break;
    default:
        sys->error(PWMWrongConfig, &portBase, &pin1, &pin2);
        break;
    }

    // Wait until peripheral is enabled
    // Normally not bothering
    sys->delayCycles(15);

    // see Data-sheet P1232
    switch (gen)
    {
        case PWM_GEN_0:
            pwmBit1 = PWM_OUT_0;
            pwmBit2 = PWM_OUT_1;
            pwmOutBit1 = PWM_OUT_0_BIT;
            pwmOutBit2 = PWM_OUT_1_BIT;
            break;
        case PWM_GEN_1:
            pwmBit1 = PWM_OUT_2;
            pwmBit2 = PWM_OUT_3;
            pwmOutBit1 = PWM_OUT_2_BIT;
            pwmOutBit2 = PWM_OUT_3_BIT;
            break;
        case PWM_GEN_2:
            pwmBit1 = PWM_OUT_4;
            pwmBit2 = PWM_OUT_5;
            pwmOutBit1 = PWM_OUT_4_BIT;
            pwmOutBit2 = PWM_OUT_5_BIT;
            break;
        case PWM_GEN_3:
            pwmBit1 = PWM_OUT_6;
            pwmBit2 = PWM_OUT_7;
            pwmOutBit1 = PWM_OUT_6_BIT;
            pwmOutBit2 = PWM_OUT_7_BIT;
            break;
        default:
            break;
    }


    // Configure
    this->sys = sys;
    this->portBase = portBase;
    this->pin1 = pin1;
    this->pin2 = pin2;

    // Apply PWM clock
    ui32PWMClock = sys->getClockFreq() / sys->getPWMClockDiv();

    // Apply Load value
    ui32Load = (ui32PWMClock / freq) - 1;

    // Set PWM Mode to UP_DOWN Mode
    PWMGenConfigure(module, gen, PWM_GEN_MODE_UP_DOWN);
    PWMGenPeriodSet(module, gen, ui32Load);

    // Set Inverts
    PWMOutputInvert(module, pwmOutBit1|pwmOutBit2, invert);

    // Note: The Output will not be enabled until the duty settles.

}

void PWM::setFreq(uint32_t freq)
{
    /**
     * Configure the PWM-Generator with the frequency given.
     *
     * freq:     Frequency in Hz.
     */

    // Update the Load value. the PWM Clock will be updated too because PWm Clock Divide might be changed.
    ui32PWMClock = sys->getClockFreq() / sys->getPWMClockDiv();
    ui32Load = (ui32PWMClock / freq) - 1;
    PWMGenPeriodSet(module, gen, ui32Load);
}

void PWM::setDuty(float duty)
{
    /**
     *  Once the PWM object has been configured, the connected motor can be completely
     *  operated using this method. Depending on the direction, i.e. depending on
     *  whether the transferred duty cycle is positive or negative,
     *  the corresponding PWM signal is only applied to one or the other
     *  output pin of the PWM generator. The other pin is grounded.
     *  As a convention, one duty cycle is greater than zero means ¡°forward¡±,
     *  and in this case the PWM signal is applied to the ¡°low value¡± pin.
     *
     *  If the duty cycle is 0.0f, both outputs are switched off. This also applies to values
     *  the amount is smaller than the minimum resolution, e.g. -1e-42f.
     *
     *  duty:     duty cycle as floating point number between -1.0f and 1.0f. A value of 0.0f
     *            or very close to 0.0f switches the output off. The sign determines the
     *            Direction of rotation.

     *
     */

    if (duty < 0)
    {
        PWMPulseWidthSet(module, pwmBit1, -duty * ui32Load);
        PWMPulseWidthSet(module, pwmBit2, 0);
    } else {
        PWMPulseWidthSet(module, pwmBit1, 0);
        PWMPulseWidthSet(module, pwmBit2, duty * ui32Load);
    }
    PWMOutputState(module,  pwmOutBit1|pwmOutBit2, true); //enable output
    PWMGenEnable(module, gen);
}

#endif
