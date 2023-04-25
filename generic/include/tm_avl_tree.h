#ifndef __TM_AVL_TREE__H
#define __TM_AVL_TREE__H 123
#include<tm_common.h>
#include<tm_stack.h>
#include<tm_queue.h>
typedef struct avl_tree_node
{
void *ptr;
struct avl_tree_node *left,*right;
}AVLTreeNode;
 
typedef struct __$_tm_avl_tree
{
struct avl_tree_node *start;
int (*predicate)(void *,void *);
int size;
}AVLTree;

typedef struct __$_tm_avl_tree_in_order_iterator
{
AVLTreeNode *node;
Stack *stack;
}AVLTreeInOrderIterator;

typedef struct __$_tm_avl_tree_pre_order_iterator
{
AVLTreeNode *node;
Stack *stack;
}AVLTreePreOrderIterator;

typedef struct __$_tm_avl_tree_post_order_iterator
{
AVLTreeNode *node;
Stack *stack;
}AVLTreePostOrderIterator;

typedef struct __$_tm_avl_tree_level_order_iterator
{
AVLTreeNode *node;
Queue *queue;
}AVLTreeLevelOrderIterator;


AVLTree *createAVLTree(bool *success,int(*predicate)(void *,void *));
void insertIntoAVLTree(AVLTree *avlTree,void *ptr,bool *success);
int getSizeOfAVLTree(AVLTree *avlTree);
void *removeFromAVLTree(AVLTree *avlTree,void *ptr,bool *success);
void *getFromAVLTree(AVLTree *avlTree,void *ptr,bool *success);
void destroyAVLTree(AVLTree *avlTree);
void clearAVLTree(AVLTree *avlTree);
int getHeightOfAVLTree(AVLTreeNode *root);
void balanceAVLTree(AVLTree *AvlTree,Stack *stack);

AVLTreeInOrderIterator getAVLTreeInOrderIterator(AVLTree *avlTree,bool *success);
bool hasNextInOrderElementInAVLTree(AVLTreeInOrderIterator *avlTreeInOrderIterator);
void *getNextInOrderElementFromAVLTree(AVLTreeInOrderIterator *avlTreeInOrderIterator,bool *success);

AVLTreePreOrderIterator getAVLTreePreOrderIterator(AVLTree *avlTree,bool *success);
bool hasNextPreOrderElementInAVLTree(AVLTreePreOrderIterator *avlTreePreOrderIterator);
void *getNextPreOrderElementFromAVLTree(AVLTreePreOrderIterator *avlTreePreOrderIterator,bool *success);

AVLTreePostOrderIterator getAVLTreePostOrderIterator(AVLTree *avlTree,bool *success);
bool hasNextPostOrderElementInAVLTree(AVLTreePostOrderIterator *avlTreePostOrderIterator);
void *getNextPostOrderElementFromAVLTree(AVLTreePostOrderIterator *avlTreePostOrderIterator,bool *success);

AVLTreeLevelOrderIterator getAVLTreeLevelOrderIterator(AVLTree *avlTree,bool *success);
bool hasNextLevelOrderElementInAVLTree(AVLTreeLevelOrderIterator *avlTreeLevelOrderIterator);
void *getNextLevelOrderElementFromAVLTree(AVLTreeLevelOrderIterator *avlTreeLevelOrderIterator,bool *success);


#endif