#include<stdio.h>
#include<tm_avl_tree.h>
#include<stdlib.h>

int comparer(void *left,void *right)
{
int *leftInt,*rightInt;
leftInt=(int *)left;
rightInt=(int *)right;
return (*leftInt)-(*rightInt);
}

int main()
{
bool success;
int *x,t;
int ch,num;
AVLTree *tree;
AVLTreeInOrderIterator inOrderIterator;
AVLTreePreOrderIterator preOrderIterator;
AVLTreePostOrderIterator postOrderIterator;
AVLTreeLevelOrderIterator levelOrderIterator;
tree=createAVLTree(&success,comparer);
if(success==false)
{
printf("Unable to create tree\n");
return 0;
}
while(1)
{
printf("1. Insert\n");
printf("2. In Order Traversal\n");
printf("3. Pre Order Traversal\n"); 
printf("4. Remove\n");
printf("5. Search\n");
printf("6. Size of Tree\n");
printf("7. Post Order Traversal\n");
printf("8. Level Order Traversal\n");
printf("9. Height of Tree\n");
printf("10. Exit\n");
printf("Enter your choice : ");
scanf("%d",&ch);
fflush(stdin);
if(ch==1)
{
printf("Enter a number to insert : ");
scanf("%d",&num);
fflush(stdin);
x=(int *)malloc(sizeof(int));
*x=num;
insertIntoAVLTree(tree,x,&success);
if(success)
{
printf("%d successfully inserted\n",*x);
}
else 
{
printf("Unable to insert\n");
}
}

if(ch==2)
{
inOrderIterator=getAVLTreeInOrderIterator(tree,&success);
if(success)
{
while(hasNextInOrderElementInAVLTree(&inOrderIterator))
{
x=(int *)getNextInOrderElementFromAVLTree(&inOrderIterator,&success);
printf("%d\n",*x);
}
}
}

if(ch==3)
{
preOrderIterator=getAVLTreePreOrderIterator(tree,&success);
if(success)
{
while(hasNextPreOrderElementInAVLTree(&preOrderIterator))
{
x=(int *)getNextPreOrderElementFromAVLTree(&preOrderIterator,&success);
printf("%d\n",*x);
}
}
}
if(ch==4)
{
printf("Enter a number to remove : ");
scanf("%d",&num);
fflush(stdin);
x=removeFromAVLTree(tree,&num,&success);
if(success)printf("%d successfully removed\n",*x);
else printf("unable to remove\n");
}
if(ch==5)
{
printf("Enter a number to search : ");
scanf("%d",&num);
fflush(stdin);
x=getFromAVLTree(tree,&num,&success);
if(success) printf("%d found\n",*x);
else printf("%d not found\n",num);
}
if(ch==6)
{
t=getSizeOfAVLTree(tree);
printf("Size of the tree is %d\n",t);
}
if(ch==7)
{
postOrderIterator=getAVLTreePostOrderIterator(tree,&success);
if(success)
{
while(hasNextPostOrderElementInAVLTree(&postOrderIterator))
{
x=(int *)getNextPostOrderElementFromAVLTree(&postOrderIterator,&success);
printf("%d\n",*x);
}
}
}

if(ch==8)
{
levelOrderIterator=getAVLTreeLevelOrderIterator(tree,&success);
if(success)
{
while(hasNextLevelOrderElementInAVLTree(&levelOrderIterator))
{
x=(int *)getNextLevelOrderElementFromAVLTree(&levelOrderIterator,&success);
printf("%d\n",*x);
}
} else printf("NULL\n");
}

if(ch==9)
{
t=getHeightOfAVLTree(tree->start);
printf("Height of Tree is %d\n",t);
}
if(ch==10) break;
}
destroyAVLTree(tree);
return 0;
}