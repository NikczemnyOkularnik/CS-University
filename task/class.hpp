#pragma once
#include <iostream>
#include <string>
#include <vector>

enum class Gender
{
    Male,
    Female
};

class Person
{
    std::string name_;
    std::string surname_;
    std::string address_;
    int ID_;
    Gender gender_;

public:
    std::string GetName() { return name_; }
    std::string GetSurname() { return surname_; }
    std::string GetAddress() { return address_; }
    int GetID() { return ID_; }
    Gender GetGender() { return gender_; }
    //ustawiam konstruktor klasy Person
    Person (std::string name, std::string surname, std::string adr, int id, Gender)
        : name_(name)
        , surname_(surname)
        , address_(adr)
        , gender_(Gender::Male)
    {}
};

class Student : public Person
{
    int index_;

public:
    int GetIndex() { return index_; }
};

class DataBase: public std::vector<Student>
{
    //inheritance from the vector class
    //std::vector<Student> student;
};

void add_student(Student & St);

void list_student();