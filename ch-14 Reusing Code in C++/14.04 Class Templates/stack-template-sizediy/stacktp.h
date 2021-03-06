/*20210218 18:24, zyj, GuangDong*/
#ifndef STACKTP_H_
#define STACKTP_H_
#include <iostream>
template <class Type>
class Stack
{
	private:
		enum {SIZE = 10}; // constant specific to class
		Type *items; // holds stack items
		int stacksize;
		int top; // index for top stack item
		Stack (const Stack & st);
		Stack & operator=(const Stack & st);
	public:
		explicit Stack(int sz = SIZE);
		~Stack(){delete [] items;}
		bool isempty() const;
		bool isfull() const;
		// push() returns false if stack already is full, true otherwise
		bool push(const Type & item); // add item to stack
		// pop() returns false if stack already is empty, true otherwise
		bool pop(Type & item); // pop top into item
		/** firiends*/
		template <class T>
		friend std::ostream & operator<<(std::ostream & os, 
					const Stack<T> & s);
};

/** private methods*/
template <class Type>
Stack<Type>::Stack(const Stack & st){}

template <class Type>
Stack<Type> & Stack<Type>::operator=(const Stack & st){ return *this;}

/** public methods*/
template <class Type>
Stack<Type>::Stack(int sz) // create an empty stack
{
	top = 0;
	stacksize = sz;
	items = new Type[sz];
}

template <class Type>
bool Stack<Type>::isempty() const
{
	return top == 0;
}

template <class Type>
bool Stack<Type>::isfull() const
{
	return top == stacksize;
}

template <class Type>
bool Stack<Type>::push(const Type & item)
{
	if (top < stacksize)
	{
		items[top++] = item;
		return true;
	}
	else
	  return false;
}

template <class Type>
bool Stack<Type>::pop(Type & item)
{
	if (top > 0)
	{
		item = items[--top];
		return true;
	}
	else
	  return false; 
}

/** friends methods */
template <class Type>
std::ostream & operator<<(std::ostream & os, 
			const Stack<Type> & s)
{
	int tmp = s.top;
	int i = 0;
	while(tmp > 0)
	{
	  os << s.items[--tmp];
	  if(i % 5 == 4 && tmp != 0) os << "\n";
	  else os << " ";
	  i++;
	}
	os << "\n";
	return os;
}

#endif
