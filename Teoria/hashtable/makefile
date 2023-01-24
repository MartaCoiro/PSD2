str-int: list.o main.o item-int.o key-string.o hashtable.o entry.o item-entry.o
	gcc list.o main.o item-int.o key-string.o hashtable.o entry.o item-entry.o -o main.exe
	
list.o :
	gcc -c list.c
	
main.o :
	gcc -c main.c
	
key-string.o:
	gcc -c key-string.c
	
hashtable.o:
	gcc -c hashtable.c
	
entry.o: 
	gcc -c entry.c

item-int.o :
	gcc -c item-int.c
	
item-entry.o :
	gcc -c item-entry.c 
	
clean: 
	del -f *.o *.exe