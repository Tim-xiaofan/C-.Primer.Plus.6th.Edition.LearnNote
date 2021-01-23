/*20200109 15:22,zyj,GuangDong*/
// expre_typeid_Operator.cpp
// compile with: /GR /EHsc
#include <iostream>
#include <typeinfo>

class Base 
{
	public:
		virtual void vvfunc() {}
};

class Derived : public Base {};

using namespace std;

int main(int argc, char *argv[]) 
{
	Derived* pd = new Derived;
	Base* pb = pd;

	cout << typeid( pb ).name() << endl;   // prints "class Base *"
	cout << typeid( *pb ).name() << endl;  // prints "class Derived"
	cout << typeid( pd ).name() << endl;   // prints "class Derived *"
	cout << typeid( *pd ).name() << endl;  // prints "class Derived"

	delete pd;
}
