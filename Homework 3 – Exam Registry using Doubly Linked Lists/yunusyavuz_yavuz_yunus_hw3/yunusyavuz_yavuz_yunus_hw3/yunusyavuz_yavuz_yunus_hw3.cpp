#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "StudentList.h"
using namespace std;

void LoadFile(StudentList &list)
{
		ifstream input;
		string FileName;
		cout<<"Enter the name of the file "<<endl;
		cin>>FileName;
		cout<<endl;
		input.open(FileName.c_str());
		while(input.fail())							    //if input fail
		{
			cout<<"Error: Could not open the file "<<FileName<<endl<<endl;
			cout<<"Enter the name of the file"<<endl;
			cin>>FileName;
			input.open(FileName.c_str());
			cout<<endl;
		}
		string line="";
		string Name="";
		string CourseName=""; 
		int grade;
		while(getline(input,line))
		{
			istringstream LineByLine(line);
			LineByLine>>Name;
			LineByLine>>CourseName;
			LineByLine>>grade;
			list.addExam(Name,CourseName,grade);			 //sent to the member function to add exams
		}
		cout<<"File has been processed.";

}

void Selection(string ToDo,StudentList &list)
{
	if(ToDo=="1")
		LoadFile(list);
	else if(ToDo=="2")
	{
		string user="",courseName="";
		int grade;
		cout<<"Please enter the user name of the student"<<endl;
		cin>>user;
		cout<<"Please enter the name of the course:"<<endl;
		cin>>courseName;
		cout<<"Please enter the grade[0..100]"<<endl;
		cin>>grade;
		cout<<endl;
		list.addExam(user,courseName,grade);
	}
	else if(ToDo=="3")
	{
		string user="";
		cout<<"Please enter the user name of the student"<<endl;
		cin>>user;
		cout<<endl;
		list.deleteStudent(user);
	}
	if(ToDo=="4")
	{
		string user="";
		cout<<"Please enter the user name of the student"<<endl;
		cin>>user;
		cout<<endl;
		list.printStudent(user);
	}
	else if(ToDo=="5")
		list.printAllAZ();   //print a to z
	else if(ToDo=="6")
		list.printAllZA();	//print z to a
}
int main()
{
	string ToDo="";
	StudentList list;
	do
	{
		cout<<"Exam Grades"<<endl<<"-----------------------------------"<<endl;
		cout<<"Please select one option [1..7]:"<<endl;
		cout<<"1. Load information from a file"<<endl;
		cout<<"2. Add student and exam manually"<<endl;
		cout<<"3. Delete a student"<<endl;
		cout<<"4. Display exam grades of a student"<<endl;
		cout<<"5. Display exam grades of all students in alphabetical order"<<endl;
		cout<<"6. Display exam grades of all students in reverse alphabetical order"<<endl;
		cout<<"7. Exit"<<endl;
		cout<<"Your choice: "<<endl;
		cin>>ToDo;
		cout<<endl;
		if(ToDo!="7")
			Selection(ToDo,list);
		cout<<endl<<endl;
	}while(ToDo!="7");
	
	list.deleteAll();
	return 0;
}