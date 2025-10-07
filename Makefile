CXX = g++
CXXFLAGS = -std=c++17 -Wall -pthread
INCLUDES = -I/usr/include/gtest
LIBS = -L/usr/lib/x86_64-linux-gnu -lgtest -lgtest_main -pthread

SRC_MAIN = main.cpp student.cpp
SRC_TEST = test_student.cpp student.cpp

program.out: $(SRC_MAIN)
	$(CXX) $(CXXFLAGS) $(SRC_MAIN) -o program.out

tests: $(SRC_TEST)
	$(CXX) $(CXXFLAGS) $(SRC_TEST) -o tests $(INCLUDES) $(LIBS)

clean:
	rm -f program.out tests
