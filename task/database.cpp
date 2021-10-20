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

void DataBase::GetStudentViaID(bool& found, const int& searchingID, std::unique_ptr<UniversityPerson>& resultPerson)
{ 
	found = false;
 
	std::for_each(person.begin(), person.end(), [&](std::unique_ptr<UniversityPerson>& s)
		{
			if (PersonType::Student == s->GetPersonType())
			{
				if (s->GetID() == searchingID)
				{
					resultPerson = std::move(s);
					found = true;
					return;
				}
			}
		});
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
    std::cout << "Przed sortowaniem pieniążka";
    std::for_each(person.begin(), person.end(), [&](std::unique_ptr<UniversityPerson> &s)
                  {
                      s->Print();
                      std::cout << "\n";
                  });
    std::cout << '\n';
    std::cout << "Po sortowaniu pieniążka";
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
    std::cout << "Przed sortowaniem ID: " << "\n";
    std::for_each(person.begin(), person.end(), [&](std::unique_ptr<UniversityPerson> &s)
                {
                    s->Print();
                    std::cout << "\n";
                });
    std::cout << "\n";
    std::cout << "Po sortowaniu ID: " << "\n";
    std::sort(person.begin(), person.end(), sortIDComparator());

    std::for_each(person.begin(), person.end(), [&](std::unique_ptr<UniversityPerson> &s)
                {
                    s->Print();
                    std::cout << "\n";
                });
}

 void DataBase::DeleteByIndex(int deleteIndex) 
{
    int it = 0;
    std::for_each(person.begin(), person.end(), [&](std::unique_ptr<UniversityPerson> & s)
                    {
                        if (PersonType::Student == s->GetPersonType())
                        {
                            if (s->GetIndex() == deleteIndex)
                            {
                                person.erase(person.begin() + it);
                                //person.erase(std::distance(person.begin(), it));
                            }
                        }
                        it++;
                    });
}

size_t DataBase::GetVectorSize()
{
    return person.size();
}
