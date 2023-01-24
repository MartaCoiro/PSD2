str :	main.o item-string.o btree.o stack.o list.o
	gcc  main.o item-string.o  btree.o stack.o list.o -o adtBtree.exe
		
int :	main.o item-int.o btree.o stack.o list.o
	gcc  main.o item-int.o  btree.o stack.o list.o -o adtBtree.exe
	
btree.o :
	gcc -c btree.c
	
main.o :
	gcc -c main.c

item-int.o :
	gcc -c item-int.c
	
item-string.o :
	gcc -c item-string.c 
	
stack.o :
	gcc -c stack.c

list.o :
	gcc -c list.c
	
clean: 
	rm -f btree.o main.o item-int.o item-string.o stack.o list.o adtBtree.exe