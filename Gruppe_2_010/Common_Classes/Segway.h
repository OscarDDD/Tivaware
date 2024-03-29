/*
 * Segway.h
 *
 *    Author: Henri Hornburg
 *     Email: henri.hornburg@student.kit.edu
 * Co-author: Max Zuidberg
 *     Email: m.zuidberg@icloud.com
 *
 * The segway class contains all the code needed drive a segway.
 */

#ifndef SEGWAY_H_
#define SEGWAY_H_

/*
 * stdbool.h:    Boolean definitions for the C99 standard
 * Config.h:     All configurable parameters of the segway, as for example its 
 *               pinout. Note: all constants are prefixed by CFG_.
 * System.h:     Header file for the System class (needed for example for clock
 *               settings)
 * Controller.h: Header file for the Controller class containing the control
 *               algorithm to drive a segway.
 * GPIO.h:       Header file for the GPIO class
 * PWM.h:        Header file for the PWM class
 * ADC.h:        Header file for the ADC class
 * MPU6050.h:    Header file for the MPU6050 class
 * Steering.h:   Header file for the Steering class
 */
#include <stdbool.h>
#include <stdint.h>
#include "Config.h"
#include "System.h"
#include "Controller.h"
#include "Timer.h"
#include "GPIO.h"
#include "PWM.h"
#include "ADC.h"
#include "MPU6050.h"
#include "Steering.h"

/**
 *  stopISR function should be declared in the main entrance
 */
extern void stopISR();

class Segway
{
public:
    Segway();
    virtual ~Segway();
    void init(System *sys, Timer *countdownTimer);
    void update();
    void backgroundTasks();
    void pause();

private:
    System* sys;
    Timer* countdownTimer;

    Controller controller;
    GPIO footSwitch, enableMotors, calibrate, greenLed;
    Steering steering;
    PWM leftMotor, rightMotor;
    ADC batteryVoltage;
    MPU6050 sensor;

    // Flags
    volatile bool updateFlag = false;

    volatile bool standby = true;

    volatile bool paused = false;

};

#endif /* SEGWAY_H_ */
