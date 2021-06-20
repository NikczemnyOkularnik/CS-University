#include "class.hpp"
#include <iostream>



std::ostream &operator<<(std::ostream &out, const Student &feature)
{
    out << feature.name_ << " " << feature.surname_ << "," << feature.address_ << "," << feature.index_ << "," << feature.ID_ << "," << feature.gender_ << std::endl;
    return out;
}

/*void printDataBase(std::vector(Student)& vec){
    if () > 0)
    {
        for (auto &el : vec)
        {
            std::cout << el;
        }
    }
    else
    {
        std::cout << "DataBase is empty!";
    }
}*/
