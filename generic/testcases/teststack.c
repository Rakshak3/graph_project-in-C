#include<stdio.h>
#include<stdlib.h>
#include<tm_sll.h>
#include<tm_stack.h>
int main()
{
int t;
bool succ,num;
Stack *stack;
int *x;
int z,x1,x2,x3,x4,x5,x6,y;
stack=createStack(&succ);
if(succ==false)
{
printf("Unable to create stack\n");
return 0;
}
x1=100;
x2=200;
x3=300;
x4=400;
x5=500;
pushOnStack(stack,(void *)&x1,&succ);
if(succ) printf("%d added\n",x1);
else printf("%d not added\n",x1);

pushOnStack(stack,(void *)&x2,&succ);
if(succ) printf("%d added\n",x2);
else printf("%d not added\n",x2);

pushOnStack(stack,(void *)&x3,&succ);
if(succ) printf("%d added\n",x3);
else printf("%d not added\n",x3);

pushOnStack(stack,(void *)&x4,&succ);
if(succ) printf("%d added\n",x4);
else printf("%d not added\n",x4);

num=isStackEmpty(stack);
if(num==false) printf("Stack is not empty\n");
else printf("Stack is empty\n");

z=getSizeOfStack(stack);
printf("Size of Stack is %d\n",z);

pushOnStack(stack,(void *)&x5,&succ);
if(succ) printf("%d added\n",x5);
else printf("%d not added\n",x5);

for(y=0;y<getSizeOfStack(stack);y++)
{
x=(int *)getFromSinglyLinkedList(stack->sll,y,&succ);
printf("%d\n",*x);
}


t=isStackEmpty(stack);
if(t) printf("Stack is empty\n");
else printf("Stack is not empty\n");

z=getSizeOfStack(stack);
printf("Size of stack is %d\n",z);

x=(int *)popFromStack(stack,&succ);
if(succ) printf("%d popped\n",*x);

z=getSizeOfStack(stack);
printf("Size of Stack is %d\n",z);

x=(int *)popFromStack(stack,&succ);
if(succ) printf("%d popped\n",*x);

x=(int *)popFromStack(stack,&succ);
if(succ) printf("%d popped\n",*x);

x=(int *)popFromStack(stack,&succ);
if(succ) printf("%d popped\n",*x);

x=(int *)popFromStack(stack,&succ);
if(succ) printf("%d popped\n",*x);

//destroyStack(stack);

t=isStackEmpty(stack);
if(t) printf("Stack is empty\n");
else printf("Stack is not empty\n"); 


return 0;
}