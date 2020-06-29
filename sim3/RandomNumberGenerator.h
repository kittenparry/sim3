#pragma once

#include <random>

class RandomNumberGenerator {
public:
	RandomNumberGenerator() {}
	~RandomNumberGenerator() {}

	int BetweenTwoValues(int one, int two) {
		std::mt19937 mt(randomDevice());
		std::uniform_int_distribution<int> dist(one, two);
		return dist(mt);
	}

private:
	std::random_device randomDevice;
};
