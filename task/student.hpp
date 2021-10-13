#pragma once
#include "universityPerson.hpp"

class Student : public UniversityPerson
{
public:
    int GetIndex() override { return index_; }
    void SetIndex(const int &index) { index_ = index; }

    //ustawiam konstruktor klasy Person
    Student(std::string name, std::string surname, std::string adr, int id, Gender gender, int index);
    void Print() override;
    PersonType GetPersonType() override { return PersonType::Student; };
};
