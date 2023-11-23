/*
	main.c

	main source for PHATT application.

	muragami, muragami@wishray.com, Jason A. Petrasko 2023
	MIT license: https://opensource.org/license/mit/
*/

#include "phatt.h"

phattResolutionMode pMode[] = {
	{ 800, 600, 1.0 },
	{ 1200, 900, 4.0 / 3.0 },
	{ 1600, 1200, 2.0 },
	{ 0, 0, -1 },
};


int main(int argc, char *argv[])
{
	phattScreenMode scrMode;
	char buffer[256];
	double start, now, last, frame;

	scrMode.res = pMode[0];
	scrMode.targetFPS = 20;
  	
    Tigr *screen = tigrWindow(scrMode.res.width, scrMode.res.height, "PHATT Prototype", TIGR_NORESIZE);

    frame = 1.0 / (double)scrMode.targetFPS;
    start = phattGetTime();
    last = start;
    while (!tigrClosed(screen))
    {
    	now = phattGetTime();
    	while (now - last < frame) {
    		phattSleep(0.01);
    		now = phattGetTime();
    	}
    	last = now;
        tigrClear(screen, tigrRGB(0x80, 0x90, 0xa0));
        snprintf(buffer, 256, "Clock: %.2f", now - start);
        tigrPrint(screen, tfont, 120, 110, tigrRGB(0xff, 0xff, 0xff), buffer);
        tigrUpdate(screen);
    }
    tigrFree(screen);

    return 0;
}

