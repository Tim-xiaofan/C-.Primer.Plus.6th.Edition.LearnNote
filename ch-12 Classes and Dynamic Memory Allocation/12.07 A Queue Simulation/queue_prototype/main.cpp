/** 20200203 21:35, zyj, GuangDong*/
#include "queue.h"
#include <iostream>

int main()
{
	using std::cout;
	using std::endl;
	Queue q(15);
	int i = 0;
	cout << "------before enqueue--------\n Queue:\n";
	cout << "item count = " << q.queuecount() << endl;
	q.show();
	while(q.enqueue(Customer(i, i * i))) i++;
	cout << "------after enqueue--------\n Queue:\n";
	cout << "item count = " << q.queuecount() << endl;
	q.show();
	Customer item;
	i = 0;
	while(q.dequeue(item) && i++ < 9)
	  cout << "dequeue:" << item << endl;
	cout << "------after dequeue--------\n Queue:\n";
	cout << "item count = " << q.queuecount() << endl;
	q.show();
	for(i = 0; i < q.queuecount(); i++)
	  q[i].set(i);
	cout << "------after set--------\n Queue:\n";
	cout << "item count = " << q.queuecount() << endl;
	q.show();
#ifdef DEEP_COPY
	Queue q1 = q;
	Queue q2;
	q2 = q;
#endif
}
