// GameOfLife.c : Defines the entry point for the application.
//

#include "GameOfLife.h"


int main() {
    int board[5][5] = {
        {0, 0, 0, 0, 0},
        {0, 0, 1, 0, 0},
        {0, 1, 1, 1, 0},
        {0, 1, 0, 0, 0},
        {0, 0, 0, 0, 0}
    };

    int generations = 10;
    for (int i = 0; i < generations; i++) {
        printBoard(board);
        nextGeneration(board);

        #ifdef _WIN32
            Sleep(1000);
        #else
            sleep(1);
        #endif
    }

    return 0;
}

void nextGeneration(int board[5][5]) {
    int tempBoard[5][5];

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            int neighbors = countNeighbors(board, i, j);
            if (board[i][j] == 1) {
                tempBoard[i][j] = (neighbors == 2 || neighbors == 3) ? 1 : 0;
            }
            else {
                tempBoard[i][j] = (neighbors == 3) ? 1 : 0;
            }
        }
    }

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            board[i][j] = tempBoard[i][j];
        }
    }
}

int countNeighbors(int board[5][5], int x, int y) {
    int count = 0;
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            if (x + i >= 0 && x + i < 5 && y + j >= 0 && y + j < 5) { // Bounds checking
                if (!(i == 0 && j == 0)) {
                    count += board[x + i][y + j];
                }
            }
        }
    }
    return count;
}

void printBoard(int board[5][5]) {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (board[i][j] == 1) {
                printf("*");
            }
            else {
                printf(" ");
            }
        }
        printf("\n");
    }
}