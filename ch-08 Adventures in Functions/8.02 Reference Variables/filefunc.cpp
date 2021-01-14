/*20210112 21:28,zyj,GuangDong*/
//filefunc.cpp -- function with ostream & parameter
#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;
void file_it(ostream & os, double fo, const double fe[],int n);
const int LIMIT = 5;

int main()
{
	ofstream fout;
	const char * fn = "ep-data.txt";
	fout.open(fn);
	if (!fout.is_open())
	{
		cout << "Can't open " << fn << ". Bye.\n";
		exit(EXIT_FAILURE);
	}
	double objective;//物镜焦距
	cout << "Enter the focal length of your "
		"telescope objective in mm: ";
	cin >> objective;
	double eps[LIMIT];//目镜焦距
	cout << "Enter the focal lengths, in mm, of " << LIMIT
		<< " eyepieces:\n";
	for (int i = 0; i < LIMIT; i++)
	{
		cout << "Eyepiece #" << i + 1 << ": ";
		cin >> eps[i];
	}
	file_it(fout, objective, eps, LIMIT);
	cout.setf(ios::showpoint);
	cout.precision(7);
	cout << "test:" << 5.0 << endl;
	file_it(cout, objective, eps, LIMIT);
	cout << "test:" << 6.0 << endl;
	cout << "Done\n";
	return 0;
}

void file_it(ostream & os, double fo, const double fe[],int n)
{
	ios_base::fmtflags initial;
	initial = os.setf(ios_base::fixed); // save initial formatting state
	os.precision(0);/*All these settings stay in place unless they’re reset by another method call*/
	os << "Focal length of objective: " << fo << " mm\n";
	os.setf(ios::showpoint);
	os.precision(1);
	os.width(12);/*This setting holds for displaying one value only,and then it reverts to the default*/
	os << "f.l. eyepiece";
	os.width(15);
	os << "magnification" << endl;
	for (int i = 0; i < n; i++)
	{
		os.width(12);
		os << fe[i];
		os.width(15);
		os << int (fo/fe[i] + 0.5) << endl;
	}
	os.setf(initial); // restore initial formatting state
}
