#ifndef StudentList_h
#define StudentList_h

#include <string>
using namespace std;


	struct examNode
{
string courseName;
int grade;
examNode * next;
// constructors come here
};
struct studentNode
{
string userName;
examNode * headExamList;
studentNode * next;
studentNode * prev;
// constructors come here
};
class StudentList
{
	private:
studentNode * head;
studentNode * tail;

public:
StudentList();
void addExam(string userName, string courseName, int grade);
void deleteStudent(string userName);
void printStudent(string userName);
void printAllAZ(); //alphabetical order display
void printAllZA(); //reverse alphabetical order display	
void deleteAll(); //to deallocate all dynamic data
bool searchUser(string userName,studentNode *&toAdd);  //since i will search in a few member functions i wrote a member function for that
void DeleteExams(examNode *Del);


// any helper functions you see necessary
// ...
};
#endif StudentList_h