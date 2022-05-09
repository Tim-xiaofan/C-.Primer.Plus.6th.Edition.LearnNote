/** 20210727 14:30, zyj, GuangDong*/
//C++11 style callbacks
#include <iostream>
#include <functional>

using std::cout;
using std::endl;

class Test
{
public:
      void blah() { std::cout << "class Test:member function" << std::endl; }
      static void sblah() { std::cout << "class Test: static member function" << std::endl; }
};

class Bim
{
public:
      void operator()(){ std::cout << "class Bim:member function" << std::endl; }
};

void boum() { std::cout << "function" << std::endl; }
	
int main()
{
	// store the member function of an object:
    Test test;
    std::function<void()> callback = std::bind(&Test::blah, test);
    callback();

    // store a callable object (by copy)
    callback = Bim{};
    callback();

    // store the address of a static function
    callback = &boum;
    callback();

    // store a copy of a lambda (that is a callable object)
    callback = [&]{test.blah();}; // often clearer -and not more expensive- than std::bind()
    callback();

	//static member function
	callback = &Test::sblah;
	callback();
	return 0;
}
