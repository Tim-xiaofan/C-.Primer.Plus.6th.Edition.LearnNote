#ifndef _LIST_H_
#define _LIST_H_

#include <memory>
#include <iostream>
#include <type_traits>

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
	friend std::ostream& operator<<(std::ostream& os, const node& nd)
	{
		return os << "<" << nd.data << ", " << nd.next.get() << ">";
	}
};

template<typename T>
using node_ptr = std::shared_ptr<node<T>>;

template<typename T>
using const_node_ptr = std::shared_ptr<node<const T>>;

template<typename T, bool Const = false>
class list_iterator
{
	public:
		using reference_type = typename std::conditional<Const, const T&, T&>::type;

		list_iterator(const node_ptr<T>& ptr)
			:ptr_(ptr)
		{}
		
		// ++i
		list_iterator& operator++()
		{ ptr_ = ptr_->next; return *this;};
		
		// i++
		list_iterator operator++(int)
		{ list_iterator ret = *this; ptr_ = ptr_->next; return ret; }
		
		reference_type operator*()
		{ return ptr_->data; }

		reference_type operator*() const
		{ return ptr_->data; }
		
		bool operator!=(const list_iterator& rhs)
		{ return ptr_ != rhs.ptr_; }
	private:	
		node_ptr<T> ptr_;
};


template<typename T>
class list
{
	public:
		using iterator = list_iterator<T>;
		using const_iterator = list_iterator<T, true>;
		list(int capacity = DEFAULT_CAPACITY);
		void add(const T elements[], int n);
		bool empty(void) const { return head_ == nullptr;}
		bool full(void) const { return count_ == capacity_; }
		iterator begin(void) { return iterator(head_);}
		iterator end(void) { return iterator(tail_->next);}
		const_iterator begin(void) const { return const_iterator(head_); };
		const_iterator end(void) const;
	private:
		node_ptr<T> head_;
		node_ptr<T> tail_;
		int count_;
		static const int DEFAULT_CAPACITY;
		int capacity_;
};

template<typename T> const int list<T>::DEFAULT_CAPACITY = 8; 

template<typename T>
list<T>::list(int capacity)
	:head_(nullptr),
	tail_(nullptr),
	count_(0),
	capacity_(capacity)
{
}

template<typename T>
void list<T>::add(const T elements[], int n)
{
	for(int i = 0; i < n && !full(); ++i)
	{
		if(empty())
		{
			head_ = node_ptr<T>(new node<T>(elements[i]));
			tail_ = head_;
		}
		else
		{
			tail_->next = node_ptr<T>(new node<T>(elements[i]));
			tail_ = tail_->next;
		}
		count_++;
	}
}

template<typename T>
typename list<T>::const_iterator list<T>::end(void) const 
{
	if(!empty())
	{
		return const_iterator(tail_->next);
	}
	else
	{
		return const_iterator(head_);
	}
}

}

#endif
