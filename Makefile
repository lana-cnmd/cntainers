FLAGS = -Wall -Wextra -Werror -std=c++17
FILES = s21_matrix_oop.cc
GTEST = -lgtest -lgtest_main
GCOV = -fprofile-arcs -ftest-coverage -fPIC -pthread

all: gcov_report

test: clean 
	g++ ${FLAGS} tests_s21_matrix.cc -c 
	g++ ${FLAGS} ${GCOV} ${FILES} tests_s21_matrix.o -o test ${GTEST}
	./test

gcov_report: test 
	lcov -t "matrix" -o matrix.info -c -d .
	genhtml -o report matrix.info

ifeq (${OS}, Linux)
	cd report && firefox index.html
else
	cd report && open index.html
endif

clean:
	rm -rf *.o *.out *.gch *.dSYM *.gcov *.gcda *.gcno *.a tests_s21_matrix *.css *.html vgcore* report *.info *.gz *.log test
