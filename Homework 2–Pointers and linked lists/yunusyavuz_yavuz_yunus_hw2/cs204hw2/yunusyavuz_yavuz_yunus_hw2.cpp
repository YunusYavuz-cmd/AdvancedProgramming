#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
using namespace std;

struct node;
void Modify(node *&head);
void Display(node *head);
void ReadingFile(node *&head);
bool SearchList(node *head, string NameSearch);
void AddingBySearch(node *&head,string NameSearch,int AddingPoints);
struct node
{
	string name;
	int point;
	node * next;
	node::node ()				//default
		:name(""),next(NULL)
	{}
	node::node (string Name,int i)
		:name(Name),point(i),next(NULL)
	{}	
};
void Selection(string ToDo,node *&head)
{
	if(ToDo=="1")
		ReadingFile(head);
	else if(ToDo=="2")
		Modify(head);
	else if(ToDo=="3")
		Display(head);
}
void SortedAdd(node *&head,string Name, int Num)
{
	node* nullcheck=head->next;							//since we will check head with if statement it can start with next one
	node* before=head;									//to add between two nodes we need the node before it 
	node *ptr=new node(Name,Num);						//creating the node we will add , next is automaticly NULL so it wont be a problem when we add to the end
	bool check=true;									//a check that goes false when we found the place that we will add the node
	if(head->name=="")									//if HEAD EMPTY
	{
		head=ptr;
	}
	else
	{
		if(head->name>Name)								//checking if we are adding to the start instead of between two nodes
		{
			ptr->next=head;
			head=ptr;									// changes head if we add to the start
		}
		else
		{
			while(nullcheck!=NULL&&check)				//looking until the end
			{
				if(nullcheck->name>ptr->name)			//if we found the one after our ptr
				{
					ptr->next=nullcheck;				//adding the tail to our node
					before->next=ptr;					//adding our node to the nodes before
					check=false;
				}
				else									
				{
					nullcheck=nullcheck->next;			//updating nodes
					before=before->next;
				}
			}
			if(nullcheck==NULL)
			{
				before->next=ptr;						//if we should add to the end
			}

		}
	}
		cout<<Name<<" has been added to the list with initial points "<<Num<<endl;
	
}
void ReadingFile(node *&head)
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
		int Num;
		while(getline(input,line))
		{
			istringstream LineByLine(line);
			LineByLine>>Name;
			LineByLine>>Num;
			if(head->name=="")							//if its first time(so head is empty)
			{
				if(Num>0)								//point must be bigger then 0
				{
					head->name=Name;
					head->point=Num;
					cout<<head->name<<" has been added to the list."<<endl;
				}
				else
				{
					cout<<Name<<" has not been added"<<endl<<"since the initial points cannot be non-positive."<<endl;
				}

			}
			else										//if its not the first node
			{
				if(SearchList(head,Name))               //if the name exist in our nodes
				{
					AddingBySearch(head,Name,Num);
				}
				else                                    //if name doesnt exist in our nodes
				{
					if(Num>0)
					{
						SortedAdd(head,Name,Num);    
					}
					else
						cout<<Name<<" has not been added"<<endl<<"since the initial points cannot be non-positive."<<endl;
				}
			}
		}

}
void Display(node *head)
{
	node *ptr=head;
	if(head->name==""||head==NULL)                            //if node is empty point table is empty
	{
		cout<<"The points table is empty"<<endl;
	}
	else
	{
		cout<<"Points Table"<<endl<<"-----------------------------------"<<endl;
		while(ptr!=NULL)                                      //prints out until the end
		{
			cout<<ptr->name<<"  "<<ptr->point<<endl;
			ptr=ptr->next;									  //update
		}
	}
}
void Modify(node *&head)
{
	string Name;
	int NumberPoints;
	cout<<"Please enter name of the driver you wish to add/modify: ";
	cin>>Name;
	cout<<"Please enter how many points you wish to initialize/add/remove: ";
	cin>>NumberPoints;
	if(SearchList(head,Name))								  //if its exist in our nodes
	{
		AddingBySearch(head,Name,NumberPoints);
	}
	else
	{
		if(NumberPoints<=0)                                   //checks the point is bigger then 0 or not(since it doesnt exist in our nodes)
			cout<<Name<<" has not been added "<<endl<<"since the initial points cannot be non-positive."<<endl;
		else
		{
			SortedAdd(head,Name,NumberPoints);
		}

	}

}
void AddingBySearch(node *&head,string NameSearch,int AddingPoints)
{
	node *ptr=head;
	node *before=head;					//since we will delete nodes we need the one before the one we will delete             
	bool first=true;					//by this bool check the node before wont be updated for the first time in the loop
	while (ptr != NULL)
	{
		if(ptr->name == NameSearch)		//If the node with the given ID is found
		{
			ptr->point+=AddingPoints;
			break;
		}
		if(first)						// so head will show the one before ptr and if the points go lower or equal to zero we can delete it easily since, we have the one before the one we will delete
		{
			ptr=ptr->next;
			first=false;
		}
		else
		{
			ptr = ptr->next;
			before=before->next;
		}
	}
	if(ptr->point<=0&&head!=ptr)		//if head is not the one we will delete
	{
		before->next=ptr->next;
		cout<<ptr->name<<" has been removed from the list "<<endl<<"since his points became non-positive"<<endl;
		delete ptr;
	}
	else if(ptr->point<=0&&head==ptr)	//if head is the one we will delete
	{
		head = head->next;
		cout<<ptr->name<<" has been removed from the list"<<endl<<"since his points became non-positive"<<endl;
		delete ptr;
	}
	else								//if not deleted(points not <= 0)
	{
		cout<<ptr->name<<" has been updated and new point is "<<ptr->point<<endl;
	}

}
bool SearchList(node *head, string NameSearch)
{
	node *ptr=head;
	while (ptr != NULL)
	{
		if(ptr->name == NameSearch)		//If the node with the given ID is found
			return true;			
		ptr = ptr->next;
	}
	//If the code proceeds from here, it means that the whole list is traversed 
	//and a node with name == NameSearch could not be found. 
	return false;
}
void ClearMemory(node *head)
{
	node *ptr;
	while(head!=NULL)
	{
		ptr=head;
		head=head->next;
		delete ptr;
	}
}

int main()
{
	string ToDo;
	node *head=new node;				//since we will manage the system in int main i created head in int main (so i can change in any function and return it with referance parameter)
	do
	{
		cout<<"Formula 1 Points Table System"<<endl<<"-----------------------------------"<<endl;
		cout<<"Please select one option [1..4]:"<<endl;
		cout<<"1. Load driver names and points from a file"<<endl;
		cout<<"2. Insert a new driver / Modify points of an existing driver"<<endl;
		cout<<"3. Display points table in alphabetical order"<<endl;
		cout<<"4. Exit"<<endl;
		cin>>ToDo;
		cout<<endl;
		if(ToDo!="4")
			Selection(ToDo,head);
		cout<<endl;
	}while(ToDo!="4");
	ClearMemory(head);				//In order to make sure that no memory leak

	return 0;
}
