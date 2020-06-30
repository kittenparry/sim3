#pragma once

#include "RandomNumberGenerator.h"
#include "Map.h"

RandomNumberGenerator RNG;
Map map;

class Human {
public:
	Human(const char* n, int a) : name(n), age(a) {
		hunger = RNG.BetweenTwoValues(50, 100);
		sleep = RNG.BetweenTwoValues(50, 100);
		positionX = 4;
		positionY = 4;
	}
	~Human();

	int getHunger() { return hunger; }
	int getSleep() { return sleep; }

	int getPositionX() { return positionX; }
	int getPositionY() { return positionY; }
	void setPosition(int x, int y) {
		if (x < 0) {
			positionX = 0;
		} else if (x >= map.width) {
			positionX = map.width - 1;
		} else {
			positionX = x;
		}
		if (y < 0) {
			positionY = 0;
		} else if (y >= map.height) {
			positionY = map.height - 1;
		} else {
			positionY = y;
		}
	}

	void moveAround() {
		switch (RNG.BetweenTwoValues(1, 4)) {
		case 1:
			setPosition(positionX, positionY - 1);
			break;
		case 2:
			setPosition(positionX -1, positionY);
			break;
		case 3:
			setPosition(positionX, positionY + 1);
			break;
		case 4:
			setPosition(positionX + 1, positionY);
			break;
		default:
			break;
		}
	}

private:
	const char* name;
	int age;
	int hunger;
	int sleep;
	int positionX;
	int positionY;
};
