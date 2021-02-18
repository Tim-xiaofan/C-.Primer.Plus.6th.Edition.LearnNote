/** 20210217 14:09, zyj, GuangDong*/
// worker0.h -- working classes
#ifndef WORKER0_H_
#define WORKER0_H_
#include <string>
#include <iostream>
class Worker // an abstract base class
{
	private:
		std::string fullname;
		long id;
	public:
		Worker() : fullname("no one"), id(0L) {}
		Worker(const std::string & s, long n)
			: fullname(s), id(n) {}
		virtual ~Worker() = 0; // pure virtual destructor
		virtual void Set();
		virtual void Show() const;
		std::string Name() const{return fullname;}
		void Name(const std::string & mname){ fullname = mname;}
		long Id() const{return id;}
};

class Waiter : virtual public Worker
{
	private:
		int panache;//星级
	public:
		Waiter() : Worker(), panache(0) {}
		Waiter(const std::string & s, long n, int p = 0)
			: Worker(s, n), panache(p) {}
		Waiter(const Worker & wk, int p = 0)
			: Worker(wk), panache(p) {}
		virtual ~Waiter(){std::cout << "free Waiter\n";}
		void Set();
		void Show() const;
		int Panache() const {return panache;};
		void Panache(int mpanache) {panache = mpanache;};
};

class Singer : virtual public Worker
{
	protected:
		enum {other, alto, contralto, soprano,
			bass, baritone, tenor};
		enum {Vtypes = 7};
	private:
		static char *pv[Vtypes]; // string equivs of voice types
		int voice;
	public:
		Singer() : Worker(), voice(other) {}
		Singer(const std::string & s, long n, int v = other)
			: Worker(s, n), voice(v) {}
		Singer(const Worker & wk, int v = other)
			: Worker(wk), voice(v) {}
		virtual ~Singer(){std::cout << "free Singer\n";}
		void Set();
		void Show() const;
		std::string Voice() const{ return pv[voice];}
		void Voice(int mvoice) { voice = mvoice;}
};

class SingingWaiter : public Singer, public Waiter
{
	public:
		SingingWaiter()
			: Worker(), Singer(), Waiter(){}
		SingingWaiter(const std::string & mname, long mid, int v = Singer::other, int p = 0)
			: Worker(mname, mid), Singer(mname, mid, v), Waiter(mname, mid, p){}
		SingingWaiter(const Worker & wk, int p = 0, int v = Singer::other)
			: Worker(wk), Singer(wk,v), Waiter(wk,p){}
		~SingingWaiter(){std::cout << "free SingingWaiter\n";}
		void Set();
		void Show() const;
};
#endif
