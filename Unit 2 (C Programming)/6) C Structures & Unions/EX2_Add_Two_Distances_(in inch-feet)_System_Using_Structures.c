/*
 ============================================================================
 Name        : EX2.c
 Author      : Mostafa Mahmoud
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

/*
EX2: C Program to Add Two Distances (in inch-feet) System Using Structures

Output:
Enter information for 1st distance
Enter feet: 12
Enter inch: 3.45
Enter information for 2nd distance
Enter feet: 12
Enter inch: 9.2
Sum of distances = 25'-0.6"
*/

#include <stdio.h>
#include <stdlib.h>

#define SIZE    3

/* Note: 1 Feet -> 12 Inch */
struct Distance
{
	int feet;
	float inch;
};

typedef struct Distance Distance;

int main(void) {

	/* Using the 1st and 2nd structures as the two distances that are taken as input from user
	 * and the 3rd as the sum of the two distances
	 */
	Distance distArr[SIZE];

	/* Initialize both members of the 3rd Distance structure to ZEROs to ACT like the sum of distances */
	distArr[2].feet = 0;
	distArr[2].inch = 0;

	for(unsigned int i = 0; i < (SIZE - 1); i++)
	{
		if (i == 0)
			printf("Enter information for %s distance:\n", "1st");
		else
			printf("Enter information for %s distance:\n", "2nd");

		printf("Enter feet: ");
		fflush(stdout);
		scanf("%d",&distArr[i].feet);

		printf("Enter inch: ");
		fflush(stdout);
		scanf("%f",&distArr[i].inch);
		printf("\n");
	}

	distArr[2].inch = distArr[0].inch + distArr[1].inch;

	/* If inch is greater than 12 , Count it as feet */
	while(distArr[2].inch >= 12)
	{
		distArr[2].feet++;
		distArr[2].inch -= 12;
	}

	distArr[2].feet += (distArr[0].feet + distArr[1].feet);

	printf("Sum of distances = %d\' - %.2f\"\n",distArr[2].feet,distArr[2].inch);
	return 0;
}
