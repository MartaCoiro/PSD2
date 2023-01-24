link :	main.o item-int.o list.o
	gcc main.o item-int.o list.o -o adtList.exe

link-str :	main.o item-string.o list.o
	gcc main.o item-string.o list.o -o adtList.exe

list.o :
	gcc -c list.c
	
main.o :
	gcc -c main.c

item-int.o :
	gcc -c item-int.c

item-string.o :
	gcc -c item-string.c

clean: 
	rm -f main.o item-int.o item-string.o list.o adtList.exe