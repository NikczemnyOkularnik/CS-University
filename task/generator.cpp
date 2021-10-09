#include "generator.hpp"
#include <stdlib.h>
#include <time.h>
#include "student.hpp"
#include "worker.hpp"

void Generator::GeneratePersonel(int NumberOfStudentsToGenerate, int NumberOfWorkersToGenerate, std::vector<std::unique_ptr<UniversityPerson>>& person) {
    srand(time(NULL));

    int nameRandId = rand() % NAMES_SIZE;
    int surnameRandId = rand() % SURNAMES_SIZE;
    int addressRandId = rand() % ADDRESSES_SIZE;

    for (int i = 0; i < NumberOfStudentsToGenerate; i++) {
        Student* s = new Student(names_[nameRandId], surnames_[surnameRandId], adresses_[addressRandId], i, i % 2 == 0 ? Gender::Female : Gender::Male, i);
        person.emplace_back(s);
    }
    for (int i = 0; i < NumberOfWorkersToGenerate; i++) {
        Worker* w = new Worker(names_[nameRandId], surnames_[surnameRandId], adresses_[addressRandId], i, i % 2 == 0 ? Gender::Female : Gender::Male, i);
        person.emplace_back(w);
    }
}