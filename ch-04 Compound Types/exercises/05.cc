#include <string>
#include <iostream>
#include <vector>

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
	std::vector<struct CandyBar> candyBars{
		{"Mocha Nunch", 2.3, 350}, 
		{"Tom", 5.1, 250},
		{"Jerry", 3.14, 99}};
	for(const CandyBar& snack: candyBars)
	{
		cout << snack.name << ", " 
			<< snack.weight << ", "
			<< snack.calories << endl;
	}
	return 0;
}
