//20230310 16:33, zyj, GuangDong
#include <iostream>
using std::endl;
using std::cout;

class Grand 
{
	// has virtual methods
	public:
		virtual ~Grand() {}
};

class Superb : public Grand 
{
	public:
		virtual ~Superb() {}
};

class Magnificent : public Superb 
{
	public:
		virtual ~Magnificent() {}
};

int main(void)
{
	Grand *g1 = new Superb();
	Superb *s = dynamic_cast<Superb*>(g1);
	cout << "s: " << s << endl;
	Magnificent *m = dynamic_cast<Magnificent*>(g1);
	cout << "m: " << m << endl;
	return 0;
}
