/*************************************************************************
 * Author        : Mostafa Mahmoud                                     
 * Project       : Lesson2_CollisionAvoidance                                  
 * File          : CA.c                                                  
 * Date          : Sep 19, 2023                                          
 * Version       :                                                   
 * GitHub        : https://github.com/mostsfamahmoud            		     
*************************************************************************/

// Include necessary header files
#include <stdio.h>    // Standard I/O library
#include "state.h"    // Header for handling state machine
#include "CA.h"       // Header for the Collision Avoidance (CA) component

// Define constants
#define SPEED_MOVE   30   // Speed when in motion
#define SPEED_STOP   0    // Speed when stopped

// Variables
static int CA_speed = 0;             // Speed of the Collision Avoidance system
static int CA_distance = 0;          // Distance detected by the Ultrasonic Sensor
static int CA_threshold = 50;        // Threshold distance for triggering actions
static CA_State CA_currentState;      // Current state of the Collision Avoidance system

// Function pointer for the current state of the Collision Avoidance system
void (*CA_pState)() = NULL;

// Define the state behavior for the CA_waiting state
STATE_define(CA_waiting)
{
	// Set the current state to CA_waiting
	CA_currentState = CA_waiting;
	printf("CA_Waiting State: Distance = %d\tSpeed = %d\n", CA_distance, CA_speed);

	// State Action: Stop the system
	CA_speed = SPEED_STOP;

	// Send Signal (speed) from CA to DC Motor
	DC_Motor_SetSpeed(CA_speed);
}

// Define the state behavior for the CA_driving state
STATE_define(CA_driving)
{
	// Set the current state to CA_driving
	CA_currentState = CA_driving;
	printf("CA_Driving State: Distance = %d\tSpeed = %d\n", CA_distance, CA_speed);

	// State Action: Move the system
	CA_speed = SPEED_MOVE;

	// Send Signal (speed) from CA to DC Motor
	DC_Motor_SetSpeed(CA_speed);
}

// Function to receive distance data from the Ultrasonic Sensor
void US_GetDistance(int distance)
{
	// Update the CA_distance variable with the new distance value
	CA_distance = distance;

	// Event Check: Determine the next state based on the distance
	if (CA_distance <= CA_threshold)
		CA_pState = STATE(CA_waiting);  // Set to CA_waiting state if the distance is below the threshold
	else
		CA_pState = STATE(CA_driving);  // Set to CA_driving state if the distance is above the threshold

	printf("US ------ Distance = %d -----> CA\n", CA_distance);
}
