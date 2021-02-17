/** 20210215 22:29, zyj, GuangDong*/
#include "studentc.h"
#include <cstring>

using std::endl;
using std::cout;
using std::cin;
using std::ios_base;

const int pupils = 3;
const int quizzes = 5;
void set(Student & sa, int n);
template<typename T>
static void valarray_list(const T & t,
			const char * info = "valarray : ");
double scores[pupils][quizzes] = {{0, 1, 2, 3, 4},
	{5, 6, 7, 8, 9}, {10, 11, 12, 13, 14}};
std::string names[pupils] = {"Tom", "Jerry", "Spike"};

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
	{
		ada[i].Name(names[i]);
		int j;
		for (j = 0; j < quizzes; j++)
			((ada[i])[j]) = ::scores[i][j];
	}
	//ada[i].Name("Tim");
	cout << "\nStudent List:\n";
	for (i = 0; i < pupils; ++i)
	  cout << ada[i].Name() << endl;
	cout << "\nResults:";
	for (i = 0; i < pupils; ++i)
	{
		cout << endl << ada[i];
		cout << "average: " << ada[i].Average() << endl;
		cout << "sum: " << ada[i].Sum() << endl;
		cout << "min: " << ada[i].min() << endl;
		cout << "max: " << ada[i].max() << endl;
		//char info[64];
		//std::strcpy(info, std::to_string(i).c_str());
		//valarray_list(ada[i].Scores(), info);
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

template<typename T>
static void valarray_list(const T & t, const char * info)
{
	using std::endl;
	using std::cout;
	int i, size = t.size();
	cout << info;
	for(i = 0; i < size; i++)
	  cout << t[i] << " ";
	cout << endl;
}

