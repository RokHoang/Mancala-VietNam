#pragma once
#include <iostream>
#include <vector>
#include <queue>
#include <fstream>
using namespace std;
#define NUM 12
#define PLAYER 0
#define BOT 1
#define MAX(a,b) ((a<b)?b:a)
#define MIN(a,b) ((a>b)?b:a)
class Board
{
public:
	bool checkEmptyTurn(int pos);
	vector<char> tile;
	vector<char> score;
	void printBoard();
	char run(int pos, int direction, queue<int> &history);
	bool checkPosEmpty(int pos);
	char eat(int pos, int direction, queue<int> &history);
	bool checkMancala();
	bool checkEmpty(int side);
	int deltaScore();//ham danh gia heuristic
	int run4Bot(int way, int turn);
	Board();
	~Board();
};

