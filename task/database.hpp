#pragma once
#include <vector>
#include <string>
#include <memory>
#include "student.hpp"
#include "worker.hpp"

class DataBase
{
    std::vector<std::unique_ptr<UniversityPerson>> person; 
public:
    std::vector<std::unique_ptr<UniversityPerson>> GetDbVector() {return person;}
    void add_student(std::unique_ptr<Student>&);
    void add_worker(std::unique_ptr<Worker>&);
    void show_database();
    void show_students();
    void show_workers();
    void earning_modification(int, int); 
    void GetStudentsWithSurname(const std::string &searchingSurname); 
    void GetStudentViaID(bool& found, const int& searchingID, std::unique_ptr<UniversityPerson>& resultPerson);
    void SortSurnames();
    void SortSalary();
    void SortID();
    void DeleteByIndex(int);
    void ID(int);
    bool CheckID(int);
    size_t getDbSize(){return person.size();}
    void GetDBCapacity();
    DataBase();
    ~DataBase();

};
struct sortSurnamesComparator
{
    inline bool operator()(std::unique_ptr<UniversityPerson> & s1, std::unique_ptr<UniversityPerson> & s2)
    {
        return (s1->GetSurname() < s2->GetSurname());
    }
};
struct sortIDComparator
{
    inline bool operator()(std::unique_ptr<UniversityPerson> & s1, std::unique_ptr<UniversityPerson> & s2)
    {
        return (s1->GetID() < s2->GetID());
    }
};
