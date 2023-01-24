#include "item.h"

typedef struct list *List;


List newList();
int isEmpty(List list);
void addHead(List list, Item item);
Item removeHead(List list);
Item getHead(List list);
int sizeList(List list);
void printList(List list);