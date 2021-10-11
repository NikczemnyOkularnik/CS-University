#pragma once
#include <iostream>
#include <string>
#include <vector>

enum class Gender {
    Male,
    Female,
    Other
};

class UniversityPerson {
protected:
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
    std::string GetGenderInString();//

    void SetName(const std::string& name) { name_ = name; }
    void SetSurname(const std::string& surname) { surname_ = surname; }
    void SetAddress(const std::string& address) { address_ = address; }
    void SetID(const int& ID) { ID_ = ID; }
    void SetGender(const Gender& gender) { gender_ = gender; }

    //ustawiam konstruktor klasy Person
    UniversityPerson(std::string name, std::string surname, std::string adr, int id, Gender gender);
     ~UniversityPerson(){};

    virtual void Print();
};

