#include <iostream>
#include <graphics.h>
using namespace std;

void plot8Way(int xc, int yc, int x, int y) {
    putpixel(xc + x, yc + y, WHITE);
    putpixel(xc - x, yc + y, WHITE);
    putpixel(xc + x, yc - y, WHITE);
    putpixel(xc - x, yc - y, WHITE);
    putpixel(xc + y, yc + x, WHITE);
    putpixel(xc - y, yc + x, WHITE);
    putpixel(xc + y, yc - x, WHITE);
    putpixel(xc - y, yc - x, WHITE);
}

void bresenhamCircle(int xc, int yc, int r, int style) {
    int x = 0, y = r;
    int d = 3 - 2 * r;
    int step = 0;

    while (x <= y) {
        bool plot = true;
        if (style == 2) plot = (step % 3 == 0);      // Dotted
        else if (style == 3) plot = (step % 10 < 6); // Dashed

        if (plot) plot8Way(xc, yc, x, y);

        if (d < 0) {
            d = d + 4 * x + 6;
        } else {
            d = d + 4 * (x - y) + 10;
            y--;
        }
        x++;
        step++;
    }
}

int main() {
    int xc, yc, r, choice;
    while (true) {
        cout << "\n--- Bresenham Circle Menu ---"
             << "\n1. Solid Circle"
             << "\n2. Dotted Circle"
             << "\n3. Dashed Circle"
             << "\n4. Exit"
             << "\nEnter choice: ";
        cin >> choice;
        if (choice == 4) break;

        cout << "Enter Center (xc yc) and Radius (r): ";
        cin >> xc >> yc >> r;

        int gd = DETECT, gm;
        initgraph(&gd, &gm, NULL);
        bresenhamCircle(xc, yc, r, choice);
        getch();
        closegraph();
    }
    return 0;
}
