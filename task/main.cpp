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
    DataBase *db = new DataBase();
    db->show_workers();
    return (0);
}