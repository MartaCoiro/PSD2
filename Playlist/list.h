#include "item-song.h"

typedef struct list *List;

List newList();
int isEmpty(List);
void selectionSortList(List);
Item removeListItem(List, Item);
Item removeHead(List);
void addHead(List, Item );
Item getHead(List);
int sizeList(List);
void printList(List);
Item searchList(List, Item ,int *pos);