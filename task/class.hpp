#pragma once
#include <iostream>
#include <string>
#include <vector>

#define GENDER   \
    etype(Male), \
        etype(Female)

#define etype(x) F_##x

typedef enum class { GENDER } Gender;
#undef etype
#define etype(x) #x

static const char *strGender[] = {GENDER};
const char *enum2str(Gender f)
{
    return strGender[static_cast<int>(f)];
}

class Student
{
    std::string name_;
    std::string surname_;
    std::string address_;
    int ID_;
    Gender gender_;
    int index_;

public:
    std::string GetName() { return name_; }
    std::string GetSurname() { return surname_; }
    std::string GetAddress() { return address_; }
    int GetID() { return ID_; }
    Gender GetGender() { return gender_; }
    int GetIndex() { return index_; }

    void SetName(const std::string& name) { name_ = name; }
    void SetSurname(const std::string& surname) { surname_ = surname; }
    void SetAddress(const std::string& address) { address_ = address; }
    void SetID(const int& ID) { ID_ = ID; }
    void SetGender(const Gender& gender) { gender_ = gender; }
    void SetIndex(const int& index) { index_ = index; }

    friend std::ostream &operator<<(std::ostream &out, const Student &person);
};

class DataBase
{
    std::vector<Student*> students;

public:
    void printDataBase(std::vector<Student*> &students);
};

