#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include "Def.h"
#define MAX 100

void push(uint8_t u8_data);

uint8_t pop(void);

uint8_t isEmpty(void);

void printStack(void);

uint8_t* balancedParentheses(uint8_t* expression);


#endif // STACK_H_INCLUDED


