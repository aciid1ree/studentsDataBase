CXX = g++
CXXFLAGS = -std=c++17 -Wall -pthread
INCLUDES = -I /opt/homebrew/include
LIBS = -L /opt/homebrew/lib -lgtest -lgtest_main -pthread

SRC_MAIN = main.cpp student.cpp
SRC_TEST = test_student.cpp student.cpp

all: program.out tests

program.out: $(SRC_MAIN)
	$(CXX) $(CXXFLAGS) $(SRC_MAIN) -o program.out

tests: $(SRC_TEST)
	$(CXX) $(CXXFLAGS) $(SRC_TEST) -o tests $(INCLUDES) $(LIBS)

run: program.out
	./program.out

test: tests
	./tests

clean:
	rm -f program.out tests
