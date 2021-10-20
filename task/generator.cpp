#include "generator.hpp"
#include <stdlib.h>
#include <time.h>
#include "student.hpp"
#include "worker.hpp"

void Generator::GeneratePersonel(int NumberOfStudentsToGenerate, int NumberOfWorkersToGenerate, std::vector<std::unique_ptr<UniversityPerson>>& person) {
    srand(time(NULL));

    int nameRandId;
    int surnameRandId;
    int addressRandId;

    for (int i = 0; i < NumberOfStudentsToGenerate; i++) {
		nameRandId = rand() % NAMES_SIZE;
    	surnameRandId = rand() % SURNAMES_SIZE;
    	addressRandId = rand() % ADDRESSES_SIZE;

        std::unique_ptr<Student> s = std::make_unique<Student>(names_[nameRandId], surnames_[surnameRandId], adresses_[addressRandId], i, i % 2 == 0 ? Gender::Female : Gender::Male, i);
        person.emplace_back(std::move(s));
    }
    for (int i = 0; i < NumberOfWorkersToGenerate; i++) {
		nameRandId = rand() % NAMES_SIZE;
    	surnameRandId = rand() % SURNAMES_SIZE;
    	addressRandId = rand() % ADDRESSES_SIZE;
		
        std::unique_ptr<Worker> w = std::make_unique<Worker>(names_[nameRandId], surnames_[surnameRandId], adresses_[addressRandId], i, i % 2 == 0 ? Gender::Female : Gender::Male, i);
        person.emplace_back(std::move(w));
    }
}