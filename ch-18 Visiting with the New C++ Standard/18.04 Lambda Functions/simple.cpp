/* 20210321 16:27, zyj, GuangDong*/
// simple.cpp -- usage of function objects 
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <iterator>
#include <cmath>
#include <ctime>

#define SIZE 10

using namespace std;

/** callback functions*/
bool f3(int x){ return (x % 3 == 0); }
bool f13(int x){ return (x % 13 == 0); }

/** function object*/
class f_mod
{
	private:
		int _dv;
	public:
		f_mod(int dv):_dv(dv){}
		bool operator()(int x){ return (x % _dv == 0); }
};

int main()
{
	std::vector<int> numbers(SIZE);
	srand(time(NULL));
	std::generate(numbers.begin(), numbers.end(), std::rand);
	ostream_iterator<int, char> out(cout, " ");
	int count3, count13;

	copy(numbers.begin(), numbers.end(), out);
	cout << endl;

	cout << "------- function pointer -------\n";
	count3 = std::count_if(numbers.begin(), numbers.end(), f3);
	cout << "Count of numbers divisible by 3: " << count3 << '\n';
	count13 = std::count_if(numbers.begin(), numbers.end(), f13);
	cout << "Count of numbers divisible by 13: " << count13 << "\n\n";

	cout << "------- function object -------\n";
	count3 = std::count_if(numbers.begin(), numbers.end(), f_mod(3));
	cout << "Count of numbers divisible by 3: " << count3 << '\n';
	count13 = std::count_if(numbers.begin(), numbers.end(), f_mod(13));
	cout << "Count of numbers divisible by 13: " << count13 << "\n\n";

	cout << "------- lambda expression -------\n";
	count3 = std::count_if(numbers.begin(), numbers.end(), 
				[](int x){ return (x % 3 == 0);});
	cout << "Count of numbers divisible by 3: " << count3 << '\n';
	count13 = std::count_if(numbers.begin(), numbers.end(),
				[](int x){ return (x % 13 == 0);});
	cout << "Count of numbers divisible by 13: " << count13 << "\n\n";
}
