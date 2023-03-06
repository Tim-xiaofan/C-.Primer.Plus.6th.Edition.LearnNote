/** 20200205 12:43, zyj, GuangDong*/
#ifndef QUEUE_H_
#define QUEUE_H_

#include <iostream>

//#define DEEP_COPY 1

// This queue will contain Customer items
class Customer
{
	private:
		long arrive; // arrival time for customer
		int processtime; // processing time for customer
	public:
		Customer(long m_arrive = 0, int m_processtime = 0) 
		{ 
			arrive = m_arrive;
			processtime = m_processtime; 
		}
		void set(long when);
		long when() const { return arrive; }
		int ptime() const { return processtime; }
		friend std::ostream & operator<<(std::ostream &os, const Customer &item);
};

typedef Customer Item;

class Queue
{
	private:
		// class scope definitions
		// Node is a nested structure definition local to this class
		struct Node { Item item; struct Node * next;};
		enum {Q_SIZE = 10};
		// private class members
		Node * front; // pointer to front of Queue
		Node * rear; // pointer to rear of Queue
		int items; // current number of items in Queue
		const int qsize; // maximum number of items in Queue
#ifndef DEEP_COPY
		Queue & operator=(const Queue & q){return *this;} /** forbid to assignment between objects*/
		Queue(const Queue & q):qsize(0){} /** forbid to use copy constructor*/
#endif
	public:
		// create queue with a qs limit
		Queue(int qs = Q_SIZE); 
		~Queue(void);
		bool isempty(void) const{ return (items == 0);}
		bool isfull(void) const {return (items == qsize);}
		int queuecount(void) const {return items;};
		bool enqueue(const Item &item); // add item to end
		bool dequeue(Item &item); // remove item from front
		void show(void)const;
		Customer & operator[](int i);
		const Customer & operator[](int i) const;
};
#endif
