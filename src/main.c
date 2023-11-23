/*
	main.c

	main source for PHATT application.

	muragami, muragami@wishray.com, Jason A. Petrasko 2023
	MIT license: https://opensource.org/license/mit/
*/

#include "phatt.h"

phattResolutionMode pMode[] = {
	{ 800, 600, 1.0 },
	{ 1200, 900, 1.0 },
	{ 1600, 1200, 1.0 },
	{ 0, 0, -1 },
};


int main(int argc, char *argv[])
{
	phattScreenMode scrMode;

	scrMode.res = pMode[0];
	scrMode.targetFPS = 30;
  	
    Tigr *screen = tigrWindow(scrMode.res.width, scrMode.res.height, "PHATT Prototype", TIGR_NORESIZE);
    while (!tigrClosed(screen))
    {
        tigrClear(screen, tigrRGB(0x80, 0x90, 0xa0));
        tigrPrint(screen, tfont, 120, 110, tigrRGB(0xff, 0xff, 0xff), "Hello, world.");
        tigrUpdate(screen);
    }
    tigrFree(screen);

    return 0;
}

