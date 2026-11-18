#include <iostream>
#include <string>
using namespace std;

class Employee {
protected:
    int empId;
    string empName, designation;

public:
    void acceptEmployee() {
        cout << "Enter Employee ID: ";
        cin >> empId;
        cin.ignore();
        cout << "Enter Employee Name: ";
        getline(cin, empName);
        cout << "Enter Designation: ";
        getline(cin, designation);
    }
};

class Salary : public Employee {
protected:
    float basicSalary, hra, da, deductions;

public:
    void acceptSalary() {
        acceptEmployee();
        cout << "Enter Basic Salary: ";
        cin >> basicSalary;
        cout << "Enter HRA: ";
        cin >> hra;
        cout << "Enter DA: ";
        cin >> da;
        cout << "Enter Deductions: ";
        cin >> deductions;
    }
};

class Payroll : public Salary {
private:
    float grossSalary, netSalary;

public:
    void calculateAndDisplay() {
        grossSalary = basicSalary + hra + da;
        netSalary = grossSalary - deductions;

        cout << "\n========== PAYROLL SLIP =========="
             << "\nEmployee ID   : " << empId
             << "\nEmployee Name : " << empName
             << "\nDesignation   : " << designation
             << "\nBasic Salary  : " << basicSalary
             << "\nHRA + DA      : " << (hra + da)
             << "\nGross Salary  : " << grossSalary
             << "\nDeductions    : " << deductions
             << "\nNet Salary    : " << netSalary
             << "\n==================================\n";
    }
};

int main() {
    Payroll p;
    p.acceptSalary();
    p.calculateAndDisplay();
    return 0;
}
