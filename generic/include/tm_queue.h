#ifndef __TM_QUEUE__H
#define __TM_QUEUE__H 123
#include<tm_sll.h>
#include<tm_common.h>

typedef struct __$_tm_queue
{
SinglyLinkedList *sll;
}Queue;

Queue *createQueue(bool *succ);
void addToQueue(Queue *queue,void *ptr,bool *succ);
void *removeFromQueue(Queue *queue,bool *succ);
int getSizeOfQueue(Queue *queue);
bool isQueueEmpty(Queue *queue);
void *ElementAtTopOfQueue(Queue *queue,bool *succ);
void *getElementFromQueue(Queue *queue,int index,bool *succ);
void clearQueue(Queue *queue);
void destroyQueue(Queue *queue);
#endif