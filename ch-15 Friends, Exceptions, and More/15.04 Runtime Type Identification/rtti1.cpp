/* 20210225 22:37, zyj, GuangDong*/
// rtti1.cpp -- using the RTTI dynamic_cast operator
#include <iostream>
#include <cstdlib>
#include <ctime>
using std::cout;

class Grand
{
	private:
		int hold;
	public:
		Grand(int h = 0) : hold(h) {}
		virtual ~Grand() {}
		virtual void Speak() const { cout << "I am a grand class!\n";}
		virtual int Value() const { return hold; }
};

class Superb : public Grand
{
	public:
		Superb(int h = 0) : Grand(h) {}
		virtual ~Superb() {}
		void Speak() const {cout << "I am a superb class!!\n"; }
		virtual void Say() const
		{ cout << "I hold the superb value of " << Value() << "!\n";}
};

class Magnificent : public Superb
{
	private:
		char ch;
	public:
		Magnificent(int h = 0, char c = 'A') : Superb(h), ch(c) {}
		virtual ~Magnificent() {}
		void Speak() const {cout << "I am a magnificent class!!!\n";}
		void Say() const {cout << "I hold the character " << ch <<
			" and the integer " << Value() << "!\n"; }
};

Grand * GetOne();

int main(void)
{
	std::srand(std::time(0));
	Grand * pg;
	Superb * ps;
	Magnificent *pm;
	for (int i = 0; i < 5; i++)
	{
		pg = GetOne();
		//pg->Speak();
		/** test whether it can  cast to */
		/** mean: try to cast pg to "Superb*", null for cannot*/
		if((ps = dynamic_cast<Superb *>(pg)))
		  ps->Say();
		if((pm = dynamic_cast<Magnificent *>(pg)))
		  pm->Say();
	}
	return 0;
}

Grand * GetOne() // generate one of three kinds of objects randomly
{
	Grand * p;
	switch( std::rand() % 3)
	{
		case 0: p = new Grand(std::rand() % 100);
				break;
		case 1: p = new Superb(std::rand() % 100);
				break;
		case 2: p = new Magnificent(std::rand() % 100,
							'A' + std::rand() % 26);
				break;
	}
	return p;
}
