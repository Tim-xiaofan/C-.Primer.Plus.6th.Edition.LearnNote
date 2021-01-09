/*20210107 12:38,zyj,GuangDong*/
// recur.cpp -- using recursion
#include <iostream>
void countdown(int n);
unsigned int n_func(unsigned int n);
int main(int argc, char *argv[])
{
	countdown(4); // call the recursive function
	std::cout << n_func(4) << std::endl;
	return 0;
}
void countdown(int n)
{
	using namespace std;
	cout << "Counting down ... " << n << endl;
	if (n > 0)
	  countdown(n-1); // function calls itself
	cout << n << ": Kaboom!\n";
}

unsigned int n_func(unsigned int n)
{
	if(n == 1 || n == 0)
	  return 1;
	else
	  return n * n_func(n-1);
}
