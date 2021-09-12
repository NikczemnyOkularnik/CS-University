#define CATCH_CONFIG_MAIN // This tells Catch to provide a main() - only do this in one cpp file
#include "catch_amalgamated.hpp"
#include "../student.hpp"
#include "../database.hpp"

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

        Student *s = new Student("Stanisław", "Nowak", "Warszawa", 12, 215, Gender::Male);
        Student *s1 = new Student("Kasia", "Adamiec", "Warszawa", 144, 2145, Gender::Female);
        Student *s2 = new Student("Zuza", "Kowalska", "Wrocław", 1, 2115, Gender::Female);
        db->add_student(s);
        db->add_student(s1);
        db->add_student(s2);
        REQUIRE(db->GetVectorSize() == 3);

        WHEN("Find student with surname Nowak")
        {
            std::vector<Student *> studentsWithSameSurname;
            db->GetAllStudentsWithSurname(studentsWithSameSurname, "Nowak");
            THEN("vector contains Nowak")
            {
                REQUIRE(studentsWithSameSurname.size());
                auto Surname0 = studentsWithSameSurname[0];
                CHECK(Surname0->GetSurname() == "Nowak");
            }
        }
        WHEN("Sort students by surname")
        {
            std::vector<Student *> studentsSortedSurnames;
            db->SortStudentsSurnames(studentsSortedSurnames);
            THEN("Surnames should be sorted alphabetically")
            {
                REQUIRE(studentsSortedSurnames.size());
                auto Surname0 = studentsSortedSurnames[0];
                CHECK(Surname0->GetSurname() == "Adamiec");
            }
        }

        WHEN("Sort students by ID number")
        {
            std::vector<Student *> studentsSortedID;
            db->SortStudentsID(studentsSortedID);
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
                REQUIRE(db->GetStudentViaID(215) == nullptr);
            }
        }
    }
}

SCENARIO("Checking getters for database")
{
    GIVEN("Database and students")
    {
        DataBase *db = new DataBase();

        Student *s = new Student("Stanisław", "Nowak", "Poznań", 12, 215, Gender::Male);
        Student *s1 = new Student("Kasia", "Adamiec", "Warszawa", 144, 2145, Gender::Female);
        Student *s2 = new Student("Zuza", "Kowalska", "Wrocław", 1, 2115, Gender::Female);
        Student *s3 = new Student("Karol", "Biskup", "Gdańsk", 37, 2117, Gender::Male);
        db->add_student(s);
        db->add_student(s1);
        db->add_student(s2);
        db->add_student(s3);
        REQUIRE(db->GetVectorSize() == 4);

        std::vector<Student *> students;
        db->SortStudentsSurnames(students);
        WHEN("GetSurname")
        {
            THEN("vector contains Adamiec")
            {
                auto Surname0 = students[0];
                CHECK(Surname0->GetSurname() == "Adamiec");
            }
        }
        WHEN("GetName")
        {
            THEN("Vector contains name Kasia")
            {
                auto Name0 = students[0];
                CHECK(Name0->GetName() == "Kasia");
            }
        }
        WHEN("GetAddress")
        {
            THEN("Vector contains Gdańsk")
            {
                auto Address0 = students[1];
                CHECK(Address0->GetAddress() == "Gdańsk");
            }
        }
        WHEN("GetID")
        {
            THEN("Vector contains 144")
            {
                auto ID0 = students[0];
                CHECK(ID0->GetID() == 144);
            }
        }
        WHEN("GetIndex")
        {
            THEN("Vector contains 2145")
            {
                auto Index0 = students[0];
                CHECK(Index0->GetIndex() == 2145);
            }
        }
        WHEN("GetGender")
        {
            THEN("Vector contains Gender")
            {
                auto Gender0 = students[0];
                auto Gender1 = students[1];
                CHECK(Gender0->GetGenderInString() == "Dziewczyna");
                CHECK(Gender1->GetGenderInString() == "Chłopak");
            }
        }
    }
}
