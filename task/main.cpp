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
    DataBase *db = new DataBase();
    db->add_student(student2);
    auto ptr = db->GetStudentViaID(144);
    std::cout << db->person[ptr]->GetID();
    return (0);
}