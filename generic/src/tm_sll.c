#ifndef __TM_SLL__C
#define __TM_SLL__C 123
#include<tm_sll.h>
#include<stdlib.h>
#include<stdio.h>
SinglyLinkedList *createSinglyLinkedList(bool *success)
{
SinglyLinkedList *singlyLinkedList;
if(success)*success=false;
singlyLinkedList=(SinglyLinkedList *)malloc(sizeof(SinglyLinkedList));
if(singlyLinkedList==NULL) return NULL;
singlyLinkedList->start=NULL;
singlyLinkedList->end=NULL;
singlyLinkedList->size=0;
if(success)*success=true;
return singlyLinkedList;
}
void addToSinglyLinkedList(SinglyLinkedList * sll,void * ptr,bool *success)
{
SinglyLinkedListNode *node;
if(success)*success=false;
if(sll==NULL) return;
node=(SinglyLinkedListNode *)malloc(sizeof(SinglyLinkedListNode));
if(node==NULL)return;
node->ptr=ptr;
node->next=NULL;
if(sll->start==NULL)
{
sll->start=node;
sll->end=node;
}
else
{
sll->end->next=node;
sll->end=node;
}
sll->size++;
if(success)*success=true;
}
void clearSinglyLinkedList(SinglyLinkedList *sll)
{
SinglyLinkedListNode *node;
if(sll==NULL || sll->start==NULL)return;
node=sll->start;
while(sll->start!=NULL)
{
node=sll->start;
sll->start=sll->start->next;
free(node);
}
sll->size=0;
sll->end=NULL;
}
int getSizeOfSinglyLinkedList(SinglyLinkedList *sll)
{
if(sll==NULL || sll->start==NULL || sll->size==0) return 0;
return sll->size;
}
void *getFromSinglyLinkedList(SinglyLinkedList *sll,int index,bool *success)
{
int y;
SinglyLinkedListNode *node;
if(success)*success=false;
if(sll==NULL || sll->start==NULL) return NULL;
if(index<0 || index>getSizeOfSinglyLinkedList(sll)) return NULL;
node=sll->start;
for(y=0;y<index;y++)
{
node=node->next;
}
if(success)*success=true;
return node->ptr;
}
void * removeFromSinglyLinkedList(SinglyLinkedList *sll,int index,bool *success)
{
void *ptr;
int x=0;
SinglyLinkedListNode *p1,*p2;
if(success)*success=false;
if(index<0 || index>sll->size)return NULL;
if(sll==NULL || sll->start==NULL)return NULL;

p1=sll->start;
while(p1 && x<index)
{
p2=p1;
p1=p1->next;
x++;
}
ptr=p1->ptr;
if(index==0)
{
sll->start=sll->start->next;
free(p1);
sll->size--;
if(success)*success=true;
return ptr;
}
if(p1==sll->end)
{
sll->end=p2;
p2->next==NULL;
free(p1);
sll->size--;
if(success)*success=true;
return ptr;
}
p2->next=p1->next;
free(p1);
if(success)*success=true;
sll->size--;
return ptr;
}

void InsertIntoSinglyLinkedList(SinglyLinkedList *sll,int index,void *ptr,bool *success)
{
int x=0;
SinglyLinkedListNode *t,*p1,*p2;
if(success)*success=false;
if(sll==NULL)return;
if(index<0 || index>sll->size)return;
t=(SinglyLinkedListNode *)malloc(sizeof(SinglyLinkedListNode));
if(t==NULL)return;
t->ptr=ptr;
t->next=NULL;
if(index==0)
{
t->next=sll->start;
sll->start=t;
sll->size++;
if(success)*success=true;
return;
}
else if(index==sll->size)
{
addToSinglyLinkedList(sll,ptr,success);
return;
}
p1=sll->start;
while(p1 && x<index)
{
p2=p1;
p1=p1->next;
x++;
}
t->next=p1;
p2->next=t;
sll->size++;
if(success)*success=true;
}
void appendToSinglyLinkedList(SinglyLinkedList *target,SinglyLinkedList *source,bool *success)
{
int done;
SinglyLinkedListNode *t,*s,*e,*node;
if(success)*success=false;
if(target==NULL)return;
if(source==NULL || source->start==NULL)
{
if(success)*success=true;
return;
}
s=NULL;
e=NULL;
done=true;
t=source->start;
while(t!=NULL)
{
node=(SinglyLinkedListNode *)malloc(sizeof(SinglyLinkedListNode));
if(node==NULL)
{
done=false;
break;
}
node->ptr=t->ptr;
node->next=NULL;
if(s==NULL)
{
s=node;
e=node;
}
else
{
e->next=node;
e=node;
}
t=t->next;
}
if(done=false)
{
while(s!=NULL)
{
node=s;
s=s->next;
free(node);
}
}
if(target->start==NULL)
{
target->start=s;
target->end=e;
target->size=source->size;
}
else
{
target->end->next=s;
target->end=e;
target->size+=source->size;
}
if(success)*success=true;
}
void destroySinglyLinkedList(SinglyLinkedList *sll)
{
if(sll==NULL)return;
clearSinglyLinkedList(sll);
}
SinglyLinkedListIterator getSinglyLinkedListIterator(SinglyLinkedList *sll,bool *success)
{
SinglyLinkedListIterator iterator;
iterator.node=NULL;
if(sll==NULL)return iterator;
if(sll->start==NULL)
{
if(success)*success=true;
return iterator;
}
iterator.node=sll->start;
return iterator;
}
bool hasNextInSinglyLinkedList(SinglyLinkedListIterator *iterator)
{
if(iterator==NULL || iterator->node==NULL) return false;
return true;
}
void *getNextElementFromSinglyLinkedList(SinglyLinkedListIterator *iterator,bool *success)
{
void *ptr=NULL;
if(success)*success=false;
if(iterator==NULL || iterator->node==NULL) return ptr;
ptr=iterator->node->ptr;
iterator->node=iterator->node->next;
if(success)*success=true;
return ptr;
}
#endif