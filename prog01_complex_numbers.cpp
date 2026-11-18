#include <iostream>
using namespace std;

class Complex {
private:
    float real, imag;

public:
    Complex() : real(0), imag(0) {}
    Complex(float r, float i) : real(r), imag(i) {}

    Complex operator+(const Complex& c) const {
        return Complex(real + c.real, imag + c.imag);
    }

    Complex operator*(const Complex& c) const {
        return Complex(
            (real * c.real) - (imag * c.imag),
            (real * c.imag) + (imag * c.real)
        );
    }

    friend istream& operator>>(istream& in, Complex& c) {
        cout << "Enter real and imaginary parts: ";
        in >> c.real >> c.imag;
        return in;
    }

    friend ostream& operator<<(ostream& out, const Complex& c) {
        out << c.real << (c.imag >= 0 ? " + " : " - ") << (c.imag >= 0 ? c.imag : -c.imag) << "i";
        return out;
    }
};

int main() {
    Complex c1, c2, sum, prod;
    cout << "Complex Number 1:\n";
    cin >> c1;
    cout << "Complex Number 2:\n";
    cin >> c2;

    sum = c1 + c2;
    prod = c1 * c2;

    cout << "\nC1 = " << c1 << endl;
    cout << "C2 = " << c2 << endl;
    cout << "Addition (C1 + C2) = " << sum << endl;
    cout << "Multiplication (C1 * C2) = " << prod << endl;
    return 0;
}
