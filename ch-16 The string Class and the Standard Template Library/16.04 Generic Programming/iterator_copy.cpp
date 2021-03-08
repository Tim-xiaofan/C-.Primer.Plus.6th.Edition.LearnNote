/* 20210307 12:33, zyj, GuangDong*/
// vector_randomshuffle.cpp -- usage of for_each
#include <iostream>
#include <string>
#include <memory>
#include <vector>
#include <cstdlib>
#include <cstdint>
#include <algorithm> /** for_each*/
#include <ctime>
#include <iterator>

using namespace std;

int main()
{
	int casts[10] = {6, 7, 2, 9 ,4 , 11, 8, 7, 10, 5};
	vector<int> dice(10);
	copy(casts, casts + 10, dice.begin()); // copy array to vector
	for(int x:dice)
		cout << x << " ";
	cout << endl;
}
