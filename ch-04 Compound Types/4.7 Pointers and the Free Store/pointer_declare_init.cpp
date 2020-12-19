/*20201219 21:52,zyj,GuangDong*/
// pointer_declare_init.cpp -- our first pointer variable
#include <iostream>
int main(int argc, char *argv[])
{
	using namespace std;
	int *p, p1, *p2;/*  pointer (p1) and oneordinary int (p2)*/
	char *p3, *p4;
	/*指针占位只与编译器使用的操作系统位数有关，64位OS：32位或64位。32位：32位*/
	cout << "sizeof(int *)" << sizeof(int *) << endl;
	cout << "sizeof(char *)" << sizeof(char *) << endl;
	cout << "sizeof(float *)" << sizeof(float *) << endl;
	cout << "sizeof(double *)" << sizeof(double *) << endl;
	cout << "sizeof(void *)" << sizeof(void *) << endl;

	char c = 'A';
	int i = 0x010101;
	p = &i;
	cout << "p = &i, *p = " << hex << *p << endl;
	//p1 = &i; //error: convert (int *) to int
	p2 = (int *)&c; // not arrow
	cout << "p2 = &c, *p2 = " << hex << *p2 << endl;
	cout << "p2 = &c, *(char*)p2 = " << *(char*)p2 << endl;
	p3 = &c;
	p4 = (char *)&i; // arrow
	cout << "p4 = &i, *p4 = " << *p4 << endl;
	cout << "p4 = &i, *(int*)p4 = " << *(int*)p4 << endl;
	c = (char)i;
	//p4 = &i; /*error:pinter self also has type*/
	return 0;
}
