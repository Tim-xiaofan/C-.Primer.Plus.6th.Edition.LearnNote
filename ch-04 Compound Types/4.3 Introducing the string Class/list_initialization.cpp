// list-initialization.cpp
#include <iostream>
#include <string> // make string class available
int main()
{
	using namespace std;
	char first_date[] = {"Le Chapon Dodu"};
	char second_date[] {"The Elegant Plate"};
	string third_date = {"The Bread Bowl"};
	string fourth_date {"Hank's Fine Eats"};
	char charr1[20]; // create an empty array
	char charr2[20] = "jaguar"; // create an initialized array
	string str1; // create an empty string object
	string str2 = "panther"; // create an initialized string
	//charr1 = charr2; // INVALID, no array assignment
	str1 = str2; // VALID, object assignment ok

	/*字符串运算*/
	cout << str1 << endl;
	cout << str2 << endl;
	string str3;
	str3 = str1 + str2; // assign str3 the joined strings
	cout << str3 << endl;
	str1 += str2; // add str2 to the end of str1
	cout << str1 << endl;
	return 0;
}
//g++ -o list-initialization list-initialization.cpp
