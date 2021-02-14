/** 20200214 16:03, zyj, GuangDong*/
// main.cpp -- use
#include "dma.h"
#include <iostream>
#include <cstring>

int main()
{
	using std::cout;
	using std::endl;
	
	baseDMA shirt("Portabelly", 8);
	hasDMA map("Mercator", "Buffalo Keys", 5);
	cout << "Displaying baseDMA object:\n";
	cout << shirt << endl;
	cout << "Displaying hasDMA object:\n";
	cout << map << endl;
	hasDMA map2;
	map2 = map;
	cout << "Result of hasDMA assignment:\n";
	cout << map2 << endl;

	hasDMA map3(map);
	cout << "Result of hasDMA copy constructor:\n";
	cout << map3 << endl;

	shirt.type();
	map.type();
	return 0;
}
