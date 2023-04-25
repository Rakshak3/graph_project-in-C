#ifndef __TM_STACK__H
#define __TM_STACK__H 123
#include<tm_sll.h>
#include<tm_common.h>

typedef struct __$_tm_stack
{
SinglyLinkedList *sll;
}Stack;

Stack *createStack(bool *succ);
void pushOnStack(Stack *stack,void *ptr,bool *succ);
void *popFromStack(Stack *stack,bool *succ);
int getSizeOfStack(Stack *stack);
bool isStackEmpty(Stack *stack);
void *ElementAtTopOfStack(Stack *stack,bool *succ);
void clearStack(Stack *stack);
void destroyStack(Stack *stack);
#endif