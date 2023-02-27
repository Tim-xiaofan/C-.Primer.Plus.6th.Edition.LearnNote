#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

struct candy_bar
{
	string name;
	double weight;
	int calories;
};

static void set(candy_bar& c, const char* name, double weight, int calories)
{
	c.name = name;
	c.weight = weight;
	c.calories = calories;
}

static void print(const candy_bar& c)
{
	cout << c.name << ", "
		<< c.weight << ", "
		<< c.calories << endl;
}

int main(void)
{
	struct candy_bar c;
	set(c, "name", 2.56, 12);
	print(c);
	return 0;
}
