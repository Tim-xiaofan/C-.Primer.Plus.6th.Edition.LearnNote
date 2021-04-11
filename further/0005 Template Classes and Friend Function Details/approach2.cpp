/** 20210411 14:43, zyj, GuangDong*/
//approach2.cpp 
#include <iostream>
#define SEPARATE(info) std::cout << "-----------" << info << "-----------\n"

using std::cout;
using std::endl;

template<class T>
class A;

template<class T>
A<T> foo(A<T>& a);

template<class T>
class A
{
	public:
		A(T a = 0): m_a(a) {}
		/** only same template type can be firends*/
		friend A foo<T>(A& a);

	private:
		T m_a;
};

template<class T>
A<T> foo(A<T>& a)
{
	return a;
}

A<double> secret_pie(3.14);

/** OK: foo<dummy> is not friend to A<double>, A<int> and so on*/
struct dummy {};
template<>
A<dummy> foo<dummy>(A<dummy>& d)
{
    cout << "Hacked! " << secret_pie.m_a << endl;
    return d;
}

int main()
{
	SEPARATE("Approach #2");
	A<int> a(5);
	int i = 4;
	dummy du;
	A<dummy> adu(du);

	foo(a); // Succeeds
	foo(i); // Cannot deduce template parameters
	foo(du);

	return 0;
}
