/** 20210411 13:56, zyj, GuangDong*/
//approach1.cpp 
#include <iostream>

using std::cout;
using std::endl;

template<class T>
class A
{
	public:
		A(T a = 0): m_a(a) {}
		/** 
		  * Approach #1: All template instantiations of A are friends with
		  * all template instantiations of foo() */
		template<class U> friend A<U> foo(A<U>& a);
	private:
		T m_a;
};

template<class T>
A<T> foo(A<T>& a)
{
	std::cout << "Approach #1: " << a.m_a << "\n";
	return a;
}

A<double> secret_pie(3.14);

/** badthing: foo<dummy> is alse friend to A<double>, A<int> and so on*/
struct dummy {};
template<>
A<dummy> foo<dummy>(A<dummy>& d)
{
    cout << "Hacked! " << secret_pie.m_a << endl;
    return d;
}

#define SEPARATE(info) std::cout << "-----------" << info << "-----------\n"
int main()
{
	A<int> ai(1);
	A<float> af(3.14);
	A<double> ad(6.18);
	dummy du;
	A<dummy> adu(du);
	SEPARATE("Approach #1");
	cout << "normal things:\n";
	foo(ai);
	foo(af);
	foo(ad);
	cout << "bad things:\n";
	foo(adu);
	return 0;
}
