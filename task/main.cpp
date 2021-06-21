#include <iostream>
#include "database.hpp"
#include "student.hpp"

int main() {
    DataBase* db = new DataBase();

    Student* s = new Student("Stanisław", "Nowak", "Warszawa", 1, 215, Gender::Male);

    db->add_student(s);
    db->list_student();
    
    return 0;
}