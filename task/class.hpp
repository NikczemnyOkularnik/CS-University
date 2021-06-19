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
};

class Student : Person
{
    int index_;
};

class DataBase
{
    std::vector<Student> student;
};