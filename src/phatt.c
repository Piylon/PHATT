/*
	phatt.c

	utility functions for PHATT application.

	muragami, muragami@wishray.com, Jason A. Petrasko 2023
	MIT license: https://opensource.org/license/mit/
*/

#include "phatt.h"
#include <unistd.h>

double phattGetTime() {
	struct timespec t;
	clock_gettime(CLOCK_REALTIME, &t);
	return (double)t.tv_sec + (double)t.tv_nsec * 0.000000001;
}

void phattSleep(double secs) {
	usleep((useconds_t )(secs * 1000000.0));
}