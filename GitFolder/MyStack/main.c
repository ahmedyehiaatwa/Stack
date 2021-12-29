#include <stdio.h>
#include <stdlib.h>
#include "Stack.c"



int main()
{
    uint8_t GivenExpression[100];
	printf("Enter the expression: \n");
	gets(GivenExpression);
	printf("%s", balancedParentheses(GivenExpression));

    return 0;
}




