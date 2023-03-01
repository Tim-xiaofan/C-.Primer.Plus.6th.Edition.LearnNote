#include <iostream>
#include <string>
#include <cstring>

using std::cout;
using std::endl;
using std::string;

class Person 
{
	private:
		static const int LIMIT = 25;
		string lname; // Person’s last name
		char fname[LIMIT]; // Person’s first name

	public:
		Person() { lname = ""; fname[0] = '\0'; } // #1
		Person(const string & ln, const char * fn = "Heyyou"); // #2
		// the following methods display lname and fname
		void Show() const; // firstname lastname format
		void FormalShow() const; // lastname, firstname format
};

Person::Person(const string& ln, const char* fn)
		:lname(ln)
{
	strncpy(fname, fn, LIMIT - 1);
}

void Person::Show(void) const
{
	cout << fname << " " << lname << endl;
}

void Person::FormalShow(void) const
{
	cout << lname << " " << fname << endl;
}

int main(void)
{
	Person one; // use default constructor
	Person two("Smythecraft"); // use #2 with one default argument
	Person three("Dimwiddy", "Sam"); // use #2, no defaults
	cout << "one----->\n";
	one.Show();
	one.FormalShow();
	cout << "two----->\n";
	two.Show();
	two.FormalShow();
	cout << "three----->\n";
	three.Show();
	three.FormalShow();
	return 0;
}
