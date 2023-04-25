#include<stdio.h>
#include<stdlib.h>
#include<tm_sll.h>
#include<tm_queue.h>
int main()
{
bool succ,num;
Queue *queue;
int *x;
int z,x1,x2,x3,x4,x5,x6,y;
queue=createQueue(&succ);
if(succ==false)
{
printf("Unable to create queue\n");
return 0;
}
x1=100;
x2=200;
x3=300;
x4=400;
x5=500;
addToQueue(queue,(void *)&x1,&succ);
if(succ) printf("%d added\n",x1);
else printf("%d not added\n",x1);

addToQueue(queue,(void *)&x2,&succ);
if(succ) printf("%d added\n",x2);
else printf("%d not added\n",x2);

addToQueue(queue,(void *)&x3,&succ);
if(succ) printf("%d added\n",x3);
else printf("%d not added\n",x3);

addToQueue(queue,(void *)&x4,&succ);
if(succ) printf("%d added\n",x4);
else printf("%d not added\n",x4);

num=isQueueEmpty(queue);
if(num==false) printf("Queue is not empty\n");
else printf("Queue is empty\n");

z=getSizeOfQueue(queue);
printf("Size of Queue is %d\n",z);

addToQueue(queue,(void *)&x5,&succ);
if(succ) printf("%d added\n",x5);
else printf("%d not added\n",x5);

z=getSizeOfQueue(queue);
printf("Size of queue is %d\n",z);

for(y=0;y<getSizeOfQueue(queue);y++)
{
x=(int *)getFromSinglyLinkedList(queue->sll,y,&succ);
printf("%d\n",*x);
}

x=(int *)ElementAtTopOfQueue(queue,&succ);
printf("Element at top is %d\n",*x);

x=(int *)getElementFromQueue(queue,2,&succ);
printf("Element at 2 is %d\n",*x);

x=(int *)getElementFromQueue(queue,3,&succ);
printf("Element at 3 is %d\n",*x);

x=(int *)getElementFromQueue(queue,1,&succ);
printf("Element at 1 is %d\n",*x);

x=(int *)removeFromQueue(queue,&succ);
if(succ) printf("%d popped\n",*x);

z=getSizeOfQueue(queue);
printf("Size of Queue is %d\n",z);

for(y=0;y<getSizeOfQueue(queue);y++)
{
x=(int *)getFromSinglyLinkedList(queue->sll,y,&succ);
printf("%d\n",*x);
}

x=(int *)ElementAtTopOfQueue(queue,&succ);
printf("Element at top is %d\n",*x);

return 0;
}