#pragma once
#include <vector>
#include <iostream>

class Student;

class DataBase {
    std::vector<Student*> students;

    void add_student(Student& St);

    void list_student();
};

