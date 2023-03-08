#ifndef _WORKER_H_
#define _WORKER_H_

#include <iostream>
#include <string>

using std::string;

class worker
{
	public:
		worker(const string& name = "nobody"):name_(name)
		{ std::cout << "worker()\n"; }
		virtual ~worker() = 0;
		virtual void type(void) const = 0;
		const string& name(void) const
		{ return name_; }
	private:
		std::string name_;
};

class singer: virtual public worker
{
	public:
		singer(const string& name = "singer"):worker(name)
		{ std::cout << "singer()\n";}
		virtual ~singer() { std::cout << "~singer()\n"; }
		virtual void type(void) const override 
		{ std::cout << "singer: " << name() << std::endl; }
};

class waiter: public virtual worker
{
	public:
		waiter(const string& name = "waiter"):worker(name)
		{ std::cout << "waiter()\n";}
		virtual ~waiter() { std::cout << "~waiter()\n"; }
		virtual void type(void) const override 
		{ std::cout << "waiter: " << name() << std::endl; }
};

class singing_waiter: public singer, public waiter
{
	public:
		singing_waiter(const string& name = "singing_waiter"):singer(name), waiter(name)
		{ std::cout << "singing_waiter()\n";}
		virtual ~singing_waiter() { std::cout << "~singing_waiter()\n"; }
		virtual void type(void) const override 
		{ std::cout << "singing_waiter: " << name() << std::endl; }
};

#endif
