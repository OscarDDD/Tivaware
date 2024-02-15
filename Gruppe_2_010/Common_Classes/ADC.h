/*
 * ADC.h
 *
 *    Author:Dong Sicheng
 *     Email:udwbi@student.kit.edu
 */

#ifndef ADC_H_
#define ADC_H_


/*
 * stdbool.h:               Boolean definitions for the C99 standard
 * stdint.h:                Variable definitions for the C99 standard
 * System.h:                Access to current CPU clock and other functions.
 */
#include <stdbool.h>
#include <stdint.h>
#include "System.h"
#include "driverlib/adc.h"

class ADC
{
public:
    ADC();
    virtual ~ADC();
    void init(System *sys, uint32_t base, uint32_t sampleSeq, uint32_t analogInput);
    void setHWAveraging(uint32_t averaging);
    uint32_t read();
    float readVolt();

private:
    /*
     * The following array is needed to let the compiler know that the
     * precompiled class library needs space for its private variables.
     * Or in shorter terms: simply ignore it.
     */
    uint32_t spaceForLib[41];

    System *sys;
    uint32_t base, sampleSeq, analogInput,pin;

    const float ADC_MAX_VOLT = 3.3f;
    //The range of analog voltage is 0 - 4095
    const int ADC_ANALOG_VOLT_LENGTH = 4096;

};


#endif /* ADC_H_ */
