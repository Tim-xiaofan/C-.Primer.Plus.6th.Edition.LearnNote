/* 20210319 22:35, zyj, GuangDong*/
// declarations.cpp -- C++ 11 declarations
#include <iostream>
#include <array>
#include <vector>
#include <memory>

class Integer
{
	private:
		int _i;
	public:
		Integer(int i) : _i(i){}
		~Integer() {}
		friend std::ostream & 
			operator<<(std::ostream & os, const  Integer & i);
};


std::ostream & 
	operator<<(std::ostream & os, const  Integer & i)
{
	os << i._i;
	return os;
}

int main()
{
	using namespace std;

	auto_ptr<Integer> apI(new Integer(1));
	cout << "*apI = "<< *apI << endl;

	unique_ptr<int> upi(new int(2));
	cout << "*upi = " << *upi << endl;

	shared_ptr<string> sps(new string("shared_ptr"));
	cout << "*sps =" << *sps << endl;
}
