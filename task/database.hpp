#pragma once
#include <vector>

class Student;

class DataBase {
    std::vector<Student*> students;

public:
    void add_student(Student* St);

    void list_student();
};
