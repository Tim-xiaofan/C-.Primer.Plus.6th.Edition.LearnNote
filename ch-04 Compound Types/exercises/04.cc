#include <string>
#include <iostream>

using std::cout;
using std::cin;
using std::endl;
using std::string;

struct CandyBar
{
	string name;
	float weight;
	int calories;
};

int main(void)
{
	struct CandyBar snack = {"Mocha Nunch", 2.3, 350};
	cout << snack.name << endl;
	cout << snack.weight << endl;
	cout << snack.calories << endl;
	return 0;
}
