#include<stdio.h>
#include<tm_array.h>

int main()
{
int s;
int *ptr;
int succ;
int i,x1,x2,x3;
Array *array;
array=createArray(&succ);
if(array==NULL)
{
printf("Unable to load data\n");
return 0;
}
x1=100;
x2=200;
x3=533;
setElementOfArray(array,3,&x1,&succ);
setElementOfArray(array,53,&x2,&succ);
setElementOfArray(array,356,&x3,&succ);

s=getSizeOfArray(array);
printf("%d\n",s);
for(i=0;i<array->size;i++)
{
ptr=(int *)getElementOfArray(array,i);
if(ptr!=NULL) printf("(%d ---> %d)  ",i,*ptr);
else printf("(%d --->   )",i);

}

return 0;
}