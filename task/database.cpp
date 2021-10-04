#include "database.hpp"
#include <algorithm>
#include <iostream>
#include <vector>

void DataBase::add_student(Student *St)
{
    person.emplace_back(St);
}
void DataBase::add_worker(Worker *Wr)
{
    person.emplace_back(Wr);
}

void DataBase::list_student() //do poprawy
{
    for (auto s : person)
    {
        s->Print();
        std::cout << "\n";
    }
    // std::for_each(person.begin(), person.end(), [](auto s){ s.Print(); })
}

void DataBase::GetAllStudentsWithSurname(std::vector<Student *> &foundStudents, const std::string &searchingSurname) //popr
{
    for (Student *s : person)
    {
        if (s->GetSurname().compare(searchingSurname) == 0)
        {
            foundStudents.push_back(s);
        }
    }
}

Student *DataBase::GetStudentViaID(const int &searchingID)
{
    for (Student *s : person)
    {
        if (s->GetID() == searchingID)
        {
            return s;
        }
    }
    return nullptr;
}

void DataBase::ID(int a)
{
    std::vector<int> check;

    for (auto l : person)
    {
        check.push_back(l->GetID());
    }

    std::cout << "\n";

    for (auto k : check)
    {
        if (k == a)
        {
            std::cout << "Istnieje student z podanym ID: " << a << "\n";
            Student *test = GetStudentViaID(a);
            test->Print();
            return;
        }
    }
    std::cout << "Brak ID " << a << " w bazie danych. Obecne ID w bazie danych: " << "\n";

    for (auto k : check)
    {
       std::cout << k << ", ";
    }

}

void DataBase::SortStudentsSurnames(std::vector<Student *> &sortSurnames)
{
    std::cout << "Przed sortowaniem nazwisk: " << "\n";

    for (Student *s : person)
    {
        sortSurnames.push_back(s);
        s->Print();
        std::cout << "\n";
    }
    std::sort(sortSurnames.begin(), sortSurnames.end(), sortSurnamesComparator());

    std::cout << "\n";
    std::cout << "Po sortowaniu nazwisk: " << "\n";

    for (auto i : sortSurnames)
    {
        i->Print();
        std::cout << "\n";
    }
}

void DataBase::SortStudentsID(std::vector<Student *> &sortID)
{
    std::cout << "Przed sortowaniem ID: " << "\n";

    for (Student *s : UniversityPerson)
    {
        sortID.push_back(s);
        s->Print();
        std::cout << "\n";
    }

    std::sort(sortID.begin(), sortID.end(), sortIDComparator());
    std::cout << "\n";
    std::cout << "Po sortowaniu ID: " << "\n";

    for (auto i : sortID)
    {
        i->Print();
        std::cout << "\n";
    }
}

void DataBase::DeleteByIndex(int deleteIndex)//poprawic
{
    for (size_t i = 0; i < person.size(); i++)
    {
        if (person[i]->GetIndex() == deleteIndex)
        {
            person.erase(person.begin() + i);
        }
    }
}
size_t DataBase::GetVectorSize()
{
    return person.size();
}

