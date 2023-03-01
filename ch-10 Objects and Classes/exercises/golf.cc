#include <iostream>
#include <cstring>
#include "golf.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;

golf::golf(const std::string& name, int hc)
		:fullname_(name),
		handicap_(hc)
{
}

void golf::show(void) const
{
	cout << fullname_ << ","
		<< handicap_ << endl;
}
