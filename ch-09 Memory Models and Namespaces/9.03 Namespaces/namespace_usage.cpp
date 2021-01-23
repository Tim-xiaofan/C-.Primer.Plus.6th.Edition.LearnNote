/*20210121 22:34,zyj,GuangDong*/
// namespace_usage.cpp
#include <iostream>
using namespace std;

namespace Jack 
{
	double pail; // variable declaration
	void fetch(void); // function prototype
	int pal; // variable declaration
	struct Well
	{ 
		unsigned int id;
	}; // structure declaration
}

namespace Jill 
{
	double bucket(double n) 
	{
		std::cout << "Jill::bucket():";
		std::cout << n << std::endl;
	} // function definition
	double fetch; // variable declaration
	int pal; // variable declaration
	struct Hill 
	{ 
		unsigned int id;
	}; // structure declaration
}

/* adds the name goose to the existing list of names in Jill*/
namespace Jill
{
	char *goose(const char*);
}

namespace std
{
	void std_f(void)
	{
		std::cout << "std::std_f()\n";
	}
}

/* provide the code for the function*/
namespace Jack
{
	void fetch(void)
	{
		std::cout << "Jack::fetch()" << std::endl;
	}
}

namespace Tom
{
	char *name;
	double salary;
}

char fetch = 'x';

int main()
{
	using namespace std; //using directive
	Jack::pail = 12.34; // use a variable
	Jill::Hill mole; // create a type Hill structure
	Jack::fetch(); // use a function
	Jill::fetch = 3.14;
	std_f();
	using Jack::fetch;//a using declaration
	cout << "after using declaration:" << endl;
	fetch();
	//double fetch; // Error! Already have a local fetch
	cout << ::fetch << endl; // output a value into global fetch
	using namespace Tom; //using directive
	name = (char *)"Tom";
	salary = 4500;
	double salary;// not an error; hides Tom::salary
	salary = 2333;
	cout << "Tom::salary = " << Tom::salary << endl;
	cout << "local salary = " << salary << endl;
	double cout = 2.333;// from here, std::cout is hided
	std::cout << "cout = " << cout << endl;
	return 0;
}
