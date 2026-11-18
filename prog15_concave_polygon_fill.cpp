#include <iostream>
#include <graphics.h>
#include <algorithm>
using namespace std;

// Concave polygon vertices
int polyX[] = {150, 300, 230, 300, 150, 200};
int polyY[] = {100, 100, 200, 300, 300, 200};
const int N = 6;

void drawConcavePolygon(int borderColor) {
    setcolor(borderColor);
    for (int i = 0; i < N; i++) {
        int next = (i + 1) % N;
        line(polyX[i], polyY[i], polyX[next], polyY[next]);
    }
}

// 1. Scan Line Fill Algorithm
void scanLineFill(int fillColor) {
    int ymin = 1000, ymax = 0;
    for (int i = 0; i < N; i++) {
        ymin = min(ymin, polyY[i]);
        ymax = max(ymax, polyY[i]);
    }

    setcolor(fillColor);
    for (int y = ymin; y <= ymax; y++) {
        int interX[20], count = 0;
        for (int i = 0; i < N; i++) {
            int next = (i + 1) % N;
            int y1 = polyY[i], y2 = polyY[next];
            int x1 = polyX[i], x2 = polyX[next];

            if ((y1 <= y && y2 > y) || (y2 <= y && y1 > y)) {
                interX[count++] = x1 + (float)(y - y1) * (x2 - x1) / (y2 - y1);
            }
        }
        sort(interX, interX + count);
        for (int i = 0; i < count; i += 2) {
            line(interX[i], y, interX[i + 1], y);
        }
    }
}

// 2. Boundary Fill (4-connected)
void boundaryFill(int x, int y, int fillColor, int borderColor) {
    int current = getpixel(x, y);
    if (current != borderColor && current != fillColor) {
        putpixel(x, y, fillColor);
        boundaryFill(x + 1, y, fillColor, borderColor);
        boundaryFill(x - 1, y, fillColor, borderColor);
        boundaryFill(x, y + 1, fillColor, borderColor);
        boundaryFill(x, y - 1, fillColor, borderColor);
    }
}

// 3. Flood Fill (4-connected)
void floodFill(int x, int y, int fillColor, int oldColor) {
    if (getpixel(x, y) == oldColor) {
        putpixel(x, y, fillColor);
        floodFill(x + 1, y, fillColor, oldColor);
        floodFill(x - 1, y, fillColor, oldColor);
        floodFill(x, y + 1, fillColor, oldColor);
        floodFill(x, y - 1, fillColor, oldColor);
    }
}

int main() {
    int choice, color;
    while (true) {
        cout << "\n--- Concave Polygon Fill Menu ---"
             << "\n1. Scan Line Fill"
             << "\n2. Boundary Fill"
             << "\n3. Flood Fill"
             << "\n4. Exit"
             << "\nEnter choice: ";
        cin >> choice;
        if (choice == 4) break;

        cout << "Enter Fill Color (1-14, e.g., 2=GREEN, 4=RED, 14=YELLOW): ";
        cin >> color;

        int gd = DETECT, gm;
        initgraph(&gd, &gm, NULL);

        drawConcavePolygon(WHITE);
        delay(500);

        if (choice == 1) {
            scanLineFill(color);
            drawConcavePolygon(WHITE);
        } else if (choice == 2) {
            boundaryFill(210, 200, color, WHITE);
        } else if (choice == 3) {
            floodFill(210, 200, color, BLACK);
        }

        getch();
        closegraph();
    }
    return 0;
}
