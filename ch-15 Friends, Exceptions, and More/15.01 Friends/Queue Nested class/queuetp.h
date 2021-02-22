/** 20200221 20:59, zyj, GuangDong*/
#ifndef QUEUE_H_
#define QUEUE_H_

#include <iostream>
#include <cstdlib>

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

template <class Item>
class Queue
{
	private:
		// class scope definitions
		// Node is a nested structure definition local to this class
		class Node 
		{
			public:
				Item item; 
				Node * next;
				Node(const Item & i):item(i), next(0){}
		};
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
		Item & operator[](int i);
		const Item & operator[](int i) const;
};


//Customer methods
std::ostream & operator<<(std::ostream &os, const Customer &item)
{
	os << "(arrival = " << item.arrive << 
		", processtime = " << item.processtime 
		<< ")";
	return os;
}

void Customer::set(long when)
{
	arrive = when;
	processtime = std::rand()% 3 + 1;
}

// Queue methods
template <class Item>
Queue<Item>::Queue(int qs) : qsize(qs)
{
	front = rear = NULL; // or nullptr
	items = 0;
}

template <class Item>
Queue<Item>::~Queue(void)
{
	Node *tmp;
	using std::cout;
	using std::endl;
	while(front != NULL)
	{
		tmp = front;
		front = front->next;
		cout << "delete : " << tmp->item << endl;
		delete tmp;
	}
}

template <class Item>
bool Queue<Item>::enqueue(const Item & item)
{
	if(isfull())return false;
	Node *add = new Node(item);
	items++;
	if(front == NULL)
	  front = add;
	else
	  rear->next = add;
	rear =  add;
	return true;
}

template <class Item>
bool Queue<Item>::dequeue(Item & item)
{
	if(isempty()) return false;
	item = front->item;
	items--;
	Node* tmp = front;
	front = front->next;
	delete tmp;
	if(items == 0)
	  rear = front = NULL;
	return true;
}

template <class Item>
void Queue<Item>::show(void)const
{
	using std::cout;
	using std::endl;
	Node *tmp = front;
	if(items == 0)
	{
		cout << "empty queue\n";
		return;
	}
	int i = 1, width = 1, items_cp = items;
	while((items_cp = items_cp / 10) != 0) width++;
	while(tmp != NULL)
	{
		cout << "#";
		cout.fill('0');
		cout.width(width);
		cout << i++ << tmp->item << "\n";
		tmp = tmp->next;
	}
}

template <class Item>
Item & Queue<Item>::operator[](int i)
{
	if(i >= items || i < 0)
	{
		std::cout << "error :out of bound\n";
		std::abort();
	}
	int id = 0;
	Node *tmp = front;
	while(id++ < i && tmp != NULL)
	  tmp = tmp->next;
	return tmp->item;
}

template <class Item>
const Item & Queue<Item>::operator[](int i) const
{
	if(i >= items || i < 0)
	{
		std::cout << "error :out of bound\n";
		std::abort();
	}
	int id = 0;
	Node *tmp = front;
	while(id++ < i && tmp != NULL)
	  tmp = tmp->next;
	return tmp->item;
}
#endif
