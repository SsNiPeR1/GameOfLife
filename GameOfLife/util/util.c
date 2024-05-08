#ifdef WIN32
	#include <windows.h>
#else
	#include <sys/ioctl.h>
	#include <stdio.h>
	#include <unistd.h>
#endif

int getTerminalWidth() {
	#ifdef WIN32
		CONSOLE_SCREEN_BUFFER_INFO csbi;
	
		GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
		int columns = csbi.srWindow.Right - csbi.srWindow.Left + 1;
	
		return columns;
	#else
		struct winsize w;
		ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
		return w.ws_col;
    #endif
}

int getTerminalHeight() {
	#ifdef WIN32
		CONSOLE_SCREEN_BUFFER_INFO csbi;

		GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
		int rows = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;

		return rows;
	#else
		struct winsize w;
		ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
		return w.ws_row;
	#endif
}