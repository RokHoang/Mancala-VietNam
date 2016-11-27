#pragma once
#include "Board.h"
#include "Bot.h"
#include <time.h>
using namespace std;
class Gameplay
{
private:
	char turn;
	Bot myBot;
public:
	Board myBoard;
	int count;
	void Play();
	void PlayVSBot();
	void BotVSBot();
	void PrintScore();
	void History(int pos, int dir);
	void Undo();
	void BotThink(int &tempPos, int &tempDir);
	int getTurn();
	void swapTurn();
	Gameplay();
	~Gameplay();
};

