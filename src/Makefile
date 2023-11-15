FLAGS = gcc -Wall -Werror -Wextra -std=c11
FILES = s21_strncat.c s21_strlen.c s21_strchr.c s21_strncmp.c s21_strncpy.c s21_memchr.c s21_memcmp.c s21_memcpy.c s21_memset.c s21_strcspn.c s21_strpbrk.c s21_strrchr.c s21_strstr.c s21_strtok.c s21_to_upper.c s21_to_lower.c s21_trim.c s21_insert.c s21_strcpy.c s21_sprintf.c s21_sscanf.c s21_strerror.c
C_SHARP_TESTS_FILES = $(FILES) tests/C_sharp_test/s21_to_upper_test.c tests/C_sharp_test/s21_to_lower_test.c tests/C_sharp_test/s21_insert_test.c tests/C_sharp_test/s21_trim_test.c #tests/C_sharp_test/s21_string_tests.c
SSCANF_TESTS_FILES = tests/sscanf_test/test.c
SPRINTF_TESTS_FILES = #tests/sprintf_test/test.c
OTHER_TESTS_FILES = tests/other_test/tests.c tests/test_main.c
OBJECTS = $(FILES:.c=.o)
OS = $(shell uname)
ifeq ($(OS), Linux)
	CHECK_FLAGS = -lcheck -pthread -lrt -lm -lsubunit -L.
else
	CHECK_FLAGS = -lcheck -L.
endif

all: s21_string.a

clean:
	rm -rf *.o *.a *.gcno *.gcda tests/*/*.gcno tests/*/*.gcda tests/*.gcno tests/*.gcda test.info *.out tests/test
	rm -rf report
	rm -rf *.dSYM .txt


rebuild: clean style all

test: s21_string.a
	$(FLAGS) -g3 --coverage $(OTHER_TESTS_FILES) $(C_SHARP_TESTS_FILES) $(SPRINTF_TESTS_FILES) $(CHECK_FLAGS) -o tests/test
	./tests/test

s21_string.a: $(OBJECTS)
	ar rc s21_string.a $(OBJECTS)
	ranlib s21_string.a

gcov_report: test
	lcov -t "test" -o test.info -c -d .
	genhtml -o report test.info
	open ./report/index.html

style:
	cp -f ../materials/linters/.clang-format ./
	clang-format -i -style=Google *.c *.h tests/*.c tests/*/*.c tests/*/*.h
	clang-format -n -style=Google *.c *.h tests/*.c tests/*/*.c tests/*/*.h
