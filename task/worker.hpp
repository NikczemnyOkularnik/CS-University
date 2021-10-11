#pragma once
#include "universityPerson.hpp"

class Worker : public UniversityPerson
{
    size_t money_;

    public:
    int GetMoney() {return money_;}
    void SetMoney(size_t & money);

    Worker(std::string name, std::string surname, std::string adr, int id, Gender gender, size_t money);

    void Print() override;
};