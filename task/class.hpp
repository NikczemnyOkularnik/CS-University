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
};

class Student : public Person
{
    int index_;

public:
    int GetIndex() { return index_; }
};

class DataBase
{
    std::vector<Student> student;
};