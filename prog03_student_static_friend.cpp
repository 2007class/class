#include <iostream>
#include <string>
using namespace std;

class Student {
private:
    string name, className, dob, bloodGroup, address, contact;
    int rollNo;
    char division;
    static int studentCount;

public:
    Student() {
        studentCount++;
    }

    ~Student() {
        studentCount--;
    }

    void setData(string name, int rollNo, string className, char division,
                 string dob, string bloodGroup, string address, string contact) {
        this->name = name;
        this->rollNo = rollNo;
        this->className = className;
        this->division = division;
        this->dob = dob;
        this->bloodGroup = bloodGroup;
        this->address = address;
        this->contact = contact;
    }

    static int getStudentCount() {
        return studentCount;
    }

    friend void displayStudent(const Student& s);
};

int Student::studentCount = 0;

void displayStudent(const Student& s) {
    cout << "\n--- Student Record ---"
         << "\nName        : " << s.name
         << "\nRoll No     : " << s.rollNo
         << "\nClass & Div : " << s.className << " - " << s.division
         << "\nDOB         : " << s.dob
         << "\nBlood Group : " << s.bloodGroup
         << "\nAddress     : " << s.address
         << "\nContact     : " << s.contact << "\n";
}

int main() {
    int n;
    cout << "Enter number of students: ";
    cin >> n;

    Student* students = new Student[n];

    for (int i = 0; i < n; i++) {
        string name, cls, dob, bg, addr, ph;
        int roll;
        char div;

        cout << "\nEnter details for Student " << i + 1 << ":\n";
        cin.ignore();
        cout << "Name: "; getline(cin, name);
        cout << "Roll No: "; cin >> roll;
        cout << "Class: "; cin >> cls;
        cout << "Division: "; cin >> div;
        cout << "DOB: "; cin >> dob;
        cout << "Blood Group: "; cin >> bg;
        cin.ignore();
        cout << "Address: "; getline(cin, addr);
        cout << "Contact: "; cin >> ph;

        students[i].setData(name, roll, cls, div, dob, bg, addr, ph);
    }

    cout << "\nTotal Active Students (Static Function): " << Student::getStudentCount() << endl;

    for (int i = 0; i < n; i++) {
        displayStudent(students[i]);
    }

    delete[] students;
    cout << "\nMemory freed. Active Students: " << Student::getStudentCount() << endl;
    return 0;
}
