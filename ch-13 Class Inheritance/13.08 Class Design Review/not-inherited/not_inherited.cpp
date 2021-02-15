/** 20210214 21:38, zyj, GunagDong*/
#include <iostream>
using std::endl;
using std::cout;

class Employee
{
	private:
		int id;
	public:
		Employee(int mid = -1)
			:id(mid){}
		void show_name(){cout << "id = " << id << endl;}
		friend std::ostream & operator<<(std::ostream &os, 
					const Employee & e);
};
std::ostream & operator<<(std::ostream & os, 
			const Employee & e)
{
	os << "id = " << e.id << std::endl;
	return os;
}

class Singer : public Employee
{
	private:
		int voice_range;
	public:
		Singer(int mid = -1, int mrange = 0)
			:Employee(mid), voice_range(mrange){}
		void range(){cout << "rang = " << voice_range << endl;}
		friend std::ostream & operator<<(std::ostream &os, 
					const Singer & s);
};
std::ostream & operator<<(std::ostream &os, 
			const Singer & s)
{
	os << (Employee &)s;
	os << "range = " << s.voice_range << endl;
	return os;
}

int main()
{
	Employee veep;
	Singer trala;
	cout << veep << endl;
	cout << trala << endl;

	//Employee * pe = &trala;
	//Singer * ps = (Singer *) &veep;
	//pe->show_name();
	//ps->range(); //danger

	Singer s1(1, 2), s2(2, 3);
	cout << s1 << endl;
	cout << s2 << endl;

	s1 = s2;
	cout << s1 << endl;
}
