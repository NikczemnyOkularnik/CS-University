#include <iostream>
#include "universityPerson.hpp"
#include "database.hpp"
#include "worker.hpp"
#include "student.hpp"
#include "generator.hpp"
#include <vector>
#include <memory>
/*
void ShowVector(const std::vector<Student *> &vec)
{
    for (Student *s : vec)
    {
        s->Print();
        std::cout << "\n";
    }
}

int main()
{
    DataBase *db = new DataBase();

    Student *s = new Student("Stanisław", "Nowak", "Warszawa", 1, 215, Gender::Male);
    Student *s1 = new Student("Kasia", "Nowak", "Warszawa", 12, 2145, Gender::Female);
    Student *s2 = new Student("Zuza", "Kowalska", "Wrocław", 144, 2115, Gender::Female);
    Student *s3 = new Student("Michał", "Bąk", "Kraków", 14, 415, Gender::Male);
    Student *s4 = new Student("Stasiu", "Bąk", "Kraków", 13, 515, Gender::Male);
    Student *s5 = new Student("Zatasiu", "ABąk", "Kraków", 19, 304, Gender::Male);

    db->add_student(s);
    db->add_student(s1);
    db->add_student(s2);
    db->add_student(s3);
    db->add_student(s4);
    db->add_student(s5);


    std::cout << "Wyświetl studentów po dodaniu: " << "\n";
    db->list_student();
    std::cout << "\n\n";

    std::vector<Student *> studentsWithSameSurname;
    db->GetAllStudentsWithSurname(studentsWithSameSurname, "Nowak");
    std::cout << "Wyświetl studentów o nazwisku Nowak" << "\n";
    ShowVector(studentsWithSameSurname);
    std::cout << "\n";

    std::vector<Student *> studentsWithSameSurname2;
    db->GetAllStudentsWithSurname(studentsWithSameSurname2, "Kowalska");
    std::cout << "Wyświetl studentów o nazwisku Kowalska" << "\n";
    ShowVector(studentsWithSameSurname2);
    std::cout << "\n";

    std::cout << "Wyświetl studentów z podanym ID"
              << "\n";
    db->ID(1);
    std::cout << "\n";
    db->ID(2);
    std::cout << "\n";
    db->ID(19);
    std::cout << "\n\n";

    std::vector<Student *> studentsSortedSurnames;
    db->SortStudentsSurnames(studentsSortedSurnames);
    std::cout << "\n";

    std::vector<Student *> studentsSortedID;
    db->SortStudentsID(studentsSortedID);
    std::cout << "\n";

    std::cout << "Wyświetl studentów przed usuwaniem" << "\n";
    db->list_student();
    db->DeleteByIndex(415);
    std::cout << "\n";

    std::cout << "Wyświetl studentów po usuwaniu" << "\n";
    db->list_student();
    std::cout << "\n";
    
    return 0;
}
*/

int main()
{
    // DataBase *db = new DataBase();
    // Generator* g = new Generator();
    // //std::vector<std::unique_ptr<UniversityPerson>> person;

    // g->GeneratePersonel(10, 2, db->person);

    DataBase *db = new DataBase();
    auto student1 = std::make_unique<Student>("Stanisław", "ANowak", "Warszawa", 1, Gender::Male, 215);
    auto student2 = std::make_unique<Student>("Stanisław", "VNowak", "Warszawa", 1, Gender::Male, 214);
    auto student3 = std::make_unique<Student>("Grzegorz", "Kwak", "Warszawa", 2, Gender::Male, 216);
    auto worker1 = std::make_unique<Worker>("Stasiu", "CNowak", "kwik", 15, Gender::Male, 2300);
    auto worker2 = std::make_unique<Worker>("Stasiu", "CNowak", "kwik", 15, Gender::Male, 2500);
    auto worker3 = std::make_unique<Worker>("Stasiu", "CNowak", "kwik", 15, Gender::Male, 2700);
    db->add_student(student1);
    db->add_student(student2);
    db->add_student(student3);
    db->add_worker(worker1);
    db->add_worker(worker2);
    db->add_worker(worker3);

    db->SortSalary();

    return (0);
}