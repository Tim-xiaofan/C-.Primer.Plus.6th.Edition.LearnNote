#include <iostream>
#include <algorithm>
#include <cstring>

using std::cout;
using std::endl;
using std::cin;

const int SLEN = 30;

struct student {
	char fullname[SLEN];
	char hobby[SLEN];
	int ooplevel;
};

static void drop_remaining(void)
{
	if(cin)
	{
		cin.clear();
	}
	while(cin.get() != '\n');
}

// getinfo() has two arguments: a pointer to the first element of
// an array of student structures and an int representing the
// number of elements of the array. The function solicits and
// stores data about students. It terminates input upon filling
// the array or upon encountering a blank line for the student
// name. The function returns the actual number of array elements
// filled.
static int getinfo(student pa[], int n)
{
	int ct = 0;
	for(int i = 0; i < n; ++i)
	{
		cout << "Student #" << (i + 1) << endl;
		cout << "Enter name: ";
		cin.getline(pa[i].fullname, SLEN);
		if(strcmp(pa[i].fullname, ""))
		{
			cout << "Enter hobby: ";
			cin.getline(pa[i].hobby, SLEN);
			cout << "Enter ooplevel: ";
			cin >> pa[i].ooplevel;
			drop_remaining();
			++ct;
		}
		else
		{
			break;
		}
	}
	return ct;
}

static void display2(const student * ps);
// display1() takes a student structure as an argument
// and displays its contents
static void display1(student st)
{
	display2(&st);
}

// display2() takes the address of student structure as an
// argument and displays the structure’s contents
static void display2(const student * ps)
{
	cout << ps->fullname << ", " << ps->hobby << ", " << ps->ooplevel;
}

// display3() takes the address of the first element of an array
// of student structures and the number of array elements as
// arguments and displays the contents of the structures
static void display3(const student pa[], int n)
{
	for(int i = 0; i < n; ++i)
	{
		display1(pa[i]);
		cout << endl;
	}
}

int main(void)
{
	cout << "Enter class size: ";
	int class_size;
	cin >> class_size;
	while (cin && cin.get() != '\n')
	  continue;
	student* ptr_stu = new student[class_size];
	int entered = getinfo(ptr_stu, class_size);
	for (int i = 0; i < entered; i++)
	{
		display1(ptr_stu[i]);
		cout << " ";
		display2(&ptr_stu[i]);
		cout << endl;
	}
	display3(ptr_stu, entered);
	delete [] ptr_stu;
	cout << "Done\n";
	return 0;	
}
