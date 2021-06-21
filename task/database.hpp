#pragma once
#include <vector>

class Student;

class DataBase {
    std::vector<Student*> students;

public:
    void add_student(Student* St);

    void list_student();

    void GetAllStudentsWithSurname(std::vector<Student*>& foundStudents, const std::string& searchingSurname);//

    Student* GetStudentViaID(const int& searchingID);//
};
