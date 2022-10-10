#ifndef CLIENT_H
#define CLIENT_H

#include "Person.h"
#include "Validation.h"
#include <vector>
#include <iterator>
class Client : public Person
{
protected:
    double Balance;
public:
    Client() :Person()
    {
        setBalance(1500);
    }
    Client(int id, string name, string password, double balance) : Person(id, name, password)
    {
        setBalance(balance);
    }
    void setBalance(int balance)
    {
        if (Validation::setBalance(balance))
            Balance += balance;
        else
        {
            cout << "you must enter balance more than 1500\n";
            //exit(0);
        }
    }
    double getBalance()
    {
        return Balance;
    }
    void deposit(double amount)
    {

        Balance += amount;
    }
    void withdraw(double amount)
    {

        if (Balance - amount >= 1500)
            Balance -= amount;
        else
        {
            cout << "you can't withdraw amount less than 1500\n";
            //exit(0);
        }
    }
    void transferTo(double amount, Client& recipient)
    {
        if (Balance > amount)
        {
            Balance = Balance - amount;
            recipient.Balance += amount;
        }
        else
        {
            cout << "Sorry Transfer failed " << '\n';
        }
    }
    void checkBalance()
    {
        if (Balance > 1500)
        {
            cout << " you can withdraw and transferto\n";
        }
        else
            cout << " you can't withdraw and transferto\n";
    }

    void display()
    {
        Person::Display();
        cout << "Balance : " << getBalance() << '\n';
    }

};
static vector<Client> allClients;
static vector<Client>::iterator ic;
#endif // CLIENT_H
