#include "Board.h"



void Board::printBoard()
{
	for (int i = 0; i < (NUM / 2); i++) {
		cout << (int)tile[i] << '\t';
	}
	cout << endl << '\t';
	for (int i = 11; i >= (NUM / 2); i--)
		cout << (int)tile[i] << '\t';
	cout << endl;
}

char Board::run(int pos, int direction, queue<int> &history)
{
	char postemp = pos;
	char flagEmpty = true;//neu da het quan

	for (char i = 1; i < 6; i++)
	{
		if (tile[(pos / 6) * 6 + i] != 0)
		{
			flagEmpty = false;
			break;
		}
	}
	if (flagEmpty)
	{
		for (char i = 1; i < 6; i++)
		{
			tile[(pos / 6) * 6 + i] += 1;

		}
		score[pos / 6] -= 5;
	}
	char total = 0;
	int count = (int)tile[pos];
	tile[pos] = 0;
	history.push((pos) * 100 + tile[pos]);
	for (; count != 0; count--) {
		if (pos == 11 && direction == 1) {
			pos = 0;
		}
		else if (pos == 0 && direction == -1) {
			pos = 11;
		}
		else
			pos = pos + direction;
		tile[pos]++;
		history.push((pos) * 100 + tile[pos]);
		if (count == 1) {
			if ((pos + direction) == 0 || (pos + direction) == (NUM / 2) || (pos + direction) == NUM)
				break;
			else {
				if (pos == 11 && direction == 1) {
					pos = -1;
				}
				else if (pos == 0 && direction == -1) {
					pos = 12;
				}
				if (tile[pos + direction] != 0) {
					count = tile[pos + direction] + 1;
					tile[pos + direction] = 0;
					history.push((pos + direction) * 100 + tile[pos + direction]);
					pos += direction;
					continue;
				}
				else
					total = eat(pos, direction, history);
			}
		}
	}
	if (checkMancala())
	{
		flagEmpty = true;//neu da het quan
		postemp = (postemp / 6) ? 0 : 1;
		for (char i = 1; i < 6; i++)
		{
			if (tile[(postemp)* 6 + i] != 0)
			{
				flagEmpty = false;
				break;
			}
		}
		if (flagEmpty)
		{
			for (char i = 1; i < 6; i++)
			{
				tile[(postemp)* 6 + i] += 1;

			}
			score[postemp] -= 5;
		}
	}
	return total;
}

bool Board::checkEmptyTurn(int pos)
{
	char flagEmpty = true;//neu da het quan

	for (char i = 1; i < 6; i++)
	{
		if (tile[(pos / 6) * 6 + i] != 0)
		{
			flagEmpty = false;
			break;
		}
	}
	return flagEmpty;
}

int Board::run4Bot(int way, int turn)
{
	char tempDir;
	char tempPos;
	queue<int> history;
	if (turn == BOT)
	{
		tempDir = ((way % 2) ? 1 : -1);
		tempPos = (way / 2) + 7;
	}
	else
	{
		tempDir = ((way % 2) ? 1 : -1);
		tempPos = way / 2;
	}
	if (tile[tempPos] == 0)
		return -71;
	char tempScore = run(tempPos, tempDir, history);

	if (tempScore == -1)
		return -71;
	else
	{
		score[turn] += tempScore;
	}
	return deltaScore();
}

bool Board::checkPosEmpty(int pos)
{
	if (tile[pos] == 0)
		return false;
	return true;
}

char Board::eat(int pos, int direction, queue<int> &history)
{
	if (pos == 11 && direction == 1) {
		pos = 0;
	}
	else if (pos == 0 && direction == -1) {
		pos = 11;
	}
	else pos = pos + direction;
	if (tile[pos] == 0) {

		if (pos == 11 && direction == 1) {
			pos = 0;
		}
		else if (pos == 0 && direction == -1) {
			pos = 11;
		}
		else pos += direction;
		if (tile[pos] == 0)
			return 0;
		char total = tile[pos];
		tile[pos] = 0;
		history.push((pos)* 100 + tile[pos]);

		return total + eat(pos, direction, history);
	}
	return 0;

}

bool Board::checkMancala()
{
	if (tile[0] == 0 && tile[NUM / 2] == 0)
		return false;
	return true;
}


bool Board::checkEmpty(int side)
{
	int i, j;
	if (side == 0) {
		i = 1; j = 5;
	}
	else
		i = 7; j = 12;
	for (; i <= j; i++) {
		if (tile[i] != 0)
			return true;
	}
	return false;
}

Board::Board()
{
	for (int i = 0; i < NUM; i++)
		tile.push_back(5);
	tile[0] = tile[NUM / 2] = 10;
	score.push_back(0);
	score.push_back(0);
}
int Board::deltaScore()
{
	return score[BOT] - score[PLAYER];
}

Board::~Board()
{
}
