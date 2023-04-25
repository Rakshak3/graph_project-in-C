#ifndef __TM_HEAP__C
#define __TM_HEAP__C 123
#include<stdlib.h>
#include<tm_heap.h>
#include<tm_array.h>
#include<stdio.h>

Heap *createHeap(int (*comparator)(void *,void *),int *success)
{
int succ;
Heap *heap;
if(success)*success=false;
heap=(Heap *)malloc(sizeof(Heap));
if(heap==NULL)return heap;
heap->array=createArray(&succ);
if(!succ)return heap;
heap->size=0;
heap->comparator=comparator;
if(success)*success=true;
return heap;
}


void addToHeap(Heap *heap,void *element,int *success)
{
int succ;
void *ciValue,*riValue;
int ci,ri;

if(success)*success=false;
if(heap==NULL)return;
setElementOfArray(heap->array,heap->size,element,success);
if(!succ)return;
heap->size++;
ci=heap->size-1;
while(ci>0)
{
ri=(ci-1)/2;
ciValue=getElementOfArray(heap->array,ci);
riValue=getElementOfArray(heap->array,ri);
if(heap->comparator(ciValue,riValue)<0)
{
setElementOfArray(heap->array,ci,riValue,&succ);
setElementOfArray(heap->array,ri,ciValue,&succ);
ci=ri;
}
else break;
}
if(success)*success=true;
}

void *removeFromHeap(Heap *heap,int *success)
{
void *element,*lastElement;
int succ,ri,swi,lci,rci,upperBound;
void *riValue,*swiValue;
if(success)*success=false;
if(heap==NULL || heap->size==0)return element;
element=getElementOfArray(heap->array,0);
lastElement=getElementOfArray(heap->array,heap->size-1);
setElementOfArray(heap->array,0,lastElement,&succ);
heap->size--;
upperBound=heap->size-1;
ri=0;
while(ri<0)
{
lci=ri*2+1;
if(lci>upperBound)break;
rci=lci+1;
if(rci>upperBound)swi=lci;
if(heap->comparator(getElementOfArray(heap->array,lci),getElementOfArray(heap->array,rci))<0)swi=lci;
else swi=rci;
riValue=getElementOfArray(heap->array,ri);
swiValue=getElementOfArray(heap->array,swi);
if(heap->comparator(riValue,swiValue)>0)
{
setElementOfArray(heap->array,ri,swiValue,&succ);
setElementOfArray(heap->array,swi,riValue,&succ);
ri=swi;
}
else break;
}
if(success)*success=true;
return element;
}

void *elementAtTopOfHeap(Heap *heap,int *success)
{
void *ptr;
if(success)*success=false;
if(heap->size==0)return NULL;
if(heap->array->x[0]==NULL)return NULL;
ptr=(int *)getElementOfArray(heap->array,0);
if(success)*success=true;
return ptr;
}

int getSizeOfHeap(Heap *heap)
{
return heap->size;
}

void *getElementFromHeap(Heap *heap,int index,int *success)
{
void *element=NULL;
if(success)*success=false;
if(index<0 || index>=heap->size)return element;
element=getElementOfArray(heap->array,index);
if(success)*success=true;
return element;
}
void updateElementInHeap(Heap *heap,int index,void *element,int *success)
{
int ci,ri,swi,lci,rci,goDown,upperBound,succ;
void *riValue,*ciValue,*swiValue;
if(success)*success=false;
if(heap==NULL)return;
if(index<0 || index>=heap->size)return;
setElementOfArray(heap->array,index,element,&succ);
if(index==0)goDown=true;
else if(index==heap->size-1) goDown=false;
else 
{
ci=index;
ri=(ci-1)/2;
ciValue=getElementOfArray(heap->array,ci);
riValue=getElementOfArray(heap->array,ri);
if(heap->comparator(riValue,ciValue)>0)goDown=false;
else goDown=true;
}
if(goDown)
{
upperBound=heap->size-1;
ri=index;
while(ri<upperBound)
{
lci=ri*2+1;
if(lci>upperBound)break;
rci=lci+1;
if(rci>upperBound)swi=lci;
if(heap->comparator(getElementOfArray(heap->array,lci),getElementOfArray(heap->array,rci))<0)swi=lci;
else swi=rci;
riValue=getElementOfArray(heap->array,ri);
swiValue=getElementOfArray(heap->array,swi);
if(heap->comparator(riValue,swiValue)>0)
{
setElementOfArray(heap->array,ri,swiValue,&succ);
setElementOfArray(heap->array,swi,riValue,&succ);
ri=swi;
}
else break;
}
}
else 
{
ci=index;
while(ci>0)
{
ri=(ci-1)/2;
ciValue=getElementOfArray(heap->array,ci);
riValue=getElementOfArray(heap->array,ri);
if(heap->comparator(riValue,ciValue)>0)
{
setElementOfArray(heap->array,ci,riValue,&succ);
setElementOfArray(heap->array,ri,ciValue,&succ);
ci=ri;
}
else break;
}
}
if(success)*success=true;
}

void destroyHeap(Heap *heap)
{
if(heap==NULL)
destroyArray(heap->array);
free(heap);
}

#endif