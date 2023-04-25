#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<tm_avl_tree.h>

int myComparator(void *p,void *q)
{
int *a,*b;
a=(int *)p;
b=(int *)q;
return *a-*b;
}

int main()
{
AVLTree *tree;
int *x,num,ch,succ;
AVLTreeInOrderIterator iterator;
tree=createAVLTree(&succ,myComparator);
while(1)
{
printf("ADD\n");
printf("REMOVE\n");
printf("Display\n");
printf("break\n");
printf("Enter your choice : ");
scanf("%d",&ch);
fflush(stdin);
if(ch==1)
{
printf("Enter number : ");
scanf("%d",&num);
fflush(stdin);
insertIntoAVLTree(tree,&num,&succ);
printf("Number added\n");
}
if(ch==2)
{
printf("Enter number to delete : ");
scanf("%d",&num);
fflush(stdin);
removeFromAVLTree(tree,&num,&succ);
printf("Number deleted\n");

}
if(ch==3)
{
iterator=getAVLTreeInOrderIterator(tree,&succ);
if(succ)
{
while(hasNextInOrderElementInAVLTree(&iterator))
{
x=(int *)getNextInOrderElementFromAVLTree(&iterator,&succ);
printf("%d\n",*x);
}
}
}
if(ch==4)break;

}

destroyAVLTree(tree);
return 0;
}