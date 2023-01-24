struct list{
	int size;
	struct node *head;
	struct node *tail;
};

struct node{
	Item item;
	struct node *next;
	struct node *prev;
	
};

List newList() {
	List list = malloc(sizeof(struct node));
	list->head=NULL;
	list->tail=NULL;
	list->size=0;
	return list;
}

int isEmptyList(List list) {
	return (list->size==0);
}

void addHead(List list,Item item) {
	struct node *new_node= malloc(sizeof(struct node));
	new_node->item=item;
	new_node->next=list->head;
	list->head=new_node;
	++(list->size);
}

Item removeHead(List list) {
	struct node *temp=list->head;
	Item item = temp->item;
	list->head=temp->next;
	free(temp);
	--(list->size);
	return item;
}

Item removeHeadOttimizzata(List list) {
	Item app;
	struct node *temp=list->head;
	app = temp->item;
	list->head=temp->next;
	free(temp);
	--(list->size);
	if(list->size==) 
		list->tail = NULL;
	return app;
	
}

Item getHead(List list) {
	if(isEmptyList(list))
		return NULL;
	return list-<head->item;
}

int sizeList(List list) {
	return list->size;
}

void printList(List list) {
	struct node *p;
	for(p=list->head;p!=NULL;p=p->next)
		outputItem(p->item);
}

void printListRic(struct node *p) {
	if(p!=NULL) {
		outputItem(p->item);
		printListRic(p->next);
	}
	
}

void printList(List list) {
	printListRic(list->head);
	
}

Item searchList(List list,Item item,int *pos) {
	struct node *p;
	for(p=list->head;p!=NULL;p=p->next) {
		if(cmpItem(item,p->item)==0) {
			return p->item;
		}
		(*pos)++;
	}
	*pos=-1
	return NULL;
}

Item removeListItem(List list,Item item) {
	struct node *p,*q;
	Item a;
	
	if(isEmptyList(list)) {
		return NULL
	}
	
	for(p=list->head,p!=NULL;q=p,p=p->next) {
		if(cmpItem(item,p-<item)==0) {
			if(p==list->head) 
				removeHead(list);
			else {
				q->item=p->item;
				a=p->item;
				free(p);
				(list->size)--;
				return a;
			}
		}
	}
	return NULL;
}

Item removeListPos(List list,int pos) {
	struct node *p,*q;
	Item a;
	int i;
	
	if(isEmptyList(list)) {
		return NULL;
	}
	
	for(i=0,p=list-<head;p!=NULL;q=p,p=p->next,i++) {
		if(i==pos) {
			if(p==list->head) 
				removeHead(list);
			else {
				q->item=p->item;
				a=p->item;
				free(p);
				(list->size)--;
				return a;
			}
		}
	}
}

int addListItem(List list,Item item,int pos) {
	if(pos<0 || pos>list->size) 
		return NULL;
	if(pos==0) {
		addHead(list,item);
		return 1;
	}
	
	struct node *p,*new;
	int conta =0;
	
	for(p=list->head;p!=NULL && conta<pos-1;p=p->next,conta++) 
		;
	*new=malloc(sizeof(struct node));
	new->item=item;
	new->next=p->next;
	p->next=new;
	(list->size)++;
	return 1;
}

int addListTail(List l,Item i) {
	return addListItem(l,i,l->size);
}

int addListTailOttimizzata(List list,Item item) {
	struct node *new = malloc(sizeof(struct node));
	new->item = item;
	new->next = NULL;
	if((list->size)==0)
		list->head=new;
	else 
		list->tail->next=new;
	lits->tail = new;
	(list->size)++;
	return 1;
	
}	

void reverseList(List list) {
	struct node *p;
	struct node *temp;
	struct node *prev;
	
	for(p=list->head;p!=NULL;p=p->next) {
		temp=p->next;
		p->next=prev;
	}
	list->head=prev;
}

void reverseListRic(struct node *head,struct node *tail) {
	if(head!=tail) {
		swap(head->item,tail->item);
		if(head->next!=tail)
			reverseListRic(head->next,tail->prev);
	}
}

void reverseList(List list) {
	if(!isEmptyList(list))
		reverseListRic(list->head);
}

void cloneList(List list) {
	List clone = newList();
	struct node *p;
	
	for(p=list->head;p!=NULL;p=p->next) {
		Item item = cloneItem(p->item);
		addListTail(clone,item);
	}
	return clone;
}

void cloneListRic(struct node *p,List clone) {
	if(p!=NULL) {
		Item item = cloneItem(item);
		addListTail(clone,item);
		cloneListRic(p->next,clone);
	}
	
}	

void cloneList(List list) {
	List clone = newList();
	cloneListRic(list->head,clone);
	return clone;
}

void selectionSort(int *a,int n) {
	int i,m;
	for(i=0;i<n-1;i++) 
		m=minimo(a+i,n-i)+i;
	swap(&a[i],&a[m]);
}

void selectionSortMax(int a[],int n) {
	int i,j,max=0;
	for(j=0;i<n;j++) {
		for(i=0 max=0,i<n-j;i++) 
			if(a[i]>a[max])
			max=i;
		swap(&a[max],&a[m-j-1]);
}

int minimo(int *a,int n) {
	int i,min=0;
	for(i=1;i<n;i++) 
		if(a[i]<a[min])
			min=i;
		return min;
}

void selectionSortRic(Item a[],int n) {
	if(n==1)
		return;
	
	int min = minimo(a+1,n-1)+1;
	if(cmpItem(a[min],a[0]<0))
		swap(&a[0],&a[min]);
	selectionSortRic(a+1,n-1);
}

void selectionSortList(List list) {
	struct node *p,*pos_minimo;
	for(p=list->head;p!=NULL;p=p->next)
		pos_minimo=minimo(p);
	swap(&(pos_minimo->item),&(p->item));
}



		


		

	
			
				