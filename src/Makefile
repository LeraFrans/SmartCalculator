CC = gcc
GCOV = -fprofile-arcs -ftest-coverage
C_TESTS = calc_tests.c
C_FILES = SmartCalc_v1.0.c
VERSION = `date +"%Y.%m.%d"`
ARCHIVE = Calc_1-$(VERSION)

all: install

install:
	mkdir -p build
	cd Calc_1 && cmake -S ./ -B ../build
	cd build && $(MAKE)

run:
	open -Fn build/Smart-Calc.app

uninstall:
	rm -rf build
	rm -rf html
	rm -rf latex

dvi: 
	mkdir -p docs
	doxygen Doxyfile
	@mv html latex docs
	open docs/html/index.html

dvi_open:
	open docs/html/index.html

dist: install
	@tar -cf $(ARCHIVE).tar build/*

test:
	mkdir -p obj
	$(CC) -c $(C_TESTS) $(shell pkg-config --cflags check)  $(shell pkg-config --libs check)
	@mv *.o obj
	$(CC) $(GCOV) -o smartcalc $(C_TESTS) $(C_FILES) -lcheck $(shell pkg-config --cflags check)  $(shell pkg-config --libs check)
	./smartcalc
	@mv *.gcno *.gcda obj

gcov_report: test
	gcov obj/*.gcda
	@mv *.gcov obj
	gcovr
	gcovr --html-details -o report.html
	@mv *.css *.html obj

open_report:
	open obj/report.html

clean:
	rm -f *.css *.info *.out  *.html *.gcno *.gcda *.o *.a *.tar .clang-format
	rm -f smartcalc CMakeLists.txt.user
	rm -f a.out CMakeLists.txt.user
	rm -rf obj docs


check:
# cppcheck Calc_1/*.h Calc_1/*.c
	cp ../materials/linters/.clang-format .clang-format
	clang-format -n *.c *.h *.cpp
	leaks --atExit -- ./smartcalc -trace address