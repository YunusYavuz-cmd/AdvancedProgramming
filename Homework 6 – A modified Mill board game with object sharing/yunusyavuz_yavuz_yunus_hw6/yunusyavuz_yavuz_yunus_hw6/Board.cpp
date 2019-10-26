#include "Board.h"
#include <iostream>
#include <string>
using namespace std;
Board::Board()
{
	for(int k=0; k<=3; k++)   //adding the board to our array q
	{
		for(int j=0; j<=3; j++)
		{
			theBoard[k][j] = '-';
		}
	}
}
char Board::CellInfo(int x,int y) const 
{
	return theBoard[x][y];   //accessor
}
bool Board::putPiece(char ch,int xx,int yy)
{
	if((xx>=0&&xx<=3)&&(yy>=0&&yy<=3))
	{
		if(CellIsEmpty(xx, yy))   //if destination cell empty
		{
			theBoard[xx][yy] = ch;
			return true;
		}
		else
		{
			cout << "The destination cell is not empty! Try again!" << endl;
			return false;
		}
	}
	else						  //if destination cell is out of range
	{
		cout << "Out of range! Try again!" << endl;
		return false;
	}
}
bool Board::CellIsEmpty(int x,int y) const 
{
	if(theBoard[x][y]=='-') //if cell have '-' its empty so returns true 
	{
		return true;
	}
	return false;
}
void Board::displayBoard()const
{
	cout<<endl;
	for(int k=0;k<=3;k++)  //displays the board
	{
		for(int j=0;j<=3;j++)
		{
			cout<<theBoard[k][j] << " ";
		}
		cout<<endl;
	}
	cout<<endl;
}
bool Board::movePiece(int x,int y,int xx,int yy)
{
	if(CellIsEmpty(xx,yy))  //if the target cell empty
	{
		if(xx==x+1&&y==yy)   //moving up
		{
			theBoard[xx][yy]=theBoard[x][y];//changing target destination
			theBoard[x][y]='-';//make - since it will be empty when changed
		}
		else if(xx==x-1&&y==yy)//moving down
		{  
			theBoard[xx][yy]=theBoard[x][y];
			theBoard[x][y]='-';
		}
		else if(yy==y-1&&x==xx)//moving left
		{  
			theBoard[xx][yy]=theBoard[x][y];
			theBoard[x][y]='-';
		}
		else if(yy==y+1&&x==xx)//moving right
		{  
			theBoard[xx][yy]=theBoard[x][y];
			theBoard[x][y]='-';
		}
		else//if not adjacent
		{
			cout<<"Source and destination cells are not adjacent! Try Again!"<<endl;
			return false;
		}
		return true;//if its not adjacent it will get in else and function will be finish since it returns false but its adjecent it will be true for sure
	}
	else 
	{
		cout<<"The destination cell is not empty! Try again!"<<endl;
		return false;
	}

}
char Board::gameOver()
{
	for(int i=0;i<=3;i++) 
	{
		for(int j=0;j<=1;j++)
		{
			if(theBoard[i][j]!='-'&&theBoard[i][j]==theBoard[i][j+1]&&theBoard[i][j]==theBoard[i][j+2])//checking every row
				return theBoard[i][j];
		}
	}
	for(int j=0;j<=3;j++) 
	{
		for(int i=0;i<=1;i++)
		{
			if(theBoard[i][j]!='-'&&theBoard[i][j]==theBoard[i+1][j]&&theBoard[i][j]==theBoard[i+2][j])//checking every column
				return theBoard[i][j];
		}
	}
	
	return '-';
}