#ifndef SCREENS_H
#define SCREENS_H

#include <iostream>
#include <windows.h>
#include "AdminManager.h"
#include"FileManager.h"

using namespace std;

class Screens
{
public:
    static void bankName()
    {
        for(int i = 0; i < 12; i++)
        {
            cout<<"\n";
        }

        cout << "\t\t\t\t\t\t  Bank El-haz\n";
    }
    static void welcome()
    {
        system("Color 7c");
        bankName();
        Sleep(3000);
        system("cls");
        system("Color f0");
    }
    static void loginOptions()
    {
        cout<< "\t\t\t\t Login As\n";
        cout<< "1-Admin\n\n";
        cout<< "2-Employee\n\n";
        cout<< "3-Client\n\n";
        cout<< "4-Exit\n\n";
    }
    static int loginAs()
    {
        loginOptions();
        int n;
        cout<<"Login as: ";
        cin >> n;
        if (n == 1 || n == 2 || n == 3)
        {
            system("cls");
            return n;
        }
        else if(n == 4)
        {
            system("cls");
            system("Color 7c");
            cout<<"\n\n\n"<<"\t\t\t\t\tSystem Closed!\n\n";
            exit(0);
        }
        else
        {
            system("cls");
            return loginAs();
        }
    }
    static void invalid(int c)
    {
        system("cls");
        cout << "Incorrect id or password!!!\n" << endl;
        loginScreen(loginAs());
    }
    static void logout()
    {
        system("cls");
        loginScreen(loginAs());
    }

    static void LoginClient()
    {
        cout<<"\t\t\t\t\t\t Login Client Page \n";
        int id;
        string password;
        cout<<"Enter Id : ";
        cin>>id;
        cout<<"Enter Password :";
        cin>>password;
        Client* client = ClientManger::login(id, password);
        if(client != NULL)
        {
            ClientManger::printClientMenu();
            if(ClientManger::clientOptions(client))
            {
                system("cls");
                //name = client->getName();
                loginOptions();
                loginScreen(loginAs());
            }
        }
        else
        {
            cout<<"\n 1- Try again\n";
            cout<<"2 - Return\n";
            int x;
            cout<<"Enter your choise:";
            cin>>x;
            system("cls");
            if(x == 1)
            {
                LoginClient();
            }
            else if(x == 2)
            {
                system("cls");
                loginOptions();
                loginScreen(loginAs());
            }
            else
            {
                cout<<"\t\t\t\tYour choice NOT in list!!!!\n";
                system("pause");
                system("cls");
                loginOptions();
                loginScreen(loginAs());
            }

        }
    }
    static void LoginEmployee()
    {
        cout<<"\t\t\t\t\t\t Login Employee Page \n";
        int id;
        string password;
        cout<<"Enter Id : ";
        cin>>id;
        cout<<"Enter Password :";
        cin>>password;
        Employee* employee = EmployeeManager::login(id, password);
        if(employee != NULL)
        {
            EmployeeManager::printEmployeeMenu();
            if(EmployeeManager::employeeOptions(employee))
            {
                system("cls");
                //name = employee->getName();
                loginOptions();
                loginScreen(loginAs());
            }

        }
        else
        {
            cout<<"\n1 - Try again\n";
            cout<<"2 - Return\n";
            int x;
            cout<<"Enter your choise:";
            cin>>x;
            system("cls");
            if(x == 1)
            {
                LoginEmployee();
            }
            else if(x == 2)
            {
                system("cls");
                loginOptions();
                loginScreen(loginAs());
            }
            else
            {
                cout<<"\t\t\t\tYour choice NOT in list!!!!\n";
                system("pause");
                system("cls");
                loginOptions();
                loginScreen(loginAs());
            }

        }
    }
    static void LoginAdmin()
    {
        cout<<"\t\t\t\t\t\t Login Admin Page \n";
        int id;
        string password;
        cout<<"Enter Id : ";
        cin>>id;
        cout<<"Enter Password :";
        cin>>password;
        Admin* admin = AdminManager::login(id, password);
        if(admin != NULL)
        {
            AdminManager::printAdminMenu();
            if(AdminManager::AdminOptions(admin))
            {
                system("cls");
                //name = admin->getName();
                loginOptions();
                loginScreen(loginAs());
            }

        }
        else
        {
            cout<<"\n1 - Try again\n";
            cout<<"2 - Return\n";
            int x;
            cout<<"Enter your choise:";
            cin>>x;
            system("cls");
            if(x == 1)
            {
                LoginAdmin();
            }
            else if(x == 2)
            {
                system("cls");
                loginOptions();
                loginScreen(loginAs());
            }
            else
            {
                cout<<"\t\t\t\tYour choice NOT in list!!!!\n";
                system("pause");
                system("cls");
                loginOptions();
                loginScreen(loginAs());
            }

        }
    }
    static void loginScreen(int c)
    {
        /*
        int n = c, id;
        string pass;
        cout << "Enter id: ";
        cin >> id;
        cout << "Enter password: ";
        cin >> pass;*/
        int n = c;
        switch(n)
        {
        case 1:
            LoginAdmin();
        case 2:
            LoginEmployee();
        case 3:
            LoginAdmin();

        /*
        case 1:
            if (AdminManager::login(id, pass) != NULL)
            {
                while (AdminManager::AdminOptions(AdminManager::login(id, pass)) != false);
                logout();
            }
            else
            {
                invalid(1);
            }
        	break;
        case 2:
        	if (EmployeeManager::login(id, pass) != NULL) {
        		while (EmployeeManager::employeeOptions(EmployeeManager::login(id, pass)) != false);
        		logout();
        	}
        	else
            {
                invalid(2);
            }
        	break;
        case 3:
        	if (ClientManger::login(id, pass) != NULL)
        	{
        		while (ClientManger::clientOptions(ClientManger::login(id, pass)) != false);
        		logout();
        	}
        	else
            {
                invalid(3);
            }
        	break;
        */
        default:
            system("cls");
            loginOptions();

        }
    }
    static void runApp()
    {

        welcome();
//		FileManager::getAllData();
        loginScreen(loginAs());
    }
};

#endif // SCREENS_H
