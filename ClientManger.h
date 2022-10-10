#ifndef CLIENTMANGER_H
#define CLIENTMANGER_H

#include "FilesHelper.h"
#include "Validation.h"

class ClientManger
{
public:
    static void printClientMenu()
    {
        system("cls");
        cout<<" 1 - Display my info. \n";
        cout << "2-Check balance.\n" ;
        cout << "3-Update Password .\n";
        cout << "4-Withdraw.\n";
        cout << "5-Deposit .\n";
        cout << "6-Transfer amount.\n";
        cout << "7-Logout. \n" ;
    }

    static void back(Client* client)
    {
        cout << endl;
        system("pause");
        clientOptions(client);
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
    static Client* login(int id, string password)
    {
        for(ic = allClients.begin(); ic != allClients.end(); ic++)
        {
            if(ic->getId() == id  && ic->getPassword() == password)
            {
                ic->display();
            }
        }
        return NULL;
    }
    static bool clientOptions(Client* client)
    {
        printClientMenu();
        cout<<"Enter your choice :";
        Employee e;
        double amount;
        int n, id;
        cin >> n;
        switch(n)
        {
        case 1:

            system("cls");
            client->display();
            break;

        case 2:
            system("cls");
            client->checkBalance();
            break;

        case 3:
            updatePassword(client);
            //FileManager::updateClients();
            break;

        case 4:
            system("cls");
            cout << "Enter amount to withdraw: ";
            cin >> amount;
            client->withdraw(amount);
            //FileManager::updateClients();
            break;
        case 5:
            system("cls");
            cout << "Enter amount to deposit: ";
            cin >> amount;
            client->deposit(amount);
            //FileManager::updateClients();
            break;
        case 6:
            system("cls");
            cout << "Enter ID : ";
            cin >> id;
            while (e.searchClient(id) == NULL)
            {
                cout << "Invalid id.\n";
                cout << "\nEnter ID : ";
                cin >> id;
            }
            cout << "\nEnter amount to transfer: ";
            cin >> amount;
            client->transferTo(amount, *e.searchClient(id));
            //FileManager::updateClients();
            break;
        case 7:
            return false;
            break;

        default:
            system("cls");
            clientOptions(client);
            return true;
        }
        back(client);
        return true;
    }

};

#endif // CLIENTMANGER_H
