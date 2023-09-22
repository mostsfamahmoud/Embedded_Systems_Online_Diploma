/*************************************************************************
 * Author        : Mostafa Mahmoud                                     
 * Project       : Lesson2_CollisionAvoidance                                  
 * File          : DC_motor.c                                                  
 * Date          : Sep 19, 2023                                          
 * Version       :                                                   
 * GitHub        : https://github.com/mostsfamahmoud            		     
*************************************************************************/

#include <stdio.h>        // Standard I/O library
#include "DC_motor.h"     // Include the header file for the DC Motor component

/* State Variables */
static int DC_speed = 0;     // Speed variable for the DC Motor
static DC_State DC_currentState;  // Current state of the DC Motor

/* State Pointer */
volatile void (*DC_pState)() = NULL;  // Function pointer for the current state of the DC Motor

// Initialize the DC Motor
void DC_Init()
{
    printf("DC Motor Initialized\n");
}

// Define the behavior of the DC_Idle state
STATE_define(DC_Idle)
{
    // Set the current state to DC_Idle
    DC_currentState = DC_Idle;

    // State Action: Implement idle behavior
    // Call PWM (Pulse Width Modulation) to set the speed = DC_speed
    printf("DC_Idle State: Speed = %d\n", DC_speed);
}

// Define the behavior of the DC_Busy state
STATE_define(DC_Busy)
{
    // Set the current state to DC_Busy
    DC_currentState = DC_Busy;

    // State Action: Implement busy behavior
    // Call PWM (Pulse Width Modulation) to set the speed = DC_speed
    printf("DC_Busy State: Speed = %d\n", DC_speed);

    // State Transition: Move to DC_Idle state after performing a task
    DC_pState = STATE(DC_Idle);
}

// Function to set the speed of the DC Motor
void DC_Motor_SetSpeed(int speed)
{
    DC_speed = speed;  // Update the speed variable

    printf("CA ------ Speed = %d -----> DC\n", DC_speed);

    // State Transition: Move to DC_Busy state when setting the speed
    DC_pState = STATE(DC_Busy);
}
