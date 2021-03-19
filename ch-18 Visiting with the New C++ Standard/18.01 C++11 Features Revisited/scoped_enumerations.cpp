/* 20210319 22:50, zyj, GuangDong*/
// scoped_enumerations.cpp -- C++ 11 enum
#include <iostream>

int main()
{
	using namespace std;
	enum Old1 {yes, no, maybe}; // traditional form
	enum class New1 {never, sometimes, often, always}; // new form
	enum struct New2 {never, lever, sever}; // new form
	cout << New2::never << endl;
	cout << New2::lever << endl;
}
