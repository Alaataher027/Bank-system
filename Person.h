#ifndef PERSON_H
#define PERSON_H

#include "Validation.h"
class Person: public Validation
{
protected:
    string Name, Password;
    int Id;
public:
    Person()
    {
        Name = " ";
        Password = " ";
        Id = 0;
    }
    Person(int id, string name, string password)
    {
        setName(name);
        setPassword(password);
        setId(id);
    }
    void setName(string name)
    {
        if (Validation::setName(name))
            Name = name;
        else if (name.length() < 5)
            cout << "Name must be greater than 5\n";
        else if (name.length() > 20)
            cout << " name must be smaller than 20 \n";
        else
            cout << "you have entered unvaild name\n";
    }
    void setPassword(string password)
    {
        if (Validation::setPassword(password))
        {
            Password = password;
        }
        else if (password.length() < 8)
            cout << "password must be greater than 8\n";
        else
            cout << " password must be smaller than 20 \n";
    }
    void setId(int id)
    {
        Id = id;
    }
    int getId()
    {
        return Id;
    }
    string getName()
    {
        return Name;
    }
    string getPassword()
    {
        return Password;
    }
    virtual void Display()
    {
        cout << "Id : " << getId() << '\n';
        cout << "Name : " << getName() << '\n';
        cout << "Password : " << getPassword() << '\n';
        cout << "=================================\n";
    }
};


#endif // PERSON_H
