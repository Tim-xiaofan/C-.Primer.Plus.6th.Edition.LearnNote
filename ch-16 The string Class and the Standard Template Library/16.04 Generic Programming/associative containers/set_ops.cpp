/* 20210310 12:39, zyj, GuangDong*/
// setops.cpp -- some set operations
#include <iostream>
#include <string>
#include <set>
#include <algorithm>
#include <iterator>
int main()
{
	using namespace std;
	const int N = 6;
	string s1[N] = {"buffoon", "thinkers", "for", "heavy", "can", "for"};
	string s2[N] = {"metal", "any", "food", "elegant", "deliver","for"};
	set<string> A(s1, s1 + N);
	set<string> B(s2, s2 + N);
	ostream_iterator<string, char> out(cout, " ");

	cout << "Set A: ";
	copy(A.begin(), A.end(), out);
	cout << endl;
	cout << "Set B: ";
	copy(B.begin(), B.end(), out);
	cout << endl;

	cout << "Union of A and B:\n";
	set_union(A.begin(), A.end(), B.begin(), B.end(), out);
	cout << endl;
	cout << "Intersection of A and B:\n";
	set_intersection(A.begin(), A.end(), B.begin(), B.end(), out);
	cout << endl;
	cout << "Difference of A and B:\n";
	set_difference(A.begin(), A.end(), B.begin(), B.end(), out);
	cout << endl;

	/** must usg output iterator */
	set<string> C;
	cout << "Set C:";
	set_union(A.begin(), A.end(), B.begin(), B.end(),
				insert_iterator<set<string> >(C, C.begin()));
	copy(C.begin(), C.end(), out);
	cout << endl;

	string s3("grungy"), s4("ghost"), s5("spook");
	C.insert(s3);
	C.insert(s4);
	C.insert(s5);
	cout << "Set C after insertion:";
	copy(C.begin(), C.end(), out);
	cout << endl;

	cout << "Showing a range[ghost, spook]:";
	copy(C.lower_bound("ghost"),C.upper_bound("spook"), out);
	cout << endl;
	return 0;
}
