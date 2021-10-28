#include <iostream>
#include "universityPerson.hpp"
#include "database.hpp"
#include "worker.hpp"
#include "student.hpp"
#include "generator.hpp"
#include <vector>
#include <memory>

int main()
{
    auto student2 = std::make_unique<Student>("Kasia", "Adamiec", "Warszawa", 144, Gender::Female, 2145);
    auto student3 = std::make_unique<Student>("Kasidasdasda", "Adaasdasdmiec", "Warszawa", 144, Gender::Female, 214);
    DataBase *db = new DataBase();
    db->add_student(student2);
    db->add_student(student3);
    db->show_students();
    db->DeleteByIndex(2145);
    db->show_students();
    return (0);
}