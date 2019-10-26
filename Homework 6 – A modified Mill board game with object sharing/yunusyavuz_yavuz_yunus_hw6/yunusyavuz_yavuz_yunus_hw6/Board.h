#ifndef BOARD_H
#define BOARD_H
using namespace std;
class Board
{
	public:
		Board();
		void displayBoard() const;
		bool putPiece(char ch, int xx, int yy);
		bool movePiece(int x,int y,int xx,int yy);
		char gameOver(); 
		char CellInfo(int x,int y)const;
	private:
		char theBoard[4][4];
		bool CellIsEmpty(int x, int y)const;
};
#endif
