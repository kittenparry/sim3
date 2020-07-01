#include <iostream>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <vector>

#include "Human.h"
#include "Map.h"

// interval of each refresh in time system below
const int NUM_SECONDS = 1;

void drawMap(int, int, int*, std::vector<int>);

int main() {
    int population = 7;
    std::vector<Human*> humans;
    for (int i = 0; i < population; i++) {
        humans.push_back(new Human("Adam"));
    }

    // map stuff below
    int mapWidth = map.width;
    int mapHeight = map.height;
    int* mapContents = new int[mapWidth * mapHeight];
    std::vector<int> tilesFood;

    for (int y = 0; y < mapHeight; y++) {
        for (int x = 0; x < mapWidth; x++) {
            mapContents[y * mapWidth + x] = 0;
        }
    }

    srand(time(NULL));
    int food = 15;
    int tempFoodVal = 0;
    while (food) {
        // making sure to not have duplicate values
        tempFoodVal = rand() % (mapWidth * mapHeight);
        while (std::count(tilesFood.begin(), tilesFood.end(), tempFoodVal)) {
            tempFoodVal = rand() % (mapWidth * mapHeight);
        }
        tilesFood.push_back(tempFoodVal);
        food--;
    }
    
    // timer system below
    double time_counter = 0;

    clock_t this_time = clock();
    clock_t last_time = this_time;

    while (true) {
        this_time = clock();

        time_counter += (double) (this_time - last_time);

        last_time = this_time;

        if (time_counter > (double) (NUM_SECONDS * CLOCKS_PER_SEC)) {
            time_counter -= (double) (NUM_SECONDS * CLOCKS_PER_SEC);

            // TODO: do human actions and stuff here?
            printf("\x1b[%dA", mapHeight); // base is: "\x1b[A", goes up x number of lines, src: https://stackoverflow.com/a/42807909/4085881

            for (int i = 0; i < humans.size(); i++) {
                humans[i]->setPrevPosition();
                mapContents[humans[i]->getPositionY() * mapWidth + humans[i]->getPositionX()] = 2;
            }

            drawMap(mapWidth, mapHeight, mapContents, tilesFood);

            for (int i = 0; i < humans.size(); i++) {
                mapContents[humans[i]->getPrevPosY() * mapWidth + humans[i]->getPrevPosX()] = 0; // reset old position to nothing
                humans[i]->moveAround();
            }
        }
    }


    delete[] mapContents;
    std::vector<Human*>().swap(humans);

    return 0;
}

void drawMap(int w, int h, int map[], std::vector<int> food) {

    // assign food if it's not a human tile
    for (int i = 0; i < food.size(); i++) {
        if (map[food[i]] != 2) map[food[i]] = 1;
    }

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
