#include <iostream>
#include "database.hpp"
#include "student.hpp"
#include <vector>

void ShowVector(const std::vector<Student*>& vec){
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
    Student* s3 = new Student("Michał", "Bąk", "Kraków", 14, 415, Gender::Male);
    Student* s4 = new Student("Stasiu", "Bąk", "Kraków", 13, 515, Gender::Male);

    db->add_student(s);
    db->add_student(s1);
    db->add_student(s2);
    db->add_student(s3);
    db->add_student(s4);

    std::cout << "Wyświetl studentów po dodaniu: " << "\n";
    db->list_student();
    std::cout <<"\n\n";

    std::vector<Student*> studentsWithSameSurname;
    db->GetAllStudentsWithSurname(studentsWithSameSurname, "Nowak");
    std::cout<< "Wyświetl studentów o nazwisku Nowak" << "\n";
    ShowVector(studentsWithSameSurname);

    std::vector<Student*> studentsWithSameSurname2;
    db->GetAllStudentsWithSurname(studentsWithSameSurname2, "Kowalska");
    std::cout<< "Wyświetl studentów o nazwisku Kowalska" << "\n";
    ShowVector(studentsWithSameSurname2);

    Student* test = db->GetStudentViaID(13);
    test->Print();
    std::cout<<"\n";

    test = db->GetStudentViaID(14);
    test->Print();
    std::cout<<"\n";

    return 0;
}