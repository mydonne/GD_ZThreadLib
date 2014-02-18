#include "stdafx.h"  
#include <iostream>  
#include "zthread/PoolExecutor.h"  
#include "zthread/ThreadedExecutor.h"  
#include "zthread/ConcurrentExecutor.h"  
#include "zthread/SynchronousExecutor.h"  
#include "zthread/Runnable.h"  
#include "zthread/PoolExecutor.h"    

using namespace ZThread;  
using namespace std;  

class LiftOff : public Runnable  
{  
public:  
	LiftOff(int count, int idn = 0): countDown(count), id(idn) {}  
	~LiftOff()  
	{  
		cout<< id << "  competed" <<endl;  
	}  
	void run()  
	{  
		int cnt = 0;
		while (countDown--)  
		{  
			cout << id << " : " <<countDown <<endl;  
		}  
		cout<<" LiftOff!" <<endl;  
	}  
private:  
	int countDown;  
	int id;  
};

int _tmain(int argc, _TCHAR* argv[])  
{  
	try  
	{  
		//ThreadedExecutor executor;		
		//ConcurrentExecutor executor;  
		//SynchronousExecutor executor;  
		PoolExecutor* executor = new PoolExecutor(5);
		for (int i = 0; i < 1000; i++)  
		{  
			executor->execute(new LiftOff(10, i));  
		}  
		cout <<"Waiting for LiftOff" <<endl;  

		executor->wait();

		for (int i = 0; i < 10000; i++)  
		{  
			executor->execute(new LiftOff(10, i));  
		}  
	}  
	catch (Synchronization_Exception&  e)  
	{  
		cerr << e.what() <<endl;  
	}  
	//cin.get();  
	return 0; 
}