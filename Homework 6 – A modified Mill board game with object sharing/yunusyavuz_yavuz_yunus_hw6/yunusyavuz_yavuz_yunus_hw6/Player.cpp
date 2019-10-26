#include "player.h"
#include "board.h"
#include<iostream>
using namespace std;
bool Player::move(int x,int y,int xx,int yy)
{
	if(board.CellInfo(x,y)==playerCh)//belongs to player or not
	{
		if(board.movePiece(x,y,xx,yy))//moves and return boolean if not returns false
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else if(board.CellInfo(x,y)=='-')//if the cell is empty 
	{
		cout<<"The source cell is empty! Try again!"<<endl;
		return false;
	}
	else
	{
		cout<<"The game piece at source coordinates isn't yours! Try again!"<<endl;
		return false;
	}
}
char Player::getSymbol()
{
	return playerCh; //accessor
}
bool Player::isWinner()
{
	if(board.gameOver()!= '-'&&board.gameOver()==playerCh)
		return true;//if there re a winner it will return the winner char other then '-'
	else
		return false;
}
bool Player::put(int x,int y)
{
	return board.putPiece(playerCh,x,y);//accessor
}