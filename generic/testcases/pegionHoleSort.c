#include<stdio.h>
#include<stdlib.h>
#include<tm_stack.h>
int main()
{
Stack **stack;
int y,req,j,max,min,range,k,i;
int *x,*d;
printf("Enter requirements : ");
scanf("%d",&req);
fflush(stdin);
x=(int *)malloc(sizeof(int)*req);
for(i=0;i<req;i++)
{
printf("Enter a number : ");
scanf("%d",&x[i]);
fflush(stdin);
}
max=x[0];
min=x[0];
for(i=1;i<req;i++)
{
if(x[i]>max)max=x[i];
if(x[i]<min)min=x[i];
}
range=max-min;
printf("%d\n",range);
stack=(Stack **)malloc(sizeof(Stack *)*(range));
for(i=0;i<req;i++)
{
j=x[i]-min;
if(stack[j]==NULL)stack[j]=createStack(&k);
printf("*****************\n");
pushOnStack(stack[j],&x[i],&k);
printf("**#########*\n");
}
j=0;
for(i=0;i<range;i++)
{
while(!isStackEmpty(stack[i]))
{
d=popFromStack(stack[i],&k);
x[j]=*d;
j++;
}
}
for(i=0;i<range;i++)
{
clearStack(stack[i]);
}
for(i=0;i<req;i++)printf("%d\n",x[i]);
return 0;
}