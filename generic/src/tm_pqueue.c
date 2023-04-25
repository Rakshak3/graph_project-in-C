#ifndef __TM_PQUEUE__C
#define __TM_PQUEUE__C 123
#include<stdio.h>
#include<stdlib.h>
#include<tm_pqueue.h>

PQueue *createPQueue(int (*comparator)(void *,void *),bool *success)
{
int succ;
PQueue *pqueue;
pqueue=(PQueue *)malloc(sizeof(PQueue));
pqueue->heap=createHeap(comparator,&succ);
if(success)*success=true;
return pqueue;
}
void addToPQueue(PQueue *pqueue,void *element,bool *success)
{
int succ;
if(success)*success=false;
if(pqueue==false || pqueue->heap==NULL)return;
addToHeap(pqueue->heap,element,&succ);
if(success)*success=true;
}

void *removeFromPQueue(PQueue *pqueue,bool *success)
{
int succ;
void *element;
if(success)*success=false;
if(isPQueueEmpty(pqueue))return NULL;
element=removeFromHeap(pqueue->heap,&succ);
if(success)*success=true;
return element;
}

int getSizeOfPQueue(PQueue *pqueue)
{
if(pqueue==NULL || pqueue->heap==NULL)return 0;
return getSizeOfHeap(pqueue->heap);
}

bool isPQueueEmpty(PQueue *pqueue)
{
if(pqueue==NULL || pqueue->heap==NULL)return true;
if(getSizeOfHeap(pqueue->heap)==0)return true;
return false;
}

void *ElementAtTopOfPQueue(PQueue *pqueue,bool *success)
{
int succ;
void *element=NULL;
if(success)*success=false;
if(isPQueueEmpty(pqueue))return NULL;
element=elementAtTopOfHeap(pqueue->heap,&succ);
if(success)*success=true;
}

void *getElementFromPQueue(PQueue *pqueue,int index,int *success)
{
void *element=NULL;
if(success)*success=false;
if(pqueue==NULL)return element;
element=getElementFromHeap(pqueue->heap,index,success);
if(success)*success=true;
return element;
}

void updateElementInPQueue(PQueue *pqueue,int index,void *element,int *success)
{
if(success)*success=false;
if(pqueue==NULL)return;
updateElementInHeap(pqueue->heap,index,element,success);
}

void destroyPQueue(PQueue *pqueue)
{
if(pqueue==NULL)return;
if(pqueue->heap==NULL)return;
destroyHeap(pqueue->heap);
free(pqueue);
}

#endif
