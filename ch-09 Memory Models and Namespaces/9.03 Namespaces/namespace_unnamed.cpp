/*20210123 13:25,zyj,GuangDong*/
/* namespace_unnamed.cpp -- 
   This provides an alternative to using static variables with internal linkage */
#include <iostream>
#define NAMESAPCE

#ifdef NAMESAPCE
namespace
{
	int counts; // static storage, internal linkage
}
#else
static int counts;
#endif
int other();
int main()
{
	counts = 2.333;
	other();
}
int other()
{
	std::cout << "counts = " << counts << std::endl;
	return 0;
}
