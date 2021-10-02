#include "worker.hpp"

Worker::Worker(std::string name, std::string surname, std::string adr, int id, Gender gender, size_t money)
:   UniversityPerson(name, surname, adr, id, gender),
    money_(money){}


void Worker::Print() {
    std::cout << "Imie: " << name_ << " Nazwisko: " << surname_ << " PESEL: " << ID_ << " Płeć: " << GetGenderInString()  << " adres: " << address_ << " money: " << money_;
}
