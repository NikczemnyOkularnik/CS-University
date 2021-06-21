#include "database.hpp"
#include "student.hpp"
#include <algorithm>
#include <iostream>

void DataBase::add_student(Student* St) {
    students.push_back(St);
}

void DataBase::list_student() {
    for (Student* s : students) {
        s->Print();
    }
}