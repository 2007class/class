#include <iostream>
#include <string>
using namespace std;

class Student {
private:
    string name, className, dob, bloodGroup, address, contact;
    int rollNo;
    char division;

public:
    // Default Constructor
    Student() {
        name = "Not Assigned";
        rollNo = 0;
        className = "SE";
        division = 'A';
        dob = "01/01/2005";
        bloodGroup = "O+";
        address = "Pune";
        contact = "0000000000";
        cout << "[Default Constructor Called]\n";
    }

    // Parameterized Constructor
    Student(string n, int r, string cls, char div, string d, string bg, string addr, string ph) {
        name = n;
        rollNo = r;
        className = cls;
        division = div;
        dob = d;
        bloodGroup = bg;
        address = addr;
        contact = ph;
        cout << "[Parameterized Constructor Called]\n";
    }

    // Copy Constructor
    Student(const Student& s) {
        name = s.name;
        rollNo = s.rollNo;
        className = s.className;
        division = s.division;
        dob = s.dob;
        bloodGroup = s.bloodGroup;
        address = s.address;
        contact = s.contact;
        cout << "[Copy Constructor Called]\n";
    }

    // Destructor
    ~Student() {
        cout << "[Destructor Called for " << name << "]\n";
    }

    void display() const {
        cout << "\n--- Student Details ---"
             << "\nName        : " << name
             << "\nRoll No     : " << rollNo
             << "\nClass & Div : " << className << " - " << division
             << "\nDOB         : " << dob
             << "\nBlood Group : " << bloodGroup
             << "\nAddress     : " << address
             << "\nContact     : " << contact << "\n";
    }
};

int main() {
    Student s1;
    s1.display();

    Student s2("Aditya", 101, "SE Comp", 'A', "14/10/2005", "B+", "Sangamner", "9876543210");
    s2.display();

    Student s3(s2);
    s3.display();

    return 0;
}
