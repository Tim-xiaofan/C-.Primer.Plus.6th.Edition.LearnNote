/*20210115 12:47,zyj,GuangDong*/
#include <iostream>
using namespace std;

struct job
{
	char name[40];
	double salary;
	int floor;
};

void job_show(const struct job &j);
// non template function first
void Swap(struct job &j, struct job &k);
// template function last
template <typename AnyType>
void Swap(AnyType &a, AnyType &b);
// explicit specialization for the job type, second
template <> 
void Swap<struct job>(struct job &, struct job &);

int main()
{
	int i = 10;
	int j = 20;
	cout << "i, j = " << i << ", " << j << ".\n";
	cout << "Using compiler-generated int swapper:\n";
	Swap(i,j); // generates void Swap(int &, int &)
	cout << "Now i, j = " << i << ", " << j << ".\n";

	double x = 24.5;
	double y = 81.7;
	cout << "x, y = " << x << ", " << y << ".\n";
	cout << "Using compiler-generated double swapper:\n";
	Swap(x,y); // generates void Swap(double &, double &)
	cout << "Now x, y = " << x << ", " << y << ".\n";

	char *m = (char *)"mm";
	char *n = (char *)"nn";
	cout << "m, n = " << m << ", " << n << ".\n";
	cout << "Using compiler-generated double swapper:\n";
	Swap(m,n); // generates void Swap(double &, double &)
	cout << "Now m, n = " << m << ", " << n << ".\n";

	// cin.get();
	struct job teacher = {"Tom", 4500.0, 0}, doctor = {"Jarray", 6500.0, 1};
	cout << "teacher, doctor = ";
	job_show(teacher);
	cout << ", ";
	job_show(doctor);
	cout << endl;
	Swap(teacher, doctor);/*Explicit one, not template one*/
	cout << "Now teacher, doctor = ";
	job_show(teacher);
	cout << ", ";
	job_show(doctor);
	cout << endl;

	return 0;
}

template <typename AnyType>
void Swap(AnyType &a, AnyType &b)
{
	AnyType tmp;
	tmp = a;
	a = b;
	b = tmp;
}

void job_show(const struct job &j)
{
	cout << "{name:" <<j.name;
	cout << ", salary:" << j.salary;
	cout << ", floor:" << j.floor << "}";
}


/*explicit specializations second*/
template <> void Swap<struct job>(struct job &j, struct job &k)
{
	using namespace std;
	cout << "explicit specialization executed------"<< endl;
	struct job tmp;
	tmp = j;
	j.salary = k.salary;
	j.floor = k.floor;
	k.salary = tmp.salary;
	k.floor  = tmp.floor;
}

/*non template function first*/
void Swap(struct job &j, struct job &k)
{
	using namespace std;
	cout << "non template executed------"<< endl;
	struct job tmp;
	tmp = j;
	j.salary = k.salary;
	j.floor = k.floor;
	k.salary = tmp.salary;
	k.floor  = tmp.floor;
}
