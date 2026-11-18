#include <iostream>
#include <graphics.h>
#include <cstdlib>
using namespace std;

const int STYLE_SOLID = 1, STYLE_DOTTED = 2, STYLE_DASHED = 3, STYLE_THICK = 4;

void bresenhamLine(int x1, int y1, int x2, int y2, int style) {
    int dx = abs(x2 - x1), dy = abs(y2 - y1);
    int sx = (x1 < x2) ? 1 : -1;
    int sy = (y1 < y2) ? 1 : -1;
    int err = dx - dy;
    int i = 0;

    while (true) {
        bool plot = true;
        if (style == STYLE_DOTTED) plot = (i % 4 == 0);
        if (style == STYLE_DASHED) plot = (i % 12 < 8);

        if (plot) {
            putpixel(x1, y1, WHITE);
            if (style == STYLE_THICK) {
                putpixel(x1 + 1, y1, WHITE);
                putpixel(x1, y1 + 1, WHITE);
                putpixel(x1 + 1, y1 + 1, WHITE);
            }
        }

        if (x1 == x2 && y1 == y2) break;
        int e2 = 2 * err;
        if (e2 > -dy) { err -= dy; x1 += sx; }
        if (e2 < dx)  { err += dx; y1 += sy; }
        i++;
    }
}

void drawRectangle(int x1, int y1, int x2, int y2, int style) {
    bresenhamLine(x1, y1, x2, y1, style);
    bresenhamLine(x2, y1, x2, y2, style);
    bresenhamLine(x2, y2, x1, y2, style);
    bresenhamLine(x1, y2, x1, y1, style);
}

void drawDiamond(int cx, int cy, int hw, int hh, int style) {
    bresenhamLine(cx, cy - hh, cx + hw, cy, style);
    bresenhamLine(cx + hw, cy, cx, cy + hh, style);
    bresenhamLine(cx, cy + hh, cx - hw, cy, style);
    bresenhamLine(cx - hw, cy, cx, cy - hh, style);
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);

    drawRectangle(50, 50, 220, 150, STYLE_DOTTED);
    outtextxy(70, 160, (char*)"Rectangle - Dotted");

    drawRectangle(300, 50, 470, 150, STYLE_THICK);
    outtextxy(320, 160, (char*)"Rectangle - Thick");

    drawDiamond(135, 300, 85, 70, STYLE_DASHED);
    outtextxy(70, 380, (char*)"Diamond - Dashed");

    drawDiamond(385, 300, 85, 70, STYLE_SOLID);
    outtextxy(320, 380, (char*)"Diamond - Solid");

    getch();
    closegraph();
    return 0;
}
