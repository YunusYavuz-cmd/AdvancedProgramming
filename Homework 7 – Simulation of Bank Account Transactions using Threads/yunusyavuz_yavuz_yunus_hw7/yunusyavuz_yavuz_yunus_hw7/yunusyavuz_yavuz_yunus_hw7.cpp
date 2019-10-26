#include <iostream>
#include <fstream>
#include <thread>
#include <mutex>
#include <string>
#include <random>
#include "strutils.h"
#include <ctime>
#include <chrono>
#include <iomanip>
#include <time.h>
using namespace std;
mutex Mutex,coutMutex;
ofstream balance;
ifstream balanceIf;

int random_range(const int & min, const int & max)
{
 static mt19937 generator(time(0));
 uniform_int_distribution<int> distribution(min, max);
 return distribution(generator);
}
void deposit(int depMin,int depMax,int depNum,string balanceName)
{
	int i=0;
	for(int a=0;a<depNum;)				
	{
		string line="";
		Mutex.lock();
		balanceIf.open(balanceName.c_str());
		getline(balanceIf,line);
		i=atoi(line);           //getting the old balance and saves to the i
		balanceIf.close();
			a++;
			i++;				//updates balance
		balance.open(balanceName.c_str());
		balance<<i;             //saves balance to the i
		balance.close();    
		Mutex.unlock();
		coutMutex.lock();     //locks for cout so other threads can continue until cout so they wont be mixed
			time_t tt = chrono::system_clock::to_time_t(chrono::system_clock::now()); 
			struct tm *ptm = new struct tm; 
			localtime_s(ptm, &tt); 
			cout<< "1 TL has been deposited: balance is "<<i<<",  "<< put_time(ptm,"%X") <<endl;
		coutMutex.unlock();
		this_thread::sleep_for(chrono::seconds(random_range(depMin,depMax)));//sleeps thread
	}
}
void withdraw(int id,int withMin,int withMax,int withNum,string balanceName)
{
	int i=0;
	for(int a=0;a<withNum;)
	{
		string line="";
		Mutex.lock();
		a++;
		balanceIf.open(balanceName.c_str());//opens ifstream to get old balance
		getline(balanceIf,line);
		i=atoi(line);
		if(i>0)
		{
			balance.open(balanceName.c_str());
			i--; //updating balance
			balance<<i;//writing balance to the filse
			balance.close();
			Mutex.unlock();
			coutMutex.lock();
				time_t tt = chrono::system_clock::to_time_t(chrono::system_clock::now()); //for time
				struct tm *ptm = new struct tm; 
				localtime_s(ptm, &tt); 
				cout<< "Withdrawal thread "<<id<<" successfully withdrawn 1 TL; balance is "<<i<<",  "<<  put_time(ptm,"%X") <<endl;
			coutMutex.unlock();
			this_thread::sleep_for(chrono::seconds(random_range(withMin,withMax)));
		}
		else //if balance is already 0
		{
			Mutex.unlock();
			coutMutex.lock();
			time_t tt = chrono::system_clock::to_time_t(chrono::system_clock::now()); 
			struct tm *ptm = new struct tm; 
			localtime_s(ptm, &tt); 
			cout<< "Withdrawal thread "<<id<<" failed to withdrawn 1 TL; balance is "/*<<balance*/<< put_time(ptm,"%X") <<endl;
			coutMutex.unlock();
			this_thread::sleep_for(chrono::seconds(random_range(withMin,withMax)));
		}
	}
}
int main()
{
	string balanceName;
	int withMin,withMax,depMin,depMax,withNum,depNum;
	cout<<"Please, enter file name in which balance will be stored: "<<endl;	cin>>balanceName;
	balance.open(balanceName.c_str());
	balance<<"0";//writing 0 for initial balance
	balance.close();
	cout<<"Please, enter min and max waiting times between withdrawal transactions per thread(in seconds): "<<endl;
	cin>>withMin>>withMax;
	cout<<"Please, enter min and max waiting times between deposit transactions (in seconds): "<<endl;	cin>>depMin>>depMax;	cout<<"Please, enter the total number of withdrawal transactions per thread: "<<endl;	cin>>withNum;	cout<<"Please, enter the total number of deposit transactions: "<<endl;	cin>>depNum;	time_t tt = chrono::system_clock::to_time_t(chrono::system_clock::now()); //gets time
	struct tm *ptm = new struct tm; 
	localtime_s(ptm, &tt); 
	cout<< "Simulation starts at "<< put_time(ptm,"%X") <<endl;	thread userdepo(&deposit,depMin,depMax,depNum,balanceName);//starting deposit thread
	thread user1(&withdraw,0,withMin,withMax,withNum,balanceName);//starting withdraw threads
	thread user2(&withdraw,1,withMin,withMax,withNum,balanceName);
	thread user3(&withdraw,2,withMin,withMax,withNum,balanceName);
	userdepo.join();  //joins threads
	user1.join();
	user2.join();
	user3.join();
	return 0;
}
