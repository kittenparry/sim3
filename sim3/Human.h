#pragma once

#include "RandomNumberGenerator.h"
#include "Map.h"

RandomNumberGenerator RNG;
Map map;

class Human {
public:
	Human(const char* n) : name(n) {
		age = RNG.BetweenTwoValues(20, 40);
		hunger = RNG.BetweenTwoValues(50, 100);
		sleep = RNG.BetweenTwoValues(50, 100);
		positionX = RNG.BetweenTwoValues(0, map.width);
		positionY = RNG.BetweenTwoValues(0, map.height);
		prevPosX = positionX;
		prevPosY = positionY;
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

	// previous tile positions to reset those back to nothing while drawing
	int getPrevPosX() { return prevPosX; }
	int getPrevPosY() { return prevPosY; }
	void setPrevPosition() {
		prevPosX = positionX;
		prevPosY = positionY;
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
	int prevPosX;
	int prevPosY;
};
