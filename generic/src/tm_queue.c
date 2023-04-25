#ifndef __TM_QUEUE__C
#define __TM_QUEUE__C 1213
#include<stdlib.h>
#include<tm_sll.h>
#include<stdio.h>
#include<tm_queue.h>
Queue *createQueue(bool *succ)
{
Queue *queue;
if(succ)*succ=false;
SinglyLinkedList *sll;
sll=createSinglyLinkedList(succ);
if(*succ=false)return NULL;
queue=(Queue *)malloc(sizeof(Queue));
if(sll==NULL)
{
destroySinglyLinkedList(sll);
if(succ)*succ=false;
return NULL;
}
queue->sll=sll;
if(succ)*succ=true;
return queue;
}
void addToQueue(Queue *queue,void *ptr,bool *succ)
{
if(succ)*succ=false;
if(queue==NULL || queue->sll==NULL)return;
addToSinglyLinkedList(queue->sll,ptr,succ);
}
void *removeFromQueue(Queue *queue,bool *succ)
{
void *ptr;
if(succ)*succ=false;
if(queue==NULL || queue->sll==NULL)return NULL;
ptr=removeFromSinglyLinkedList(queue->sll,0,succ);
if(succ)*succ=true;
return ptr;
}
int getSizeOfQueue(Queue *queue)
{
int x;
if(queue==NULL) return 0;
x=getSizeOfSinglyLinkedList(queue->sll);
return x;
}
void *ElementAtTopOfQueue(Queue *queue,bool *succ)
{
void *ptr;
if(succ)*succ=false;
if(isQueueEmpty(queue))return NULL;
ptr=getFromSinglyLinkedList(queue->sll,0,succ);
if(succ)*succ=true;
return ptr;
}

void *getElementFromQueue(Queue *queue,int index,bool *succ)
{
void *ptr;
if(succ)*succ=false;
if(isQueueEmpty(queue))return NULL;
ptr=getFromSinglyLinkedList(queue->sll,index,succ);
if(succ)*succ=true;
return ptr;
}

bool isQueueEmpty(Queue *queue)
{
if(queue==NULL)return true;
if(queue->sll==NULL)return true;
if(queue->sll->size==0)return true;
return false;
}
void clearQueue(Queue *queue)
{
if(queue==NULL || queue->sll==NULL)return;
clearSinglyLinkedList(queue->sll);
}
void destroyQueue(Queue *queue)
{
if(queue==NULL)return;
destroySinglyLinkedList(queue->sll);
free(queue);
}
#endif