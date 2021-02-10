/** 20200205 12:44, zyj, GuangDong*/
#include "queue.h"
#include <cstdlib>

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
Queue::Queue(int qs) : qsize(qs)
{
	front = rear = NULL; // or nullptr
	items = 0;
}

Queue::~Queue(void)
{
	struct Node *tmp;
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

bool Queue::enqueue(const Item & item)
{
	if(isfull())return false;
	Node *add = new Node;
	add->item = item;
	add->next = NULL;
	items++;
	if(front == NULL)
	  front = add;
	else
	  rear->next = add;
	rear =  add;
	return true;
}

bool Queue::dequeue(Item & item)
{
	if(isempty()) return false;
	item = front->item;
	items--;
	struct Node* tmp = front;
	front = front->next;
	delete tmp;
	if(items == 0)
	  rear = front = NULL;
	return true;
}

void Queue::show(void)const
{
	using std::cout;
	using std::endl;
	struct Node *tmp = front;
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

Customer & Queue::operator[](int i)
{
	if(i >= items || i < 0)
	{
		std::cout << "error :out of bound\n";
		std::abort();
	}
	int id = 0;
	struct Node *tmp = front;
	while(id++ < i && tmp != NULL)
	  tmp = tmp->next;
	return tmp->item;
}

const Customer & Queue::operator[](int i) const
{
	if(i >= items || i < 0)
	{
		std::cout << "error :out of bound\n";
		std::abort();
	}
	int id = 0;
	struct Node *tmp = front;
	while(id++ < i && tmp != NULL)
	  tmp = tmp->next;
	return tmp->item;
}
