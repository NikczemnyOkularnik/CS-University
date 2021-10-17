#pragma once
#include <iostream>
#include <string>
#include <vector>

enum class Gender {
    Male,
    Female,
    Other
};
enum class PersonType{
    UniversityPerson,
    Student,
    Worker
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
    virtual PersonType GetPersonType() {return PersonType::UniversityPerson;}
    std::string GetGenderInString();//  
    virtual int GetMoney() {return 0;}
    virtual int GetIndex() { return 0;}

    void SetName(const std::string& name) { name_ = name; }
    void SetSurname(const std::string& surname) { surname_ = surname; }
    void SetAddress(const std::string& address) { address_ = address; }
    void SetID(const int& ID) { ID_ = ID; }
    void SetGender(const Gender& gender) { gender_ = gender; }

    //ustawiam konstruktor klasy Person
    UniversityPerson(std::string name, std::string surname, std::string adr, int id, Gender gender);
    UniversityPerson(std::string name, std::string surname, std::string adr, int id, Gender gender, int index);
    UniversityPerson(std::string name, std::string surname, std::string adr, int id, Gender gender, size_t money);
     ~UniversityPerson(){};

    virtual void Print();
};

