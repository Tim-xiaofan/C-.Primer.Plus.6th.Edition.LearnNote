/* 20210321 15:31, zyj, GuangDong*/
// override.cpp -- avoid hide
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
	virtual void f(char ch) const { std::cout << val() << ch << "\n";}
};
class Bingo : public Action
{
public:
		Bingo(int i = 0) : Action(i) {}
		/** mismatch, get compile-time error message*/
		virtual void f(char * ch) const override { std::cout << val() << ch << "!\n"; }
};

int main()
{
}
