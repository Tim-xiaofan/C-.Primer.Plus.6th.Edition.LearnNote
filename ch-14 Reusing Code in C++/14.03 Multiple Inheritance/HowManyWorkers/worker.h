#ifndef _WORKER_H_
#define _WORKER_H_

#include <iostream>

class worker
{
	public:
		worker(){ std::cout << "worker()\n"; }
		virtual ~worker() = 0;
		virtual void type(void) const = 0;
};

class singer: public worker
{
	public:
		singer() { std::cout << "singer()\n";}
		virtual ~singer() { std::cout << "~singer()\n"; }
		virtual void type(void) const override 
		{ std::cout << "singer\n"; }
};

class waiter: public worker
{
	public:
		waiter() { std::cout << "waiter()\n";}
		virtual ~waiter() { std::cout << "~waiter()\n"; }
		virtual void type(void) const override 
		{ std::cout << "waiter\n"; }
};

class singing_waiter: public singer, public waiter
{
	public:
		singing_waiter() { std::cout << "singing_waiter()\n";}
		virtual ~singing_waiter() { std::cout << "~singing_waiter()\n"; }
		virtual void type(void) const override 
		{ std::cout << "singing_waiter\n"; }
};

#endif
