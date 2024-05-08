// GameOfLife.h : Include file for standard system include files,
// or project specific include files.

#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef WIN32
	#include <windows.h>
#else
	#include <unistd.h>
	#include <time.h>
#endif

void tick(int *ptr, int width, int height);
int neighbors(int *ptr, int x, int y, int width, int height);
void printBoard(int *ptr, int width, int height);