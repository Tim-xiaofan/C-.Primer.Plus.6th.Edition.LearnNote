/*20210114 21:09,zyj,GuangDong*/
#include <iostream>
using namespace std;

void print(const char * str, int width); // #1
void print(double d, int width = 0); // #2
void print(long l, int width = 0); // #3
void print(int i, int width = 0); // #4
void print(const char *str); // #5

/*reference not allowed*/
double cube(double x);
double cube(double & x);

/*const allowed*/
void dribble(char * bits); // overloaded
void dribble (const char *cbits); // overloaded
void dabble(char * bits); // not overloaded
void drivel(const char * bits); // not overloaded

/*only function type not allowed*/
long gronk(int n, float m); // same signatures,
//double gronk(int n, float m); // hence not allowed

/*function allowed with different signature*/
long gronk1(int n, float m); // same signatures,
double gronk1(float n, float m); // hence not allowed

int main()
{
	print("Pancakes", 15); // use #1
	print("Syrup"); // use #5
	print(1999.0, 10); // use #2
	print(1999, 12); // use #4
	print(1999L, 15); // use #3
	unsigned int year = 3210;
	//print(year, 6); // ambiguous call
	print((float)year, 6);
	double d = 6.0;
	double &rd = d;
	//cout << cube(d) << endl;//ambiguous
	//cout << cube(rd) << endl;//ambiguous
	cout << cube(6.0) << endl;

	const char p1[20] = "How's the weather?";
	char p2[20] = "How's business?";
	dribble(p1); // dribble(const char *);
	dribble(p2); // dribble(char *);
	//dabble(p1); // no match
	dabble(p2); // dabble(char *);
	drivel(p1); // drivel(const char *);
	drivel(p2); // drivel(const char *);
	return 0;
}


void print(const char * str, int width)
{
	using namespace std;
	cout.width(width);
	cout << str << endl;
}
void print(double d, int width)
{
	using namespace std;
	cout.width(width);
	cout << d << endl;
}

void print(long l, int width)
{
	using namespace std;
	cout.width(width);
	cout << l << endl;
}

void print(int i, int width)
{
	using namespace std;
	cout.width(width);
	cout << i << endl;
}

void print(const char *str)
{
	using namespace std;
	cout << str << endl;
}



double cube(double x)
{
	using namespace std;
	cout << "cube value:" << endl;
	return x * x * x;
}
double cube(double & x)
{
	using namespace std;
	cout << "cube reference:" << endl;
	return x * x * x;
}


void dribble(char * bits)
{ // overloaded
	using namespace std;
	cout << "dribble(char * bits): " << bits << endl;
}
void dribble (const char *cbits) // overloaded
{ // overloaded
	using namespace std;
	cout << "dribble(const char * cbits): " << cbits << endl;
}
void dabble(char * bits) // not overloaded
{ // overloaded
	using namespace std;
	cout << "dabble(char * bits): " << bits << endl;
}
void drivel(const char * bits) // not overloaded
{ // overloaded
	using namespace std;
	cout << "drivel(const char * bits): " << bits << endl;
}
