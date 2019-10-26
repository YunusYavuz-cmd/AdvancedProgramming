#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "DynIntStack.h"
using namespace std;
void ReadAndQeue(ifstream &input)
{
	string line="";
	DynIntStack bracketCheck;
	char ch;
	int out=0;
	int i=1;                                                            //to get line information
	bool sytaxCheck=true;
	while(getline(input,line)&&sytaxCheck)								//When the file is finished or when the stack is empty it will quit while loop
	{
			istringstream SeperateLine(line);                           //seperating line by line so we can count lines
			while(SeperateLine>>ch&&sytaxCheck)                         
			{
				if(ch=='{')             
					bracketCheck.push(i);                              //we push the line number of '{' into our stack so when we found a closing bracket we can pop line number of the last '{' from stack 
				else if(ch=='}')                                       
				{
					if(bracketCheck.isEmpty())                         //Checking if stack is empty (checks if we have a open bracket for that closing bracket) if empty then we have a sytac error
					{
						cout<<"Syntax error in line "<<i<<"."<<endl;
						sytaxCheck=false;                              //since we found a sytax error we make our bool false
					}
					else
					{
						bracketCheck.pop(out);                         //pops the last one we add so we found the matches and line number
						cout<<"Code block: "<<out<<" - "<<i<<endl;
					}
				}
			}
			i++;                                                       // to get the line information we update our int i
	}
	if(!bracketCheck.isEmpty())                                        //if the file is finished and our stack is not empty that means we have a syntax error no closing bracket for one or more '{'
	{
		cout<<"Syntax error at the end of the program"<<endl;
		while(!bracketCheck.isEmpty())									//if its not empty it will pop the ones remain in the stack
		{
			int dummy=0;                                                //the number that will be poped 
			bracketCheck.pop(dummy);
		}
	}
}
int main()
{
	string fileName;
	ifstream input;
	cout<<"Enter the input file name"<<endl;
	cin>>fileName;
	input.open(fileName.c_str());
	while(input.fail())                                   //checks input until open successfully
	{
		cout<<"Could not open the file "<<fileName<<endl;
		cin>>fileName;
		input.open(fileName.c_str());
	}
	cout<<endl;
	ReadAndQeue(input);
	return 0;
}