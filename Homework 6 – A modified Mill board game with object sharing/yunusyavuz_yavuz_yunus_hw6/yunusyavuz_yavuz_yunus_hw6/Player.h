#ifndef PLAYER_H
#define PLAYER_H
#include<iostream>
#include "board.h"
using namespace std;
class Player
{
	public:
		Player();
		Player::Player(char ch,Board &theBoard)
		:playerCh(ch), board(theBoard)
		{ }
		bool put(int x,int y);
		char getSymbol();
		bool isWinner();
		bool move(int x,int y,int xx,int yy);
	private:
		Board &board;
		char playerCh;
};
#endif