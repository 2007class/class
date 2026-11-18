#include <iostream>
#include <string>
using namespace std;

class Library {
private:
    int bookId;
    string bookName, authorName;
    float price;

public:
    Library() : bookId(0), bookName(""), authorName(""), price(0.0f) {}

    Library(int id, string bName, string aName, float p)
        : bookId(id), bookName(bName), authorName(aName), price(p) {}

    void accept() {
        cout << "Enter Book ID: ";
        cin >> bookId;
        cin.ignore();
        cout << "Enter Book Name: ";
        getline(cin, bookName);
        cout << "Enter Author Name: ";
        getline(cin, authorName);
        cout << "Enter Price: ";
        cin >> price;
    }

    void display() const {
        cout << "ID: " << bookId
             << " | Book: " << bookName
             << " | Author: " << authorName
             << " | Price: Rs. " << price << endl;
    }
};

int main() {
    Library b1(101, "Computer Graphics", "Donald Hearn", 550.0f);
    Library b2;

    cout << "Enter details for Book 2:\n";
    b2.accept();

    cout << "\n--- Library Catalog ---\n";
    b1.display();
    b2.display();
    return 0;
}
