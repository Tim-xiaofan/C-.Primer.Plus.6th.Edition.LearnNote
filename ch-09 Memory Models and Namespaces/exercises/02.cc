/*20230228 20:47,zyj,GuangDong*/
// 02.cpp -- redo listing 9
#include <iostream>
#include <string>

// function prototype
static void strcount(const std::string& str);

int main()
{
	using namespace std;
	string input;
	cout << "Enter a line:\n";
	while (getline(cin, input) && (input != ""))
	{
		strcount(input);
		cout << "Enter next line (empty line to quit):\n";
	}
	cout << "Bye\n";
	return 0;
}

static void strcount(const std::string& str)
{
	using namespace std;
	static int total = 0; // static local variable
	int count = str.size(); // automatic local variable
	cout << "\"" << str <<"\" contains ";
	total += count;
	cout << count << " characters\n";
	cout << total << " characters total\n";
}
