
CFLAGS= #-Wall -Werror -Wextra

all: s21_grep

s21_grep: reader.o parse.o patterns.o main.o 
	gcc main.o reader.o parse.o patterns.o -o s21_grep

reader.o: reader.c
	gcc $(CFLAGS) -c reader.c -o reader.o

parse.o: parse.c
	gcc $(CFLAGS) -c parse.c -o parse.o

patterns.o: patterns.c
	gcc $(CFLAGS) -c patterns.c -o patterns.o

main.o: main.c
	gcc $(CFLAGS) -c main.c -o main.o

clean:
	rm -rf s21_grep main.o patterns.o parse.o reader.o
