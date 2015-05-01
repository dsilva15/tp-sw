all: nes

nes: main.o functions.o
	gcc main.o functions.o -o nes

main.o: main.c
	gcc -c main.c

functions.o: functions.c
	gcc -c functions.c
	
clean:
	rm *o nes
