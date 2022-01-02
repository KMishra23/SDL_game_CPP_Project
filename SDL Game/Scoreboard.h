#pragma once

#ifndef Scoreboard_HEADER
#define Scoreboard_HEADER

//#include "Game.h"
#include <vector>

class Scoreboard
{
private:
	int score = 0;
	std::vector<int> previousScores;

public:
	Scoreboard();
	~Scoreboard();

	void UpdateScore(int addScore);
	void resetScore();
	int getScore();
	void saveScore();
};

#endif