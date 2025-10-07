#include <iostream>
#include <vector>
#include "student.h"

int main() {
    StudentDatabase db;
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

        switch(choice) {
            case 1: {
                Student s;
                std::cout << "Введите имя: "; std::cin >> s.name;
                std::cout << "Введите возраст: "; std::cin >> s.age;
                std::cout << "Введите специальность: "; std::cin >> s.major;
                std::cout << "Введите GPA: "; std::cin >> s.gpa;
                db.addStudent(s);
                break;
            }
            case 2: {
                for (auto& s : db.getAllStudents()) {
                    std::cout << s.name << " " << s.age << " " << s.major << " " << s.gpa << "\n";
                }
                break;
            }
            case 3: {
                const Student* last = db.getLatestStudent();
                if (last) std::cout << last->name << "\n";
                break;
            }
            case 4: {
                std::cout << "Введите имя: "; std::cin >> name;
                Student* s = db.getStudentByName(name);
                if (s) std::cout << s->name << "\n";
                else std::cout << "Не найден\n";
                break;
            }
            case 5: {
                std::cout << "Введите имя: "; std::cin >> name;
                db.deleteStudentByName(name);
                break;
            }
            case 0: break;
            default: std::cout << "Неверный выбор\n";
        }
    } while(choice != 0);
}
