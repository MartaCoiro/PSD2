link: queue.o main.o item-int.o list.o
	gcc queue.o main.o item-int.o list.o -o a.exe

list: queue-list.o main.o item-string.o list.o
	gcc queue-list.o main.o item-string.o list.o -o a.exe

queue.o:
	gcc -c queue.c

queue-list.o:
	gcc -c queue-list.c

list.o:
	gcc -c list.c

main.o:
	gcc -c main.c

item-int.o:
	gcc -c item-int.c

item-string.o:
	gcc -c item-string.c

clean:
	rm -f *.o a.exe
