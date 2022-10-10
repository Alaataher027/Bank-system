#ifndef ADMIN_H
#define ADMIN_H

#include "Employee.h"
#include "Client.h"
#include "Person.h"
#include <vector>
class Admin : public Person
{
protected:
    double Salary;
public:
    Admin()
    {
        Salary = 5000;
    }
    Admin(int id, string name, string password, double salary) : Person(id, name, password)
    {
        Salary = salary;
    }
    void setSalary(int salary)
    {
        if (Validation::setSalary)
        {
            Salary = salary;
        }
        else
            cout << "Min salary is 5000 !\n";
        //exit(0);
    }
    int getSalary()
    {
        return Salary;
    }
    void display()
    {
        Person::Display();
        cout << "Salary : " << getSalary() << '\n';
    }


    void addClient(Client& client)
    {
        allClients.push_back(client);
    }

    Client* searchClient(int id)
    {

        for(ic = allClients.begin(); ic != allClients.end(); ic++)
        {
            if(ic-> getId() == id)
            {
                ic->display() ;
            }
        }
        return NULL;
    }
    void listClient()
    {
        for(ic = allClients.begin(); ic != allClients.end(); ic++)
        {
            ic->display() ;
            cout<<"======================\n";
        }
    }
    void editClient(int id, string name, string password, double balance)
    {
        searchClient(id)-> setName(name);
        searchClient(id)->setPassword(password);
        searchClient(id)->setBalance(balance);
    }
    void addEmployee(Employee& employee)
    {
        allEmployees.push_back(employee);
    }
    Employee* searchEmployee(int id)
    {
        for(ie = allEmployees.begin(); ie != allEmployees.end(); ie++)
        {
            if(ie->getId() == id)
            {
                ie->display();
            }
        }
        return NULL;
    }
    void editEmployee(int id, string name, string password, double salary)
    {
        searchEmployee(id)->setName(name);
        searchEmployee(id)->setPassword(password);
        searchEmployee(id)->setSalary(salary);
    }
    void listEmployee()
    {
        for(ie = allEmployees.begin(); ie != allEmployees.end(); ie++)
        {
            ie->display();
            cout<<"=======================\n";
        }
    }


};
static vector<Admin> allAdmins;
static vector<Admin>::iterator ia;
#endif // ADMIN_H
