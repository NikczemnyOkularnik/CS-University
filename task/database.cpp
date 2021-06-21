#include "database.hpp"
#include "student.hpp"
#include <algorithm>
#include <iostream>

void DataBase::add_student(Student& St) {
    void push_back(Student St);
}

void DataBase::list_student() {
    for (Student* s : students) {
        std::cout << (s->Print()) << std::endl;
    }
}