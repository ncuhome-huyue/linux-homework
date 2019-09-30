proj:main.o number.o op.o
	gcc -Wall main.o number.o op.o -o proj
main.o:main.c
	gcc -Wall main.c -c
number.o:number.c
	gcc -Wall number.c -c
op.o:op.c
	gcc -Wall op.c -c

clean:
	rm -f *.o
