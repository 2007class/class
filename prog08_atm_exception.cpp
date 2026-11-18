#include <iostream>
#include <stdexcept>
#include <string>
using namespace std;

class ArithmeticException : public runtime_error {
public:
    ArithmeticException(const string& msg) : runtime_error(msg) {}
};

class IllegalArgumentException : public invalid_argument {
public:
    IllegalArgumentException(const string& msg) : invalid_argument(msg) {}
};

// Simulates 'finally' block execution upon leaving try scope
struct FinallyBlock {
    ~FinallyBlock() {
        cout << "[Finally]: Transaction session closed.\n";
    }
};

int main() {
    double balance = 10000.0;
    int choice;
    double amount;

    while (true) {
        cout << "\n--- ATM MENU ---"
             << "\n1. Check Balance"
             << "\n2. Deposit Money"
             << "\n3. Withdraw Money"
             << "\n4. Exit"
             << "\nEnter choice: ";
        cin >> choice;

        if (choice == 4) {
            cout << "Thank you for using the ATM.\n";
            break;
        }

        try {
            FinallyBlock finallyCleanup;

            if (choice == 1) {
                cout << "Current Balance: Rs. " << balance << endl;
            } else if (choice == 2) {
                cout << "Enter deposit amount: ";
                cin >> amount;
                if (amount <= 0)
                    throw IllegalArgumentException("Deposit amount must be greater than zero!");
                balance += amount;
                cout << "Deposited Rs. " << amount << ". New Balance: Rs. " << balance << endl;
            } else if (choice == 3) {
                cout << "Enter withdrawal amount: ";
                cin >> amount;
                if (amount <= 0)
                    throw IllegalArgumentException("Withdrawal amount must be greater than zero!");
                if (amount > balance)
                    throw ArithmeticException("Insufficient funds in account!");
                balance -= amount;
                cout << "Withdrawn Rs. " << amount << ". Remaining Balance: Rs. " << balance << endl;
            } else {
                throw IllegalArgumentException("Invalid menu option selected!");
            }
        } catch (const IllegalArgumentException& e) {
            cout << "[IllegalArgumentException]: " << e.what() << endl;
        } catch (const ArithmeticException& e) {
            cout << "[ArithmeticException]: " << e.what() << endl;
        }
    }
    return 0;
}
