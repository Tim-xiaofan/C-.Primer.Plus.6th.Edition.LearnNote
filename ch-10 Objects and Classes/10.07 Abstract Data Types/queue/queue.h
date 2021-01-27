/*20210127 13:03,zyj,GuangDong*/
#ifndef QUEUE_H_
#define QUEUE_H_

typedef unsigned long Item;
typedef void(*show_item)(const Item &);
class Queue
{
	private:
		enum {MAX = 10}; /** constant specific to class*/
		Item items[MAX]; /** holds queue items*/
		int head; /** index for queue head*/
		int tail; /** index for queue tail*/
	public:
		Queue();
		bool isempty() const;
		bool isfull() const;
		/** enter an item at tail*/
		bool enqueue(const Item & item); 
		/** dequeue an item at head*/
		bool dequeue(Item & item);
		void show(show_item si)const;
};

#endif
