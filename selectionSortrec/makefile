int :	utils.o vettore.o main.o item-int.o
	gcc utils.o vettore.o main.o item-int.o -o vettore.exe
	
str :	utils.o vettore.o main.o item-string.o
	gcc utils.o vettore.o main.o item-string.o -o vettore.exe
	

utils.o :
	gcc -c utils.c
	
vettore.o :
	gcc -c vettore.c
	
main.o :
	gcc -c main.c

item-int.o :
	gcc -c item-int.c
	
item-string.o :
	gcc -c item-string.c 
	
clean: 
	rm -f *.o *.exe