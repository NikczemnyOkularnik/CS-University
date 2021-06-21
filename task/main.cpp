#include <iostream>
#include "database.hpp"
#include "student.hpp"
#include <vector>

void ShowVector(const vector<Student*>& vec){
    for(Student* s : vec){
        s->Print();
        std::cout<<"\n";
    }
}

int main() {
    DataBase* db = new DataBase();

    Student* s = new Student("Stanisław", "Nowak", "Warszawa", 1, 215, Gender::Male);
    Student* s1 = new Student("Kasia", "Nowak", "Warszawa", 12, 2145, Gender::Female);
    Student* s2 = new Student("Zuza", "Kowalska", "Wrocław", 144, 2115, Gender::Female);
    Student* s3 = new Student("Michał", "Bąk", "Kraków", 1, 415, Gender::Male);
    Student* s4 = new Student("Stasiu", "Bąk", "Kraków", 1, 515, Gender::Male);

    db->add_student(s);
    db->add_student(s1);
    db->add_student(s2);
    db->add_student(s3);
    db->add_student(s4);

    db->list_student();

    std::vector<Student*> studentsWithSameSurname;
    db->GetAllStudentsWithSurname(studentsWithSameSurname, "Nowak");
    ShowVector(studentsWithSameSurname);

    db->GetAllStudentsWithSurname(studentsWithSameSurname, "Kowalska");
    ShowVector(studentsWithSameSurname);

    Student* test = db->GetStudentViaID(215);
    test->Print();
    std::cout<<"\n";

    test = db->GetStudentViaID(515);
    test->Print();
    std::cout<<"\n";

    return 0;
}