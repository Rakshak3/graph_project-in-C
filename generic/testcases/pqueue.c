#include<stdio.h>
#include<stdlib.h>
#include<tm_pqueue.h>
int comparator(void *left,void *right)
{
int *leftSide=(int *)left;
int *rightSide=(int *)right;
return *leftSide-*rightSide;
}
int main()
{
int succ;
PQueue *pqueue;
int *ptr,i;
int x1,x2,x3,x4,x5,x6;
x1=100;
x2=32;
x3=34;
x4=2;
x5=64;
x6=23;
pqueue=createPQueue(comparator,&succ);
addToPQueue(pqueue,&x1,&succ);
addToPQueue(pqueue,&x2,&succ);
addToPQueue(pqueue,&x3,&succ);
addToPQueue(pqueue,&x4,&succ);
addToPQueue(pqueue,&x5,&succ);
addToPQueue(pqueue,&x6,&succ);
i=getSizeOfPQueue(pqueue);
printf("Size of PQueue is : %d\n",i);
i=0;
while(i<getSizeOfPQueue(pqueue))
{
ptr=(int *)getElementFromPQueue(pqueue,i,&succ);
printf("%d\n",*ptr);
i++;
}

return 0;
}