#ifndef _WORKER_H_
#define _WORKER_H_

#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::endl;

class worker
{
	public:
		worker(const string& name = "nobody"):name_(name)
		{ std::cout << "worker()\n"; }
		virtual ~worker() = 0;
		virtual void type(void) const = 0;
		const string& name(void) const
		{ return name_; }
		virtual void show(void) const
		{
			std::cout << "worker::show()\n";
			cout << "name: " << name_ << endl;
		}
	private:
		std::string name_;
};

class singer: virtual public worker
{
	public:
		singer(const string& name = "singer")
			:worker(name), works_count_(1)
		{ std::cout << "singer()\n";}
		virtual ~singer() { std::cout << "~singer()\n"; }
		virtual void type(void) const override 
		{ std::cout << "singer: " << name() << std::endl; }
		void show(void) const override
		{
			std::cout << "singer::show()\n";
			worker::show();
			cout << "works_count: " << works_count_ << endl;
		}
	private:
		int works_count_;
};

class waiter: public virtual worker
{
	public:
		waiter(const string& name = "waiter")
			:worker(name), rating_(1.0)
		{ std::cout << "waiter()\n";}
		virtual ~waiter() { std::cout << "~waiter()\n"; }
		virtual void type(void) const override 
		{ std::cout << "waiter: " << name() << std::endl; }
		void show(void) const override
		{
			std::cout << "waiter::show()\n";
			worker::show();
			cout << "rating: " << rating_ << endl;
		}
	private:
		double rating_;
};

class singing_waiter: public singer, public waiter
{
	public:
		singing_waiter(const string& name = "singing_waiter")
			:worker(name), singer(name), waiter(name)
		{ std::cout << "singing_waiter()\n";}
		virtual ~singing_waiter() { std::cout << "~singing_waiter()\n"; }
		virtual void type(void) const override 
		{ std::cout << "singing_waiter: " << name() << std::endl; }
		void show(void) const override
		{
			std::cout << "singing_waiter::show()\n";
			singer::show();
			waiter::show();
		}
};

#endif
