#ifndef __TM_STACK__C
#define __TM_STACK__C 1213
#include<stdlib.h>
#include<tm_sll.h>
#include<stdio.h>
#include<tm_stack.h>
Stack *createStack(bool *succ)
{
Stack *stack;
if(succ)*succ=false;
SinglyLinkedList *sll;
sll=createSinglyLinkedList(succ);
if(*succ=false)return NULL;
stack=(Stack *)malloc(sizeof(Stack));
if(sll==NULL)
{
destroySinglyLinkedList(sll);
if(succ)*succ=false;
return NULL;
}
stack->sll=sll;
if(succ)*succ=true;
return stack;
}
void pushOnStack(Stack *stack,void *ptr,bool *succ)
{
if(succ)*succ=false;
if(stack==NULL || stack->sll==NULL)return;
InsertIntoSinglyLinkedList(stack->sll,0,ptr,succ);
}
void *popFromStack(Stack *stack,bool *succ)
{
void *ptr;
if(succ)*succ=false;
if(stack==NULL || stack->sll==NULL)return NULL;
ptr=removeFromSinglyLinkedList(stack->sll,0,succ);
if(succ)*succ=true;
return ptr;
}
int getSizeOfStack(Stack *stack)
{
int x;
if(stack==NULL) return 0;
x=getSizeOfSinglyLinkedList(stack->sll);
return x;
}
void *ElementAtTopOfStack(Stack *stack,bool *succ)
{
void *ptr;
if(succ)*succ=false;
if(isStackEmpty(stack))return NULL;
ptr=getFromSinglyLinkedList(stack->sll,0,succ);
if(succ)*succ=true;
return ptr;
}
bool isStackEmpty(Stack *stack)
{
if(stack==NULL)return true;
if(stack->sll==NULL)return true;
if(stack->sll->size==0)return true;
return false;
}
void clearStack(Stack *stack)
{
if(stack==NULL || stack->sll==NULL)return;
clearSinglyLinkedList(stack->sll);
}
void destroyStack(Stack *stack)
{
if(stack==NULL)return;
destroySinglyLinkedList(stack->sll);
free(stack);
}
#endif