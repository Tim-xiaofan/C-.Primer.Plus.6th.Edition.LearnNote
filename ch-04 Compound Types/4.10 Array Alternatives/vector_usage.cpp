/*20201223 21:45,zyj,GuangDong*/
// vector_usage.cpp
#include <iostream>
#include <vector>

int main(int argc, char *argv[])
{
	using namespace std;
	vector<int> vi; // create a zero-size array of int
	cout << "Enter a number:";
	int n;
	cin >> n;
	vector<double> vd(n); // create an array of n doubles
	cout << "sizeof(vector<int> vi):" << sizeof(vi) << endl;
	cout << "sizeof(vector<doubles> vd(" << n <<")):" << sizeof(vd)<< endl;
	return 0;
}
