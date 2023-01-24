int :	bst.o main.o item-int.o queue.o
	gcc bst.o main.o item-int.o queue.o -o bst.exe
	
str :	bst.o main.o item-string.o
	gcc bst.o main.o item-string.o -o bst.exe
	
bst.o :
	gcc -c bst.c
	
main.o :
	gcc -c main.c

item-int.o :
	gcc -c item-int.c
	
item-string.o :
	gcc -c item-string.c

queue.o :
	gcc -c queue.c
	
clean: 
	rm -f *.o *.exe