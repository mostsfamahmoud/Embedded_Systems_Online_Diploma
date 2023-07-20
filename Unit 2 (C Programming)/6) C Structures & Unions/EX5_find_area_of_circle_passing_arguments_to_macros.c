/*
 ============================================================================
 Name        : EX5.c
 Author      : Mostafa Mahmoud
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

/*
EX5: C Program to find area of a circle, passing arguments to macros. [Area of circle=nr2]

Output
Enter the radius: 3
Area = 28.27
*/

#include <stdio.h>
#include <stdlib.h>

#define PI  3.142857

#define AREA_OF_CIRCLE(RADIUS)    (RADIUS * RADIUS * PI)

int main(void) {

	unsigned int radius;

	printf("Enter the radius: ");
	fflush(stdout);
	scanf("%u",&radius);

	printf("Area = %.2lf\n",AREA_OF_CIRCLE(radius));

	return 0;
}
