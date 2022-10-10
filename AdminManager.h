#ifndef ADMINMANAGER_H
#define ADMINMANAGER_H
#include "EmployeeManager.h"

class AdminManager
{
public:
    static void printAdminMenu()
    {
        system("cls");
        cout << "1 - Display my info. \n";
        cout << "2 - Update Password. \n";
        cout << "3 - Add new client. \n";
        cout << "4 - Search for client. \n";
        cout << "5 - List all clients. \n";
        cout << "6 - Edit client info. \n";
        cout << "7 - Add new Employee. \n";
        cout << "8 - Search for Employee. \n";
        cout << "9 - List all Employees. \n";
        cout << "10 - Edit Employee info. \n";
        cout << "11 - Logout\n";
    }
    static void newClient(Admin* admin)
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
        admin->addClient(client);
        //FileManager::updateClients();
        cout << "\n Client added! \n";
    }
    static void listAllClients(Admin* admin)
    {
        system("cls");
        cout << "All clients: \n";
        admin->listClient();
    }
    static void searchForClient(Admin* admin)
    {
        int id;
        system("cls");
        cout << "Enter client id: ";
        cin >> id;
        if (admin->searchClient(id) == NULL)
        {
            cout << "\nClient not found !!\n";
        }
        else
        {
            admin->searchClient(id)->display();
        }
    }
    static void editClientInfo(Admin* admin)
    {
        int id;
        system("cls");
        cout << "Enter client id: ";
        cin >> id;
        if (admin->searchClient(id) == NULL)
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
            admin->editClient(id, name, password, balance);
            cout << "\nClient info updated!\n";
        }

    }
    static void back(Admin* admin)
    {
        cout << endl;
        system("pause");
        AdminOptions(admin);
    }
    static Admin* login(int id, string password)
    {
        static vector<Admin>::iterator ia;
        for(ia = allAdmins.begin(); ia != allAdmins.end(); ia++)
        {
            if(ia->getId() == id  && ia->getPassword() == password)
            {
                ia->display();
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
    static bool AdminOptions(Admin* admin)
    {
        printAdminMenu();
        string name, password;
        double salary;
        cout << "Enter your choice :";
        Employee e;
        int n, id;
        cin >> n;
        switch (n)
        {
        case 1:
            system("cls");
            admin->display();
            break;
        case 2:
            updatePassword(admin);
            //FileManager::updateAdmins();
            break;
        case 3:
            newClient(admin);
            break;
        case 4:
            searchForClient(admin);
            break;
        case 5:
            listAllClients(admin);
            break;
        case 6:
            editClientInfo(admin);
            break;
        case 7:
            cout << "Name : ";
            cin >> name;
            cout << "Password : ";
            cin >> password;
            cout << "Salary : ";
            cin >> salary;
            e.setName(name);
            e.setPassword(password);
            e.setSalary(salary);
            e.setId(FilesHelper::getLast("EmployeeId.txt") + 1);
            admin->addEmployee(e);
            //FileManager::updateEmployees();
            cout << "\nEmployee added successfully.\n";
            break;
        case 8:
            system("cls");
            cout << "Enter employee id: ";
            cin >> id;
            if (admin->searchEmployee(id) == NULL)
            {
                cout << "\nEmployee not found!!\n";
            }
            else
            {
                admin->searchEmployee(id)->display();
            }
        case 9:
            system("cls");
            cout << "All employees: \n" << endl;
            admin->listEmployee();
            break;
        case 10:
            system("cls");
            cout << "Enter employee id: ";
            cin >> id;
            if (admin->searchEmployee(id) == NULL)
            {
                cout << "\nEmployee not found !!\n";
            }
            else
            {
                string name;
                string  password;
                double salary;
                cout << "Name : ";
                cin >> name;
                cout << "Password : ";
                cin >> password;
                cout << "Salary : ";
                cin >> salary;
                admin->editEmployee(id, name, password, salary);
                //FileManager::updateEmployees();
                cout << "\nEmployee info updated.\n";
            }
            break;
        case 11:
            return false;
            break;
        default:
            system("cls");
            AdminOptions(admin);
            return true;
        }
        back(admin);
        return true;
    }

};

#endif // ADMINMANAGER_H
