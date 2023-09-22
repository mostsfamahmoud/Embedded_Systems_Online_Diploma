/*************************************************************************
 * Author        : Mostafa Mahmoud                                     
 * Project       : Lesson2_CollisionAvoidance                                  
 * File          : main.c                                                  
 * Date          : Sep 19, 2023                                          
 * Version       :                                                   
 * GitHub        : https://github.com/mostsfamahmoud            		     
*************************************************************************/

// Include necessary header files
#include "CA.h"         // Collision Avoidance component
#include "US_sensor.h"  // Ultrasonic Sensor component
#include "DC_motor.h"   // DC Motor component

// Function to initialize the system
void setup()
{
    // Initialize all drivers (possibly hardware drivers)
    // Initialize all interrupts (IRQs)
    // Initialize Hardware Abstraction Layer (HAL) components for Ultrasonic Sensor (US_Driver) and DC Motor (DC_Driver)
    // Initialize any other necessary blocks or components

    US_Init();   // Initialize Ultrasonic Sensor
    DC_Init();   // Initialize DC Motor
	
    CA_pState = STATE(CA_waiting);  // Set the state pointer for Collision Avoidance to CA_waiting state
    DC_pState = STATE(DC_Idle);     // Set the state pointer for DC Motor to DC_Idle state
    US_pState = STATE(US_Busy);     // Set the state pointer for Ultrasonic Sensor to US_Busy state
}

// Main function, the entry point of the program
int main()
{
    // Call the setup function to initialize the system
    setup();

    // Enter an infinite loop to continuously manage and control the system
    while(1)
    {
        // Call the state functions for each component
        US_pState();  // Execute Ultrasonic Sensor state
        CA_pState();  // Execute Collision Avoidance state
        DC_pState();  // Execute DC Motor state
    }

    return 0;  // Return 0 to indicate successful execution (not used in embedded systems)
}
