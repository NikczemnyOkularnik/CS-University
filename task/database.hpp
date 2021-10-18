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
    void add_student(std::unique_ptr<Student>&);
    void add_worker(std::unique_ptr<Worker>&);
    size_t getDbSize(){return person.size();}
    void show_database();
    void show_students();
    void show_workers();
    void GetStudentsWithSurname(const std::string &searchingSurname); 
    std::unique_ptr<UniversityPerson> GetStudentViaID(const int &searchingID); 
    void SortSurnames();
    void SortSalary();
    void SortStudentsID(std::vector<Student *> &sortID);
    void DeleteByIndex(int);
    void ID(int);
    size_t GetVectorSize();
    ~DataBase();
    //std::unique_ptr<UniversityPerson> p1 = std::make_unique<Student>;
    //std::unique_ptr<UniversityPerson> p2 = std::make_unique<Worker>;

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
    inline bool operator()(Student *s1, Student *s2)
    {
        return (s1->GetID() < s2->GetID());
    }
};
