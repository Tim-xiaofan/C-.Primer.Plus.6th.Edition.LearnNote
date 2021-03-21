/* 20210320 21:19, zyj, GuangDong*/
// simple.cpp 
#include <iostream>
#include <cstring>
using namespace std;

class Test
{
	private:
		char *_name;
		static int count;

	public:
		Test(const char *name);

		/** copy constructor*/
		Test(const Test & t);

		/** move constructor*/
		Test(Test && t);

		~Test();

		friend ostream & operator<<(ostream & os, const Test & t);
};

ostream & operator<<(ostream & os, const Test & t)
{
	return (os << t._name);
}

int Test::count = 0;

Test::~Test()
{
	cout << "delete object : " << _name << endl;
	delete [] _name;
	count--;
}

Test::Test(const char *name)
{
	count++;
	_name = new char[strlen(name) + 1];
	strcpy(_name, name);
	cout << "constructor called\n";
}

/** copy constructor*/
Test::Test(const Test & t)
{
	count++;
	/** alloc and cpy*/
	_name = new char[strlen(t._name) + 1];
	strcpy(_name, t._name);
	cout << "copy constructor called\n";
}

/** move constructor*/
Test::Test(Test && t)
{
	count++;
	/** just steal address*/
	_name = t._name; 
	/** avoid double free*/
	t._name = nullptr;
	cout << "move constructor called\n";
}

Test get_test()
{
	//cout << "before\n";
	return Test("t2");
}

int main()
{
	{
		//Test t1("t1");
		//Test t2(t1);
		//Test && rrt1 = 
		//	static_cast<Test &&>(t1);  
		//Test t3(rrt1);/** still copy constructor*/
		//Test t4(move(t1));
		//Test t5{Test{"t2"}};
		//cout << t5 << endl;
		cout << get_test() << endl;
	}
}
