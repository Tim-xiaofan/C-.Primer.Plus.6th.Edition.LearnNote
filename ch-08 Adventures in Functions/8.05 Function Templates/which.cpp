/*20210116 16:15,zyj,GuangDong*/
#include <iostream>

void may(int); // #1
float may(float, float = 3); // #2
void may(char); // #3
char * may(const char *); // #4
char may(const char &); // #5
template<class T> void may(const T &); // #6
template<class T> void may(T *); // #7

int main()
{
	may('B');
	return 0;
}

void may(int)
{
	using namespace std;
	cout << "match #1" << endl;
}
float may(float, float)
{
	using namespace std;
	cout << "match #2" << endl;
	return 0.0;
}
void may(char)
{
	using namespace std;
	cout << "match #3" << endl;
}
char * may(const char *)
{
	using namespace std;
	cout << "match #2" << endl;
	return NULL;
}
char may(const char &)
{
	using namespace std;
	cout << "match #5" << endl;
	return '\0';
}
template<class T> void may(const T &)
{
	using namespace std;
	cout << "match #6" << endl;
}
template<class T> void may(T *)
{
	using namespace std;
	cout << "match #7" << endl;
}
