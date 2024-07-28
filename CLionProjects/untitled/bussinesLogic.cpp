// Created by youssef on 7/25/2024.

#include "bankSystem.h"
#include "bussinesLogic.h"
#include <bits/stdc++.h>

#pragma region globalvar
static Client clients[10];
static Employee employees[10];
int bankSystemDisplay::choice;
string employeeName;
string employeeJob;
int employeeID;
int age;
float salary;
int oth;
double othr;
string clientname;
int clientid;
string email;
string password;
#pragma endregion

#pragma region systemDisplay
void bankSystemDisplay::addClient(Client arrayClients[], string clientname, int age, string password,  string email, float balance) {
  for (int i = 0; i < 10; i++) {
    if (arrayClients[i].Client_name == "Null") {
      arrayClients[i].setClientName(clientname);
      arrayClients[i].setClientID(i);
      arrayClients[i].setClientAge(age);
      arrayClients[i].setPassword(password);
      arrayClients[i].setClientEmail(email);
      arrayClients[i].setClientBalance(balance);
      return;
    }
  }
}

void bankSystemDisplay::displayClients(Client arrayClients[]) {
  for (int i = 0; i < 10; i++) {
    if (arrayClients[i].Client_name == "Null") {
      cout << "There's no clients" << endl;
      break;
    }
    cout<<"----------------------------------------------------"<<endl;
    arrayClients[i].printClient();
    cout<<"----------------------------------------------------"<<endl;

  }
}

void bankSystemDisplay::adjustClient(string clientname, int clientid) {
  for (auto & client : clients) {
    if (client.Client_name == clientname && client.Client_id == clientid) {
      string newName;          string newEmail;

      cout<<"what would you like to adjust, sir"<<endl;
      cout<<"A - To adjust name please press 1 "<<endl;
      cout<<"B - To adjust ID please press 2 "<<endl;
      cout<<"C - To adjust age please press 3 "<<endl;
      cout<<"D - To adjust email please press 4 "<<endl;
      cout<<"E - To adjust password please press 5 "<<endl;
      cout<<"F - To deposit please press 6 "<<endl;
      cout<<"G - To Go back please press 7 "<<endl;
      cout<<"Please Enter your choice: ";
      cin>>bankSystemDisplay::choice;
      switch (bankSystemDisplay::choice) {
        case 1:
          cout<<"Please enter the new name: ";
        cin>>newName;
        client.setClientName(newName);
        displayClientsMenu();
        break;

        case 2:
          int newID;
        cout<<"Please enter the new ID: ";
        cin>>newID;
        client.setClientID(newID);
        displayClientsMenu();
        break;

        case 3:
          int newAge;
        cout<<"Please enter the new age: ";
        cin>>newAge;
        client.setClientAge(newAge);
        displayClientsMenu();
        break;

        case 4:
          cout<<"Please enter the new email: ";
        cin>>newEmail;
        client.setClientEmail(newEmail);
        displayClientsMenu();
        break;

        case 5:
          int newPassword;
        cout<<"Please enter the new password: ";
        cin>>newPassword;
        client.setClientID(newPassword);
        displayClientsMenu();
        break;

        case 6:
          float Amount;
        cout<<"Please enter the amout desierd to deposit: ";
        cin>>Amount;
        client.deposit(Amount);
        displayClientsMenu();
        break;

        default:
          displayClientsMenu();
        break;
      }
    }
  }
}



  void bankSystemDisplay::displayClientsMenu() {
    cout << "Here's the Clients menu" << endl;
    cout << "1 - To display all the clients press 1 " << endl;
    cout << "2 - To adjust a client press 2 " << endl;
    cout << "3 - To add a client press 3 " << endl;
    cout << "4 - To go back press 4 " << endl;
    cout << "5 - To Exit press 5 " << endl;
    cout << "Please enter your choice: ";
    cin >> bankSystemDisplay::choice;

    switch (bankSystemDisplay::choice) {

      case 1:
        bankSystemDisplay::displayClients(clients);
      displayClientsMenu();
      break;

      case 2:
      cout<<"Please enter the client name: ";
      cin>>clientname;
      cout<<"Please enter the client id: ";
      cin>>clientid;
      bankSystemDisplay::adjustClient(clientname, clientid);
      break;

      case 3:
        cout << "Please enter the client name: ";
      cin >> clientname;
      int age;
      cout << "Please enter the client age: ";
      cin>>age;
      cout << "Please enter the client email: ";
      cin>>email;
      cout << "Please enter the client password: ";
      cin>>password;
      float balance;
      cout << "Please enter the client balance: ";
      cin>>balance;
      bankSystemDisplay::addClient(clients, clientname,age,password, email,balance);

      cout<<"----------------------------"<<endl;
      cout<<"Client added succesfully"<<endl;
      cout<<"----------------------------"<<endl;
      displayClientsMenu();
      break;

      case 4:
        displayMenu();
      break;

      default:
        break;
    }
  }
#pragma endregion

#pragma region Emolyees
  void bankSystemDisplay::displayEmployeesMenu() {
    cout << "Here's the Employees menu" << endl;
    cout << "1 - To display all the employees press 1 " << endl;
    cout << "2 - To adjust a employee press 2 " << endl;
    cout << "3 - To add a employee press 3 " << endl;
    cout << "4 - To go back press 4 " << endl;
    cout << "5 - To Exit press 5 " << endl;
    cout << "Please enter your choice: ";
    cin >> bankSystemDisplay::choice;

  switch (bankSystemDisplay::choice) {
    case 1:
    bankSystemDisplay::displayEmployees(employees);
    displayEmployeesMenu();
    break;

    case 2:
    cout<<"Please enter the Employee name: ";
    cin>>employeeName;
    cout<<"Please enter the Employee job: ";
    cin>>employeeJob;
    cout<<"Please enter the Employee ID: ";
    cin>>employeeID;
    bankSystemDisplay::adjustEmployee(employeeName, employeeJob, employeeID);
    break;

    case 3:
    cout << "Please enter the Employee name: ";
    cin >> employeeName;
    cout << "Please enter the Employee age: ";
    cin>>age;
    cout << "Please enter the Employee job: ";
    cin>>employeeJob;
    cout << "Please enter the Employee salary: ";
    cin>>salary;
    cout << "Please enter the Employee oth: ";
    cin>>oth;
    cout << "Please enter the Employee othr: ";
    cin>>othr;
    bankSystemDisplay::addEmployees(employees, employeeName, employeeJob, age, salary, oth, othr);

    cout<<"----------------------------"<<endl;
    cout<<"Employee added succesfully"<<endl;
    cout<<"----------------------------"<<endl;
    displayEmployeesMenu();
    break;

    case 4:
      displayMenu();
    break;

    default:
      break;
  }
}
 void bankSystemDisplay::addEmployees(Employee employees[], string employeeName, string employeeJob, int age,  float salary, int oth, double othr) {
  for (int i = 0; i < 10; i++) {
    if (employees[i].Employee_name == "Null") {
      employees[i].setEmployeeName(employeeName);
      employees[i].setEmployeeID(i);
      employees[i].setEmployeeAge(age);
      employees[i].setEmployeeJob(employeeJob);
      employees[i].setEmployeeSalary(salary);
      employees[i].setOverTimeHours(oth);
      employees[i].setOverTimeHoursRate(othr);
      return;
    }
  }
}
void bankSystemDisplay::displayEmployees(Employee employeesArray[]) {
  for (int i = 0; i < 10; i++) {
    if (employeesArray[i].Employee_name == "Null") {
      cout << "There's no Employees" << endl;
      break;
    }
    cout<<"----------------------------------------------------"<<endl;
    employeesArray[i].print();
    cout<<"----------------------------------------------------"<<endl;

  }
}
void bankSystemDisplay::adjustEmployee(string employeeName, string employeeJob, int employeeId) {
  for (auto & employee : employees) {
    if (employees->Employee_name == employeeName && employees->Employee_id == employeeId && employees->Employee_job==employeeJob) {
      string newName;          string newJob;
      cout<<"what would you like to adjust, sir"<<endl;
      cout<<"A - To adjust name please press 1 "<<endl;
      cout<<"B - To adjust ID please press 2 "<<endl;
      cout<<"C - To adjust age please press 3 "<<endl;
      cout<<"D - To adjust job please press 4 "<<endl;
      cout<<"E - To adjust overtimehours please press 5 "<<endl;
      cout<<"F - To adjust overtimehoursrate please press 6 "<<endl;
      cout<<"G - To Go back please press 7 "<<endl;
      cout<<"Please Enter your choice: ";
      cin>>bankSystemDisplay::choice;
      switch (bankSystemDisplay::choice) {
        case 1:
        cout<<"Please enter the new name: ";
        cin>>newName;
        employee.setEmployeeName(newName);
        displayEmployeesMenu();
        break;

        case 2:
        int newID;
        cout<<"Please enter the new ID: ";
        cin>>newID;
        employee.setEmployeeID(newID);
        displayEmployeesMenu();
        break;

        case 3:
        int newAge;
        cout<<"Please enter the new age: ";
        cin>>newAge;
        employee.setEmployeeAge(newAge);
        displayEmployeesMenu();
        break;

        case 4:
        cout<<"Please enter the new job: ";
        cin>>newJob;
        employee.setEmployeeJob(newJob);
        displayEmployeesMenu();
        break;

        case 5:
        int newOverTimeHours;
        cout<<"Please enter the new overtimehours: ";
        cin>>newOverTimeHours;
        employee.setOverTimeHours(newOverTimeHours);
        displayEmployeesMenu();
        break;

        case 6:
        float newOverTimeHoursRate;
        cout<<"Please enter the new overtimehoursrate: ";
        cin>>newOverTimeHoursRate;
        employee.setOverTimeHoursRate(newOverTimeHoursRate);
        displayEmployeesMenu();
        break;

        default:
          displayClientsMenu();
        break;
      }
    }
    else {
      cout<<"Wrong information, please check again"<<endl;
      return;
    }
  }

}


#pragma endregion


#pragma region diplayMenu
  void bankSystemDisplay::displayMenu(){
    cout << "Hello Admin" << endl;
    cout << "1 - For Clients menu press 1 " << endl;
    cout << "2 - For Employees menu press 2 " << endl;
    cout << "Please enter your choice: ";
    cin >> bankSystemDisplay::choice;

    switch (bankSystemDisplay::choice) {
      case 1:
        bankSystemDisplay::displayClientsMenu();
      break;
      case 2:
        bankSystemDisplay::displayEmployeesMenu();
      break;
      default:
        break;
    }
  }
#pragma endregion


