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
    void GetAllStudentsWithSurname(std::vector<Student *> &foundStudents, const std::string &searchingSurname); 
    Student *GetStudentViaID(const int &searchingID); 
    void SortStudentsSurnames(std::vector<Student *> &sortSurnames);
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
    inline bool operator()(Student *s1, Student *s2)
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
