#include "StudentList.h"
#include <iostream>
#include <string>

using namespace std;

StudentList::StudentList()
{
	head=new studentNode;
	head->next=NULL;
	head->prev=NULL;
	head->headExamList=NULL;
	head->userName="";
	tail=head;
}
bool StudentList::searchUser(string userName,studentNode *&toAdd)  //looks for the user in the node if it exist then it returns true
{
	studentNode *ptr=head;
	while(ptr!=NULL)

	{
		if(ptr->userName==userName)
		{
			toAdd=ptr;   
			return true;            //returns as soon as it finds
		}
		ptr=ptr->next;
	}
	return false;                   //user does not exist in the list

}

void StudentList::addExam(string userName, string courseName, int grade)  
{
	studentNode *toAdd;
	studentNode *after=head->next;
	studentNode *previous=head;
	bool check=true;
	examNode *NewEx= new examNode;
		NewEx->courseName=courseName;
		NewEx->grade=grade;
		NewEx->next=NULL;
	if(head->userName=="")									//if list empty
	{
		studentNode *ptr=new studentNode;
		ptr->userName=userName;
		ptr->headExamList=NewEx;
		ptr->next=NULL;
		ptr->prev=NULL;
		head=ptr;
		tail=head;
		cout<<"A new student with user name "<<userName<<" has been added."<<endl<<"Exam for "<<courseName<<" with grade "<<grade<<" is added for "<<userName<<endl;
	}
	else if(searchUser(userName,toAdd))						//if student already exist
	{
		examNode *check=toAdd->headExamList;
		examNode *nextOne=check->next;
		while(nextOne!=NULL)
		{
			nextOne=nextOne->next;
			check=check->next;
		}
		check->next=NewEx;
		cout<<"Exam for "<<courseName<<" with grade "<<grade<<" is added for "<<userName<<endl;
	}
	else													//if student not exist in the list
	{
		studentNode *ptr=new studentNode;
		ptr->userName=userName;
		ptr->headExamList=NewEx;
		ptr->next=NULL;
		ptr->prev=NULL;
		if(head->userName>userName)								//checking if we are adding to the start instead of between two nodes
		{
			head->prev=ptr;
			ptr->next=head;		
			head=ptr;									// changes head if we add to the start
			
		}
		else
		{
			while(after!=NULL&&check)				//looking until the end
			{
				if(after->userName>ptr->userName)			//if we found the one after our ptr
				{
					ptr->prev=previous;
					ptr->next=after;				//adding the tail to our node
					ptr->next->prev=ptr;
					previous->next=ptr;					//adding our node to the nodes before
					
					check=false;
				}
				else									
				{
					after=after->next;			//updating nodes
					previous=previous->next;
				}
			}
			if(after==NULL)
			{
				ptr->prev=previous;
				previous->next=ptr;						//if we should add to the end				
				tail=ptr;
			}
		}
		cout<<"A new student with user name "<<userName<<" has been added."<<endl<<"Exam for "<<courseName<<" with grade "<<grade<<" is added for "<<userName<<endl;
	}

}
void StudentList::printStudent(string userName)
{
	studentNode *toPrint;
	if(searchUser(userName,toPrint))		//searches and save the node to the "toPrint"
	{
		examNode *exPrint=toPrint->headExamList;
		cout<<toPrint->userName<<endl<<"-------------------"<<endl;
		while(exPrint!=NULL)				//printing all exams
		{
			cout<<exPrint->courseName<<":  "<<exPrint->grade<<endl;
			exPrint=exPrint->next;
		}
	}
	else                 
	{
		cout<<"Student does not exist in the list.";
	}


}

void StudentList::DeleteExams(examNode *Del)  //deletes only exam lists that sent to the node
{
	examNode *ptr;
	while(Del!=NULL)
	{
		ptr=Del;
		Del=Del->next;    
		delete ptr;
	}

}
void StudentList::printAllAZ()
{
	if(head==NULL||head->userName=="")
	{
		cout<<"Student list is empty.";
	}
	else
	{
		cout<<"Printing all students in alphabetical order."<<endl;
		studentNode * ptr=head;
		while(ptr!=NULL)
		{
			cout<<ptr->userName<<endl<<"------------------"<<endl;
			examNode *ptr2=ptr->headExamList;	
			while(ptr2!=NULL)                                      //prints out until the end
			{
				cout<<ptr2->courseName<<":  "<<ptr2->grade<<endl;
				ptr2=ptr2->next;									  //update
			}
			ptr=ptr->next;
			cout<<endl<<endl;
		}
	}
}
void StudentList::printAllZA()
{
	if(tail==NULL||tail->userName=="")
	{
		cout<<"Student list is empty.";
	}
	else
	{
		cout<<"Printing all students in reverse alphabetical order."<<endl;
		studentNode * ptr=tail;
		while(ptr!=NULL)
		{
			cout<<ptr->userName<<endl<<"------------------"<<endl;
			examNode *ptr2=ptr->headExamList;	
			while(ptr2!=NULL)                                      //prints out until the end
			{
				cout<<ptr2->courseName<<":  "<<ptr2->grade<<endl;
				ptr2=ptr2->next;									  //update
			}
			ptr=ptr->prev;
			cout<<endl<<endl;
		}
	}
}

void StudentList::deleteStudent(string userName)
{
	studentNode *toDel;
	if(searchUser(userName,toDel))
	{
		if(toDel->prev==NULL)				//if its head
		{
			head=head->next;
			if(head!=NULL)					//if its the only one in the list				
				head->prev=NULL;
			DeleteExams(toDel->headExamList);
			delete toDel;
		}
		else if(toDel->next==NULL)			//if its tail
		{
			tail=tail->prev;
			tail->next=NULL;
			DeleteExams(toDel->headExamList);
			delete toDel;
		}
		else								//somewhere in the middle
		{
			toDel->prev->next=toDel->next;
			toDel->next->prev=toDel->prev;
			DeleteExams(toDel->headExamList);
			delete toDel;
		}
		cout<<"Student "<<userName<<" has been deleted."<<endl;
	}
	else
	{
		cout<<"Student does not exist in the list."<<endl;
	}
}

void StudentList::deleteAll()
{
	studentNode *Del=head;
	while(head!=NULL)
	{
		Del=head;
		DeleteExams(head->headExamList);//deletes exam lists
		head=head->next;
		delete Del;
	}
}