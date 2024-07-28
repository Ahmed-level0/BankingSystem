// Created by youssef on 7/25/2024.

#ifndef BUSSINESLOGIC_H
#define BUSSINESLOGIC_H
#include "bankSystem.h"
#include <iostream>

class bankSystemDisplay{
public:

#pragma region vars
   static  int choice;
#pragma endregion

    static void displayMenu();
    static void displayEmployeesMenu();
    static void addEmployees(Employee employees[], string employeeName, string employeeJob,int age,float salary, int oth, double othr);
    static void displayEmployees(Employee employees[]);
    static void adjustEmployee(string employeeName , string employeeJob,int employeeId);
    static void displayClientsMenu();
    static void addClient(Client clients[], string clientnamee, int age, string password,string email, float balance);
    static void displayClients(Client Clients[]);
    static void adjustClient(string clientname , int clientid);
};
#endif //BUSSINESLOGIC_H
