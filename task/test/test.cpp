#define CATCH_CONFIG_MAIN // This tells Catch to provide a main() - only do this in one cpp file
#include "catch_amalgamated.hpp"
#include "../student.hpp"
#include "../database.hpp"
#include "../worker.hpp"
#include "../universityPerson.hpp"

// SCENARIO( "vectors can be sized and resized", "[vector]" ) {

//     GIVEN( "A vector with some items" ) {
//         std::vector<int> v( 5 );

//         REQUIRE( v.size() == 5 );
//         REQUIRE( v.capacity() >= 5 );

//         WHEN( "the size is increased" ) {
//             v.resize( 10 );

//             THEN( "the size and capacity change" ) {
//                 REQUIRE( v.size() == 5 );
//                 REQUIRE( v.capacity() >= 10 );
//             }
//         }
//         WHEN( "the size is reduced" ) {
//             v.resize( 0 );

//             THEN( "the size changes but not capacity" ) {
//                 REQUIRE( v.size() == 0 );
//                 REQUIRE( v.capacity() >= 5 );
//             }
//         }
//         WHEN( "more capacity is reserved" ) {
//             v.reserve( 10 );

//             THEN( "the capacity changes but not the size" ) {
//                 REQUIRE( v.size() == 5 );
//                 REQUIRE( v.capacity() >= 10 );
//             }
//         }
//         WHEN( "less capacity is reserved" ) {
//             v.reserve( 0 );

//             THEN( "neither size nor capacity are changed" ) {
//                 REQUIRE( v.size() == 5 );
//                 REQUIRE( v.capacity() >= 5 );
//             }
//         }
//     }
// }
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
        auto worker3 = std::make_unique<Worker>("Grażyna", "Marek", "Sosonowiec", 15, Gender::Other, 2700);

        db->add_student(student1);
        db->add_student(student2);
        db->add_student(student3);
        db->add_worker(worker1);
        db->add_worker(worker2);
        db->add_worker(worker3);

        REQUIRE(db->getDbSize() == 6);

        WHEN("Find student with surname Nowak")
        {
            std::vector<std::unique_ptr<UniversityPerson>> sameSurname;
            db->GetStudentsWithSurname("Nowak");
            THEN("vector contains Nowak")
            {
                REQUIRE(sameSurname.size());
                auto & Surname0 = sameSurname[0];
                CHECK(Surname0->GetSurname() == "Nowak");
            }
        }
        WHEN("Sort students by surname")
        {
            std::vector<std::unique_ptr<UniversityPerson>> sortSurname;
            db->SortSurnames();
            THEN("Surnames should be sorted alphabetically")
            {
                REQUIRE(sortSurname.size());
                auto & Surname0 = sortSurname[0];
                CHECK(Surname0->GetSurname() == "Adamiec");
            }
        }

        WHEN("Sort students by ID number")
        {
            std::vector<Student *> studentsSortedID;
            db->SortID();
            THEN("ID numbers should be sorted from smallest to the biggest")
            {
                REQUIRE(studentsSortedID.size());
                auto ID0 = studentsSortedID[2];
                CHECK(ID0->GetID() == 144);
            }
        }
        WHEN("Delete students by ID")
        {
            db->DeleteByIndex(215);
            THEN("Student should be erased from db vector by using ID")
            {
                REQUIRE(db->CheckID(215) == false);
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
        auto worker3 = std::make_unique<Worker>("Grażyna", "Marek", "Sosonowiec", 15, Gender::Other, 2700);

        db->add_student(student1);
        db->add_student(student2);
        db->add_student(student3);
        db->add_student(student4);
        db->add_worker(worker1);
        db->add_worker(worker2);
        db->add_worker(worker3);

        REQUIRE(db->getDbSize() == 7);

        std::vector<std::unique_ptr<UniversityPerson>> people;
        db->SortSurnames();
        WHEN("GetSurname")
        {
            THEN("vector contains Adamiec")
            {
                auto & Surname0 = people[1];
                CHECK(Surname0->GetSurname() == "Adamiec");
            }
        }
        WHEN("GetName")
        {
            THEN("Vector contains name Kasia")
            {
                auto & Name0 = people[1];
                CHECK(Name0->GetName() == "Kasia");
            }
        }
        WHEN("GetAddress")
        {
            THEN("Vector contains Gdańsk")
            {
                auto & Address0 = people[3];
                CHECK(Address0->GetAddress() == "Gdańsk");
            }
        }
        WHEN("GetID")
        {
            THEN("Vector contains 144")
            {
                auto & ID0 = people[1];
                CHECK(ID0->GetID() == 144);
            }
        }
        WHEN("GetIndex")
        {
            THEN("Vector contains 2145")
            {
                auto & Index0 = people[1];
                CHECK(Index0->GetIndex() == 2145);
            }
        }
        WHEN("GetGender")
        {
            THEN("Vector contains Gender")
            {
                auto & Gender0 = people[1];
                auto & Gender1 = people[0];
                CHECK(Gender0->GetGenderInString() == "Dziewczyna");
                CHECK(Gender1->GetGenderInString() == "Chłopak");
            }
        }
    }
}
