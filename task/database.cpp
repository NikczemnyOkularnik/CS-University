#include "database.hpp"
#include <algorithm>
#include <iostream>
#include "student.hpp"

void DataBase::add_student(Student* St) {
    students.push_back(St);
}

void DataBase::list_student() {
    for (Student* s : students) {
        s->Print();
        std::cout<<"\n";
    }
}

void DataBase::GetAllStudentsWithSurname(std::vector<Student*>& foundStudents, const std::string& searchingSurname) {
    for (Student* s : students) {
        if (s->GetSurname().compare(searchingSurname) == 0) {
            foundStudents.push_back(s);
        }
    }
}

Student* DataBase::GetStudentViaID(const int& searchingID) {
    for (Student* s : students) {
        if (s->GetID() == searchingID) {
            return s;
        }
    }
    std::cout << "No students with ID = " << searchingID;
    return nullptr;
}