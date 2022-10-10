#ifndef PARSER_H
#define PARSER_H
#include <sstream>
#include "Admin.h"

class Parser
{
public:
    static vector<string> split(string line)
    {
        stringstream st(line);
        string s;
        vector <string> info ;
        while(getline(st, s, '|'))
        {
            info.push_back(s);
        }
        return info;
    }

    static Client parseToClient(string line)
    {
        vector <string> info = split(line);
        Client c;
        c.setId(stoi(info[0]));
        c.setName(info[1]);
        c.setPassword(info[2]);
        c.setBalance(stoi(info[3]));
        return c;
    }
    static Employee parseToEmployee(string line)
    {
        vector<string> info = split(line);
        Employee e;
        e.setId(stoi(info[0]));
        e.setName(info[1]);
        e.setPassword(info[2]);
        e.setSalary(stod(info[3]));
        return e;
    }
    static Admin parseToAdmin(string line)
    {
        vector<string> info = split(line);
        Admin a;
        a.setId(stoi(info[0]));
        a.setName(info[1]);
        a.setPassword(info[2]);
        a.setSalary(stoi(info[3]));
        return a;
    }
};

#endif // PARSER_H
