/* 20210321 15:10, zyj, GuangDong*/
// inheriting_constructors.cpp
#include <iostream>
#include <cstring>
using namespace std;

class BS
{
private:
	int q;
	double w;
public:
	BS() : q(0), w(0) {}
	BS(int k) : q(k), w(100) {}
	BS(double x) : q(-1), w(x) {}
	BS(int k, double x) : q(k), w(x) {}
	void Show() const {std::cout << q <<", " << w << '\n';}
};

class DR : public BS
{
private:
	short j;
public:
	using BS::BS;
	DR() :BS(), j(-100) {} // DR needs its own default constructor
	DR(double x) : BS(2*x), j(int(x)) {}
	DR(int i) : BS(i, 0.5 * i), j(-2) {}
	void Show() const {std::cout << j << ", "; BS::Show();}
};

int main()
{
	DR o1; // use DR()
	DR o2(18.81); // use DR(double) instead of BS(double)
	DR o3(10, 1.8); // use BS(int, double)
}
