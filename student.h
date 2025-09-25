#pragma once
#include <string>
#include <vector>

struct Student {
    std::string name;
    int age;
    std::string major;
    double gpa;
};

class StudentDatabase {
private:
    std::vector<Student> database;

public:
    void addStudent(const Student& student);
    std::vector<Student> getAllStudents() const;
    const Student* getLatestStudent() const;
    void deleteStudentByName(const std::string& name);
    Student* getStudentByName(const std::string& name);
};
