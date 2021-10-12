#include "universityPerson.hpp"

void UniversityPerson::Print()
{
    std::cout << "Imie: " << name_ << " Nazwisko: " << surname_ << " PESEL: " << ID_ << " Płeć: " << GetGenderInString() << " adres: " << address_;
    std::cout << '\n';
}

UniversityPerson::UniversityPerson(std::string name, std::string surname, std::string adr, int id, Gender gender)
    : name_(name), surname_(surname), address_(adr), ID_(id), gender_(gender) {}

std::string UniversityPerson::GetGenderInString()
{
    switch (gender_)
    {
    case Gender::Male:
        return "Chłopak";
        break;
    case Gender::Female:
        return "Dziewczyna";
        break;
    case Gender::Other:
        return "Other";
        break;
    default:
        return "";
        break;
    }
}
/* Fruit::Fruit(const std::string &name, size_t amount, size_t basePrice,  Time *time, size_t expiry_date, size_t time_elapsed)
        : Cargo(name, amount, basePrice, time)
        , time_elapsed_(time_elapsed)
        , expiry_date_(expiry_date)
        {}
    */