#ifndef FILEMANAGER_H
#define FILEMANAGER_H
#include "DataSourceInterface.h"
#include "FilesHelper.h"
#include "Client.h"
#include "Employee.h"
#include "Admin.h"
class FileManager : public DataSourceInterface
{
public:
    void addClient(Client client)
    {
        FilesHelper::saveClient(client);
    }
    void addEmployee(Employee employee)
    {
        FilesHelper::saveEmployee("Employee.txt", "EmployeeId.txt", employee);
    }
    void addAdmin(Admin admin)
    {
        FilesHelper::saveAdmin("Admin.txt", "AdminId.txt", admin);
    }
    void getAllClients()
    {
        FilesHelper::getClients();
    }
    void getAllEmployees()
    {
        FilesHelper::getEmployees();
    }
    void getAllAdmins()
    {
        FilesHelper::getAdmins();
    }
    void removeAllClients()
    {
        FilesHelper::clearFile("Clients.txt", "ClientId.txt");
    }
    void removeAllEmployees()
    {
        FilesHelper::clearFile("Employee.txt", "EmployeeId.txt");
    }
    void removeAllAdmins()
    {
        FilesHelper::clearFile("Admin.txt", "AdminId.txt");
    }
    void getAllData()
    {
        getAllClients();
        getAllEmployees();
        getAllAdmins();
    }
/*
    void updateClients()
    {
        FilesHelper::clearFile("Clients.txt", "ClientId.txt");
        for (ic = allClients.begin(); ic != allClients.end(); ic++)
        {

            addClient(*(ic));
        }
    }
    void updateEmployees()
    {
        FilesHelper::clearFile("Employee.txt", "EmployeeId.txt");
        for (ie = allEmployees.begin(); ie != allEmployees.end(); ie++)
        {
            addEmployee(*ie);
        }
    }
    void updateAdmins()
    {
        FilesHelper::clearFile("Admin.txt", "AdminId.txt");
        for (ia = allAdmins.begin(); ia != allAdmins.end(); ia++)
        {
            addAdmin(*ia);
        }
    }*/

};

#endif // FILEMANAGER_H
