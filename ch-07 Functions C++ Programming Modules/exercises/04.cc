#include <iostream>

using std::cout;
using std::endl;
using std::cin;

long double probability(unsigned numbers, unsigned picks)
{
	long double result = 1.0;
	for(long double n = numbers; picks > 0; --picks, --n)
	{
		result *= n / picks;
	}
	return result;
}


int main(void)
{
	double total1, choices1, total2, choices2;
	cout << "Enter the total number of choices on the game card and\n"
		"the number of picks allowed:\n";
	while ((cin >> total1 >> choices1 >> total2 >> choices2) &&
				choices1 <= total1 &&
				choices2 <= total2)
	{
		cout << "You have one chance in ";
		// compute the odds
		cout << probability(total1, choices1) * probability(total2, choices2); 
		cout << " of winning.\n";
		cout << "Next four numbers (q to quit): ";
	}
	cout << "bye\n";
	return 0;	
}
