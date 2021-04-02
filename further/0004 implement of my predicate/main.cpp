/** 20210401 11:16, zyj, GuangDong*/
// list_class_insert.cpp
#include <list>
#include <iostream>
#include <string>

//class predicate 
//{
//	private:
//		;
//	public:
//		predicate(const callback cb);
//		predicate & operator=(const callback cb){_cb = cb; return *this;}
//		bool operator()(int x)const{return _cb(x);}
//};

template<typename T>
struct predicate : public std::unary_function<T,bool>
{
    bool operator () (T value)
    {
        // do something and return a boolean
    }
}

class equal
{
	private:
		int _val;
	public:
		equal(int x):_val(x){}
		bool operator()(int x) const { return (_val == x);}
};


int main()
{
}
