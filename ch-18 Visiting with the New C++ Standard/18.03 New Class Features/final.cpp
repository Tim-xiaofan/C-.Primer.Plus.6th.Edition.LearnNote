/* 20210321 15:38, zyj, GuangDong*/
// final.cpp -- to prohibit derived classes from overriding a particular virtual method
#include <iostream>
#include <cstring>
using namespace std;

class Action
{
private:
	int a;
public:
	Action(int i = 0) : a(i) {}
	int val() const {return a;};
	virtual void f(char ch) const final{ std::cout << val() << ch << "\n";}
};
class Bingo : public Action
{
public:
		Bingo(int i = 0) : Action(i) {}
		virtual void f(char ch) const override { std::cout << val() << ch << "!\n"; }
};

int main()
{
}
