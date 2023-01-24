link :	utils.o vettore.o main.o
	gcc utils.o vettore.o main.o -o vettore.exe

driver: utils.o vettore.o driver.o
	gcc utils.o vettore.o driver.o -o driver.exe

driver_sum: utils.o vettore.o driver_sum.o
	gcc utils.o vettore.o driver_sum.o -o driver_sum.exe
	
driver_sum_vecs: utils.o vettore.o driver_sum_vecs.o
	gcc utils.o vettore.o driver_sum_vecs.o -o driver_sum_vecs.exe

utils.o :
	gcc -c utils.c

vettore.o :
	gcc -c vettore.c

main.o :
	gcc -c main.c

driver.o :
	gcc -c driver.c
	
driver_sum_vecs.o :
	gcc -c driver_sum_vecs.c

driver_sum.o :
	gcc -c driver_sum.c

clean:
	rm -f utils.o vettore.o main.o driver.o driver.exe vettore.exe driver_sum.o driver_sum.exe driver_sum_vecs.o driver_sum_vecs.exe
