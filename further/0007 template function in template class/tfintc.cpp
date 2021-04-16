/** 20210416 12:35, zyj, GuangDong*/
// tfintc.cpp -- template function int template class
#include <iostream>
using std::cout;
using std::endl;

template <class T>
class MyClass {
    public:
        template <class U>
        void foo(U a);
};


template <class T>
template <class U>
void MyClass<T>::
foo(U a) 
{
	cout << a << "\n";
}

int main()
{
	MyClass<int> mc;
	mc.foo(2);
	return 0;
}
