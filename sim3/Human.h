#pragma once

#include "RandomNumberGenerator.h"

RandomNumberGenerator RNG;

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
		positionX = x;
		positionY = y;
	}

private:
	const char* name;
	int age;
	int hunger;
	int sleep;
	int positionX;
	int positionY;
};
