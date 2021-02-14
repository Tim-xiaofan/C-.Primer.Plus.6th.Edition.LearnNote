/** 20210210 15:49, zyj, GuangDong */
#include "tabtenn0.h"
#include <iostream>

void Show(TableTennisPlayer & rt)
{
	using std::cout;
	cout << "Name: ";
	rt.Name();
	cout << "\nTable: ";
	if (rt.HasTable())
	  cout << "yes\n";
	else
	  cout << "no\n";
}

int main()
{
	using std::cout;
	using std::endl;
	TableTennisPlayer ttp;
	ttp.Name();
	cout << endl;
	TableTennisPlayer player1("Tara", "Boomdea", false);
	RatedPlayer rplayer1(1140, "Mallory", "Duck", true);
	rplayer1.Name(); // derived object uses base method
	if (rplayer1.HasTable())
	  cout << ": has a table.\n";
	else
	  cout << ": hasn't a table.\n";
	player1.Name(); // base object uses base method
	if (player1.HasTable())
	  cout << ": has a table";
	else
	  cout << ": hasn't a table.\n";
	cout << "Name: ";
	rplayer1.Name();
	cout << "; Rating: " << rplayer1.Rating() << endl;
	// initialize RatedPlayer using TableTennisPlayer object
	RatedPlayer rplayer2(1212, player1);
	cout << "Name: ";
	rplayer2.Name();
	cout << "; Rating: " << rplayer2.Rating() << endl;

	RatedPlayer rplayer3(1140, "Mallory", "Duck", true);
	TableTennisPlayer & rt = rplayer3;
	TableTennisPlayer * pt = &rplayer3;
	rt.Name(); // invoke Name() with reference
	cout << endl;
	pt->Name(); // invoke Name() with pointer
	cout << endl;

	Show(player1);
	Show(rplayer1);

	RatedPlayer olaf1(1840, "Olaf", "Loaf", true);
	TableTennisPlayer olaf2(olaf1);/** copy constructor*/
	return 0;
}
