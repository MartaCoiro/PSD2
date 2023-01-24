#include "item.h"

typedef struct node *BTree;

BTree newTree();
int isEmptyTree(BTree);
BTree buildTree(BTree, BTree, Item);
Item getBTreeRoot(BTree);
BTree getLeft(BTree);
BTree getRight(BTree);
void preOrder(BTree);
void postOrder(BTree);
void inOrder(BTree);
int max(int a,int b);
int height(BTree);
int numNodi(BTree);
void byLevel(BTree);
void preOrderIter(BTree);
void postOrderIter(BTree);
void inOrderIter(BTree);
int member(BTree t, Item e);
int conta_el(BTree t, Item e);
 