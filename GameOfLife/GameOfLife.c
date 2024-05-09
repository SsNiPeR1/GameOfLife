// GameOfLife.c : Defines the entry point for the application.
//

#include "GameOfLife.h"
#include "util/util.h"

int main() {
    const int width = getTerminalWidth();
    const int height = getTerminalHeight();

    int* grid = (int*)malloc(width * height * sizeof(int));

	if (grid == NULL) {
		printf("Memory allocation failed\n");
		return 1;
	}

	srand(time(NULL));

    for (int i = 0; i < width * height; i++) {
		grid[i] = rand() % 2;
	}

	for (;;) {
		tick(grid, width, height);
		printBoard(grid, width, height);
		#ifdef WIN32
			Sleep(100);
			system("cls");
		#else
			usleep(100000);
			system("clear");
		#endif
	}

	free(grid);

    return 0;
}

int neighbors(int *ptr, int x, int y, int width, int height) {
	int count = 0;
	for (int i = -1; i < 2; i++) {
		for (int j = -1; j < 2; j++) {
			int col = (x + i + width) % width;
			int row = (y + j + height) % height;
			count += ptr[row * width + col];
		}
	}
	count -= ptr[y * width + x];
	return count;
}

void tick(int* ptr, int width, int height) {
	int *new = (int*)malloc(width * height * sizeof(int));
	if (new == NULL) {
		printf("Memory allocation failed\n");
		return;
	}

	for (int i = 0; i < width * height; i++) {
		int x = i % width;
		int y = i / width;
		int count = neighbors(ptr, x, y, width, height);
		if (ptr[i] == 1) {
			if (count < 2) {
				new[i] = 0;
			}
			else if (count == 2 || count == 3) {
				new[i] = 1;
			}
			else {
				new[i] = 0;
			}
		}
		else {
			if (count == 3) {
				new[i] = 1;
			}
			else {
				new[i] = 0;
			}
		}
	}

	for (int i = 0; i < width * height; i++) {
		ptr[i] = new[i];
	}

	free(new);
}

void printBoard(int* ptr, int width, int height) {
	char* buffer = (char*)malloc(width + 1);
	if (buffer == NULL) {
		printf("Memory allocation failed\n");
		exit(1);
	}
	buffer[width] = '\0';

	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			buffer[j] = (ptr[i * width + j] == 1) ? '#' : ' ';
		}
		printf("%s\n", buffer);
	}

	free(buffer);
}
