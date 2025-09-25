#include <iostream>
#include <vector>
#include <string>
#include "gtest/gtest.h"
#include <gmock/gmock.h>

struct Student {
    std::string name;
    int age;
    std::string major;
    double gpa;
};

// Функция для добавления студента в базу данных
void addStudent(std::vector<Student>& database, Student& student) {
    database.push_back(student);
    std::cout << "Студент добавлен в базу данных.\n";
}

// Функция для вывода всех студентов из базы данных
void displayStudents(const std::vector<Student>& database) {
    std::cout << "Список студентов:\n";
    for (const Student& student : database) {
        std::cout << "Имя: " << student.name << "\n";
        std::cout << "Возраст: " << student.age << "\n";
        std::cout << "Специальность: " << student.major << "\n";
        std::cout << "Средний балл: " << student.gpa << "\n\n";
    }
}

void displayLatestStudent(const std::vector<Student>& database) {
    std::cout << "Последний студент:\n";
    Student lastStudent = database.back();
    std::cout << "Имя: " << lastStudent.name << "\n";
    std::cout << "Имя: " << lastStudent.name << "\n";
    std::cout << "Возраст: " << lastStudent.age << "\n";
    std::cout << "Специальность: " << lastStudent.major << "\n";
    std::cout << "Средний балл: " << lastStudent.gpa << "\n\n";
}


void deleteStudentByName(std::vector<Student>& database, const std::string& name) {
    database.erase(
        std::remove_if(database.begin(), database.end(),
                       [&](const Student& s) { return s.name == name; }),
        database.end());
}

Student* getStudentByName(std::vector<Student>& database, const std::string& name) {
    auto it = std::find_if(database.begin(), database.end(),
                           [&](const Student& s) { return s.name == name; });

    if (it != database.end()) {
        return &(*it); 
    }
    return nullptr; 
}

class StudentDatabaseTest : public ::testing::Test {
    protected:
        std::vector<Student> db;
    
        void SetUp() override {
            db = {
                {"Иван", 20, "Информатика", 4.5},
                {"Мария", 21, "Математика", 4.7},
                {"Петр", 19, "Физика", 4.2}
            };
        }
    };

TEST_F(StudentDatabaseTest, AddStudent) {
    Student newStudent{"Анна", 22, "Биология", 4.9};
    addStudent(db, newStudent);

    ASSERT_EQ(db.size(), 4);
    EXPECT_EQ(db.back().name, "Анна");
    EXPECT_DOUBLE_EQ(db.back().gpa, 4.9);
}

TEST_F(StudentDatabaseTest, displayLatestStudent) {
    std::stringstream buffer;
    std::streambuf* oldCout = std::cout.rdbuf(buffer.rdbuf());

    displayLatestStudent(db);
    std::cout.rdbuf(oldCout);

    std::string output = buffer.str();
    EXPECT_NE(output.find("Петр"), std::string::npos);
    EXPECT_NE(output.find("19"), std::string::npos);
    EXPECT_NE(output.find("Физика"), std::string::npos);
    EXPECT_NE(output.find("4.2"), std::string::npos);
}

int main() {
    std::vector<Student> database;

    int choice;
    std::string name;
    do {
        std::cout << "Меню:\n";
        std::cout << "1. Добавить студента\n";
        std::cout << "2. Вывести список студентов\n";
        std::cout << "3. Вывести последнего добавленного студента\n";
        std::cout << "4. Найти студента по имени\n";
        std::cout << "5. Удалить студента\n";
        std::cout << "0. Выход\n";
        std::cout << "Выберите действие: ";
        std::cin >> choice;

        switch (choice) {
            case 1: {
                Student newStudent;
                std::cout << "Введите имя студента: ";
                std::cin >> newStudent.name;
                std::cout << "Введите возраст студента: ";
                std::cin >> newStudent.age;
                std::cout << "Введите специальность студента: ";
                std::cin >> newStudent.major;
                std::cout << "Введите средний балл студента: ";
                std::cin >> newStudent.gpa;
                addStudent(database, newStudent);
                break;
            }
            case 2:
                displayStudents(database);
                break;
            case 3:
                displayLatestStudent(database);
                break;
            case 4:{
                std::cout << "Введите имя: ";
                std::cin >> name;
                auto student = getStudentByName(database, name); 
                if (student) {
                    std::cout << "Нашли студента: " << student->name << std::endl;
                } else {
                    std::cout << "Студент не найден" << std::endl;
                }
                break;
            }
            case 5:
                std::cout << "Введите имя: ";
                std::cin >> name;
                deleteStudentByName(database, name); 
                break;
            case 0:
                std::cout << "Выход из программы.\n";
                break;
            default:
                std::cout << "Неверный выбор. Попробуйте снова.\n";        
        }
    } while (choice != 0);

    ::testing::InitGoogleTest();
   return RUN_ALL_TESTS();
}

