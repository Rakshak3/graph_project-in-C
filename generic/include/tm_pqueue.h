#ifndef __TM_PQUEUE__H
#define __TM_PQUEUE__H 123
#include<tm_heap.h>
#include<stdlib.h>
#include<stdio.h>

typedef struct __$_tm_pqueue
{
Heap *heap;
}PQueue;

PQueue *createPQueue(int (*comparator)(void *,void *),bool *success);
void addToPQueue(PQueue *pqueue,void *element,bool *success);
void *removeFromPQueue(PQueue *pqueue,bool *success);
int getSizeOfPQueue(PQueue *pqueue);
bool isPQueueEmpty(PQueue *pqueue);
void *ElementAtTopOfPQueue(PQueue *pqueue,bool *success);
void *getElementFromPQueue(PQueue *pqueue,int index,int *success);
void updateElementInPQueue(PQueue *pqueue,int index,void *element,int *success);
void destroyPQueue(PQueue *pqueue);

#endif