/** 20210219 22:40, zyj, GuangDong*/
// tempparm.cpp – templates as parameters
#include <iostream>
#include "stack-template/stacktp.h"

/**
  template <class Type>
  class Stack 
  {
  ...
  };
 */

template <template <class T> class Thing, class U = int, class V = double>
class Crab
{
	private:
		Thing<U> s1; /** Stack<int> */
		Thing<V> s2; /** Stack<double>*/
	public:
		Crab() {};
		// assumes the thing class has push() and pop() members
		bool push(int a, double x) { return s1.push(a) && s2.push(x); }
		bool pop(int & a, double & x){ return s1.pop(a) && s2.pop(x); }
};

int main()
{
	using std::cout;
	using std::cin;
	using std::endl;
	Crab<Stack, int, double> nebula;
	// Stack must match template <typename T> class thing
	int ni;
	double nb;
	cout << "Enter int double pairs, such as 4 3.5 (0 0 to end):\n";
	while (cin>> ni >> nb && ni > 0 && nb > 0)
	{
		if (!nebula.push(ni, nb))
		  break;
	}
	while (nebula.pop(ni, nb))
	  cout << ni << ", " << nb << endl;
	cout << "Done.\n";
	return 0;
}
