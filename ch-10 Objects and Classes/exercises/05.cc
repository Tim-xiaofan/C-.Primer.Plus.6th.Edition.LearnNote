#include <iostream>
#include <cassert>
#include <string>
#include <cstdlib>
#include <time.h>

using std::cout;
using std::endl;
using std::string;

template<typename T>
class stack
{
	public:
		stack();
		~stack();
		const T& top(void) const; 
		bool pop(void);
		bool push(const T& e);
		void show(void) const;
		bool empty(void) const { return top_ == 0; }
	private:
		static const int MAXCAPACITY = 8;
		int top_;
		T data_[MAXCAPACITY];
};

template <typename T>
stack<T>::stack()
		:top_(0)
{}

template <typename T>
stack<T>::~stack()
{}


template <typename T>
const T& stack<T>::top(void) const
{
	assert(top_ > 0 && top_ <= MAXCAPACITY);
	return data_[top_ - 1];
}

template <typename T>
bool stack<T>::pop(void)
{
	if(top_ > 0)
	{
		--top_;
		return true;
	}
	else
	{
		return false;
	}
}


template <typename T>
bool stack<T>::push(const T& e)
{
	if(top_ < MAXCAPACITY)
	{
		data_[top_++] = e;
		return true;
	}
	else
	{
		return false;
	}
}

template <typename T>
void stack<T>::show(void) const
{
	for(int i = 0; i < top_; ++i)
	{
		cout << data_[i] << " ";
	}
	cout << endl;
}

struct customer 
{
	string fullname;
	double payment;
};

std::ostream& operator<<(std::ostream& os, const customer& c)
{
	os << "<" <<c.fullname << ", " << c.payment << ">";
	return os;
}

int main(void)
{
	{
		stack<int> s;
		int i = 0;
		while(s.push(i))
		{
			++i;
		}
		s.show();
		while(!s.empty())
		{
			cout << "pop " << s.top() << ": ";
			s.pop();
			s.show();
		}
	}

	{
		srand(::time(nullptr));
		
		customer c = {.payment = 6000.0};
		stack<customer> s;
		while(s.push(c))
		{
			c.payment = (1 + ::rand() % 2000) * 1.99 + 6000;
		}
		s.show();
		double total = 0.0;
		while(!s.empty())
		{
			total += s.top().payment;
			cout << "pop " << s.top() << ": " << total << endl;;
			s.pop();
		}
	}
	return 0;
}
