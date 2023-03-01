#include <iostream>
#include "golf.h"

using std::cout;
using std::endl;

int main(void)
{
	golf g("Tom", 12);
	g.show();
	g.handicap(24);
	g.show();
	return 0;
}
