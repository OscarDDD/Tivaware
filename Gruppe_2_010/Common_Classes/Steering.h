/*
 * Steering.h
 *
 *    Author: Yang Zhou
 *     Email: ugvxu@student.kit.edu
 */

#ifndef STEERING_H_
#define STEERING_H_

#include "System.h"
#include "MPU6050.h"
#include "ADC.h"


class Steering
{
public:
    Steering();
    ~Steering();
    void init(System *sys, uint32_t base, uint32_t sampleSeq, uint32_t analogInput);
    void calibrate();
    bool isCalibrated();
    float getValue();
private:

    /*
     * ADC of steering unit
     */
    ADC steering;

    /*
     * float that represents the min value and max value
     * to be measured
     */
    float min = 0;
    float max = 0;
};

#endif /* STEERING_H_ */
