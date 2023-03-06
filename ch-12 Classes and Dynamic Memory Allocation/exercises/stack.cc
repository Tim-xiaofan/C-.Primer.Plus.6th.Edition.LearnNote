#include "stack.h"
#include <cstring>

Stack::Stack(int n)
		:pitems(new Item[n]),
		size(n),
		top(0)
{}

Stack::Stack(const Stack& rhs)
{
	size = rhs.size;
	top = rhs.top;
	pitems = new Item[size];
	memcpy(pitems, rhs.pitems, top * sizeof(Item));
}

Stack::~Stack()
{
	delete[] pitems;
}

bool Stack::push(const Item& item)
{
	if(!isfull())
	{
		pitems[top++] = item;
		return true;
	}
	else
	{
		return false;
	}
}

bool Stack::pop(Item& item)
{
	if(!isempty())
	{
		item = pitems[--top];
		return true;
	}
	else
	{
		return false;
	}
}

Stack& Stack::operator=(const Stack& rhs)
{
	if(this != &rhs)
	{
		top = rhs.top;
		size = rhs.size;
		delete[] pitems;
		pitems = new Item[size];
		memcpy(pitems, rhs.pitems, top * sizeof(Item));
	}
	return *this;
}

std::ostream& operator<<(std::ostream& os, const Stack& s)
{
	for(int i = 0; i < s.top; ++i)
	{
		os << s.pitems[i] << " ";
	}
	return os;
}
