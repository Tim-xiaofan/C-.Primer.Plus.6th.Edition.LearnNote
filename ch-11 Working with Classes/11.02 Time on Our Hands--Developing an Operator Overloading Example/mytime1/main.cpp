/*20210127 22:22,zyj,GuangDong*/
// main.cpp -- implementing Time methods
#include <iostream>
#include "mytime1.h"
int main()
{
	using std::cout;
	using std::endl;
	Time planning;
	Time coding(2, 40);
	Time fixing(5, 55);
	Time debuging(15, 55);

	cout << "planning time = ";
	planning.Show();
	cout << endl;

	cout << "coding time = ";
	coding.Show();
	cout << endl;

	cout << "fixing time = ";
	fixing.Show();
	cout << endl;
	
	cout << "debuging time = ";
	debuging.Show();
	cout << endl;

	cout << "coding + fixing = ";
	(coding + fixing).Show();
	cout << endl;
	
	cout << "coding + fixing + debuging = ";
	(coding + fixing + debuging).Show();
	cout << endl;

	cout << "coding + 25 = ";
	(coding + 25).Show();
	cout << endl;

	//cout << "coding + \"25\" = ";
	//(coding + "25").Show();
	//cout << endl;
	if(fixing > debuging)
	  cout << "fixing > debuging\n";

	if(fixing <= debuging)
	  cout << "fixing <= debuging\n";

	cout << "coding - fixing= ";
	(coding - fixing).Show();
	cout << endl;
	
	cout << "debuging - fixing= ";
	(debuging - fixing).Show();
	cout << endl;
	
	cout << "debuging - debuging= ";
	(debuging - debuging).Show();
	cout << endl;

	cout << "debuging - fixing - coding= ";
	(debuging - fixing - coding).Show();
	cout << endl;
	
	cout << "debuging - (fixing + coding)= ";
	(debuging - (fixing + coding)).Show();
	cout << endl;
	
	cout << "debuging * 0.5 = ";
	(debuging * 0.5).Show();
	cout << endl;

#ifdef FRIEND
	cout << "0.5 * debuging = ";
	(0.5 * debuging).Show();
	cout << endl;
#endif
	
	cout << "debuging * 2 = ";
	(debuging * 2).Show();
	cout << endl;

#ifdef FRIEND
	cout << "2 * debuging = ";
	(2 * debuging).Show();
	cout << endl;

	cout << coding << endl;
	cout << fixing << endl;
	cout << debuging << endl;
#endif
	return 0;
}
