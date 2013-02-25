int main(string args[])
{
	Game g = new TicTacToe();
	//Game g = new ConnectFour();
	Player p1, p2;

	int p1Wins = 0, p2Wins = 0, draws = 0;

	for (int i = 0; i < 100; i++) {
		p1 = new RandomRolloutPlayer(g, true, 100);
		//p1 = new HumanPlayer(g, true);
		//p1 = new RandomPlayer(g, true);
		p2 = new RandomRolloutPlayer(g, false, 100);
		while (g.gameStatus(p2.getCurState()) == Game.status.ONGOING) {
			//p1 goes
			System.out.println("Player 1's turn:");
			p1.MakeMove();
			p2.updateGameState(p1.getCurState());
			g.printState(p1.getCurState());
			System.out.println("Status is " + g.gameStatus(p1.getCurState()));


			//p2 goes
			System.out.println("Player 1's turn:");
			p2.MakeMove();
			p1.updateGameState(p2.getCurState());
			g.printState(p1.getCurState());
			System.out.println("Status is " + g.gameStatus(p1.getCurState()));
		}

		if (g.gameStatus(p2.getCurState()) == Game.status.DRAW) {
			draws++;
		} else if (g.gameStatus(p2.getCurState()) == Game.status.PLAYER1WIN) {
			p1Wins++;
		} else if (g.gameStatus(p2.getCurState()) == Game.status.PLAYER2WIN) {
			p2Wins++;
		}

		System.out.println("P1 wins: " + p1Wins + ", P2 wins: "
			+ p2Wins + ", Draws: " + draws);
	}
	return 0;
}