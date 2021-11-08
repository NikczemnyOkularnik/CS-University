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
    auto db = std::make_unique<DataBase>();
    db->show_students();
    return (0);
}