#ifndef __TM_AVL_TREE__C
#define __TM_AVL_TREE__C 123
#include<tm_avl_tree.h>
#include<stdlib.h>
#include<stdio.h>
#include<tm_stack.h>
#include<tm_queue.h>
AVLTree *createAVLTree(bool *success,int(*predicate)(void *,void *))
{
int succ;
AVLTree *avlTree;
if(success)*success=false;
avlTree=(AVLTree *)malloc(sizeof(AVLTree));
if(avlTree==NULL)return NULL;
avlTree->start=NULL;
avlTree->predicate=predicate;
avlTree->size=0;
if(success)*success=true;
return avlTree;
}

void insertIntoAVLTree(AVLTree *avlTree,void *ptr,bool *success)
{
int *x;
Stack *stack;
int weight,succ;
AVLTreeNode *t,*j;
if(success)*success=false;
if(avlTree==NULL) return;
if(avlTree->start==NULL)
{
t=(AVLTreeNode *)malloc(sizeof(AVLTreeNode));
if(t==NULL)return;
t->ptr=ptr;
t->left=NULL;
t->right=NULL;
avlTree->start=t;
avlTree->size++;
if(success)*success=true;
return;
}
stack=createStack(&succ);
if(succ==false) return;
j=avlTree->start;
while(1)
{
weight=avlTree->predicate(ptr,j->ptr);
if(weight==0)return;
pushOnStack(stack,j,&succ);
if(succ==false)
{
destroyStack(stack);
return;
}
if(weight<0)
{
if(j->left==NULL)
{
t=(AVLTreeNode *)malloc(sizeof(AVLTreeNode));
if(t==NULL)return;
t->ptr=ptr;
t->left=NULL;
t->right=NULL;
j->left=t;
break;
}
else j=j->left;
}
else
{
if(j->right==NULL)
{
t=(AVLTreeNode *)malloc(sizeof(AVLTreeNode));
if(t==NULL)return;
t->ptr=ptr;
t->left=NULL;
t->right=NULL;
j->right=t;
break;
}
else j=j->right;
}
}
avlTree->size++;
if(success)*success=true;
balanceAVLTree(avlTree,stack);
destroyStack(stack);
}


void balanceAVLTree(AVLTree *avlTree,Stack *stack)
{
int lh,rh,succ,diff;
AVLTreeNode *root,*parent,*rclc,*lcrc,*rc,*lc,**p2p;
while(!isStackEmpty(stack))
{
root=(AVLTreeNode *)popFromStack(stack,&succ);
lh=getHeightOfAVLTree(root->left);
rh=getHeightOfAVLTree(root->right);
diff=lh-rh;
if(diff>=-1 && diff<=1) continue;
if(isStackEmpty(stack)) p2p=&(avlTree->start);
else
{
parent=(AVLTreeNode *)ElementAtTopOfStack(stack,&succ);
if(parent->left==root) p2p=&(parent->left);
else p2p=&(parent->right);
}
if(lh<rh)
{
rc=root->right;
if(getHeightOfAVLTree(rc->left)>getHeightOfAVLTree(rc->right))
{
rclc=rc->left;
rc->left=rclc->right;
rclc->right=rc;
root->right=rclc;
rc=root->right;
}
root->right=rc->left;
rc->left=root;
*p2p=rc;
}
else
{
lc=root->left;
if(getHeightOfAVLTree(lc->right)>getHeightOfAVLTree(lc->left))
{
lcrc=lc->right;
lc->right=lcrc->left;
lcrc->left=lc;
root->left=lcrc;
lc=root->left;
}
root->left=lc->right;
lc->right=root;
*p2p=lc;
}
}
}

int getSizeOfAVLTree(AVLTree *avlTree)
{
if(avlTree==NULL || avlTree->start==NULL)return 0;
return avlTree->size;
}

void *removeFromAVLTree(AVLTree *avlTree,void *ptr,bool *success)
{
void *foundPtr;
int weight,succ;
Stack *stack;
Queue *queue;
AVLTreeNode *t,*j,**p2p,*e,*f,*g;
if(success)*success=false;
if(avlTree==NULL || avlTree->start==NULL) return NULL;
stack=createStack(&succ);
if(succ==false)return NULL;
queue=createQueue(&succ);
if(succ==false) return NULL;
t=avlTree->start;
while(t!=NULL)
{
weight=avlTree->predicate(ptr,t->ptr);
if(weight==0)
{
if(success)*success=true;
foundPtr=t->ptr;
break;
}
pushOnStack(stack,t,&succ);
j=t;
if(weight<0) t=t->left;
else t=t->right;
}
if(t==NULL)
{
destroyStack(stack);
destroyQueue(queue);
free(stack);
return NULL;
}
if(avlTree->start==t) p2p=&(avlTree->start);
else if(j->left==t) p2p=&(j->left);
else p2p=&(j->right);
if(t->left==t->right)
{
*p2p=NULL;
if(success)*success=true;
balanceAVLTree(avlTree,stack);
destroyStack(stack);
destroyQueue(queue);
free(stack);
free(t);
return foundPtr;
}
else
{
if(t->right!=NULL)
{
for(e=t->right;e->left!=NULL;e=e->left)
{
addToQueue(queue,e,&succ);
if(succ==false)
{
destroyQueue(queue);
free(queue);
return NULL;
}
f=e;
}
pushOnStack(stack,e,&succ);
if(t->right==e)
{
e->left=t->left;
}
else
{
f->left=e->right;
e->left=t->left;
e->right=t->right;
}
*p2p=e;
}
else
{
for(e=t->left;e->right!=NULL;e=e->right)f=e;
if(e!=t->left)
{
f->right=e->left;
e->left=t->left;
}
*p2p=e;
}
}
while(!isQueueEmpty(queue))
{
g=removeFromQueue(queue,&succ);
pushOnStack(stack,g,&succ);
}
balanceAVLTree(avlTree,stack);
destroyStack(stack);
free(stack);
destroyQueue(queue);
free(queue);
avlTree->size--;
free(t);
return foundPtr;
}

void *getFromAVLTree(AVLTree *avlTree,void *ptr,bool *success)
{
void *foundPtr;
int weight;
AVLTreeNode *t;
if(success)*success=false;
if(avlTree==NULL || avlTree->start==NULL)return NULL;
t=avlTree->start;
while(t!=NULL)
{
weight=avlTree->predicate(ptr,t->ptr);
if(weight==0) 
{
if(success)*success=true;
foundPtr=t->ptr;
break;
}
if(weight<0) t=t->left;
else t=t->right;
}
if(t==NULL)return NULL;
return foundPtr;
} 

void destroyAVLTree(AVLTree *avlTree)
{
if(avlTree==NULL) return;
clearAVLTree(avlTree);
free(avlTree);
}

int getHeightOfAVLTree(AVLTreeNode *root)
{
int lch,rch;
if(root==NULL)return 0;
lch=getHeightOfAVLTree(root->left);
rch=getHeightOfAVLTree(root->right);
//if(lch>rch)lch+1; else rch+1;
return (lch>rch)?lch+1:rch+1;
}

void clearAVLTree(AVLTree *avlTree)
{
int succ;
AVLTreeInOrderIterator iterator;
void *t;
iterator=getAVLTreeInOrderIterator(avlTree,&succ);
while(hasNextInOrderElementInAVLTree(&iterator))
{
t=getNextInOrderElementFromAVLTree(&iterator,&succ);
free(t);
}
}

AVLTreeInOrderIterator getAVLTreeInOrderIterator(AVLTree *avlTree,bool *success)
{
int succ;
AVLTreeNode *t;
AVLTreeInOrderIterator avlTreeInOrderIterator;
avlTreeInOrderIterator.node=NULL;
avlTreeInOrderIterator.stack=NULL;
if(success)*success=false;
if(avlTree==NULL)return avlTreeInOrderIterator;
if(avlTree->start==NULL)
{
if(success)*success=true;
return avlTreeInOrderIterator;
}
avlTreeInOrderIterator.stack=createStack(&succ);
if(succ==false) return avlTreeInOrderIterator;
t=avlTree->start;
while(t!=NULL)
{
pushOnStack(avlTreeInOrderIterator.stack,t,&succ);
if(succ==false)
{
destroyStack(avlTreeInOrderIterator.stack);
avlTreeInOrderIterator.node=NULL;
avlTreeInOrderIterator.stack=NULL;
return avlTreeInOrderIterator;
}
t=t->left;
}
avlTreeInOrderIterator.node=popFromStack(avlTreeInOrderIterator.stack,&succ);
if(success)*success=true;
return avlTreeInOrderIterator;
}

bool hasNextInOrderElementInAVLTree(AVLTreeInOrderIterator *avlTreeInOrderIterator)
{
if(avlTreeInOrderIterator==NULL || avlTreeInOrderIterator->node==NULL) return false;
else return true;
}

void *getNextInOrderElementFromAVLTree(AVLTreeInOrderIterator *avlTreeInOrderIterator,bool *success)
{
int succ;
AVLTreeNode *t,*j;
if(success)*success=false;
if(avlTreeInOrderIterator==NULL || avlTreeInOrderIterator->node==NULL) return NULL;
j=avlTreeInOrderIterator->node;
t=j->right;
while(t!=NULL)
{
pushOnStack(avlTreeInOrderIterator->stack,t,&succ);
if(succ==false)
{
destroyStack(avlTreeInOrderIterator->stack);
avlTreeInOrderIterator->node=NULL;
avlTreeInOrderIterator->stack=NULL;
return j->ptr;
}
t=t->left;
}
if(isStackEmpty(avlTreeInOrderIterator->stack))
{
destroyStack(avlTreeInOrderIterator->stack);
avlTreeInOrderIterator->stack=NULL;
avlTreeInOrderIterator->node=NULL;
return j->ptr;
}
avlTreeInOrderIterator->node=popFromStack(avlTreeInOrderIterator->stack,&succ);
if(success)*success=true;
return j->ptr;
}

AVLTreePreOrderIterator getAVLTreePreOrderIterator(AVLTree *avlTree,bool *success)
{
int succ;
AVLTreeNode *t;
AVLTreePreOrderIterator avlTreePreOrderIterator;
avlTreePreOrderIterator.node=NULL;
avlTreePreOrderIterator.stack=NULL;
if(success)*success=false;
if(avlTree==NULL)return avlTreePreOrderIterator;
if(avlTree->start==NULL)
{
if(success)*success=true;
return avlTreePreOrderIterator;
}
avlTreePreOrderIterator.stack=createStack(&succ);
if(succ==false) return avlTreePreOrderIterator;
avlTreePreOrderIterator.node=avlTree->start;
if(success)*success=true;
return avlTreePreOrderIterator;
}

bool hasNextPreOrderElementInAVLTree(AVLTreePreOrderIterator *avlTreePreOrderIterator)
{
if(avlTreePreOrderIterator==NULL || avlTreePreOrderIterator->node==NULL)return false;
return true;
}

void *getNextPreOrderElementFromAVLTree(AVLTreePreOrderIterator *avlTreePreOrderIterator,bool *success)
{
int succ;
AVLTreeNode *j;
if(success)*success=false;
if(avlTreePreOrderIterator==NULL || avlTreePreOrderIterator->node==NULL)return NULL;
j=avlTreePreOrderIterator->node;
if(j->right)
{
pushOnStack(avlTreePreOrderIterator->stack,j->right,&succ);
if(succ==false)
{
destroyStack(avlTreePreOrderIterator->stack);
avlTreePreOrderIterator->stack=NULL;
avlTreePreOrderIterator->node=NULL;
if(success)*success=true;
return j->ptr;
}
}
if(j->left)
{
pushOnStack(avlTreePreOrderIterator->stack,j->left,&succ);
if(succ==false)
{
destroyStack(avlTreePreOrderIterator->stack);
avlTreePreOrderIterator->stack=NULL;
avlTreePreOrderIterator->node=NULL;
if(success)*success=true;
return j->ptr;
}
}
if(isStackEmpty(avlTreePreOrderIterator->stack))
{
destroyStack(avlTreePreOrderIterator->stack);
avlTreePreOrderIterator->stack=NULL;
avlTreePreOrderIterator->node=NULL;
}
else
{
avlTreePreOrderIterator->node=popFromStack(avlTreePreOrderIterator->stack,&succ);
}
if(success)*success=true;
return j->ptr;
}

AVLTreePostOrderIterator getAVLTreePostOrderIterator(AVLTree *avlTree,bool *success)
{
int succ;
AVLTreeNode *t;
AVLTreePostOrderIterator avlTreePostOrderIterator;
avlTreePostOrderIterator.node=NULL;
avlTreePostOrderIterator.stack=NULL;
if(success)*success=false;
if(avlTree==NULL) return avlTreePostOrderIterator;
if(avlTree->start==NULL)
{
if(success)*success=true;
return avlTreePostOrderIterator;
}
avlTreePostOrderIterator.stack=createStack(&succ);
if(succ==false)return avlTreePostOrderIterator;
t=avlTree->start;
while(1)
{
while(t!=NULL)
{
if(t->right)
{
pushOnStack(avlTreePostOrderIterator.stack,t->right,&succ);
if(succ==false)
{
destroyStack(avlTreePostOrderIterator.stack);
avlTreePostOrderIterator.node=NULL;
avlTreePostOrderIterator.stack=NULL;
if(success)*success=true;
return avlTreePostOrderIterator;
}
}
pushOnStack(avlTreePostOrderIterator.stack,t,&succ);
if(succ==false)
{
destroyStack(avlTreePostOrderIterator.stack);
avlTreePostOrderIterator.node=NULL;
avlTreePostOrderIterator.stack=NULL;
if(success)*success=true;
return avlTreePostOrderIterator;
}
t=t->left;
}
t=popFromStack(avlTreePostOrderIterator.stack,&succ);
if(!isStackEmpty(avlTreePostOrderIterator.stack) && t->right && t->right==ElementAtTopOfStack(avlTreePostOrderIterator.stack,&succ))
{
popFromStack(avlTreePostOrderIterator.stack,&succ);
pushOnStack(avlTreePostOrderIterator.stack,t,&succ);
if(succ==false)
{
destroyStack(avlTreePostOrderIterator.stack);
avlTreePostOrderIterator.node=NULL;
avlTreePostOrderIterator.stack=NULL;
if(success)*success=true;
return avlTreePostOrderIterator;
}
t=t->right;
}
else break;
}
avlTreePostOrderIterator.node=t;
if(success)*success=true;
return avlTreePostOrderIterator;
}

bool hasNextPostOrderElementInAVLTree(AVLTreePostOrderIterator *avlTreePostOrderIterator)
{
if(avlTreePostOrderIterator==NULL || avlTreePostOrderIterator->node==NULL) return false;
return true;
}

void *getNextPostOrderElementFromAVLTree(AVLTreePostOrderIterator *avlTreePostOrderIterator,bool *success)
{
int succ;
AVLTreeNode *j,*t;
if(success)*success=false;
if(avlTreePostOrderIterator==NULL || avlTreePostOrderIterator->node==NULL) return NULL;
j=avlTreePostOrderIterator->node;
if(isStackEmpty(avlTreePostOrderIterator->stack))
{
destroyStack(avlTreePostOrderIterator->stack);
avlTreePostOrderIterator->node=NULL;
avlTreePostOrderIterator->stack=NULL;
if(success)*success=true;
return j->ptr;
}
t=NULL;
while(1)
{
while(t)
{
if(t->right)
{
pushOnStack(avlTreePostOrderIterator->stack,t->right,&succ);
if(succ==false)
{
destroyStack(avlTreePostOrderIterator->stack);
avlTreePostOrderIterator->node=NULL;
avlTreePostOrderIterator->stack=NULL;
if(success)*success=true;
return j->ptr;
}
}
pushOnStack(avlTreePostOrderIterator->stack,t,&succ);
if(succ==false)
{
destroyStack(avlTreePostOrderIterator->stack);
avlTreePostOrderIterator->node=NULL;
avlTreePostOrderIterator->stack=NULL;
if(success)*success=true;
return j->ptr;
}
t=t->left;
}
t=popFromStack(avlTreePostOrderIterator->stack,&succ);
if(!isStackEmpty(avlTreePostOrderIterator->stack) && t->right && t->right==ElementAtTopOfStack(avlTreePostOrderIterator->stack,&succ))
{
popFromStack(avlTreePostOrderIterator->stack,&succ);
pushOnStack(avlTreePostOrderIterator->stack,t,&succ);
if(succ==false)
{
destroyStack(avlTreePostOrderIterator->stack);
avlTreePostOrderIterator->node=NULL;
avlTreePostOrderIterator->stack=NULL;
if(success)*success=true;
return j->ptr;
}

t=t->right;
}
else break;
}
if(success)*success=true;
avlTreePostOrderIterator->node=t;
return j->ptr;
}

AVLTreeLevelOrderIterator getAVLTreeLevelOrderIterator(AVLTree *avlTree,bool *success)
{
AVLTreeNode *t;
int succ;
AVLTreeLevelOrderIterator avlTreeLevelOrderIterator;
if(success)*success=false;
avlTreeLevelOrderIterator.node=NULL;
avlTreeLevelOrderIterator.queue=NULL;
if(avlTree==NULL)return avlTreeLevelOrderIterator;
if(avlTree->start==NULL)
{
if(success)*success=true;
return avlTreeLevelOrderIterator;
}
avlTreeLevelOrderIterator.queue=createQueue(&succ);
if(succ==false) return avlTreeLevelOrderIterator;
t=avlTree->start;
addToQueue(avlTreeLevelOrderIterator.queue,t,&succ);
if(succ==false)
{
destroyQueue(avlTreeLevelOrderIterator.queue);
avlTreeLevelOrderIterator.node=NULL;
avlTreeLevelOrderIterator.queue=NULL;
if(success)*success=true;
return avlTreeLevelOrderIterator;
}
if(t->left)
{
addToQueue(avlTreeLevelOrderIterator.queue,t->left,&succ);
if(succ==false)
{
destroyQueue(avlTreeLevelOrderIterator.queue);
avlTreeLevelOrderIterator.node=NULL;
avlTreeLevelOrderIterator.queue=NULL;
if(success)*success=true;
return avlTreeLevelOrderIterator;
}
}
if(t->right)
{
addToQueue(avlTreeLevelOrderIterator.queue,t->right,&succ);
if(succ==false)
{
destroyQueue(avlTreeLevelOrderIterator.queue);
avlTreeLevelOrderIterator.node=NULL;
avlTreeLevelOrderIterator.queue=NULL;
if(success)*success=true;
return avlTreeLevelOrderIterator;
}
}
avlTreeLevelOrderIterator.node=removeFromQueue(avlTreeLevelOrderIterator.queue,&succ);
if(success)*success=true;
return avlTreeLevelOrderIterator;
}
 
bool hasNextLevelOrderElementInAVLTree(AVLTreeLevelOrderIterator *avlTreeLevelOrderIterator)
{
if(avlTreeLevelOrderIterator==NULL) return false;
if(avlTreeLevelOrderIterator->node==NULL) return false;
return true;
}

void *getNextLevelOrderElementFromAVLTree(AVLTreeLevelOrderIterator *avlTreeLevelOrderIterator,bool *success)
{
AVLTreeNode *t,*j;
int succ;
if(success)*success=false;
if(avlTreeLevelOrderIterator==NULL || avlTreeLevelOrderIterator->node==NULL) return NULL;
j=avlTreeLevelOrderIterator->node;
if(isQueueEmpty(avlTreeLevelOrderIterator->queue))
{
destroyQueue(avlTreeLevelOrderIterator->queue);
avlTreeLevelOrderIterator->node=NULL;
avlTreeLevelOrderIterator->queue=NULL;
if(success)*success=true;
return j->ptr;
}
t=(AVLTreeNode *)removeFromQueue(avlTreeLevelOrderIterator->queue,&succ);
if(t->left)
{
addToQueue(avlTreeLevelOrderIterator->queue,t->left,&succ);
if(succ==false)
{
destroyQueue(avlTreeLevelOrderIterator->queue);
avlTreeLevelOrderIterator->node=NULL;
avlTreeLevelOrderIterator->queue=NULL;
if(success)*success=true;
return j->ptr;
}
}
if(t->right)
{
addToQueue(avlTreeLevelOrderIterator->queue,t->right,&succ);
if(succ==false)
{
destroyQueue(avlTreeLevelOrderIterator->queue);
avlTreeLevelOrderIterator->node=NULL;
avlTreeLevelOrderIterator->queue=NULL;
if(success)*success=true;
return j->ptr;
}
}
avlTreeLevelOrderIterator->node=t;
if(success)*success=true;
return j->ptr;
}

#endif