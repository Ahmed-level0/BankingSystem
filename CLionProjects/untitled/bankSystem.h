// Created by youssef on 7/24/2024.

#ifndef BANKSYSTEM_H
#define BANKSYSTEM_H
#include <iostream>
using namespace std;

#pragma region Client
class Client{
// protected:
public:
    Client();
    string Client_name;
    string Client_password;
    int Client_age;
    int Client_id;
    string Client_email;
    float Client_balance;
    static int client_count;
    void setClientName(string clientname);
    void setPassword(string password);
    void setClientAge(int age);
    void setClientID(int id);
    void setClientEmail(string email);
    void setClientBalance(float balance);
    void deposit(float amount);
    void printClient();

    friend ostream& operator<<(ostream& os, const Client& client) {
        os << client.Client_name << '\n';
        os << client.Client_id<< '\n';
        os << client.Client_age << '\n';
        os << client.Client_password << '\n';
        os << client.Client_email << '\n';
        os << client.Client_balance << '\n';
        return os;
    }
};
#pragma endregion

#pragma region Employee
class Employee{
public:
    string Employee_name;
    string Employee_job;
    int Employee_age;
    int Employee_id;
    double Employee_salary;
    int overTimeHours;
    double overTimeHoursRate;
    Employee();
    void setEmployeeName(string name);
    void setEmployeeJob(string job);
    void setEmployeeAge(int age);
    void setEmployeeID(int id);
    void setEmployeeSalary(double salary);
    void setOverTimeHours(int hours);
    void setOverTimeHoursRate(double rate);
    virtual void print();
    // ~Employee();
};
#pragma endregion

#pragma region Accountant
class Accountant : public Employee{
protected:
    string systemAccount;
    string systemAccountPassword;
    string department;
public:
    Accountant();
    void setSystemAccount(string acc);
    void setSystemAccountPassword(string pass);
    void setDepartment(string depart);
    void print();
};
#pragma endregion

#pragma region Admin
class Admin {
public:
    static void getClientNumber(Client c);
    static void getInfo(Client c);
    static void getInfo(Accountant a);
};
#pragma endregion


#endif //BANKSYSTEM_H
