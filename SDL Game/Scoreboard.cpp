#include "Scoreboard.h"
#include <fstream>
#include <iostream>
using namespace std;

Scoreboard::Scoreboard()
{}

Scoreboard::~Scoreboard()
{}

void Scoreboard::UpdateScore(int addScore)
{
	score += addScore;
}

int Scoreboard::getScore()
{
	return score;
}

void Scoreboard::saveScore()
{
	ofstream scores("Scores.txt", ios_base::out | ios_base::app);
	scores << score << endl;
	scores.close();
}

void Scoreboard::resetScore()
{
	score = 0;
}