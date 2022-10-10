#ifndef EMPLOYEEMANAGER_H
#define EMPLOYEEMANAGER_H

#include "ClientManger.h"
#include "FileManager.h"
class EmployeeManager
{
public:
    static void printEmployeeMenu()
    {
        system("cls");
        cout << "1 - Display my info.\n" ;
        cout << "2 - Update Password.\n" ;
        cout << "3 - Add new client.\n" ;
        cout << "4 - Search for client.\n" ;
        cout << "5 - List all clients.\n" ;
        cout << "6 - Edit client info.\n" ;
        cout << "7 - Logout. \n";

    }
    static void back(Employee* e)
    {
        cout << endl;
        system("pause");
        employeeOptions(e);
    }
    static void newClient(Employee* employee)
    {
        string name, password;
        double balance;
        cout << "Name : ";
        cin >> name;
        cout << "Password : ";
        cin >> password;
        cout << "Balance : ";
        cin >> balance;
        Client client;
        client.setId(FilesHelper::getLast("ClientId.txt") + 1);
        client.setName(name);
        client.setPassword(password);
        client.setBalance(balance);
        employee->addClient(client);
        //FileManager::updateClients();
        cout << "\n Client added! \n";
    }
    static void listAllClients(Employee* employee)
    {
        system("cls");
        cout << "All clients: \n";
        employee->listClient();
    }
    static void searchForClient(Employee* employee)
    {
        int id;
        system("cls");
        cout << "Enter client id: ";
        cin >> id;
        if (employee->searchClient(id) == NULL)
        {
            cout << "\nClient not found !!\n";
        }
        else
        {
            employee->searchClient(id)->display();
        }
    }
    static void editClientInfo(Employee* employee)
    {
        int id;
        system("cls");
        cout << "Enter client id: ";
        cin >> id;
        if (employee->searchClient(id) == NULL)
        {
            cout << "\nClient not found !!\n";
        }
        else
        {
            string name, password;
            double balance;
            cout << "Name : ";
            cin >> name;
            cout << "Password : ";
            cin >> password;
            cout << "Balance : ";
            cin >> balance;
            employee->editClient(id, name, password, balance);
            cout << "\nClient info updated!\n";
        }

    }
    static Employee* login(int id, string password)
    {
        static vector<Employee>::iterator i1;
        for(i1 = allEmployees.begin(); i1 != allEmployees.end(); i1++)
        {
            if(i1->getId() == id  && i1->getPassword() == password)
            {
                i1->display();
            }
        }
    }
    static void updatePassword(Person* person)
    {
        string password;
        cout<<"Enter Password ";
        cin>>password;
        if (Validation::setPassword(password))
        {
            person->setPassword(password);
            cout << "\n Password updated !\n";
        }
        else
        {
            updatePassword(person);
        }
    }
    static bool employeeOptions(Employee* employee)
    {
        printEmployeeMenu();
        cout << "Your choice is: ";
        int n;
        cin >> n;
        switch (n)
        {
        case 1:
            system("cls");
            employee->display();
            break;
        case 2:
            updatePassword(employee);
            //FileManager::updateEmployees();
            break;
        case 3:
            newClient(employee);
            break;
        case 4:
            searchForClient(employee);
            break;
        case 5:
            listAllClients(employee);
            break;
        case 6:
            editClientInfo(employee);
            break;
        case 7:
            return false;
            break;
        default:
            system("cls");
            employeeOptions(employee);
            return true;

        }
        back(employee);
        return true;
    }
};

#endif // EMPLOYEEMANAGER_H
