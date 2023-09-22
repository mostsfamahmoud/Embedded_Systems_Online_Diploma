/*************************************************************************
 * Author        : Mostafa Mahmoud                                     
 * Project       : Lesson2_CollisionAvoidance                                  
 * File          : US_sensor.h                                                
 * Date          : Sep 19, 2023                                          
 * Version       :                                                   
 * GitHub        : https://github.com/mostsfamahmoud            		     
*************************************************************************/

#ifndef US_SENSOR_H_
#define US_SENSOR_H_

#include "state.h"  // Include the header file for handling state machine

// Define the possible states for the Ultrasonic Sensor (US) component
typedef enum{
	US_Busy  // Busy state
} US_State;

// Declare the volatile external function pointer for the current state of the Ultrasonic Sensor
volatile extern void (*US_pState)();

// Initialize the Ultrasonic Sensor
void US_Init();

/* Declare State Functions */
STATE_define(US_Busy);  // Declare the behavior of the US_Busy state

#endif /* US_SENSOR_H_ */
