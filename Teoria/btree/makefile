str :	main.o item-string.o btree.o
	gcc  main.o item-string.o  btree.o -o btree.exe
		
int :	main.o item-int.o btree.o
	gcc  main.o item-int.o  btree.o -o btree.exe
	
btree.o :
	gcc -c btree.c
	
main.o :
	gcc -c main.c

item-int.o :
	gcc -c item-int.c
	
item-string.o :
	gcc -c item-string.c 
	
clean: 
	rm -f *.o *.exe