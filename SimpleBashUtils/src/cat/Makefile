
CFLAGS= -Wall -Werror -Wextra

all: s21_cat

s21_cat: reader.o parser.o main.o 
	gcc main.o reader.o parser.o -o s21_cat
	rm -rf main.o parser.o reader.o

reader.o: reader.c
	gcc $(CFLAGS) -c reader.c -o reader.o

parser.o: parser.c
	gcc $(CFLAGS) -c parser.c -o parser.o

main.o: main.c
	gcc $(CFLAGS) -c main.c -o main.o

clean:
	rm -rf s21_cat main.o parser.o reader.o
