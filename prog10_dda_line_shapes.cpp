#include <iostream>
#include <graphics.h>
#include <cstdlib>
using namespace std;

const int STYLE_SOLID = 1, STYLE_DOTTED = 2, STYLE_DASHED = 3, STYLE_THICK = 4;

void ddaLine(int x1, int y1, int x2, int y2, int style) {
    int dx = x2 - x1, dy = y2 - y1;
    int steps = (abs(dx) > abs(dy)) ? abs(dx) : abs(dy);
    if (steps == 0) return;

    float xInc = (float)dx / steps;
    float yInc = (float)dy / steps;
    float x = x1, y = y1;

    for (int i = 0; i <= steps; i++) {
        int px = (int)(x + 0.5), py = (int)(y + 0.5);
        bool plot = true;
        if (style == STYLE_DOTTED) plot = (i % 4 == 0);
        if (style == STYLE_DASHED) plot = (i % 12 < 8);

        if (plot) {
            putpixel(px, py, WHITE);
            if (style == STYLE_THICK) {
                putpixel(px + 1, py, WHITE);
                putpixel(px, py + 1, WHITE);
                putpixel(px + 1, py + 1, WHITE);
            }
        }
        x += xInc;
        y += yInc;
    }
}

void drawRectangle(int x1, int y1, int x2, int y2, int style) {
    ddaLine(x1, y1, x2, y1, style);
    ddaLine(x2, y1, x2, y2, style);
    ddaLine(x2, y2, x1, y2, style);
    ddaLine(x1, y2, x1, y1, style);
}

void drawDiamond(int cx, int cy, int hw, int hh, int style) {
    ddaLine(cx, cy - hh, cx + hw, cy, style);
    ddaLine(cx + hw, cy, cx, cy + hh, style);
    ddaLine(cx, cy + hh, cx - hw, cy, style);
    ddaLine(cx - hw, cy, cx, cy - hh, style);
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
