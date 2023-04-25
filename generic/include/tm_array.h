#ifndef __TM__ARRAY__H
#define __TM__ARRAY__H 123
#include<tm_common.h>

typedef struct __array
{
int rows;
int size;
void ***x;
}Array;

Array *createArray(int *success);
void setElementOfArray(Array *array,int index,void *element,int *success);
void *getElementOfArray(Array *array,int index);
int getSizeOfArray(Array *array);
void destroyArray(Array *array);
#endif