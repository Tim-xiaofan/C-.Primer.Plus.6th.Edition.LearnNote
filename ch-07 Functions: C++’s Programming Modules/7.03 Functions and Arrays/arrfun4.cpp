/*20201230 22:40,zyj,GuangDong*/
// arrfun4.cpp -- array functions and const 
#include <iostream>
#define LIMIT 20
using namespace std;
int fill_array(double ar[], int limit);
void show_array(const double ar[], int n);
void revalue(double r, double ar[], int n);

int main(int argc, char *argv[])
{
	double input[LIMIT];
	int count = fill_array(input, LIMIT);
	cout << "get " << count << " vals" << endl;
	show_array(input, count);
	return 0;
}

int fill_array(double ar[], int limit)
{
	double temp;
	int i;
	for (i = 0; i < limit; i++)
	{
		cout << "Enter value #" << (i + 1) << ": ";
		cin >> temp;
		if (!cin) // bad input
		{
			cin.clear();
			while (cin.get() != '\n')/*stop reading until get newline character*/
			  continue;
			cout << "Bad input; input process terminated.\n";
			break;
		}
		else if (temp < 0) // signal to terminate
		  break;
		ar[i] = temp;
	}
	return i;
}

void show_array(const double ar[], int n)
{
	using namespace std;
	for (int i = 0; i < n; i++)
	{
		cout << "Property #" << (i + 1) << ": $";
		cout << ar[i] << endl;
	} 
}

// multiplies each element of ar[] by r
void revalue(double r, double ar[], int n)
{
	for (int i = 0; i < n; i++)
	  ar[i] *= r;
}
