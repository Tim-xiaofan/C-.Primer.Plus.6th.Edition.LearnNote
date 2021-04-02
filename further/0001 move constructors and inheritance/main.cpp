/** 20210401 09:22, zyj, GuangDong*/
// main.cpp -- Move constructors and inheritance
#include <iostream>

class T0
{
public:
    T0() { puts("ctor 0"); }
    ~T0() { puts("dtor 0"); }
    T0(T0 const&) { puts("copy 0"); }
    T0(T0&&) { puts("move 0"); }
    T0& operator=(T0 const&) { puts("assign 0"); return *this; }
    T0& operator=(T0&&) { puts("move assign 0"); return *this; }
};

class T : public T0
{
public:
    T(): T0() { puts("ctor"); }
    ~T() { puts("dtor"); }
    T(T const& o): T0(o) { puts("copy"); }
    //T(T&& o): T0(o) { puts("move"); }
	T(T&& o): T0(std::move(o)) { puts("move"); }
    T& operator=(T const& o) { puts("assign"); return static_cast<T&>(T0::operator=(o)); }
    //T& operator=(T&& o) { puts("move assign"); return static_cast<T&>(T0::operator=(o)); }
    T& operator=(T&& o) { puts("move assign"); T0::operator=(std::move(o)); return *this;} 
};

int main()
{
    T t = std::move(T());
    return 0;
}
