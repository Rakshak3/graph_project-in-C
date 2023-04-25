#include<stdio.h>
#include<stdlib.h>
#include<tm_heap.h>
#include<tm_array.h>

int myComparator(void *left,void *right)
{
int *a,*b;
a=(int *)left;
b=(int *)right;
return *a-*b;
}

int main()
{
int succ;
int *ptr;
int x1,x2,x3,x4,x5,x6,x7,x8,x9,x10,x11,x12,x13;
int size;
Heap *heap;
heap=createHeap(myComparator,&succ);
x1=100;
x2=43;
x3=23;
x4=71;
x5=42;
x6=31;
x7=15;
x8=6;
x9=66;
x10=74;
x11=12;
x12=33;
x13=41;
addToHeap(heap,&x1,&succ);
addToHeap(heap,&x2,&succ);
addToHeap(heap,&x3,&succ);
addToHeap(heap,&x4,&succ);
addToHeap(heap,&x5,&succ);
addToHeap(heap,&x6,&succ);
addToHeap(heap,&x7,&succ);
addToHeap(heap,&x8,&succ);
addToHeap(heap,&x9,&succ);
addToHeap(heap,&x10,&succ);
addToHeap(heap,&x11,&succ);
addToHeap(heap,&x12,&succ);
addToHeap(heap,&x13,&succ);
size=getSizeOfHeap(heap);
printf("%d\n",size);
ptr=(int *)elementAtTopOfHeap(heap,&succ);
printf("%d\n",*ptr);

ptr=removeFromHeap(heap,&succ);
if(ptr==NULL)printf("NULL\n");
else printf("%d removed\n",*ptr);
ptr=removeFromHeap(heap,&succ);
if(ptr==NULL)printf("NULL\n");
else printf("%d removed\n",*ptr);
ptr=removeFromHeap(heap,&succ);
if(ptr==NULL)printf("NULL\n");
else printf("%d removed\n",*ptr);
ptr=removeFromHeap(heap,&succ);
printf("********\n");
if(ptr==NULL)printf("NULL\n");
else printf("%d removed\n",*ptr);

ptr=removeFromHeap(heap,&succ);
if(ptr==NULL)printf("NULL\n");
else printf("%d removed\n",*ptr);



return 0;
}