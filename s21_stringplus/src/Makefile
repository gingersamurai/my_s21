CC = gcc

CFLAGS = -Wall -Wextra -Werror
LD_S21_STRING_FLAGS = -L. -l:s21_string.a
LD_CHECK_FLAGS = -lcheck -lpthread -lm
GCOV_FLAGS = 

SOURCES = $(wildcard functions/s21_*.c)
OBJECTS = $(patsubst functions/%.c, %.o, $(SOURCES))

FOR_TESTS = 0

UNAME := $(shell uname -s)
ifeq ($(UNAME), Linux)
	LD_CHECK_FLAGS +=  -lsubunit
endif



.PHONY: all gcov_report test s21_string.a clean my_gcov_report

all: gcov_report


gcov_report: GCOV_FLAGS += -fprofile-arcs -ftest-coverage
gcov_report: test
	./test > /dev/null
	lcov -t "report" -o report.info -c -d .
	genhtml -o "html_report" report.info
	open html_report/index.html
		
test: the_final_test.o s21_string.a
	$(CC) $< $(LD_S21_STRING_FLAGS) $(LD_CHECK_FLAGS) $(GCOV_FLAGS) -o $@

mytest: mytest.c s21_string.a
	$(CC) $< $(LD_S21_STRING_FLAGS) -o $@

s21_string.a: $(OBJECTS)
	ar rc s21_string.a $(OBJECTS)
	ranlib s21_string.a

the_final_test.o: the_final_test.c
	$(CC) -c $^


%.o: functions/%.c
	$(CC) -c $^ $(GCOV_FLAGS) $(CFLAGS)

clean:
	rm -rf *.a t *.o *.gcno o *.gcda report.info html_report test

