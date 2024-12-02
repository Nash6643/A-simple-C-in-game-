#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 4

void initializeTable(char table[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            table[i][j] = '.';
        }
    }
}


void placeCharacter(char table[SIZE][SIZE], char character, int count) {
    for (int i = 0; i < count; i++) {
        int p = rand() % SIZE;
        int l = rand() % SIZE;
        table[p][l] = character;
    }
}







void printTable(char table[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%c ", table[i][j]);
        }
        printf("\n");
    }
}

int main() {
    char table[SIZE][SIZE];
    int x, y;

    srand(time(NULL));
    x = rand() % SIZE;
    y = rand() % SIZE;

    initializeTable(table);
    table[x][y] = '@';
    
    //
     int n = SIZE;
    int starCount = (int)(0.15 * n * n);
     int OCount = (int)(0.1 * n * n);
    placeCharacter(table, '*', starCount);
    placeCharacter(table, 'O', OCount);

    
    
    
    
    
    
    
    
    
    
    
    
    
    

    char move;
    while (1) {
        printTable(table);
        printf("Move (@) with w (up), s (down), a (left), d (right), q (quit): ");
        scanf(" %c", &move);

        table[x][y] = '.'; // Clear current position

        if (move == 'w' && x > 0) {
            x--;
        } else if (move == 's' && x < SIZE - 1) {
            x++;
        } else if (move == 'a' && y > 0) {
            y--;
        } else if (move == 'd' && y < SIZE - 1) {
            y++;
        } else if (move == 'q') {
            break;
        }

        table[x][y] = '@'; // Update new position
    }

    return 0;
}

