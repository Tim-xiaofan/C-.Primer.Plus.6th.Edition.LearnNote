/*20210107 21:32,zyj,GuangDong*/
// simple1.cpp -- pointer to function
#include <iostream>
#include <typeinfo>
using namespace std;

double d1 = 1, d2 = 2, d3 = 3;
const double *pd[3] = {&d1, &d2, &d3};

const double * f1(const double ar[], int n)
{
	//cout << "f1" << endl;
	return pd[0];
}
const double * f2(const double [], int)
{
	//cout << "f2" << endl;
	return pd[1];
}
const double * f3(const double *, int)
{
	//cout << "f3" << endl;
	return pd[2];
}

int main(int argc, char *argv[])
{
	const double * (*p1)(const double *, int) = f1;
	auto p2 = f2; // C++11 automatic type deduction
	double av[3];
	cout << (*p1)(av,3) << ": " << *(*p1)(av,3) << endl;
	cout << p2(av,3) << ": " << *p2(av,3) << endl;
	/* function poniter array, which means each element is function pointer */
	const double * (*pa[3])(const double *, int) = {f1,f2,f3};
	//cout << "pa is " << typeid(*pa[0]).name() << endl;
	cout << "sizeof(pa) = " << sizeof(pa) << endl;
	int i;
	//cout << "i is " << typeid(i).name() << endl;
	for(i = 0; i < 3; i++)
	  cout << *(*pa[i])(av,3) << endl;
	/* Automatic type deduction works with a single initializer value, not an initialization list */
	//auto pa1 = {f3,f2,f1};/*not work ,but g++ compiler does not give a warning*/
	//cout << "sizeof(pa1) = " << sizeof(pa1) << endl;
	//cout << *(*pa1[0])(av,3) << endl;
	/* error:match for ‘operator[]’ (operand types are 
	  ‘std::initializer_list<const double* (*)(const double*, int)>’ and ‘int’)*/
	auto pb = pa;
	cout << "sizeof(pb) = " << sizeof(pb) << endl;
	for(i = 0; i < 3; i++)
	  cout << *(*pb[i])(av,3) << endl;
	/* if no auto:pointer notation*/
	const double *(**pb1)(const double *, int) = pa;
	cout << "sizeof(pb1) = " << sizeof(pb) << endl;
	for(i = 0; i < 3; i++)
	  cout << *(*pb1[i])(av,3) << endl;
	/* create a pointer to the whole array*/
	auto pc = &pa;
	cout << "sizeof(pc) = " << sizeof(pc) << endl;
	const double *(*(*pd)[3])(const double *, int) = &pa;
	for(i = 0; i < 3; i++)
	  cout << *(*(*pd)[i])(av, 3) << endl;
	/* C++ does provide tools other than auto for simplifying declarations */
	typedef const double *(*p_fun)(const double *, int);
	p_fun pf1 = f1;
	cout << endl << *(*pf1)(av, 3) << endl;
	p_fun pf_arr[3] = {f2, f3, f1};
	for(i = 0; i < 3; i++)
		cout << *(*pf_arr[i])(av, 3) << endl;
	p_fun (*paf)[3] = &pf_arr; // paf points to an array of 3 function pointers
	cout << endl;
	for(i = 0; i < 3; i++)
	  cout << *(*(*paf)[i])(av, 3) << endl;
	return 0;
}
