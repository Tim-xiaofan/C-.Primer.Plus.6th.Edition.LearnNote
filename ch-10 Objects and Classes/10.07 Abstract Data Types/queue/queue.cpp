/*20210127 14:11,zyj,GuangDong*/
// stack.cpp -- Queue member functions
#include "queue.h"
#include <iostream>
Queue::Queue() // create an empty stack
{
	head = 0;
	tail = 0;
}

bool Queue::isempty() const
{
	return head == tail;
}

bool Queue::isfull() const
{
	return head == (tail + 1) % MAX;
}

bool Queue::enqueue(const Item & item)
{
	if (head != (tail + 1) % MAX)/** not full*/
	{
		items[tail] = item;
		tail = (tail + 1) % MAX;
		//std::cout << "enqueue: " << item << ", tail = " << tail << std::endl;
		return true;
	}
	else
	  return false;
}

bool Queue::dequeue(Item & item)
{
	if (head != tail)/* not empty*/
	{
		item = items[head];
		head = (head + 1) % MAX;
		return true;
	}
	else
	  return false; 
}

void Queue::show(show_item si)const
{
	int i = head;
	while(i != tail)
	{
		(*si)(items[i]);
		i = (i + 1) % MAX;
	}
}
