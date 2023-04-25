#ifndef __TM_DLL__C
#define __TM_DLL__C 231
#include<tm_dll.h>
#include<stdlib.h>
DoublyLinkedList * createDoublyLinkedList(bool *succ)
{
if(succ) *succ=false;
DoublyLinkedList *dll;
dll=(DoublyLinkedList *)malloc(sizeof(DoublyLinkedList));
if(dll==NULL) return NULL;
dll->start=NULL;
dll->end=NULL;
dll->size=0;
if(succ) *succ=true;
return dll;
}
void destroyDoublyLinkedList(DoublyLinkedList *dll)
{
if(dll==NULL) return;
clearDoublyLinkedList(dll);
free(dll);
}
int getSizeOfDoublyLinkedList(DoublyLinkedList *dll)
{
if(dll==NULL) return 0;
return dll->size;
}
void addToDoublyLinkedList(DoublyLinkedList *dll,void *ptr,bool *succ)
{
DoublyLinkedListNode *node;
if(succ) *succ=false;
if(dll==NULL)return;
node=(DoublyLinkedListNode *)malloc(sizeof(DoublyLinkedListNode));
if(node==NULL) return;
node->ptr=ptr;
node->previous=NULL;
node->next=NULL;
if(dll->start==NULL)
{
dll->start=node;
dll->end=node;
} else
{
dll->end->next=node;
node->previous=dll->end;
dll->end=node;
}
dll->size++;
if(succ) *succ=true;
}
void *removeFromDoublyLinkedList(DoublyLinkedList *dll,int index,bool *succ)
{
void *ptr;
int x=0;
DoublyLinkedListNode *p1;
if(dll==NULL)return NULL;
if(succ) *succ=false;
if(index<0 || index>dll->size) return NULL;
p1=dll->start;
while(x<index && p1!=NULL)
{
p1=p1->next;
x++;
}
if(p1!=NULL &&x<index)return NULL;
ptr=p1->ptr;
if(dll->start==p1 && dll->end==p1)
{
dll->start==NULL;
dll->end==NULL;
dll->size=0;
free(p1);
if(succ) *succ=true;
dll->size--;
return ptr;
}
if(p1==dll->start)
{
dll->start=dll->start->next;
dll->start->previous=NULL;
if(succ)*succ=true;
free(p1);
dll->size--;
return ptr;
} 
if(p1==NULL)
{
dll->end=dll->end->previous;
dll->end->next=NULL;
} 
else
{
p1->previous->next=p1->next;
p1->next->previous=p1->previous;
}
free(p1);
if(succ)*succ=true;
dll->size--;
return ptr;
}
void *getFromDoublyLinkedList(DoublyLinkedList *dll,int index,bool *succ)
{
int x=0;
DoublyLinkedListNode *node;
if(succ)*succ=false;
if(dll==NULL)return NULL;
node=dll->start;
while(node && x<index)
{
node=node->next;
x++;
}
if(node==NULL && x<index)return NULL;
if(succ) *succ=true;
return node->ptr;
}
void insertIntoDoublyLinkedList(DoublyLinkedList * dll,int index,void * ptr,bool * succ)
{
int x=0;
DoublyLinkedListNode *node,*p1;
if(succ) * succ=false;
if(dll==NULL) return;
if(index<0 || index>dll->size) return;
p1=dll->start;
while(x<index)
{
p1=p1->next;
x++;
}
node=(DoublyLinkedListNode *)malloc(sizeof(DoublyLinkedListNode));
if(node==NULL) return;
node->ptr=ptr;
node->next=NULL;
node->previous=NULL;
if(p1==NULL || index==dll->size)
{
addToDoublyLinkedList(dll,ptr,succ);
return;
}
if(p1==dll->start)
{
node->next=dll->start;
dll->start->previous=node;
dll->start=node;
}else
{
node->next=p1;
node->previous=p1->previous;
p1->previous->next=node;
p1->previous=node;
}
dll->size++;
if(succ) *succ=true;
}
void appendToDoublyLinkedList(DoublyLinkedList *target,DoublyLinkedList *source,bool *succ)
{
bool done;
if(succ)*succ=false;
DoublyLinkedListNode *node,*s,*e,*t;
if(target==NULL) return;
if(source==NULL)
{
if(succ)*succ=true;
return;
}
s=NULL;
e=NULL;
t=source->start;
while(t)
{
node=(DoublyLinkedListNode *)malloc(sizeof(DoublyLinkedListNode));
node->ptr=t->ptr;
node->next;
node->previous;
if(s==NULL)
{
s=node;
e=node;
}else
{
e->next=node;
node->previous=e;
e=node;
}
}
if(target->start==NULL)
{
target->start=s;
target->end=e;
target->size=source->size;
}else
{
target->end->next=s;
s->previous=target->end;
target->end=e;
target->size+=source->size;
}
if(succ)*succ=true;
}
 
void clearDoublyLinkedList(DoublyLinkedList *dll)
{
DoublyLinkedListNode *node;
if(dll==NULL) return;
node=dll->start;
while(dll->start!=NULL)
{
node=dll->start;
dll->start=dll->start->next;
free(node);
}
dll->end=NULL;
dll->size=0;
}
DoublyLinkedListIterator getDoublyLinkedList(DoublyLinkedList *dll,bool * succ)
{
DoublyLinkedListIterator iter;
if(succ)*succ=false;
iter.node=NULL;
if(dll==NULL) return iter;
if(dll->start==NULL) 
{
if(succ)*succ=true;
return iter;
}
if(succ)*succ=true;
iter.node=dll->start;
return iter;
}

DoublyLinkedListIterator getRevDoublyLinkedList(DoublyLinkedList *dll,bool *succ)
{
DoublyLinkedListIterator iter;
if(succ) *succ=false;
iter.node=NULL;
if(dll==NULL) return iter;
if(dll->end==NULL) 
{
if(succ) *succ=true;
return iter;
}
if(succ)*succ=true;
iter.node=dll->end;
return iter;
}
bool hasNextInDoublyLinkedList(DoublyLinkedListIterator *iter)
{
if(iter==NULL) return false;
if(iter->node==NULL) return false;
return true;
}
bool hasPreviousInDoublyLinkedList(DoublyLinkedListIterator *iter)
{
if(iter==NULL)return false;
if(iter->node==NULL) return false;
return true;
}
void * getNextElementFromDoublyLinkedList(DoublyLinkedListIterator *iter,bool *succ)
{
void *ptr=NULL;
if(succ)*succ=false;
if(iter==NULL || iter->node==NULL) return ptr;
ptr=iter->node->ptr;
iter->node=iter->node->next;
if(succ)*succ=true;
return ptr;
}
void * getPreviousElementFromDoublyLinkedList(DoublyLinkedListIterator *iter,bool *succ)
{
void *ptr=NULL;
if(succ)*succ=false;
if(iter==NULL || iter->node==NULL) return ptr;
ptr=iter->node->ptr;
iter->node=iter->node->previous;
if(succ)*succ=true;
return ptr;
}

#endif