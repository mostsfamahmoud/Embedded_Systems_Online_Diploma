/*************************************************************************
 * Author        : Mostafa Mahmoud                                     
 * Project       : Lesson2_CollisionAvoidance                                  
 * File          : DC_motor.h                                                 
 * Date          : Sep 19, 2023                                          
 * Version       :                                                   
 * GitHub        : https://github.com/mostsfamahmoud            		     
*************************************************************************/

#ifndef DC_MOTOR_H_
#define DC_MOTOR_H_

#include "state.h"  // Include the header file for handling state machine

// Define the possible states for the DC Motor component
typedef enum {
	DC_Idle,  // Idle state
	DC_Busy   // Busy state
} DC_State;

// Declare the volatile external function pointer for the current state of the DC Motor
volatile extern void (*DC_pState)();

// Initialize the DC Motor
void DC_Init();

/* Declare State Functions */
STATE_define(DC_Idle);  // Declare the behavior of the DC_Idle state
STATE_define(DC_Busy);  // Declare the behavior of the DC_Busy state

#endif /* DC_MOTOR_H_ */
