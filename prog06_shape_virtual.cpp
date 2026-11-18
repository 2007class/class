#include <iostream>
using namespace std;

class Shape {
public:
    virtual void calculateArea() = 0;
    virtual ~Shape() {}
};

class Circle : public Shape {
private:
    float radius;

public:
    Circle(float r) : radius(r) {}
    void calculateArea() override {
        cout << "Area of Circle: " << 3.14159f * radius * radius << endl;
    }
};

class Rectangle : public Shape {
private:
    float length, breadth;

public:
    Rectangle(float l, float b) : length(l), breadth(b) {}
    void calculateArea() override {
        cout << "Area of Rectangle: " << length * breadth << endl;
    }
};

class Triangle : public Shape {
private:
    float base, height;

public:
    Triangle(float b, float h) : base(b), height(h) {}
    void calculateArea() override {
        cout << "Area of Triangle: " << 0.5f * base * height << endl;
    }
};

int main() {
    Shape* s;
    float r, l, b, base, h;

    cout << "Enter Circle radius: ";
    cin >> r;
    Circle c(r);
    s = &c;
    s->calculateArea();

    cout << "\nEnter Rectangle length and breadth: ";
    cin >> l >> b;
    Rectangle rect(l, b);
    s = &rect;
    s->calculateArea();

    cout << "\nEnter Triangle base and height: ";
    cin >> base >> h;
    Triangle tri(base, h);
    s = &tri;
    s->calculateArea();

    return 0;
}
