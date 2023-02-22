#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;

struct car
{
	string make;
	int year;
};

int main(void)
{
	cout << "How many cars do you wish to catalog? ";
	int n;
	cin >> n;
	cin.get();

	vector<struct car> cars;
	struct car c;
	for(int i = 0; i < n; ++i)
	{
		cout << "Car #" << i << endl;
		cout << "Please enter make: ";
		getline(cin, c.make);
		cout << "Please enter year made: ";
		cin >> c.year;
		cin.get();
		cars.push_back(c);
	}
	
	cout << "Here is your collection: " << endl;
	for(const struct car& c: cars)
	{
		cout << c.year << " " << c.make << endl;
	}
	return 0;
}
