/** 20210411 14:54, zyj, GuangDong*/
//approach3.cpp 
#include <iostream>

using std::cout;
using std::endl;

template<class T>
class A
{
    public:
        A(T a = 0): m_a(a) {}

        friend A operator+(const A& lhs, const A& rhs);

    private:
        T m_a;
};

inline A<int> operator+(const A<int>& lhs, const A<int>& rhs)
{
    return lhs.m_a + rhs.m_a;
}

int main()
{
    A<int> a(5);
    A<int> b(7);
    int i = 4;

    a + b;    // Succeeds
    i + a;    // Also succeeds
	foo(a);   // Succeeds
    foo(i);   // Fails: foo not declared in this scope
    foo(A<int>(i)); // Succeeds
    return 0;
}
