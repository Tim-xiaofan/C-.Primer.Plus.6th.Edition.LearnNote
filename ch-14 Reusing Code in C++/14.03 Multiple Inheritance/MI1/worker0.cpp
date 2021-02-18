/** 20210216 20:48, zyj, GuangDong*/
// worker0.cpp -- working class methods
#include "worker0.h"
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

// Worker methods
// must implement virtual destructor, even if pure
Worker::~Worker() { cout << "free Worker\n";}
void Worker::Set()
{
	cout << "Enter worker's name: ";
	getline(cin, fullname);
	cout << "Enter worker's ID: ";
	cin >> id;
	while (cin.get() != '\n')
	  continue;
}

void Worker::Show() const
{
	cout << "Name: " << fullname << "\n";
	cout << "Employee ID: " << id << "\n";
}

// Waiter methods
void Waiter::Set()
{
	Worker::Set();
	cout << "Enter waiter's panache rating: ";
	cin >> panache;
	while (cin.get() != '\n')
	  continue;
}

void Waiter::Show() const
{
	cout << "Category: waiter\n";
	Worker::Show();
	cout << "Panache rating: " << panache << "\n";
}


// Singer methods
char * Singer::pv[] = {(char *)"other", (char *)"alto", (char *)"contralto",
	(char *)"soprano", (char *)"bass", (char *)"baritone", (char *)"tenor"};

void Singer::Set()
{
	Worker::Set();
	cout << "Enter number for singer's vocal range:\n";
	int i;
	for (i = 0; i < Vtypes; i++)
	{
		cout << i << ": " << pv[i] << " ";
		if ( i % 4 == 3)
		  cout << endl;
	}
	if (i % 4 != 0)
	  cout << endl;
	while (cin >> voice && (voice < 0 || voice >= Vtypes) )
	  cout << "Please enter a value >= 0 and < " << Vtypes << endl;
	while (cin.get() != '\n')
	  continue;
}
void Singer::Show() const
{
	cout << "Category: singer\n";
	Worker::Show();
	cout << "Vocal range: " << pv[voice] << endl;
}

/** SingingWaiter methods*/
void SingingWaiter::Set()
{
}

void SingingWaiter::Show() const
{
	cout << "Category: SingingWaiter\n";
	cout << "Name: " << Worker::Name() << "\n";
	cout << "Employee ID: " << Worker::Id() << "\n";
	cout << "Vocal range: " << Singer::Voice() << endl;
	cout << "Panache rating: " << Waiter::Panache() << "\n";
}
