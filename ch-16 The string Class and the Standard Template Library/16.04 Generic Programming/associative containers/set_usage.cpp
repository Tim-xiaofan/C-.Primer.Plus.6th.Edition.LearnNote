/* 20210309 22:13, zyj, GuangDong*/
// set_usage.cpp -- usage of set container
#include <iostream>
#include <string>
#include <memory>
#include <vector>
#include <cstdlib>
#include <cstdint>
#include <algorithm> /** for_each*/
#include <ctime>
#include <iterator>
#include <cstdint>
#include <set>

#define N 10

using namespace std;

const string months[12]=
{
	"January",
	"February",
	"March",
	"April",
	"May",
	"June",
	"July",
	"Aguest",
	"September",
	"October",
	"November",
	"December"
};

static void output(const std::string & s) {std::cout << s << " ";}

int main()
{
	string s1[N] = {"buffoon", "thinkers", "for", "heavy", "can", "for", "July", "Aguest", "May", "February"};
	set<string, less<string> > A(s1, s1 + N); // initialize set A using a range from array
	ostream_iterator<string, char> out(cout, " ");
	cout << "set A : ";
	copy(A.begin(), A.end(), out);
	cout << endl;
	
	set<string, less<string> > B(months, months + 12);
	cout << "set B : ";
	copy(B.begin(), B.end(), out);
	cout << endl;

	/** sets union*/
	cout << "A U B : ";
	set_union(A.begin(), A.end(), B.begin(), B.end(), out);
	cout << endl;

	set<string, less<string> > C;
	/** must use ouput iterator*/
	insert_iterator<set<string> > insertor(C, C.begin());
	cout << "A U B : ";
	set_union(A.begin(), A.end(), B.begin(), B.end(), insertor);
	copy(C.begin(), C.end(), out);
	cout << endl;

	/** sets intersection*/
	set<string> D;
	insert_iterator<set<string> > insertor1(D, D.begin());
	cout << "A and B : ";
	set_intersection(A.begin(), A.end(), B.begin(), B.end(), insertor1);
	copy(D.begin(), D.end(), out);
	cout << endl;
	
	/** sets difference*/
	set<string> E;
	insert_iterator<set<string> > insertor2(E, E.begin());
	cout << "A B difference: ";
	set_difference(A.begin(), A.end(), B.begin(), B.end(), insertor2);
	copy(E.begin(), E.end(), out);
	cout << endl;

	/** not need a location because sorting determines where additions to a set go*/
	set<string> F;
	string s("Tom");
	F.insert(s);
	F.insert(months, months + 12);
	cout << "F : ";
	copy(F.begin(), F.end(), out);
	cout << endl;
}
