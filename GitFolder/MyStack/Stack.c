#include "Stack.h"
#include "Def.h"

uint8_t stackarr[MAX];
sint8_t top=-1;


void push(uint8_t u8_data)
{
  if (top+1<MAX){
    stackarr[top]= u8_data;
    top++;
  }
}


uint8_t pop(void)
{
    if (top>-1){
            top--;
        return stackarr[top];
    }
    else
        printf("Stack is empty");
        return -1;
}

uint8_t isEmpty(void)
{
    if (top>-1)
        return 0;
    else
        return 1;
}

void printStack(void)
{
    uint8_t *ptr= stackarr;
    while(*ptr)
    {
        printf("%c\n", *ptr);
        ptr++;
    }
}

uint8_t* balancedParentheses(uint8_t* expression){

    uint8_t curlybracket =0;
    uint8_t squarebracket=0;
    uint8_t bracket=0;


	while(*expression){
		if(*expression == '(')
        {
            curlybracket++;
            push(*expression);
        }
        if(*expression == ')')
            curlybracket--;
        if(*expression == '{')
            {
            bracket++;
            push(*expression);
            }
        if(*expression == '}')
            bracket--;
        if(*expression == '[')
        {
            squarebracket++;
            push(*expression);
        }
        if(*expression == ']')
            squarebracket--;

            expression++;
	}
	if(curlybracket==0 && squarebracket==0 && bracket==0)
		return "Balanced";
	else
		return "Not Balanced";
}





