/*
 * Steering.cpp
 *
 *    Author: Yang Zhou
 *     Email: ugvxu@student.kit.edu
 */

#include "Steering.h"
#include "Config.h"
#include "Segway.h"

Steering::Steering()
{
    /*
     * Default empty constructor
     */
}

Steering::~Steering()
{
    /*
     * Default empty destructor
     */
}

void Steering::init(System *sys, uint32_t base, uint32_t sampleSeq, uint32_t analogInput)
{
    steering.init(sys, base, sampleSeq, analogInput);
    steering.setHWAveraging(64);

}

void Steering::calibrate()
{
    /*
     *  Measure the volt of max and min values. the function
     *  first measure the max value if not existing then the min value.
     *  the value will be overwritten if the current volt is bigger (or smaller) than
     *  max (or min) value.
     */
    float volt = this->steering.readVolt();
    if (this->max == 0 && this->min == 0)
    {
        this->max = volt;
    }
    else if (volt > this->max)
    {
        this->min = this->max;
        this->max = volt;
    }
    else if (volt < this->max && this->min == 0)
    {
        this->min = volt;
    }
}

bool Steering::isCalibrated()
{
    /**
     *  Check if the steering is calibrated
     */
    return this->max != 0 && this->min != 0;
}

float Steering::getValue()
{
    /**
     *  return a value between -1.0f and 1.0f corresponding to a
     *  full steering to the right (-1.0f) or left (1.0f). 0.0f
     *  corresponds to driving straight ahead
     */
    if (this->max != 0 && this->min != 0)
    {
        float value = (2 * this->steering.readVolt()) / (this->max - this->min) - (this->max + this->min) / (this->max - this->min);

        // deviation
        if (value > 1)
        {
            return 1;
        }
        else if (value < -1)
        {
            return -1;
        }
        else
        {
            return value;
        }
    }
    else
    {
        return 0;
    }
}
