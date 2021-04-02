/** 20210401 11:16, zyj, GuangDong*/
// list_class_insert.cpp
#include <list>
#include <iostream>
#include <string>

class predicate 
{
	private:
		typedef bool(*callback)(int);
	private:
		callback _cb;
	public:
		predicate(const callback cb);
		predicate & operator=(const callback cb){_cb = cb; return *this;}
		bool operator()(int x)const{return _cb(x);}
};

class equal
{
	private:
		int _val;
	public:
		equal(int x):_val(x){}
		bool operator()(int x) const { return (_val == x);}
};


class A
{
	public:
		virtual void tell(void)const{std::cout << "A\n";}
};

class B : public A
{
	public:
		virtual void tell(void)const{std::cout << "B\n";}
};

class C : public B
{
	public:
		virtual void tell(void)const{std::cout << "C\n";}
};

void func_test(const A a[], int n)
{
	int i;
	for(i = 0; i < n; i++)
	  a[i].tell();
}

int main()
{

	A a;
	B b;
	C c;

	A & ra = b;
	ra.tell();
	A & rb = c;
	rb.tell();
	
	A as[3] = {A(), B(), C()};
	func_test(as, 3);
}
