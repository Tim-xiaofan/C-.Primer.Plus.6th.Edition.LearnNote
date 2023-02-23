#include <iostream>
#include <vector>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::string;

const float NEXT_10000_TAX = 0.1;
const float NEXT_20000_TAX = 0.15;
const float AFTER_35000_TAX = 0.20;

float calculate_tax(float income)
{
	if(income <= 5000)
	{
		return 0.0;
	}
	else if(income <= 15000)
	{
		return (income - 5000) * NEXT_10000_TAX;
	}
	else if(income <= 35000)
	{
		return 10000 * NEXT_10000_TAX + (income - 5000 - 10000) * NEXT_20000_TAX;
	}
	else
	{
		return 10000 * NEXT_10000_TAX + 20000 * NEXT_20000_TAX + (income - 35000) * AFTER_35000_TAX;
	}
}

int main(void)
{
	float income;	
	while((cin >> income) && ( income >= 0))
	{
		cout << "tax: " << calculate_tax(income) << endl;
	}
	return 0;
}
