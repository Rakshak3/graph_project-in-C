#ifndef __TM_ARRAY__C
#define __TM_ARRAY__C 123
#include<tm_array.h>
#include<stdio.h>
#include<stdlib.h>
Array *createArray(int *success)
{
Array *array;
if(success)*success=false;
array=(Array *)malloc(sizeof(Array));
if(array==NULL)return NULL;
array->x=NULL;
array->size=0;
array->rows=0;
if(success)*success=true;
return array;
}


void setElementOfArray(Array *array,int index,void *element,int *success)
{
void ***tmp;
int i,rowIndex;
int columnIndex;
rowIndex=index/10;
columnIndex=index%10;
if(rowIndex>=array->rows)
{
if(array->x!=NULL)
{
tmp=(void ***)calloc(rowIndex+1,sizeof(void **));
if(tmp==NULL)return;
for(i=0;i<=array->rows-1;i++)
{
tmp[i]=array->x[i];
}
free(array->x);
array->x=tmp;
array->rows=rowIndex+1;
}
else
{
array->x=(void ***)calloc(rowIndex+1,sizeof(void **));
if(array->x==NULL)return;
array->rows=rowIndex+1;
}
}
if(array->x[rowIndex]==NULL)
{
array->x[rowIndex]=(void **)calloc(10,sizeof(void *));
if(array->x[rowIndex]==NULL)return;
}
array->x[rowIndex][columnIndex]=element;
if(index>=array->size) array->size=index+1;
if(success)*success=true;
}


void *getElementOfArray(Array *array,int index)
{
int rowIndex,columnIndex;;
if(array->x==NULL)return NULL;
rowIndex=index/10;
if(rowIndex>=array->rows)return NULL;
if(array->x[rowIndex]==NULL)return NULL;
columnIndex=index%10;
return array->x[rowIndex][columnIndex];
}


int getSizeOfArray(Array *array)
{
return array->size;
}

void destroyArray(Array *array)
{
int i;
if(array==NULL)return;
if(array->x==NULL)
{
free(array);
return;
}
for(i=0;i<getSizeOfArray(array);i++);
{
if(array->x[i]!=NULL)free(array->x[i]);
}
free(array->x);
free(array);
}

#endif
