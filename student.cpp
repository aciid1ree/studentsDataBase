#include "student.h"
#include <algorithm>

void StudentDatabase::addStudent(const Student& student) {
    database.push_back(student);
}

std::vector<Student> StudentDatabase::getAllStudents() const {
    return database;
}

const Student* StudentDatabase::getLatestStudent() const {
    if (database.empty()) return nullptr;
    return &database.back();
}

void StudentDatabase::deleteStudentByName(const std::string& name) {
    database.erase(
        std::remove_if(database.begin(), database.end(),
                       [&](const Student& s){ return s.name == name; }),
        database.end());
}

Student* StudentDatabase::getStudentByName(const std::string& name) {
    auto it = std::find_if(database.begin(), database.end(),
                           [&](const Student& s){ return s.name == name; });
    if (it != database.end()) return &(*it);
    return nullptr;
}
