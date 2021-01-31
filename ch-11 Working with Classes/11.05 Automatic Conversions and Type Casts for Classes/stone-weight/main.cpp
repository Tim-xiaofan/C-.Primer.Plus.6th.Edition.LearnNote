/** 20210130 17:10,zyj,GunagDong*/
// main.cpp -- Stonewt methods
#include <iostream>
using std::cout;
using std::endl;
#include "stonewt.h"

void display(const Stonewt & st, int n);

int main()
{
	Stonewt myCat;
#ifndef AMBIGUOUS
	myCat = 11;/** ambiguous*/
#endif 
	myCat.show_lbs();
	myCat.show_stn();
	Stonewt incognito = 275; // uses constructor to initialize
	Stonewt wolfe(285.7); // same as Stonewt wolfe = 285.7;
	Stonewt taft(21, 8);
	cout << "The celebrity weighed ";
	incognito.show_stn();
	cout << "The detective weighed ";
	wolfe.show_stn();
	cout << "The President weighed ";
	taft.show_lbs();
	incognito = 276.8; // uses constructor for conversion
	taft = 325; // same as taft = Stonewt(325);
	cout << "After dinner, the celebrity weighed ";
	incognito.show_stn();
	cout << "After dinner, the President weighed ";
	taft.show_lbs();
	display(taft, 2);
	cout << "The wrestler weighed even more.\n";
	display(422, 2);
	cout << "No stone left unearned\n";

	double d = Stonewt(28.75); // ?? possible ??
	cout << "d = " << d << endl;

	Stonewt wolfe1(285.7);
	double host = double (wolfe1); // syntax #1
	cout << "host = " << host << endl;

	int thinker = (int) wolfe1; // syntax #2
	cout << "thinker = " << thinker << endl;

	Stonewt wells(20, 3); /** syntax #3*/
	long star = wells; // implicit use of conversion function
	cout << "star = " << star << endl;
	
	//short fish = wells; /** ambiguous*/
	short fish = (int) wells; // narrow
	cout << "fish = " << fish << endl;
	
	//long long snail = wells; /** ambiguous */
	long long snail = (double) wells; /** narrow */
	cout << "snail = " << snail << endl;

	/** book */
	Stonewt poppins(9,2.8); // 9 stone, 2.8 pounds
	double p_wt = poppins; // implicit conversion
	cout << "Convert to double => ";
	cout << "Poppins: " << p_wt << " pounds.\n";
	cout << "Convert to int => ";
	cout << "Poppins: " << int (poppins) << " pounds.\n";

	return 0;
}

void display(const Stonewt & st, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "Wow! ";
		st.show_stn();
	} 
}
