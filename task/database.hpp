#pragma once
#include <vector>
#include <string>
#include "student.hpp"

class DataBase {
    std::vector<Student*> students;

public:
    void add_student(Student* St);

    void list_student();

    void GetAllStudentsWithSurname(std::vector<Student*>& foundStudents, const std::string& searchingSurname);//

    Student* GetStudentViaID(const int& searchingID);//

    void SortStudentsSurnames(std::vector<Student *> &sortSurnames);


};
struct sortSurnamesComparator
{
    inline bool operator() ( Student* struct1, Student* struct2)
    {
        return (struct1->GetSurname() < struct2->GetSurname());
    }
};
