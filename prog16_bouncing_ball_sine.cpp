#include <iostream>
#include <graphics.h>
#include <cmath>
using namespace std;

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);

    int midY = getmaxy() / 2;
    int maxX = getmaxx();
    int amplitude = 100;
    float frequency = 0.03f;

    while (!kbhit()) {
        for (int x = 20; x < maxX - 20; x += 4) {
            if (kbhit()) break;

            cleardevice();

            // Draw reference ground/axis line
            setcolor(DARKGRAY);
            line(0, midY, maxX, midY);

            // Draw sine wave trajectory
            setcolor(CYAN);
            for (int tx = 20; tx < maxX - 20; tx++) {
                int ty = midY - (int)(abs(sin(tx * frequency)) * amplitude);
                putpixel(tx, ty, CYAN);
            }

            // Bouncing ball follows |sin| wave above ground line
            int y = midY - (int)(abs(sin(x * frequency)) * amplitude) - 15;

            setcolor(YELLOW);
            setfillstyle(SOLID_FILL, YELLOW);
            fillellipse(x, y, 15, 15);

            delay(20);
        }
    }

    getch();
    closegraph();
    return 0;
}
