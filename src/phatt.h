/*
	phatt.h

	main header for PHATT application.

	muragami, muragami@wishray.com, Jason A. Petrasko 2023
	MIT license: https://opensource.org/license/mit/
*/

#include "wren.h"
#include "tigr.h"
#include <time.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct _phattResolutionMode {
	int width;
	int height;
	double scale;
} phattResolutionMode;

typedef struct _phattScreenMode {
	phattResolutionMode res;
	int targetFPS;
} phattScreenMode;

double phattGetTime();
void phattSleep(double secs);