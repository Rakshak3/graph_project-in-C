#ifndef __TM_HEAP__H 
#define __TM_HEAP__H 123	
#include<tm_array.h>
typedef struct __heap
{
Array *array;
int size;
int (*comparator)(void *,void *);
}Heap;

Heap *createHeap(int (*comparator)(void *,void *),int *success);
void addToHeap(Heap *heap,void *element,int *success);
void *removeFromHeap(Heap *heap,int *success);
void *elementAtTopOfHeap(Heap *heap,int *success);
int getSizeOfHeap(Heap *heap);
void destroyHeap(Heap *heap);
void *getElementFromHeap(Heap *heap,int index,int *success);
void updateElementInHeap(Heap *heap,int index,void *element,int *success);
#endif