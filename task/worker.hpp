#pragma once
#include "universityPerson.hpp"

class Worker : public UniversityPerson
{
    public:
    int GetMoney() override {return money_;}
    void SetMoney(size_t & money);

    Worker(std::string name, std::string surname, std::string adr, int id, Gender gender, size_t money);
    PersonType GetPersonType() override {return PersonType::Worker;};

    void Print() override;
};