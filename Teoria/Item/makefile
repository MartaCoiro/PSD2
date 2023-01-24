link : utils.o vettore.o main.o item_int.o 
	gcc utils.o vettore.o main.o item_int.o -o vettore.exe
	
link_str : utils.o vettore.o main.o item_string.o 
	gcc utils.o vettore.o main.o item_string.o -o vettore.exe
	
utils.o :
	gcc -c utils.c
	
vettore.o :
	gcc -c vettore.c
	
main.o :
	gcc -c main.c
	
item_int.o :
	gcc -c item_int.c
	
item_string.o :
	gcc -c item_string.c
	
clean:
	rm -f utils.o vettore.o main.o item_int.o item_string.o vettore.exe
	
	