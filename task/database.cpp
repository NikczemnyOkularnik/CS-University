#include "database.hpp"
#include <student.hpp>

void add_student(Student& St) {
    void push_back(Student St);
}

void list_student() {
    for (vector<Student*>::iterator it = begin(); it != end(); it++) {
        std::cout << (*it) << std::endl;
    }
}