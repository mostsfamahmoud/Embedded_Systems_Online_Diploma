/*************************************************************************
 * Author        : Mostafa Mahmoud                                     
 * Project       : Lesson2_CollisionAvoidance                                  
 * File          : CA.h                                                  
 * Date          : Sep 19, 2023                                          
 * Version       :                                                   
 * GitHub        : https://github.com/mostsfamahmoud            		     
*************************************************************************/

#ifndef CA_H_
#define CA_H_

#include "state.h"  // Include the header for handling state machine

// Define the possible states for the Collision Avoidance (CA) component
typedef enum {
	CA_waiting,   // Waiting state
	CA_driving    // Driving state
} CA_State;

// Declare the State Pointer to function
extern void (*CA_pState)();

/* Declare State Functions */
STATE_define(CA_waiting);  // Declare the behavior of the CA_waiting state
STATE_define(CA_driving);  // Declare the behavior of the CA_driving state

#endif /* CA_H_ */
