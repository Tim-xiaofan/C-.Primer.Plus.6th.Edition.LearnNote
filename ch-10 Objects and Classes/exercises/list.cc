#include "list.h"

namespace exercises
{

template<typename T>
list<T>::list(int capacity)
	:capacity_(capacity),
	head_(nullptr),
	tail_(nullptr)
{
}

template<typename T>
void list<T>::add(const T elements[], int n)
{
	for(int i = 0; i < n & !full(); ++i)
	{
		if(empty())
		{
			head_ = std::make_shared(elements[i]);
			tail_ = head_;
		}
		else
		{
			tail_->next = std::make_shared(elements[i]);
			tail_ = tail_->next;
		}
		count_++;
	}
}

}
