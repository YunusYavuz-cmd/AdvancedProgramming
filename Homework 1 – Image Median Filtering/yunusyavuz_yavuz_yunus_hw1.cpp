#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include "strutils.h"
#include <iomanip>

using namespace std;

bool NumCheck(string num)
{
	for(int i=0;i<num.length();i++)
	{
		if(num.at(i)<48 || num.at(i)>57)   //checking by ASCII table (if not num)
		{
			return false;
		}

	}
	return true;
}

void PrintFilteredVec(vector<vector<int>> vec)    //printing the filtered vectors
{
	for (int j=0; j < vec.size(); j++)
    {   
		for (int k=0; k < vec[0].size(); k++)
        {   
			cout << setw(4) << vec[j][k];
        }
        cout << endl;
    }
}


int Median(vector<int> vec)
{

	if(vec.size()%2==0)										 //taking median if even
	{
		return (vec[vec.size()/2]+vec[(vec.size()/2)-1])/2;
	}
	else													//taking median if odd
	{
		return vec[(vec.size()/2)];
	}

}

void Sort(vector<int> &vec)									//sorting the subvec
{
	for(int i=vec.size()-1;i>0;i--)       
	{
		for(int j=0;j<i;j++)
		{
			if(vec[j+1]<vec[j])
				swap(vec[j],vec[j+1]);							//sorting with swapping		
		}
	}


}
void SubVector(const vector<vector<int>> & mat,int filtersize)
{
	int num=filtersize/2;
	int numneg=-num;
	vector<vector<int>> FilteredVec;
	int filteredNums;
	for(int j=0;j<mat.size();j++)                         //we will take subvectors for all numbers in matrix so we will start with [0][0] to [size-1][size-1]
	{
		vector<int> Fvec;
		for(int i = 0; i < mat[0].size(); i++)
		{
			vector <int> vec;							    //creating vec to take subvectors numbers in this vector so we can sort and take the median
			for(int a=num;a>=numneg;a--)
			{
				if(j-a>=0 && j-a<mat.size())				// to pass the numbers bigger then size and smaller then 0
					{
					for(int b=num;b>=numneg;b--)
					{
					
						if(i-b>=0&&i-b<mat[0].size())		 
						{

							vec.push_back(mat[j-a][i-b]);	//pushing subvector nums to a vector so we can sort
						}
					}
				}
			}
			Sort(vec);   
			filteredNums=Median(vec);						  //taking the median
			Fvec.push_back(filteredNums);					  //saving medians
		}
		FilteredVec.push_back(Fvec);						  //getting filtered vector
	}
	PrintFilteredVec(FilteredVec);							  //print filtered vector
}

int main()
{
	int filter=0;
	ifstream input;
	string name="";
	cout<<"This program performs median filtering operation on an input matrix given in a text file"<<endl;
	cout<<"Enter the filter size (must be a positive odd integer)"<<endl;
	cin>>filter;
	while(filter<=0||filter%2==0)					//condition filter size must be bigger then zero and odd
	{
		cout<<"Error. Enter the filter size (must be a positive odd integer)"<<endl;
		cin>>filter;
	}
	cout<<"Enter the name of the file "<<endl;
	cin>>name;
	input.open(name.c_str());

	while(input.fail())								//checking if failed
	{
		cout<<"Error. Could not open the file "<<name<<endl;
		cout<<"Enter the name of the file "<<endl;
		cin>>name;
		input.open(name.c_str());
	}

	vector<vector<int>> mat;
	string line="";
	string num;
	int numbers;
	int RowSize=0;
	bool RowCheck=true;
	bool Betweencheck=true;
	bool NumberCheck=true;
	int i=0;
	while(getline(input,line)&&RowCheck&&Betweencheck&&NumberCheck)													//Getting line also including fails (if not same number of rows, if not between [0,255] and if not number)
		{	
			vector<int> vec;
			istringstream LineByL(line);
			while(LineByL>>num)
			{
				if(NumCheck(num))
				{
					numbers=atoi(num);																				//if it passes the numbercheck(if its a num) convert it to an integer
				}
				else
				{
					cout<<"Error: Input file contains invalid characters "<<endl<<"Program Exiting...";				//if not a number giving the error massage and exits by break
					NumberCheck=false;
					break;
				}
				if(numbers<=255 && numbers>=0)
				{
					vec.push_back(numbers);
				}
				else																								//if not in range
				{
					Betweencheck=false;
					cout<<"Pixel with value: "<<numbers <<" is not in range [0,255]"<<endl<<"Program Exiting...";
					break;
				}
			}
			if(NumberCheck&&Betweencheck)																			//SO if one of them fails in the first place, it wont look for row check and wont add to the vec
				{
					mat.push_back(vec);		
					if(mat[0].size()!=mat[i].size())																//if betweencheck already failed wont look for row check
					{
						RowCheck=false;
						cout<<"Input file is not in matrix format"<<endl<<"Program Exiting...";
					}
				}
			i++;
		}
	if(Betweencheck&&RowCheck&&NumberCheck)																			//if not failed with any of them continues with creating the subvectors
	{
		SubVector(mat,filter);
	}

		return 0;
}
