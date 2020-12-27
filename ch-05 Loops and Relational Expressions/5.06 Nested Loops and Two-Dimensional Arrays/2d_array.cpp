/*20201227 16:19,zyj,GuangDong*/
//2d_array.cpp --usage of 2d array
#include <iostream>
#include <iomanip>
// 华氏温度到摄氏温度
float f2c(int f)
{
	return ((f -32) / 1.8);
}
int main(int argc, char *argv[])
{
	using namespace std;
	//declare an 2d array
	//华氏度 = 32°F+ 摄氏度 × 1.8
	//摄氏度 = (华氏度 - 32°F) ÷ 1.8
	int maxtemps[4][5] = // 2-D array
	{
		{96, 100, 87, 101, 105}, // values for maxtemps[0]
		{96, 98, 91, 107, 104}, // values for maxtemps[1]
		{97, 101, 93, 108, 107}, // values for maxtemps[2]
		{98, 103, 95, 109, 108} // values for maxtemps[3]
	};
	//access element cout<<fixed<< setprecision(2)<<sum
	for (int row = 0; row < 4; row++)
	{
		for (int col = 0; col < 5; ++col)
		  cout << maxtemps[row][col] << "(" 
			  << setiosflags(ios::fixed) <<setprecision(2) 
			  <<f2c(maxtemps[row][col]) 
			  <<")"<< "\t";
		cout << endl;
	}
	return 0;
}
