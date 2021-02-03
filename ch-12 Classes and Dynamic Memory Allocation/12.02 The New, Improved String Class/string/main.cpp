/** 20210131 22:08,zyj,GuangDong*/
// compile with strngbad.cpp
#include <iostream>
using std::cout;
using std::endl;
using std::cin;
#include "string.h"
void callme1(String &); // pass by reference
void callme2(String); // pass by value

int main()
{
	using std::endl;
	{
		String headline1("Celery Stalks at Midnight");
		String knot;
		knot = headline1; // assignment operator invoked
		String metoo = knot; // use copy constructor, possibly assignment, too
		String st1("Tom"), st2("Jarray");
		if(st1 > st2)
		  cout << st1 << " > " << st2 << endl;
		if(st1 < st2)
		  cout << st1 << " < " << st2 << endl;
		if(st1 == "Tom")/** an tempprary objet is created*/
		  cout << st1 << " = " << "Tom" << endl;
		String st3;
		cin >> st3;
		cout << "st3 = " << st3 << endl;
		cout << "st1.len = " << st1.length() << ", "
			<< "st2.len = " << st2.length() << ", "
			<< "st3.len = " << st3.length() << endl;
		String opera("The Magic Flute");
		cout << "opera = " << opera << endl;
		cout << "opera[4] = " << opera[4] << endl;

		String means("might");
		means[0] = 'r';
		cout << "means = " << means << endl;

		const String answer("futile");
		String text("Once upon a time");
		cout << "answer = " << answer << endl;
		cout << "answer[1] = " << answer[1] << endl;
		cin >> text[1]; // ok, uses non-const version of operator[]()
		//cin >> answer[1];

		/** static member*/
		int count = String::HowMany(); // invoking a static member function
		cout << "count = " << count << endl; 
	}
	cout << "End of main()\n";
	return 0;
}

void callme1(String & rsb)
{
	cout << "String passed by reference:\n";
	cout << " \"" << rsb << "\"\n";
}

void callme2(String sb)
{
	cout << "String passed by value:\n";
	cout << " \"" << sb << "\"\n";
}
