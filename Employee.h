#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include "Client.h"
#include <vector>
class Employee : public Person
{
protected:
    double Salary;
public:
    Employee() : Person()
    {
        Salary = 5000;
    }
    Employee(int id, string name, string password, double salary) : Person(id, name, password)
    {
        Salary = salary;
    }
    void setSalary(double salary)
    {
        if (Validation::setSalary)
        {
            Salary = salary;
        }
        else
            cout << "Min salary is 5000 !\n";
        //exit(0);
    }
    double getSalary()
    {
        return Salary;
    }
    void display()
    {
        Person::Display();
        cout << "Salary : " << getSalary() << '\n';

    }
    vector<Client> allClients;
    static vector<Client>::iterator i;

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
            cout<<"======================/n";
        }
    }
    void editClient(int id, string name, string password, double balance)
    {
        searchClient(id)-> setName(name);
        searchClient(id)->setPassword(password);
        searchClient(id)->setBalance(balance);
    }
};
static vector<Employee> allEmployees;
static vector<Employee>::iterator ie;
#endif // EMPLOYEE_H
