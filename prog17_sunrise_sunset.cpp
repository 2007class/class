#include <iostream>
#include <graphics.h>
#include <cmath>
using namespace std;

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);

    int maxX = getmaxx();
    int maxY = getmaxy();
    int horizonY = maxY - 100;

    // Arc parameters for sun's curved path
    int centerX = maxX / 2;
    int radiusX = (maxX / 2) - 50;
    int radiusY = horizonY - 80;

    for (int angle = 180; angle >= 0; angle -= 2) {
        float rad = angle * 3.14159f / 180.0f;
        int sunX = centerX + (int)(radiusX * cos(rad));
        int sunY = horizonY - (int)(radiusY * sin(rad));

        // Change sky background color based on sun elevation (angle)
        if (angle > 145 || angle < 35) {
            setbkcolor(BLUE);       // Dawn / Dusk
        } else if (angle > 120 || angle < 60) {
            setbkcolor(LIGHTBLUE);  // Morning / Late Afternoon
        } else {
            setbkcolor(CYAN);       // Midday Bright Sky
        }

        cleardevice();

        // Draw Sun
        int sunColor = (angle > 140 || angle < 40) ? LIGHTRED : YELLOW;
        setcolor(sunColor);
        setfillstyle(SOLID_FILL, sunColor);
        fillellipse(sunX, sunY, 30, 30);

        // Draw Ground / Hills
        setcolor(GREEN);
        setfillstyle(SOLID_FILL, GREEN);
        bar(0, horizonY, maxX, maxY);

        setcolor(WHITE);
        if (angle > 120)
            outtextxy(20, 20, (char*)"SUNRISE");
        else if (angle >= 60)
            outtextxy(20, 20, (char*)"MIDDAY");
        else
            outtextxy(20, 20, (char*)"SUNSET");

        delay(60);
    }

    // Night scene after sunset
    setbkcolor(BLACK);
    cleardevice();
    setcolor(GREEN);
    setfillstyle(SOLID_FILL, GREEN);
    bar(0, horizonY, maxX, maxY);

    // Draw Moon & Stars
    setcolor(WHITE);
    setfillstyle(SOLID_FILL, WHITE);
    fillellipse(maxX - 120, 90, 22, 22);
    outtextxy(20, 20, (char*)"NIGHT");

    getch();
    closegraph();
    return 0;
}
