#include <iostream>
#include <graphics.h>
#include <cmath>
using namespace std;

void ddaCircle(int xc, int yc, int r, int style) {
    float x1 = r, y1 = 0;
    float startX = x1, startY = y1;

    // Determine epsilon = 2^(-n) such that 2^(n-1) <= r < 2^n
    int n = 0;
    while ((1 << n) < r) n++;
    float eps = 1.0f / (1 << n);

    int step = 0;
    do {
        float x2 = x1 + eps * y1;
        float y2 = y1 - eps * x2;

        bool plot = true;
        if (style == 2) plot = (step % 4 == 0);      // Dotted
        else if (style == 3) plot = (step % 16 < 10); // Dashed

        if (plot) {
            putpixel(xc + (int)(x2 + 0.5), yc + (int)(y2 + 0.5), WHITE);
        }

        x1 = x2;
        y1 = y2;
        step++;
    } while ((y1 - startY) < eps || (startX - x1) > eps);
}

int main() {
    int xc, yc, r, choice;
    cout << "Enter Center (xc yc) and Radius (r): ";
    cin >> xc >> yc >> r;
    cout << "1. Solid Circle\n2. Dotted Circle\n3. Dashed Circle\nEnter choice: ";
    cin >> choice;

    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);

    ddaCircle(xc, yc, r, choice);

    getch();
    closegraph();
    return 0;
}
