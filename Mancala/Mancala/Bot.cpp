#include "Bot.h"


Bot::Bot()
{
	fstream fIn;
	fIn.open("model1.txt", ios::in);
	ImportNeuralNetwork(fIn);
	root = NULL;
}

void Bot::importState(Board temp)
{
	if (root != NULL)
	{
		delete root;
		root = NULL;
		root = new Board(temp);
	}
	else
	{
		root = new Board(temp);
	}
}

int Bot::think(int& pos, int& direction)
{
	int way;

	int alpha = MIN_SCORE;
	int beta = MAX_SCORE;
	//minimax(*root, MAX_DEPTH, true, way);
	abprunning(*root, MAX_DEPTH, alpha,beta, true , way);

	//double alpha = MIN_SCORE;
	//double beta = MAX_SCORE;
	//ANN(*root, MAX_DEPTH, alpha, beta, true, way);

	direction = ((way % 2) ? 1 : -1);
	pos = (way / 2) + 7;
	return way;
}
int Bot::minimax(Board& node, int depth, bool maxPlayer, int& flagTemp)
{
	if (depth == 0 || !node.checkMancala())
		return node.deltaScore();
	Board temp;
	int flag = 0;
	int tempScore;
	if (maxPlayer)
	{
		int bestValue = MIN_SCORE;
		for (int i = 0; i < 10; i++)
		{
			temp = node;
			if (temp.run4Bot(i, BOT) != -71)
			{
				tempScore = minimax(temp, depth - 1, false,flagTemp);
			}
			else
				continue;
			if (bestValue < tempScore)
			{
				flag = i;
				bestValue = tempScore;
			}
		}
		if (depth == MAX_DEPTH)
		{
			flagTemp = flag;
		}
		return bestValue;
	}
	else
	{
		int bestValue = MAX_SCORE;
		for (int i = 0; i < 10; i++)
		{
			temp = node;
			if (temp.run4Bot(i, PLAYER) != -71)
			{
				tempScore = minimax(temp, depth - 1, true,flagTemp);
			}
			else
				continue;
			if (bestValue > tempScore)
			{
				flag = i;
				bestValue = tempScore;
			}
		}
		if (depth == MAX_DEPTH)
		{
			flagTemp = flag;
		}
		return bestValue;
	}
}

int Bot::abprunning(Board &node, int depth, int alpha, int beta, bool maxPlayer, int& flagTemp)
{
	if (depth == 0 || !node.checkMancala())
		return node.deltaScore();
	Board temp;
	int flag = 0;
	int tempScore;
	if (maxPlayer)
	{
		int bestValue = MIN_SCORE;
		for (int i = 0; i < 10; i++)
		{
			temp = node;
			if (temp.run4Bot(i, BOT) != -71)
			{
				tempScore = abprunning(temp, depth - 1,alpha,beta, false, flagTemp);
			}
			else
				continue;
			if (bestValue < tempScore)
			{
				flag = i;
				bestValue = tempScore;
			}
			alpha = MAX(alpha, bestValue);
			if (beta <= alpha)
				break;
			//if (alpha > 20)//test
				//break;//
		}
		if (depth == MAX_DEPTH)
		{
			flagTemp = flag;
		}
		return bestValue;
	}
	else
	{
		int bestValue = MAX_SCORE;
		for (int i = 0; i < 10; i++)
		{
			temp = node;
			if (temp.run4Bot(i, PLAYER) != -71)
			{
				tempScore = abprunning(temp, depth - 1, alpha, beta,true, flagTemp);
			}
			else
				continue;
			if (bestValue > tempScore)
			{
				flag = i;
				bestValue = tempScore;
			}
			beta = MIN(beta, bestValue);
			if (beta <= alpha)
				break;
			//if (beta < 20 )//test
				//break;//
		}

		if (depth == MAX_DEPTH)
		{
			flagTemp = flag;
		}

		return bestValue;
	}
}
double Bot::ANN(Board& node, int depth, double alpha, double beta, bool maxPlayer, int& flagTemp)
{
	if (depth == 0 || !node.checkMancala())
		//return node.deltaScore();
		return (CalculateOutput(node));
	Board temp;
	int flag = 0;
	int tempScore;
	if (maxPlayer)
	{
		int bestValue = MIN_SCORE;
		for (int i = 0; i < 10; i++)
		{
			temp = node;
			if (temp.run4Bot(i, BOT) != -71)
			{
				tempScore = abprunning(temp, depth - 1, alpha, beta, false, flagTemp);
			}
			else
				continue;
			if (bestValue < tempScore)
			{
				flag = i;
				bestValue = tempScore;
			}
			alpha = MAX(alpha, bestValue);
			if (beta <= alpha)
				break;
			//if (alpha > 20)//test
			//break;//
		}
		if (depth == MAX_DEPTH)
		{
			flagTemp = flag;
		}
		return bestValue;
	}
	else
	{
		int bestValue = MAX_SCORE;
		for (int i = 0; i < 10; i++)
		{
			temp = node;
			if (temp.run4Bot(i, PLAYER) != -71)
			{
				tempScore = abprunning(temp, depth - 1, alpha, beta, true, flagTemp);
			}
			else
				continue;
			if (bestValue > tempScore)
			{
				flag = i;
				bestValue = tempScore;
			}
			beta = MIN(beta, bestValue);
			if (beta <= alpha)
				break;
			//if (beta < 20 )//test
			//break;//
		}

		if (depth == MAX_DEPTH)
		{
			flagTemp = flag;
		}

		return bestValue;
	}
}

int Bot::abprunningtree(int pos, int dir)
{
	Node* temp = NULL;
	int postemp = (pos - 1) * 2 + (dir == 1 ? 1 : 0);
	for (int i = 0; i < roothead->nextState.size(); i++)
	{
		if (i == postemp)
		{
			temp = roothead->nextState[i];
			continue;
		}
		if (roothead->nextState[i] != NULL)
		{
			delete roothead->nextState[i];
		}
	}
	roothead = temp;
	int alpha;
	int beta;
	while (true)
	{

	}
	return 0;

}


void Bot::ImportNeuralNetwork(fstream &fIn){
	/*
	double temp;

	for (int i = 0; i < 7; i++){
	fIn >> temp;
	linearNode.push_back(temp);
	}
	sigmoidNode.resize(6);
	for (int i = 0; i < 6; i++){
	for (int j = 0; j < 13; j++){
	fIn >> temp;
	sigmoidNode[i].push_back(temp);
	}
	}
	return;
	*/
	string word;
	double temp;
	getline(fIn, word);
	getline(fIn, word);

	//threshold
	fIn >> word;
	fIn >> temp;
	linearNode.push_back(temp);
	for (int i = 1; i < 7; i++)
	{
		fIn >> word >> word;
		fIn >> temp; linearNode.push_back(temp);
	}

	sigmoidNode.resize(6);
	for (int i = 0; i < 6; i++)
	{
		getline(fIn, word);
		getline(fIn, word);
		getline(fIn, word);
		fIn >> word;
		fIn >> temp;
		sigmoidNode[i].push_back(temp);
		for (int j = 1; j < 13; j++)
		{
			fIn >> word >> word;
			fIn >> temp;
			sigmoidNode[i].push_back(temp);
		}
	}
}

double Bot::CalculateOutput(Board& temp){
	double outputSig[6] = { 0 };
	for (int i = 0; i < 6; i++){
		for (int j = 0; j < 12; j++){
			outputSig[i] += (double)temp.tile[j] * sigmoidNode[i][j + 1];
		}
		outputSig[i] -= sigmoidNode[i][0];
	}
	double tempOutput = 0;
	for (int i = 0; i < 6; i++){
		tempOutput += outputSig[i] * linearNode[i + 1];
	}
	tempOutput -= linearNode[0];
	return tempOutput;
}
Bot::~Bot()
{
}
