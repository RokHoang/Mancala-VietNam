#include "Board.h"
#include <vector>
#include <string>
#pragma once
using namespace std;
#define MAX_SCORE 71
#define MIN_SCORE -71
#define MAX_DEPTH 7

struct Node
{
	char pos;
	char dir;
	char level;
	Board* state;
	vector<Node*> nextState;
	~Node()
	{
		delete state;
		for (int i = 0; i < nextState.size(); i++)
		{
			if (nextState[i] != NULL)
				delete nextState[i];
		}
	}
};

class Bot
{
	Board *root;
	Node *roothead;
public:
	vector<double> linearNode;
	vector<vector<double>> sigmoidNode;
	int think(int& pos, int& direction);
	int minimax(Board& node, int depth, bool maximizingPlayer, int& flag);
	int abprunning(Board& node, int depth, int alpha, int beta, bool maximizingPlayer, int& flag);
	double ANN(Board& node, int depth, double alpha, double beta, bool maximizingPlayer, int& flag);
	int abprunningtree(int pos, int dir);
	void importState(Board temp);
	double CalculateOutput(Board& temp);
	void ImportNeuralNetwork(fstream&);
	Bot();
	~Bot();
};
