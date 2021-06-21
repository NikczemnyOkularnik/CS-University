#include "database.hpp"
#include <algorithm>
#include <iostream>

void DataBase::add_student(Student *St)
{
    students.push_back(St);
}

void DataBase::list_student()
{
    for (Student *s : students)
    {
        s->Print();
        std::cout << "\n";
    }
}

void DataBase::GetAllStudentsWithSurname(std::vector<Student *> &foundStudents, const std::string &searchingSurname)
{
    for (Student *s : students)
    {
        if (s->GetSurname().compare(searchingSurname) == 0)
        {
            foundStudents.push_back(s);
        }
    }
}

Student *DataBase::GetStudentViaID(const int &searchingID)
{
    for (Student *s : students)
    {
        if (s->GetID() == searchingID)
        {
            return s;
        }
    }
    std::cout << "No students with ID = " << searchingID;
    return nullptr;
}

void DataBase::SortStudentsSurnames(std::vector<Student *> &sortSurnames)
{
    std::cout << "przed sortowaniem " << "\n";

    for (Student *s : students)
    {
        sortSurnames.push_back(s);
        s->Print();
        std::cout << "\n";
    }
    std::sort(sortSurnames.begin(), sortSurnames.end(), sortSurnamesComparator());

    std::cout << "po sortowaniu: " << "\n";
    std::cout << "Size = " << sortSurnames.size() << "\n";

    for (auto i : sortSurnames)
    {
        i->Print();
        std::cout << "\n";
    }
}

void DataBase::SortStudentsID(std::vector<Student *> &sortID)
{
    std::cout << "przed sortowaniem: " << "\n";
    for (Student *s : students)
    {
        sortID.push_back(s);
        s->Print();
        std::cout << "\n";
    }

    std::sort(sortID.begin(), sortID.end(), sortIDComparator());
    
    std::cout << "po sortowaniu: " << "\n";
    for(auto i :sortID)
    {
        i->Print();
        std::cout << "\n";
    }
}

void DataBase::DeleteByIndex(int deleteIndex)
{
    for(int i = 0; i < students.size(); i++)
    {
        if(students[i]->GetIndex() == deleteIndex)
        {
            students.erase(students.begin() + i);
        }
    }
}