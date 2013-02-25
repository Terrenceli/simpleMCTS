// simpleMCTS.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


int _tmain(int argc, _TCHAR* argv[])
{
	/*
	TreeNode* tn=new TreeNode();
	for(long long i=0;i<100;i++){


	tn->selectAction();
	tn->expand();


	}
	cout<<"end"<<endl;
	getchar();


	delete tn;
	return 0;
	*/

	
	//Game* g = new ConnectFour();
	Game* g = new TicTacToe();
	//Game g = new ConnectFour();
	shared_ptr<Player> p1;
	shared_ptr<Player> p2;

	int p1Wins = 0, p2Wins = 0, draws = 0;
	clock_t time = clock();
	int numOfGames=5000;
	for (int i = 0; i < numOfGames; i++) {
		//p1 = new RandomRolloutPlayer(g, true, 50);
		//p1 = new HumanPlayer(g, true);
		p1 = shared_ptr<Player>(new RandomPlayer(g, true));
		p2 = shared_ptr<Player>(new RandomRolloutPlayer(g, false,30));

		while (g->gameStatus(p2->getCurState()) == Game::status::ONGOING) {
			//p1 goes
//			cout<<"Player 1's turn:"<<endl;
			p1->MakeMove();
			p2->updateGameState(p1->getCurState());
//			g->printState(p1->getCurState());
//			cout<<"Status is " << g->gameStatus(p1->getCurState())<<endl;


			//p2 goes
//			cout<<"Player 2's turn:"<<endl;
			p2->MakeMove();
			p1->updateGameState(p2->getCurState());
//			g->printState(p1->getCurState());
//			cout<<"Status is " <<g->gameStatus(p1->getCurState())<<endl;
		}

		if (g->gameStatus(p2->getCurState()) == Game::status::DRAW) {
			draws++;
		} else if (g->gameStatus(p2->getCurState()) == Game::status::PLAYER1WIN) {
			p1Wins++;
		} else if (g->gameStatus(p2->getCurState()) == Game::status::PLAYER2WIN) {
			p2Wins++;
		}

		cout<<"P1 wins: " <<p1Wins << ", P2 wins: "
			<<p2Wins << ", Draws: " <<draws<<endl;
		delete g;
	}
	cout<<"P1 wins: " <<p1Wins << ", P2 wins: "
		<<p2Wins << ", Draws: " <<draws<<endl;
	clock_t time_used = clock() - time;
	cout<<"total time: "<<time_used<<"ms"<<endl;
	cout<<"average time per game: "<<time_used/numOfGames<<"ms"<<endl;
	getchar();
}

