#ifndef _LIST_H_
#define _LIST_H_

#include <memory>

namespace exercises
{

template<typename T>
struct node
{
	T data;
	std::shared_ptr<node> next;
	node(const T& d, std::shared_ptr<node> p = nullptr)
		:data(d),
		next(p)
	{}
};

template<typename T>
using node_ptr = std::shared_ptr<node<T>>;

template<typename T>
class iterator
{
	public:
		iterator(const node_ptr<T>& ptr)
			:ptr_(ptr)
		{}
		iterator& operator++() { ptr_ = ptr_->next; return *this;};
		iterator operator++(int) { iterator ret = *this; ptr_ = ptr_->next; return ret; }
		T& operator*() { return *ptr_;}
	private:	
		node_ptr<T> ptr_;
};

template<typename T>
class list
{
	public:
		list(int capacity = DEFAULT_CAPACITY);
		void add(const T elements[], int n);
		bool empty(void) const { return head_ == tail_;}
		bool full(void) const { return count_ == capacity_; }
	private:
		node_ptr<T> head_;
		node_ptr<T> tail_;
		int count_;
		static const int DEFAULT_CAPACITY;
		int capacity_;
};

}

#endif
