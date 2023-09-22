/*************************************************************************
 * Author        : Mostafa Mahmoud                                     
 * Project       : Lesson2_CollisionAvoidance                                  
 * File          : US_sensor.c                                                
 * Date          : Sep 19, 2023                                          
 * Version       :                                                   
 * GitHub        : https://github.com/mostsfamahmoud            		     
*************************************************************************/

#include <stdio.h>      // Standard I/O library
#include <stdlib.h>     // Standard library for generating random numbers
#include "US_sensor.h"  // Include the header file for the Ultrasonic Sensor component

/* State Variables */
static int US_distance = 0;          // Distance detected by the Ultrasonic Sensor
static US_State US_currentState;     // Current state of the Ultrasonic Sensor

/* State Pointer */
volatile void (*US_pState)() = NULL;  // Function pointer for the current state of the Ultrasonic Sensor


// Function to generate a random distance within a given range
static int generateRandomDistance(int left, int right, int count)
{
	int rand_num;
	/* This generates a random number in the range between 'left' and 'right' (inclusive) */
	for(int i = 0; i < count; i++)
	{
		rand_num = (rand() % (right - left + 1)) + left;
	}

	return rand_num;
}

// Initialize the Ultrasonic Sensor
void US_Init()
{
	// Perform initialization of the Ultrasonic Sensor
	// Call the necessary US Drivers or functions
	printf("US Initialized\n");
}

// Define the behavior of the US_Busy state
STATE_define(US_Busy)
{
	// Set the current state to US_Busy
	US_currentState = US_Busy;

	// State Action: Simulate detecting a distance
	US_distance = generateRandomDistance(45, 55, 1);  // Generate a random distance
	printf("US_Busy State: Distance = %d\n", US_distance);

	// Send Signal (distance) from US to CA (Collision Avoidance)
	US_GetDistance(US_distance);  // Call the connector function to communicate distance data

	// State Transition: Remain in the US_Busy state
	US_pState = STATE(US_Busy);
}
