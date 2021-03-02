/* 20210302 20:48, zyj, GuangDong*/
// str1.cpp -- introducing the string class .Page 953
#include <iostream>
#include <string>
// using string constructors
int main()
{
	using namespace std;
	string one("Lottery Winner!"); // ctor #1
	cout << one << endl; // overloaded <<
	string two(20, '$'); // ctor #2
	cout << two << endl;
	string three(one); // ctor #3
	cout << three << endl;
	one += " Oops!"; // overloaded +=
	cout << one << endl;
	two = "Sorry! That was ";
	three[0] = 'P';
	string four; // ctor #4
	four = two + three; // overloaded +, =
	cout << four << endl;
	char alls[] = "All's well that ends well";
	string five(alls,20); // ctor #5
	cout << five << "!\n";
	string six(alls+6, alls + 10); // ctor #6
	cout << six << ", ";
	string seven(&five[6], &five[10]); // ctor #6 again
	cout << seven << "...\n";
	string eight(four, 7, 16); // ctor #7
	cout << eight << " in motion!" << endl;

	/** diy*/
	/** string(const char * s, size_type n)*/
	cout << endl << endl;
	string str1("str1", 4);
	cout << "str1 = " << str1 << endl;
	string str2("str2", 15);
	cout << "str2 = " << str2 << endl;
	string str3("str3", 1);
	cout << "str3 = " << str3 << endl;

	/** template<class Iter>string(Iter begin,Iter end)*/
	char all[] = {"0123456789abcdefghijklmnopqrstuvwxyz"};
	string str4(all + 0, all + 15);
	cout << "str4 = " << str4 << endl;
	string str5(&str4[7], &str4[13]);
	cout << "str5 = " << str5 << endl;

	/** string(const string & str, size_type pos, size_type n = npos)*/
	string str6(str4, 7, 21);
	cout << "str6 = " << str6 << endl;
	return 0;
}
