CXX = g++
CXXFLAGS = -std=c++17 -Wall -pthread
INCLUDES = -I /opt/homebrew/include
LIBS = -L /opt/homebrew/lib -lgtest -lgtest_main -pthread

# Основные файлы
SRC_MAIN = main.cpp student.cpp
SRC_TEST = test_student.cpp student.cpp

# Цели по умолчанию
all: program.out tests

# Сборка основной программы
program.out: $(SRC_MAIN)
	$(CXX) $(CXXFLAGS) $(SRC_MAIN) -o program.out

# Сборка тестов
tests: $(SRC_TEST)
	$(CXX) $(CXXFLAGS) $(SRC_TEST) -o tests $(INCLUDES) $(LIBS)

# Запуск программы
run: program.out
	./program.out

# Запуск тестов
test: tests
	./tests

# Очистка
clean:
	rm -f program.out tests
