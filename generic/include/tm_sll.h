#ifndef __TM_SLL__H
#define __TM_SLL__H 123
#include<tm_common.h>

typedef struct sll_node
{
void *ptr;
struct sll_node *next;
}SinglyLinkedListNode;

typedef struct sll
{
struct sll_node *start;
struct sll_node *end;
int size;
}SinglyLinkedList;

typedef struct SinglyLinkedListIterator
{
SinglyLinkedListNode *node;
}SinglyLinkedListIterator;

SinglyLinkedList * createSinglyLinkedList(bool *success);
void addToSinglyLinkedList(SinglyLinkedList * sll,void * ptr,bool *success);
void clearSinglyLinkedList(SinglyLinkedList *sll);
int getSizeOfSinglyLinkedList(SinglyLinkedList *sll);
void * getFromSinglyLinkedList(SinglyLinkedList *sll,int index,bool *success);
void * removeFromSinglyLinkedList(SinglyLinkedList *sll,int index,bool *success);
void InsertIntoSinglyLinkedList(SinglyLinkedList *sll,int index,void *ptr,bool *success);
void appendToSinglyLinkedList(SinglyLinkedList *target,SinglyLinkedList *source,bool *success);
void destroySinglyLinkedList(SinglyLinkedList *sll);
SinglyLinkedListIterator getSinglyLinkedListIterator(SinglyLinkedList *sll,bool *success);
bool hasNextInSinglyLinkedList(SinglyLinkedListIterator *iter);
void * getNextElementFromSinglyLinkedList(SinglyLinkedListIterator *iter,bool *success);
#endif