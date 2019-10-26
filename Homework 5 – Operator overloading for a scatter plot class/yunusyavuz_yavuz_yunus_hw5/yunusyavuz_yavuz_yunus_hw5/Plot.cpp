#include "Plot.h"
#ifndef iostream
#include <iostream>
#endif // !iostream
using namespace std;

Plot::Plot()					 //constructor
{
	size=0;
	Elements=NULL;
}
Plot::Plot(const Plot & copy)	 //deep copy const
{
	size=copy.size;
	if(size != 0) 
	{
		Elements=new Point[size];
		for(int i=0;i<copy.size;i++)
		{
			Elements[i].x=copy.Elements[i].x;
			Elements[i].y=copy.Elements[i].y;
		}
	}
	else 
	{
		Elements = NULL;
	}
}
Plot::~Plot()						//destructor
{
	size=0;
	if(Elements!=NULL)
		delete[] Elements;
}
Plot Plot::operator + (const Plot & plt)
{
	Plot newPlot;
	if(size==0)   //if its already empty
	{
		newPlot.size=plt.size;
		newPlot.Elements=new Point[newPlot.size];
		for(int i=0;i<plt.size;i++)
		{
			newPlot.Elements[i].x=plt.Elements[i].x;
			newPlot.Elements[i].y=plt.Elements[i].y;
		}
		return newPlot;
	}
	else
	{ 
		int sameX=0; //for same x coords
		for(int i=0;i<plt.size;i++)
		{
			if(Elements[i].x==plt.Elements[i].x)//how many same x coord points
			{
				sameX++;
			}
		}
		if(sameX==0)
		{
			newPlot.size=size+plt.size;
			newPlot.Elements=new Point[newPlot.size]; //creating new plot if no same x coords same size as the sum of two
			for(int i=0;i<size;i++)
			{
				newPlot.Elements[i].x=Elements[i].x; // adding 2 of them
				newPlot.Elements[i].y=Elements[i].y;
			}
			for(int i=0;i<plt.size;i++)
			{
				newPlot.Elements[i].x=plt.Elements[i].x; //adding second one
				newPlot.Elements[i].y=plt.Elements[i].y;
			}
			return newPlot;
		}
		else											//if there are same x coords
		{
			Plot samePlots,difPlots;
			samePlots.size=sameX;
			samePlots.Elements=new Point [sameX]; 
			difPlots.size=size+plt.size-2*sameX;  //*2 same since we need to substract from two of them
			difPlots.Elements=new Point [difPlots.size];
			int i=0;
			int j=0;
			int k=0;
			for(;i<plt.size;i++)
			{
				bool diff=true;
				for(int a=0;a<size;a++)  // finding different ones
				{
					if(Elements[a].x==plt.Elements[i].x)
					{
						diff=false;
					}

				}
				if(diff)
				{
					difPlots.Elements[j].x=plt.Elements[i].x;  //seperating different ones
					difPlots.Elements[j].y=plt.Elements[i].y;
					j++;
				}
				else
				{
					samePlots.Elements[k].x=plt.Elements[i].x;  // separating same ones
					samePlots.Elements[k].y=plt.Elements[i].y;
					k++;
				}
	
			}
			for(int a=0;a<size;a++)           //doing same seperating different points 
			{
				bool diffCheck=true;
				for(int b=0;b<plt.size;b++)
				{
					if(Elements[a].x==plt.Elements[b].x)
					{
						diffCheck=false;
					}		
				}
				if(diffCheck)  //if different points(x coords)
				{
						difPlots.Elements[j].x=Elements[a].x;
						difPlots.Elements[j].y=Elements[a].y;
						j++;
				}
			}
			newPlot.size=plt.size+size-sameX; //creating the plot that will returned
			newPlot.Elements=new Point[newPlot.size];
			int a=0;
			for(;a<difPlots.size;a++)
			{
				newPlot.Elements[a].x=difPlots.Elements[a].x;  //adding different ones
				newPlot.Elements[a].y=difPlots.Elements[a].y;
			}
			for(int i=0;i<samePlots.size;i++)    
			{
				for(int j=0;j<size;j++)
				{
					if(samePlots.Elements[i].x==Elements[j].x)//adding same points
					{
						newPlot.Elements[a].x=samePlots.Elements[i].x;
						newPlot.Elements[a].y=(samePlots.Elements[i].y+Elements[j].y)/2;
						a++;
					}
				}
			}
			return newPlot;
		}
	}
}
bool Plot::operator ==(const Plot& plt)  //boolean
{
		if(size!=plt.size)//if not same size already false
		{
			return false;
		}
		else
		{
			for(int i=0;i<size;i++)
			{
				if(Elements[i].x!=plt.Elements[i].x||Elements[i].y!=plt.Elements[i].y)
					return false;
			}
			return true;
		}


}
Plot Plot::operator - (const Point & pt)
 {
	bool same=false;
	int i=0;
	for(;i<size&&!same;i++)
	{
		if(Elements[i].x==pt.x && Elements[i].y==pt.y)
			same=true;
	}
	if(same&&size!=1)
	{
		i--;
		Plot newPlot;
		newPlot.size=size-1;//since its a point size minus one
		newPlot.Elements=new Point[size-1];
		int j=0;
		for(int a=0;a<newPlot.size;a++)
		{
			if(a!=i)
			{
				newPlot.Elements[a].x=Elements[j].x;
				newPlot.Elements[a].y=Elements[j].y;
			}
			else
			{
				j++;
				newPlot.Elements[a].x=Elements[j].x;
				newPlot.Elements[a].y=Elements[j].y;
			}

			j++;
		}
		return newPlot;
	}
	else if(size==1)
	{
		Plot newPlot;
		return newPlot;
	}
	else
	{
		return *this;
	}


}
const Plot& Plot::operator -= (const Point & pt)
{
	*this= *this-pt;//send to the - operator
	return *this;
}
Plot Plot::operator + (const Point & pt)	
{
	Plot newPlt;
	bool check=false;
	if(size==0)
	{
		newPlt.size=1;
		newPlt.Elements=new Point[newPlt.size];
		newPlt.Elements[0].x=pt.x;
		newPlt.Elements[0].y=pt.y;
		return newPlt;
	}
	else
	{
		int i=0;
		for(;i<size&&!check;i++)
		{
			if(Elements[i].x==pt.x)
				check=true;
		}
		i--;//since it will add one more after we found
		if(check)
		{
			Plot newbie(*this);
			newbie.Elements[i].y=(Elements[i].y+pt.y)/2;
			return newbie;
		}
		else
		{
			newPlt.size=size+1;
			newPlt.Elements=new Point[newPlt.size];
			int z=0;
			for(;z<size;z++)
			{
				newPlt.Elements[z].x=Elements[z].x;
				newPlt.Elements[z].y=Elements[z].y;
			}
			newPlt.Elements[z].x=pt.x;
			newPlt.Elements[z].y=pt.y;
		}
		return newPlt;
	}
}
const Plot& Plot::operator += (const Plot & plt)
{
   *this= *this+plt;//sending to the + operator
   return *this;
}
Point Plot::GetElements(int i) const				//accessor
{
	Point El;
	El.x=Elements[i].x;
	El.y=Elements[i].y;

	return El;
}
int Plot::GetSize() const						
{
	return size;
}

const Plot & Plot::operator = (const Plot & plt)
{
	if(this != &plt)
	{
		size=plt.size;
		delete[] Elements;//clear old elements
		Elements=new Point[size];
		for(int i=0; i<plt.size;i++)
		{
			Elements[i]=plt.Elements[i];
		}
	}
	return *this;
}
Plot Plot::Order()				//SELECTION SORT 
{
	Plot newPlot(*this);
	Point pt;
	for(int i=0;i<newPlot.size-1;i++)
	{
		int min=i;
		for(int j=i+1;j<newPlot.size;j++)
		{
			if(newPlot.Elements[j].x<newPlot.Elements[min].x)
			{
				min=j;
			}

		}
		if(min!=i)
		{
			pt=newPlot.Elements[i];
			newPlot.Elements[i]=newPlot.Elements[min];  //min to max
			newPlot.Elements[min]=pt;
		}
	}
	return newPlot;
}
Plot operator +( Point lhs, Plot rhs)
{
	Plot ret;
	ret=rhs + lhs; 
	return ret;
}
ostream&operator << (ostream &output,const Plot &plt) //output
{
	int sizeOf=plt.GetSize();
	Plot newPlot(plt);
	Plot newPlot2=newPlot.Order();  //sort member function
	int i=0;
	for(;i<sizeOf-1 ;i++)
	{
		Point out=newPlot2.GetElements(i);
		output<<"("<<out.x<<","<<out.y<<")"<<",  ";
	}
	Point out=newPlot2.GetElements(i);
	output<<"("<<out.x<<","<<out.y<<")";
	return output;
}