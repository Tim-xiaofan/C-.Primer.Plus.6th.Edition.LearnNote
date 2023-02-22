#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int main(void)
{
	double daphne = 100.0;
	double cleo = 100.0;
	int year = 0;
    while(cleo <= daphne)
    {
		++year;
        daphne += 10;
        cleo += cleo * 0.05;
    }
	cout << year << " years it takes for the value of Cleo’s investment "
		"to exceed the value of Daphne’s investment" << endl;
	cout << "Daphne's final balance is " << daphne << "." << endl;
	cout << "Cleo's final balance is " << cleo << "." << endl;
    return 0;
}
