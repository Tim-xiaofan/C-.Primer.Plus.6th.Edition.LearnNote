/** 20210217 19:04, zyj, GungDong*/
#include <iostream>
using std::cout; 
using std::endl; 
class B
{
	public:
		short q(){ cout << "B::q()\n"; return 0;}
};

class C : virtual public B
{
	public:
		long q(){ cout << "C::q()\n"; return 0;}
		int omg(){ cout << "C::omg\n"; return 0;};
};

class D : public C
{
};

class E : virtual public B
{
	private:
		int omg(){ cout << "E::omg\n"; return 0;};
};

class F: public D, public E
{
};

int main()
{
	F f;
	f.omg();
}
