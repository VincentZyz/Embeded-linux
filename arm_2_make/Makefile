out: main.o use.o
	gcc main.o use.o -o out

main.o:
	gcc -c main.c -o main.o

use.o:
	gcc -c use.c -o use.o

.PHONE:clean
clean:
	rm out
