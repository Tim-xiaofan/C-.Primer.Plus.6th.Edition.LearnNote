/** 20210221 21:00, zyj, GuangDong*/
// bank.cpp -- using the Queue interface
// compile with queue.cpp
#include <iostream>
#include <cstdlib> // for rand() and srand()
#include <ctime> // for time()
#include "queuetp.h"

int main()
{
	using std::cin;
	using std::cout;
	using std::endl;
	using std::string;

	Queue<string> cs(5);
	string temp;
	while(!cs.isfull())
	{
		cout << "Please enter your name. You will be "
			"served in the order of arrival.\n"
			"name: ";
		getline(cin, temp);
		cs.enqueue(temp);
	}

	cout << "The queue is full. Processing begins!\n";
	while (!cs.isempty())
	{
		cs.dequeue(temp);
		cout << "Now processing " << temp << "...\n";
	}
	return 0;
}
