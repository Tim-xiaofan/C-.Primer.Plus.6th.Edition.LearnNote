#include <iostream>
#include "golf.h"

using std::cout;
using std::endl;

static const int N = 3;

int main(void)
{
	{
		golf golfs[N];
		int ct = 0;
		while(setgolf(golfs[ct]) && (ct < N))
		{
			++ct;
		}
		for(int i = 0; i < ct; ++i)
		{
			showgolf(golfs[i]);
		}
	}

	{
		golf andy;
		setgolf(andy, "Ted", 15);
		showgolf(andy);
		handicap(andy, 14);
		showgolf(andy);
	}
	return 0;
}
