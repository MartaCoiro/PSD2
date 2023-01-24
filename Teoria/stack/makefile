link: stack.o main.o item-int.o list.o
	gcc stack.o main.o item-int.o list.o -o a.exe

link-str: stack-list.o main.o item-string.o list.o
	gcc stack-list.o main.o item-string.o list.o -o a.exe

stack.o:
	gcc -c stack.c

stack-list.o:
	gcc -c stack-list.c

utils.o:
	gcc -c utils.c

array.o:
	gcc -c array.c

list.o:
	gcc -c list.c

main.o:
	gcc -c main.c

item-int.o:
	gcc -c item-int.c

item-string.o:
	gcc -c item-string.c

clean:
	rm -f a.exe


