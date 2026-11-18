#include <iostream>
#include <string>
using namespace std;

class Employee {
protected:
    string name;
    int id;

public:
    Employee(string n, int i) : name(n), id(i) {}
    virtual void calculateSalary() = 0;
    virtual ~Employee() {}
};

class PermanentEmployee : public Employee {
private:
    float basicPay, allowances;

public:
    PermanentEmployee(string n, int i, float basic, float allow)
        : Employee(n, i), basicPay(basic), allowances(allow) {}

    void calculateSalary() override {
        cout << "\n[Permanent Employee] ID: " << id << " | Name: " << name
             << " | Total Salary: Rs. " << (basicPay + allowances) << endl;
    }
};

class ContractEmployee : public Employee {
private:
    int hoursWorked;
    float hourlyRate;

public:
    ContractEmployee(string n, int i, int hours, float rate)
        : Employee(n, i), hoursWorked(hours), hourlyRate(rate) {}

    void calculateSalary() override {
        cout << "\n[Contract Employee]  ID: " << id << " | Name: " << name
             << " | Total Salary: Rs. " << (hoursWorked * hourlyRate) << endl;
    }
};

int main() {
    PermanentEmployee pe("Rohan Sharma", 201, 45000, 12000);
    ContractEmployee ce("Priya Patil", 305, 160, 400);

    Employee* emp1 = &pe;
    Employee* emp2 = &ce;

    emp1->calculateSalary();
    emp2->calculateSalary();
    return 0;
}
