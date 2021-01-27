/*20210127 14:25,zyj,GuangDong*/
// main.cpp -- test class Queue
#include "queue.h"
#include <iostream>

void si_cb(const Item &item)
{
	std::cout << item << " ";
}

int main()
{
	using std::cout;
	using std::endl;
	Queue q;
	int i = 1;
	while(q.enqueue(i++));
	show_item si;
	si = &si_cb;
	q.show(si);
	cout << endl;
	Item item;
	while(q.dequeue(item))
	  std::cout << item << " ";
	cout << endl;
}
