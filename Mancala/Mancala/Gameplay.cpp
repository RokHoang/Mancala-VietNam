#include "Gameplay.h"



//void Gameplay::Play()
//{
//	cout << "Nhap vao huong va luot di: ";
//	int tempPos, tempDir;
//	while (myBoard.checkMancala()) {
//		do
//		{
//			if (turn == 0)
//				cout << "Nguoi choi 1: cac o: 1,2,3,4,5: ";
//			else
//				cout << "Nguoi choi 2: cac o: 7,8,9,10,11: ";
//			cin >> tempPos;
//		} while (myBoard.tile[tempPos] == 0 && !myBoard.checkEmptyTurn(tempPos));
//		do
//		{
//			cout << "Huong di:\n -1 nguoc chieu kim dong ho\n1 chieu kim dong ho\nLua chon: ";
//			cin >> tempDir;
//		} while (tempDir != -1 && tempDir != 1);
//		int tempScore = myBoard.run(tempPos, tempDir);
//		myBoard.score[(int)turn] += tempScore;
//		myBoard.printBoard();
//		turn = (turn != 1) ? 1 : 0;
//		PrintScore();
//	}
//}

void Gameplay::BotThink(int &tempPos, int &tempDir){
	myBot.importState(myBoard);
	myBot.think(tempPos, tempDir);
}

//void Gameplay::PlayVSBot()
//{
//	//cout << "Nhap vao huong va luot di: ";
//	/*clock_t start;
//	clock_t end;*/
//	while (myBoard.checkMancala()) {
//		/*cout << "--------------------------------------------------" << endl;
//		cout << "Luot thu: " << count << endl;
//		start = clock();*/
//		do
//		{
//			if (turn == PLAYER)
//			{
//				//cout << "Nguoi choi 1: cac o: 1,2,3,4,5: ";
//				cout << "Player:\nLua chon: ";
//				cin >> tempPos;
//			}
//			else
//			{
//				myBot.importState(myBoard);
//				myBot.think(tempPos, tempDir);
//				cout << "Bot:\nLua chon: " << tempPos << "\nHuong di: " << tempDir << endl;
//			}
//			//cout << "Nguoi choi 2: cac o: 7,8,9,10,11: ";
//			//cin >> tempPos;
//		} while (myBoard.tile[tempPos] == 0 && !myBoard.checkEmptyTurn(tempPos));
//		do
//		{
//			if (turn == PLAYER)
//			{
//				//cout << "Huong di:\n-1 nguoc chieu kim dong ho\n1 chieu kim dong ho\nLua chon: ";
//				cout << "Huong di: ";
//				cin >> tempDir;
//			}
//			else
//			{
//
//			}
//		} while (tempDir != -1 && tempDir != 1);
//		int tempScore = myBoard.run(tempPos, tempDir);
//		myBoard.score[(int)turn] += tempScore;
//		myBoard.printBoard();
//		turn = (turn != 1) ? 1 : 0;
//		PrintScore();
//		count++;
//		/*end = clock();
//		cout << "Time: " << (end - start) / CLOCKS_PER_SEC << endl;*/
//	}
//	for (int i = 1; i < 6; i++)
//		myBoard.score[0] += myBoard.tile[i];
//	for (int i = 7; i < 12; i++)
//		myBoard.score[1] += myBoard.tile[i];
//	cout << "Diem cuoi cung: " << endl;
//	PrintScore();
//}

void Gameplay::swapTurn(){
	turn = (turn != 1) ? 1 : 0;
}

void Gameplay::BotVSBot()
{
}

int Gameplay::getTurn(){
	return (int)turn;
}

void Gameplay::PrintScore()
{
	cout << endl << "Diem so nguoi choi 1: " << (int)myBoard.score[0] << endl;
	cout << "Diem so nguoi choi 2: " << (int)myBoard.score[1] << endl;
}

void Gameplay::History(int pos, int dir)
{
}


Gameplay::Gameplay()
{
	count = 0;
	turn = PLAYER;
}


Gameplay::~Gameplay()
{
}
