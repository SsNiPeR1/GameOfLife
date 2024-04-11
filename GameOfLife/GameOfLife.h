// GameOfLife.h : Include file for standard system include files,
// or project specific include files.

#pragma once

#include <stdio.h>
#include <stdlib.h>

#ifdef _WIN32
	#include <windows.h>
#else
	#include <unistd.h>
#endif

void nextGeneration(int board[5][5]);
int countNeighbors(int board[5][5], int x, int y);
void printBoard(int board[5][5]);