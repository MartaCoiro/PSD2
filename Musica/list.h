#include "item.h"

typedef struct list *List;

List newList();
int isEmptyList(List list);
void addHead(List list, Item item);
Item removeHead(List list);
Item getHead(List list);
int sizeList(List list);
void printList(List list);
Item searchList(List list, Item item, int *pos);
Item removeListItem(List list, Item item);
Item removeListPos(List list,int pos);
int addListItem(List list,Item item,int pos);
int addListTail(List list,Item i);
void reverseList(List list);
void cloneList(List list);
void selectionSortList(List list);
