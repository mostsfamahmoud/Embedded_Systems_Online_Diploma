/*************************************************************************
 * Author        : Mostafa Mahmoud                                     
 * Project       : Lesson2_CollisionAvoidance                                  
 * File          : state.h                                                 
 * Date          : Sep 19, 2023                                          
 * Version       :                                                   
 * GitHub        : https://github.com/mostsfamahmoud            		     
*************************************************************************/

#ifndef STATE_H_
#define STATE_H_

// Define a macro for generating state function names
#define STATE_define(_StateFun_)   void ST_##_StateFun_()

// Define a macro for creating a state function pointer
#define STATE(_StateFun_)          ST_##_StateFun_

// Function prototypes for states connectors
void US_GetDistance(int distance);
void DC_Motor_SetSpeed(int speed);

#endif /* STATE_H_ */
