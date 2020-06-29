#include <iostream>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#include "Human.h"

// interval of each refresh in time system below
const int NUM_SECONDS = 1;

void drawMap(int w, int h, int map[]);

int main() {
    Human* h1 = new Human("Adam", 23);


    // map stuff below
    int mapWidth = 10;
    int mapHeight = 12;
    int* mapContents = new int[mapWidth * mapHeight];

    for (int y = 0; y < mapHeight; y++) {
        for (int x = 0; x < mapWidth; x++) {
            mapContents[y * mapWidth + x] = 0;
        }
    }

    mapContents[h1->getPositionY() * mapWidth + h1->getPositionX()] = 2;

    srand(time(NULL));
    int food = 15;
    while (food) {
        int rx = rand() % mapWidth;
        int ry = rand() % mapHeight;

        if (mapContents[ry * mapWidth + rx] == 0 && mapContents[ry * mapWidth + rx] != 2) {
            mapContents[ry * mapWidth + rx] = 1;
            food--;
        }
    }

    drawMap(mapWidth, mapHeight, mapContents);

    delete[] mapContents;

    
    // timer system below
    /*
    int count = 1;

    double time_counter = 0;

    clock_t this_time = clock();
    clock_t last_time = this_time;

    // printf("Gran = %ld\n", NUM_SECONDS * CLOCKS_PER_SEC);

    while (true) {
        this_time = clock();

        time_counter += (double) (this_time - last_time);

        last_time = this_time;

        if (time_counter > (double) (NUM_SECONDS * CLOCKS_PER_SEC)) {
            time_counter -= (double) (NUM_SECONDS * CLOCKS_PER_SEC);

            // TODO: do human actions and stuff here?
            printf("%d\n", count);
            count++;
        }

        // printf("DebugTime = %f\n", time_counter);
    }
    */
    return 0;
}

void drawMap(int w, int h, int map[]) {
    char tileChar;
    for (int y = 0; y < h; y++) {
        for (int x = 0; x < w; x++) {
            switch (map[y * w + x]) {
            case 0:
                tileChar = ' ';
                break;
            case 1: // food at the moment
                tileChar = '+';
                break;
            case 2:
                tileChar = 'O';
                break;
            default:
                break;
            }

            printf("(%c)", tileChar);
        }
        printf("\n");
    }
}
