libretto :	list.o utils.o main.o esame.o item.o libretto.o
	gcc list.o utils.o main.o esame.o item.o libretto.o -o libretto.exe
	
list.o :
	gcc -c list.c
	
main.o :
	gcc -c main.c
	
utils.o :
	gcc -c utils.c
	
esame.o :
	gcc -c esame.c

item.o :
	gcc -c item.c
	
libretto.o :
	gcc -c libretto.c
	
clean: 
	rm -f *.o *.exe