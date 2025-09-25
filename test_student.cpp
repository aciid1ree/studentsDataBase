#include "student.h"
#include <gtest/gtest.h>

class StudentDatabaseTest : public ::testing::Test {
protected:
    StudentDatabase db;

    void SetUp() override {
        db.addStudent({"Иван", 20, "Информатика", 4.5});
        db.addStudent({"Мария", 21, "Математика", 4.7});
        db.addStudent({"Петр", 19, "Физика", 4.2});
    }
};

// 1. Проверка добавления студента
TEST_F(StudentDatabaseTest, AddStudent) {
    db.addStudent({"Анна", 22, "Биология", 4.9});
    auto students = db.getAllStudents();
    ASSERT_EQ(students.size(), 4);
    EXPECT_EQ(students.back().name, "Анна");
    EXPECT_DOUBLE_EQ(students.back().gpa, 4.9);
}

// 2. Проверка получения последнего студента
TEST_F(StudentDatabaseTest, GetLatestStudent) {
    const Student* last = db.getLatestStudent();
    ASSERT_NE(last, nullptr);
    EXPECT_EQ(last->name, "Петр");
}

// 3. Проверка поиска студента по имени
TEST_F(StudentDatabaseTest, GetStudentByName) {
    Student* s = db.getStudentByName("Мария");
    ASSERT_NE(s, nullptr);
    EXPECT_EQ(s->major, "Математика");

    Student* notFound = db.getStudentByName("Николай");
    EXPECT_EQ(notFound, nullptr);
}

// 4. Проверка удаления студента
TEST_F(StudentDatabaseTest, DeleteStudentByName) {
    db.deleteStudentByName("Мария");
    Student* s = db.getStudentByName("Мария");
    EXPECT_EQ(s, nullptr);
    EXPECT_EQ(db.getAllStudents().size(), 2);
}

// 5. Проверка возвращаемого списка студентов
TEST_F(StudentDatabaseTest, GetAllStudents) {
    auto students = db.getAllStudents();
    ASSERT_EQ(students.size(), 3);
    EXPECT_EQ(students[0].name, "Иван");
    EXPECT_EQ(students[1].name, "Мария");
    EXPECT_EQ(students[2].name, "Петр");
}

// 6. Проверка работы с пустой базой
TEST(StudentDatabaseEdgeCase, EmptyDatabase) {
    StudentDatabase emptyDb;
    EXPECT_EQ(emptyDb.getAllStudents().size(), 0);
    EXPECT_EQ(emptyDb.getLatestStudent(), nullptr);
    EXPECT_EQ(emptyDb.getStudentByName("Любой"), nullptr);
    emptyDb.deleteStudentByName("Любой"); // не должно падать
}


int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
