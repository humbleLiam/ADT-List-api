CC = gcc 
CFLAGS =  -I. -Wall -pedantic 
SRC = src/
INC = includes/
BIN = bin/

main: main.o adtLL.o $(INC)adtLL.h
	$(CC) $(CFLAGS) main.o adtLL.o -o run

main.o: $(SRC)main.c $(INC)adtLL.h
	$(CC) $(CFLAGS) -c $(SRC)main.c  -o main.o

adtLL.o: $(SRC)adtLL.c $(INC)adtLL.h
	$(CC) $(CFLAGS) -c $(SRC)adtLL.c  -o adtLL.o

clean:
	rm *.o run	