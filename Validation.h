#ifndef VALIDATION_H
#define VALIDATION_H

#include <iostream>
#include<string>
using namespace std;
class Validation
{
public:
    static bool setName(string name)
    {
        bool flag = true;

        if (name.length() <= 20 && name.length() >= 5)
        {
            for (int i = 0; i < name.length(); i++)
            {
                if (!isalpha(name[i]))
                {
                    return false;
                }
            }
        }
        return flag;
    }
    static bool setPassword(string password)
    {
        if (password.length() <= 20 && password.length() >= 8)
            return true;
        else
            return false;
    }
    static bool setBalance(int balance)
    {
        if (balance < 1500)
            return false;
        else
            return true;
    }
    static bool setSalary(int salary)
    {
        if (salary >= 5000)
        {
            return true;
        }
        else
            return false;
    }
};

#endif // VALIDATION_H
