#include "database.hpp"
#include "generator.hpp"
#include <algorithm>
#include <iostream>
#include <vector>
#include <typeinfo>
DataBase::DataBase()
{
    // Generator *g = new Generator();
    // g->GeneratePersonel(30, 5, person);
}
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

std::ptrdiff_t DataBase::GetStudentViaID(const int &searchingID)
{
    auto student_to_find = std::find_if(person.begin(), person.end(), [&](std::unique_ptr<UniversityPerson> & s)
                                        { return (s->GetID() == searchingID); });

    auto personPosition = std::distance(person.begin(), student_to_find);
    std::cout << person[personPosition] -> GetID();
    return personPosition;

}

void DataBase::ID(int a)
{
    auto IDCheck = std::find_if(person.begin(), person.end(), [&](std::unique_ptr<UniversityPerson> &per)
                                {
                                    if (per->GetID() == a)
                                    {
                                        std::cout << "Istnieje student z podanym ID: " << a << "\n";
                                        per->Print();
                                    }
                                    return (per->GetID() == a);
                                });

    if (IDCheck == person.end())
    {
        std::cout << '\n';
        std::cout << "Brak ID " << a << " w bazie danych. Obecne ID w bazie danych: " << '\n';
        show_students();
    }
}
bool DataBase::CheckID(int ID)
{
    auto position = std::find_if(person.begin(), person.end(), [&](std::unique_ptr<UniversityPerson> &per)
                                 { return (per->GetID() == ID); });

    auto IDposition = std::distance(person.begin(), position);
    if(position == person.end())
    {
        return false;
    }
    else
    {
        return (person[IDposition]->GetID() == ID);
    }
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
void DataBase::SortSalary()
{
    std::cout << "Przed sortowaniem pieniążka: "
              << "\n";
    std::for_each(person.begin(), person.end(), [&](std::unique_ptr<UniversityPerson> &s)
                  {
                      s->Print();
                      std::cout << "\n";
                  });
    std::cout << '\n';
    std::cout << "Po sortowaniu pieniążka: "
              << '\n';
    std::sort(person.begin(), person.end(), [&](std::unique_ptr<UniversityPerson> &s, std::unique_ptr<UniversityPerson> &w)
              { return (s->GetMoney() > w->GetMoney()); });
    std::for_each(person.begin(), person.end(), [&](std::unique_ptr<UniversityPerson> &s)
                  {
                      s->Print();
                      std::cout << "\n";
                  });
}

void DataBase::SortID()
{
    std::cout << "Przed sortowaniem ID: "
              << "\n";
    std::for_each(person.begin(), person.end(), [&](std::unique_ptr<UniversityPerson> &s)
                  {
                      s->Print();
                      std::cout << "\n";
                  });
    std::cout << "\n";
    std::cout << "Po sortowaniu ID: "
              << "\n";
    std::sort(person.begin(), person.end(), sortIDComparator());

    std::for_each(person.begin(), person.end(), [&](std::unique_ptr<UniversityPerson> &s)
                  {
                      s->Print();
                      std::cout << "\n";
                  });
}

void DataBase::DeleteByIndex(int deleteIndex)
{
    auto index_to_delete = std::find_if(person.begin(), person.end(), [&](std::unique_ptr<UniversityPerson> &s)
                                        { return (s->GetIndex() == deleteIndex); });
    if (index_to_delete != person.end())
    {
        person.erase(index_to_delete);
        person.shrink_to_fit();
    }
}
size_t DataBase::getDbSize() 
{ 
    return person.size(); 
}
size_t DataBase::GetDBCapacity()
{
    return person.capacity();
}

void DataBase::earning_modification(const int ID, const int newSalary)
{
    auto personEarning = std::find_if(person.begin(), person.end(), [&](std::unique_ptr<UniversityPerson> &s)
                                      { return (s->GetID() == ID); });

    auto personPosition = std::distance(person.begin(), personEarning);
    if (person[personPosition]->GetPersonType() == PersonType::Worker)
    {
        person[personPosition]->SetMoney(newSalary);
    }
}