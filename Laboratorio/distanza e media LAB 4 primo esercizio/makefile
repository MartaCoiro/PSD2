punto.exe: point.o main.o
	gcc point.o main.o -o punto.exe
	
point.o:
	gcc -c point.c
	
main.o:
	gcc -c main.c
		
clean:
	rm -f point.o main.o punto.exe