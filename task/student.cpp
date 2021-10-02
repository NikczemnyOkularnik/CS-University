#include "student.hpp"

Student::Student(std::string name, std::string surname, std::string adr, int id, Gender gender, int index)
        : UniversityPerson(name, surname, adr, id, gender)
        , index_(index) {}

void Student::Print() {
    std::cout << "Imie: " << name_ << " Nazwisko: " << surname_ << " PESEL: " << ID_ << " Płeć: " << GetGenderInString()  << " adres: " << address_ << " index: " << index_;
}


