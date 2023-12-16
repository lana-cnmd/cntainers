CC = g++
FLAGS = -Wall -Wextra -Werror -std=c++17
FILES = test_list.cc
GTEST = -lgtest -lgtest_main
GCOV = -fprofile-arcs -ftest-coverage -fPIC -pthread

all: gcov_report

test: clean 
	${CC} ${FLAGS} ${GCOV} ${FILES} ${GTEST} -o test
	./test

gcov_report: test
	mkdir report
	gcovr --html-details -o report/coverage.html
	open ./report/coverage.html

clean:
	rm -rf *.o *.out *.gch *.dSYM *.gcov *.gcda *.gcno *.a *.css *.html *.info *.gz *.log test report