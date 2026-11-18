#include <iostream>
#include <string>
using namespace std;

class Publication {
protected:
    string title;
    float price;

public:
    void accept() {
        cin.ignore();
        cout << "Enter Title: ";
        getline(cin, title);
        cout << "Enter Price: ";
        cin >> price;
    }

    void display() const {
        cout << "Title: " << title << "\nPrice: Rs. " << price << endl;
    }
};

class Book : public Publication {
private:
    int pageCount;

public:
    void acceptBook() {
        cout << "\n--- Enter Book Details ---\n";
        accept();
        cout << "Enter Page Count: ";
        cin >> pageCount;
    }

    void displayBook() const {
        cout << "\n--- Book Details ---\n";
        display();
        cout << "Pages: " << pageCount << endl;
    }
};

class Tape : public Publication {
private:
    float playingTime;

public:
    void acceptTape() {
        cout << "\n--- Enter Tape Details ---\n";
        accept();
        cout << "Enter Playing Time (in minutes): ";
        cin >> playingTime;
    }

    void displayTape() const {
        cout << "\n--- Tape Details ---\n";
        display();
        cout << "Playing Time: " << playingTime << " mins" << endl;
    }
};

int main() {
    Book b;
    Tape t;

    b.acceptBook();
    t.acceptTape();

    b.displayBook();
    t.displayTape();
    return 0;
}
