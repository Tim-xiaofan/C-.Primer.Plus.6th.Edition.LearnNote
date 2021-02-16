/** 20210215 22:29, zyj, GuangDong*/
#include "studentc.h"

using std::endl;
using std::cout;
using std::cin;
using std::ios_base;

const int pupils = 3;
const int quizzes = 5;
void set(Student & sa, int n);

int main()
{
	double scores[7] = {75.5, 78.5, 99, 88, 89, 69, 58.5};
	Student s1("S1", scores, 7);
	cout << s1;
	cout.setf(ios_base::fixed, ios_base::floatfield);
	cout.precision(1);
	cout << "S1 average: " << s1.Average() << endl;

	/** book codes*/
	Student ada[pupils] ={
		Student(quizzes), 
		Student(quizzes), 
		Student(quizzes)};
	int i;
	for (i = 0; i < pupils; ++i)
	  set(ada[i], quizzes);
	cout << "\nStudent List:\n";
	for (i = 0; i < pupils; ++i)
	  cout << ada[i].Name() << endl;
	cout << "\nResults:";
	for (i = 0; i < pupils; ++i)
	{
		cout << endl << ada[i];
		cout << "average: " << ada[i].Average() << endl;
	}
	cout << "Done.\n";
	return 0;
}

void set(Student & sa, int n)
{
	cout << "Please enter the student's name: ";
	getline(cin, sa);
	cout << "Please enter " << n << " quiz scores:\n";
	for (int i = 0; i < n; i++)
	  cin >> sa[i];
	while (cin.get() != '\n')
	  continue;
}
