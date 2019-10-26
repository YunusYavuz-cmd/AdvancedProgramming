#ifndef Plot_h
#define Plot_h
using namespace std;
#include <iostream>
struct Point
{
	int x;
	double y;
};

class Plot
{
	private:
		int size;
		Point *Elements;
	public:
		Plot();
		Plot(const Plot &);
		~Plot();
		Plot Plot::operator + (const Point & pt);
		Plot Plot::operator - (const Point & pt);
	    Plot Plot::operator + (const Plot & pt);
		const Plot& Plot::operator -= (const Point & pt);
		const Plot& Plot::operator += (const Plot & plt);
		const Plot & Plot::operator = (const Plot & plt);	
		int GetSize() const;//accessor
		Point GetElements(int i) const;
		Plot Order();//selection sort
		bool Plot::operator ==(const Plot& plt);
};
		Plot operator +( Point lhs, Plot rhs);
		ostream&operator << (ostream &output,const Plot &plt);
#endif Plot_h