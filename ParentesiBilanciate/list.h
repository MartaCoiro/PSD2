typedef struct list *List;

List newList();
int isEmptyList(List list);
void addHead(List list,Item item);
Item removeHead(List list);
Item getHead(List list);
void printList(List list);