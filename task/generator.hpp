#pragma once
#include <memory>
#include <string>
#include <vector>

class UniversityPerson;

class Generator {
public:
    void GeneratePersonel(int NumberOfStudentsToGenerate, int NumberOfWorkersToGenerate, std::vector<std::unique_ptr<UniversityPerson>>& person);

private:
    static constexpr int NAMES_SIZE = 27;
    static constexpr int SURNAMES_SIZE = 28;
    static constexpr int ADDRESSES_SIZE = 26;

    const std::string names_[NAMES_SIZE] = {"Harry","Ross",
                        "Bruce","Cook",
                        "Carolyn","Morgan",
                        "Albert","Walker",
                        "Randy","Reed",
                        "Larry","Barnes",
                        "Lois","Wilson",
                        "Jesse","Campbell",
                        "Ernest","Rogers",
                        "Theresa","Patterson",
                        "Henry","Simmons",
                        "Michelle","Perry",
                        "Frank","Butler",
                        "Shirley"};
    const std::string surnames_[SURNAMES_SIZE] = {"Ruth","Jackson",
                    "Debra","Allen",
                    "Gerald","Harris",
                    "Raymond","Carter",
                    "Jacqueline","Torres",
                    "Joseph","Nelson",
                    "Carlos","Sanchez",
                    "Ralph","Clark",
                    "Jean","Alexander",
                    "Stephen","Roberts",
                    "Eric","Long",
                    "Amanda","Scott",
                    "Teresa","Diaz",
                    "Wanda","Thomas"};
    const std::string adresses_[ADDRESSES_SIZE] = {"Kwiatkowa 12/3", "Borowska 14", 
                    "Ceglana 15a", "Drobiowa 18",
                    "Kwiatkowa 3", "Borowska 1", 
                    "Ceglana 15b", "Drobiowa 19",
                    "Kwiatkowa 66", "Borowska 6/3/3", 
                    "Ceglana 15c", "Drobiowa 20",
                    "Kwiatkowa 33/1", "Borowska 2", 
                    "Ceglana 12b", "Drobiowa 21",
                    "Kwiatkowa 14", "Borowska 3", 
                    "Ceglana 1b", "Drobiowa 22",
                    "Kwiatkowa 90", "Borowska 4", 
                    "Ceglana 15d", "Drobiowa 23",
                    "Elfia 6", "Figlarna 88"};
};
