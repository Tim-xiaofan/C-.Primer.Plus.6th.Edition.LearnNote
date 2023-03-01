//20230228 21:25, zyj, Hutao
#include <iostream>
#include <cstring>
#include "04h.h"


namespace SALES
{
using std::endl;
using std::cout;
using std::cin;
// copies the lesser of 4 or n items from the array ar
// to the sales member of s and computes and stores the
// average, maximum, and minimum values of the entered items;
// remaining elements of sales, if any, set to 0
void setSales(Sales & s, const double ar[], int n)
{
	int entered = (n < QUARTERS) ? n : QUARTERS;
	memcpy(s.sales, ar, entered * sizeof(double));
	for(int i =  entered; i < QUARTERS; ++i)
	{
		s.sales[i] = 0;
	}

	double sum = 0;
	s.min = ar[0];
	s.max = ar[0];
	for(int i = 0; i < entered; ++i)
	{
		sum += ar[i];
		if(s.min > ar[i])
		{
			s.min = ar[i];
		}
		if(s.max < ar[i])
		{
			s.max = ar[i];
		}
	}
	s.average = sum / entered;
}

// gathers sales for 4 quarters interactively, stores them
// in the sales member of s and computes and stores the
// average, maximum, and minimum values
void setSales(Sales & s)
{
	double inputs[QUARTERS];
	int ct = 0;
	cout << "Enter sale: ";
	while((ct < QUARTERS) && (cin >> inputs[ct]))
	{
		++ct;
		if(ct < QUARTERS)
		{
			cout << "Next sale: ";
		}
	}
	setSales(s, inputs, ct);
}

// display all information in structure s
void showSales(const Sales & s)
{
	cout << "sales:";
	for(int i = 0; i < QUARTERS; ++i)
	{
		cout << s.sales[i] << " ";
	}
	cout << ", average:";
	cout << s.average << ", max:"
		<< s.max << ", min:"
		<< s.min << endl;
}

}

