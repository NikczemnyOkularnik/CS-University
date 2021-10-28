#define CATCH_CONFIG_MAIN // This tells Catch to provide a main() - only do this in one cpp file
#include "catch_amalgamated.hpp"
#include "../student.hpp"
#include "../database.hpp"
#include "../worker.hpp"
#include "../universityPerson.hpp"

SCENARIO("Adding new students to database")
{
    GIVEN("Database and students")
    {
        DataBase *db = new DataBase();

        auto student1 = std::make_unique<Student>("Stanisław", "Nowak", "Szczecin", 12, Gender::Male, 215);
        auto student2 = std::make_unique<Student>("Kasia", "Adamiec", "Warszawa", 144, Gender::Female, 2145);
        auto student3 = std::make_unique<Student>("Zuza", "Kowalska", "Wrocław", 1, Gender::Female, 2115);
        auto worker1 = std::make_unique<Worker>("Grzegorz", "Kwak", "Gdańsk", 2, Gender::Male, 2300);
        auto worker2 = std::make_unique<Worker>("Krzysztof", "Balonik", "Radom", 15, Gender::Male, 2500);
        auto worker3 = std::make_unique<Worker>("Grażyna", "Marek", "Sosonowiec", 17, Gender::Other, 2700);

        db->add_student(student1);
        db->add_student(student2);
        db->add_student(student3);
        db->add_worker(worker1);
        db->add_worker(worker2);
        db->add_worker(worker3);

        REQUIRE(db->getDbSize() == 6);

        WHEN("Find student with surname Nowak")
        {
            db->GetStudentsWithSurname("Nowak");
            THEN("vector contains Nowak")
            {
                REQUIRE(db->person.size());
                auto Surname0 = db->person[0]->GetSurname();
                CHECK(Surname0 == "Nowak");
            }
        }
        WHEN("Find student with ID")
        {
            auto ptr = db->GetStudentViaID(15);
            THEN("vector contains ID 15")
            {
                REQUIRE(db->person.size());
                auto Surname0 = db->person[ptr]->GetID();
                CHECK(Surname0 == 15);
            }
        }
        WHEN("Sort students by surname")
        {
            db->SortSurnames();
            THEN("Surnames should be sorted alphabetically")
            {
                REQUIRE(db->person.size());
                auto Surname0 = db->person[0]->GetSurname();
                CHECK(Surname0 == "Adamiec");
            }
        }
        WHEN("Sort students by ID number")
        {
            db->SortID();
            THEN("ID numbers should be sorted from smallest to the biggest")
            {
                REQUIRE(db->person.size());
                auto ID5 = db->person[5]->GetID();
                CHECK(ID5 == 144);
            }
        }
        WHEN("Sort workers by salary")
        {
            db->SortSalary();
            THEN("Salary should be sorted from biggest to smallest")
            {
                REQUIRE(db->person.size());
                auto Money1 = db->person[1]->GetMoney();
                CHECK(Money1 == 2500);
            }
        }
        WHEN("Check if ID exist")
        {
            auto result = db->CheckID(2);
            THEN("Result should be true if there is ID = 2")
            {
                REQUIRE(db->person.size());
                CHECK(result == true);
            }
        }
        WHEN("Check if earning modification is working")
        {
            db->earning_modification(2,3000);
            db->SortID();
            THEN("Worker with ID = 2, should have 3000")
            {
                REQUIRE(db->person.size());
                auto Money1 = db->person[1]->GetMoney();
                CHECK(Money1 == 3000);
            }
        }
        WHEN("Delete students by Index")
        {
            db->DeleteByIndex(215);
            THEN("Student should be erased from db vector by using index, size should be smaller")
            {
                REQUIRE(db->person.size() == 5);
                auto result = db->CheckID(12);
                CHECK(result == false);
            }
        }
    }
}

SCENARIO("Checking getters for database")
{
    GIVEN("Database and students")
    {
        DataBase *db = new DataBase();

        auto student1 = std::make_unique<Student>("Stanisław", "Nowak", "Szczecin", 12, Gender::Male, 215);
        auto student2 = std::make_unique<Student>("Kasia", "Adamiec", "Warszawa", 144, Gender::Female, 2145);
        auto student3 = std::make_unique<Student>("Zuza", "Kowalska", "Wrocław", 1, Gender::Female, 2115);
        auto student4 = std::make_unique<Student>("Karol", "Biskup", "Gdańsk", 37, Gender::Male, 2117);
        auto worker1 = std::make_unique<Worker>("Grzegorz", "Kwak", "Gdańsk", 2, Gender::Male, 2300);
        auto worker2 = std::make_unique<Worker>("Krzysztof", "Balonik", "Radom", 15, Gender::Male, 2500);
        auto worker3 = std::make_unique<Worker>("Grażyna", "Marek", "Sosonowiec", 17, Gender::Other, 2700);

        db->add_student(student1);
        db->add_student(student2);
        db->add_student(student3);
        db->add_student(student4);
        db->add_worker(worker1);
        db->add_worker(worker2);
        db->add_worker(worker3);

        REQUIRE(db->getDbSize() == 7);

        db->SortSurnames();
        // WHEN("GetSurname")
        // {
        //     THEN("vector contains Adamiec")
        //     {
        //         auto & Surname0 = people[1];
        //         CHECK(Surname0->GetSurname() == "Adamiec");
        //     }
        // }
        // WHEN("GetName")
        // {
        //     THEN("Vector contains name Kasia")
        //     {
        //         auto & Name0 = people[1];
        //         CHECK(Name0->GetName() == "Kasia");
        //     }
        // }
        // WHEN("GetAddress")
        // {
        //     THEN("Vector contains Gdańsk")
        //     {
        //         auto & Address0 = people[3];
        //         CHECK(Address0->GetAddress() == "Gdańsk");
        //     }
        // }
        // WHEN("GetID")
        // {
        //     THEN("Vector contains 144")
        //     {
        //         auto & ID0 = people[1];
        //         CHECK(ID0->GetID() == 144);
        //     }
        // }
        // WHEN("GetIndex")
        // {
        //     THEN("Vector contains 2145")
        //     {
        //         auto & Index0 = people[1];
        //         CHECK(Index0->GetIndex() == 2145);
        //     }
        // }
        // WHEN("GetGender")
        // {
        //     THEN("Vector contains Gender")
        //     {
        //         auto & Gender0 = people[1];
        //         auto & Gender1 = people[0];
        //         CHECK(Gender0->GetGenderInString() == "Dziewczyna");
        //         CHECK(Gender1->GetGenderInString() == "Chłopak");
        //     }
        // }
    }
}
