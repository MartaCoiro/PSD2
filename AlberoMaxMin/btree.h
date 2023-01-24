#include "item.h"

typedef struct node *BTree;

BTree newTree();
int isEmptyTree(BTree);
BTree buildTree(BTree, BTree, Item);
Item getBTreeRoot(BTree);
BTree getLeft(BTree);
BTree getRight(BTree);
/*void preOrder(BTree);
void postOrder(BTree);
void inOrder(BTree);*/
int min(char a,char b, char c);
char getMin(BTree b);
int maxC(char a,char b,char c);
char getMax(BTree t);
int height(BTree t);
int max(int a,int b);
int numNodi(BTree b);
int ricercaEl(BTree t,Item e);
int conta_el(BTree t,Item i);
void preOrderIter(BTree t);
void postOrderIter(BTree t);
void inOrderIter(BTree t);
//List funzione(BTree t, Item i);