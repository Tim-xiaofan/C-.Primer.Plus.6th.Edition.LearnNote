#include "zlog.h"

int main()
{
	EVENT_LOG("event%d\n", 1);
	EVENT_LOG("event%d, %s\n", 1, "string");
	EVENT_LOG("error%d\n", 1);
	EVENT_LOG("error%d, %s\n", 1, "string");
}
