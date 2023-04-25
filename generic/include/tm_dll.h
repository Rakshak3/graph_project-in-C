#ifndef __TM_DLL__H
#define __TM_DLL__H 123
#include<tm_common.h>
typedef struct dll_node
{
void *ptr;
struct dll_node *next;
struct dll_node *previous; 
}DoublyLinkedListNode;   

typedef struct dll
{
struct dll_node *start;
struct dll_node *end;
int size;
}DoublyLinkedList;

typedef struct Doubly_Linked_List_Iterator
{
DoublyLinkedListNode *node;
}DoublyLinkedListIterator;

DoublyLinkedList * createDoublyLinkedList(bool *succ);
void destroyDoublyLinkedList(DoublyLinkedList *dll);
int getSizeOfDoublyLinkedList(DoublyLinkedList *dll);
void addToDoublyLinkedList(DoublyLinkedList *dll,void *ptr,bool *succ);
void *removeFromDoublyLinkedList(DoublyLinkedList *dll,int index,bool *succ);
void *getFromDoublyLinkedList(DoublyLinkedList *dll,int index,bool *succ);
void insertIntoDoublyLinkedList(DoublyLinkedList *dll,int index,void *ptr,bool *succ);
void appendToDoublyLinkedList(DoublyLinkedList *target,DoublyLinkedList *source,bool *succ);
void clearDoublyLinkedList(DoublyLinkedList *dll);
DoublyLinkedListIterator getDoublyLinkedList(DoublyLinkedList *dll,bool *succ);
DoublyLinkedListIterator getRevDoublyLinkedList(DoublyLinkedList *dll,bool *succ);
bool hasNextInDoublyLinkedList(DoublyLinkedListIterator *iter);
bool hasPreviousInDoublyLinkedList(DoublyLinkedListIterator *iter);
void * getNextElementFromDoublyLinkedList(DoublyLinkedListIterator *iter,bool *succ);
void * getPreviousElementFromDoublyLinkedList(DoublyLinkedListIterator *iter,bool *succ);
#endif