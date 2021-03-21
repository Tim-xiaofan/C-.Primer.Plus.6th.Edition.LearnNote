/* 20210321 14:56, zyj, GuangDong*/
// delegating_constructors.cpp
#include <iostream>
#include <cstring>
using namespace std;

class Notes {
	private:
		int k;
		double x;
		std::string st;
	public:
		Notes();
		Notes(int);
		Notes(int, double);
		Notes(int, double, std::string);
};

Notes::Notes(int kk, double xx, std::string stt) : k(kk),
	x(xx), st(stt) {/*do stuff*/}

Notes::Notes() : Notes(0, 0.01, "Oh") {/* do other stuff*/}

Notes::Notes(int kk) : Notes(kk, 0.01, "Ah") {/* do yet other stuff*/ }

Notes::Notes( int kk, double xx ) : Notes(kk, xx, "Uh") {/* ditto*/ }

int main()
{

}
