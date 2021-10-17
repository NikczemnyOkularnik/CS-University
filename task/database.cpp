#include "database.hpp"
#include <algorithm>
#include <iostream>
#include <vector>
#include <typeinfo>

void DataBase::add_student(std::unique_ptr<Student> &St)
{
    person.emplace_back(std::move(St));
}
void DataBase::add_worker(std::unique_ptr<Worker> &Wr)
{
    person.emplace_back(std::move(Wr));
}

void DataBase::show_database()
{
    std::for_each(person.begin(), person.end(), [](std::unique_ptr<UniversityPerson> &s)
                  {
                      s->Print();
                      std::cout << '\n';
                  });
}
void DataBase::show_students()
{
    std::for_each(person.begin(), person.end(), [](std::unique_ptr<UniversityPerson> &s)
                  {
                      if (PersonType::Student == s->GetPersonType())
                      {
                          s->Print();
                          std::cout << '\n';
                      }
                  });
}
void DataBase::show_workers()
{
    std::for_each(person.begin(), person.end(), [](std::unique_ptr<UniversityPerson> &s)
                  {
                      if (PersonType::Worker == s->GetPersonType())
                      {
                          s->Print();
                          std::cout << '\n';
                      }
                  });
}
void DataBase::GetStudentsWithSurname(const std::string &searchingSurname)
{
    std::for_each(person.begin(), person.end(), [&](std::unique_ptr<UniversityPerson> &s)
                  {
                      if (PersonType::Student == s->GetPersonType())
                      {
                          if (s->GetSurname().compare(searchingSurname) == 0)
                          {
                              s->Print();
                              std::cout << '\n';
                          }
                      }
                  });
}

std::unique_ptr<UniversityPerson> DataBase::GetStudentViaID(const int &searchingID)
{
    std::for_each(person.begin(), person.end(), [&](std::unique_ptr<UniversityPerson> &s)
                  {
                      if (PersonType::Student == s->GetPersonType())
                      {
                          if (s->GetID() == searchingID)
                          {
                              std::cout << searchingID;
                              return &s;
                          }
                      }
                      //<----------------------------------------- What should we return here??
                  });
}

void DataBase::ID(int a)
{
    std::find_if(person.begin(), person.end(), [&](std::unique_ptr<UniversityPerson> &per) {
        if(per-> GetID() == a)
        {
            per->Print();
            return a;
        }
    });
    //std::vector<int> check;
    // for (auto &l : person)
    // {
    //     check.push_back(l->GetID());
    // }

    // std::cout << "\n";

    // for (auto k : check)
    // {
    //     if (k == a)
    //     {
    //         std::cout << "Istnieje student z podanym ID: " << a << "\n";
    //         auto test = GetStudentViaID(a);
    //         test->Print();
    //         return;
    //     }
    // }
    // std::cout << "Brak ID " << a << " w bazie danych. Obecne ID w bazie danych: "
    //           << "\n";

    // for (auto k : check)
    // {
    //     std::cout << k << ", ";
    // }
}

void DataBase::SortSurnames()
{
    std::cout << "Przed sortowaniem nazwisk: " << '\n';
    std::for_each(person.begin(), person.end(), [&](std::unique_ptr<UniversityPerson> &s)
                  {
                      s->Print();
                      std::cout << "\n";
                  });
    std::sort(person.begin(), person.end(), sortSurnamesComparator());
    std::cout << "\n";
    std::cout << "Po sortowaniu nazwisk: " << '\n';
    std::for_each(person.begin(), person.end(), [&](std::unique_ptr<UniversityPerson> &s)
                  {
                      s->Print();
                      std::cout << "\n";
                  });
}

// void DataBase::SortStudentsID(std::vector<Student *> &sortID)
// {
//     std::cout << "Przed sortowaniem ID: " << "\n";
//     std::for_each(sortID.begin(), sortID.end(), [&](std::unique_ptr<UniversityPerson> &s)
//                 {
//                     s->Print();
//                     std::cout << "\n";
//                 });

//     std::sort(sortID.begin(), sortID.end(), sortIDComparator());
//     std::cout << "\n";
//     std::cout << "Po sortowaniu ID: " << "\n";

//     std::for_each(sortID.begin(), sortID.end(), [&](std::unique_ptr<UniversityPerson> &s)
//     {
//         s->Print();
//         std::cout << "\n";
//     });
// }

//  void DataBase::DeleteByIndex(int deleteIndex)        //ONGOING
// {
//     int it = 0;
//     std::for_each(person.begin(), person.end(), [&](std::unique_ptr<UniversityPerson> & s)
//                     {
//                         if (PersonType::Student == s->GetPersonType())
//                         {
//                             if (s->GetIndex() == deleteIndex)
//                             {
//                                 person.erase(person.begin() + it);
//                                 //person.erase(std::distance(person.begin(), it));
//                             }
//                         }
//                         it++;
//                     });
// }

size_t DataBase::GetVectorSize()
{
    return person.size();
}
