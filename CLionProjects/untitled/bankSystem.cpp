// Created by youssef on 7/24/2024.

#include "bankSystem.h"
#include <bits/stdc++.h>
using namespace std;


#pragma region Client
int Client::client_count = 0;
Client::Client() : Client_name("Null"), Client_password("Null"), Client_age(0),Client_id(-1), Client_email("Null"), Client_balance(0.0) {
  client_count++;
}
void Client::setClientName(string clientname) { Client_name = clientname; }
void Client::setPassword(string password) { Client_password = password; }
void Client::setClientAge(int age) { Client_age = age; }
void Client::setClientID(int id) { Client_id = id; }
void Client::setClientEmail(string email) { Client_email = email; }
void Client::setClientBalance(float balance) { Client_balance = balance; }
void Client::deposit(float amount) { Client_balance += amount; }
void Client::printClient() {
  cout << "Client Name: " << Client_name << " Client Age: " << Client_age
       << " Client ID: " << Client_id << " Client Email: " << Client_email
       << " Client Password: " << Client_password << " Client Balance: "
       << Client_balance << endl;
}
#pragma endregion


#pragma region Employee
Employee::Employee(): Employee_name("Null"), Employee_job("Null"), Employee_age(0), Employee_id(0), Employee_salary(0.0), overTimeHours(0), overTimeHoursRate(0.0){}
void Employee::setEmployeeName(string name) { Employee_name = name; }
void Employee::setEmployeeJob(string job) { Employee_job = job; }
void Employee::setEmployeeAge(int age) { Employee_age = age; }
void Employee::setEmployeeID(int id) { Employee_id = id; }
void Employee::setOverTimeHours(int hours) { overTimeHours = hours; }
void Employee::setOverTimeHoursRate(double rate) { overTimeHoursRate = rate; }
void Employee::setEmployeeSalary(double salary) { Employee_salary = salary;}
void Employee::print(){
  cout << "Employee Name: " << Employee_name
       << " Employee Job: " << Employee_job
       << " Employee Age: " << Employee_age
       << " Employee ID: " << Employee_id
       << " Employee Salary: " << Employee_salary
       << " Employee Overtime Hours: " << overTimeHours
       << " Employee Overtime Hours Rate: " << overTimeHoursRate << endl;
}
#pragma endregion


#pragma region Accountant
Accountant::Accountant():systemAccount("null"), systemAccountPassword("null"), department("null") {}
void Accountant::setSystemAccount(string acc) {
    systemAccount = acc;
}
void Accountant::setSystemAccountPassword(string pass) {
    systemAccountPassword = pass;
}
void Accountant::setDepartment(string depart) {
    department = depart;
}
void Accountant::print() {
    Employee::print();
    cout<<"Employee Account and Password are: "<<systemAccount<<" , "<<systemAccountPassword<<" And department is: "<<department<<endl;
}
#pragma endregion


#pragma region Admin
void Admin::getClientNumber(Client c) {
    cout<<"The client Number is: "<<c.client_count<<endl;
}
void Admin::getInfo(Accountant a){
    a.print();
    cout<<"\n";
}
void Admin::getInfo(Client c){
    c.printClient();
    cout<<"\n";
}
#pragma endregion

