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

void midpointCircle(int xc, int yc, int r, int style) {
    int x = 0, y = r;
    int p = 1 - r;
    int step = 0;

    while (x <= y) {
        bool plot = true;
        if (style == 2) plot = (step % 3 == 0);      // Dotted
        else if (style == 3) plot = (step % 10 < 6); // Dashed

        if (plot) plot8Way(xc, yc, x, y);

        x++;
        if (p < 0) {
            p = p + 2 * x + 1;
        } else {
            y--;
            p = p + 2 * (x - y) + 1;
        }
        step++;
    }
}

int main() {
    int xc, yc, r, choice;
    while (true) {
        cout << "\n--- Midpoint Circle Menu ---"
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
        midpointCircle(xc, yc, r, choice);
        getch();
        closegraph();
    }
    return 0;
}
