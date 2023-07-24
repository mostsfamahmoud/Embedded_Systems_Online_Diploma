#include <stdio.h>
#include <time.h>

// Clock() return the current number of clock ticks
// CLOCKS_PER_SEC (the number of clock ticks per second)

int main()
{
    clock_t t;
    t = clock();

    int num1, num2, sum;

    printf("Enter the first number: \n");
    //scanf("%d",&num1);
    num1 = 1;

    printf("Enter the second number: \n");
    //scanf("%d",&num2);
    num2 = 2;
    sum = num1 + num2;

    printf("Sum of two values is %d\n",sum);

    t = clock() - t;
    double timeTaken = ((double)t) / CLOCKS_PER_SEC;
    printf("Execution time: %lf seconds",timeTaken);
    
    return 0;
}
