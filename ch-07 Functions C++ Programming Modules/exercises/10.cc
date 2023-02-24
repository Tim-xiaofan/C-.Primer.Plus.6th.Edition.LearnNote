#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::cin;
using std::vector;

using callback = double (*)(double, double);

static double add(double x, double y)
{
	return x + y;
}

static double sub(double x, double y)
{
	return x - y;
}

static double mul(double x, double y)
{
	return x * y;
}

static double div(double x, double y)
{
	return x / y;
}

static double calculate(double x, double y, callback cb)
{
	return cb(x, y);
}

int main(void)
{
	vector<callback> callbacks ={add, sub, mul, div};
	double x, y;
	cout << "enter x, y: ";
	while(cin >> x >> y)
	{
		for(size_t i = 0; i < callbacks.size(); ++i)
		{
			cout << "cb #" << (i + 1) << ": ";
			cout << calculate(x, y, callbacks[i]) << endl;
		}
		cout << "next x, y: ";
	}
	return 0;	
}
