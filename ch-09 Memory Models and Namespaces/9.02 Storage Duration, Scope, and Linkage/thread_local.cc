#include <iostream>
#include <thread>
#include <unistd.h>

using std::cout;
using std::endl;

static void thread_func(void)
{
	static thread_local int i = 0;
	cout << ++i << endl;
}

int main(void)
{
	std::thread t1(thread_func);
	sleep(1);
	std::thread t2(thread_func);
	t1.join();
	t2.join();
	return 0;
}
