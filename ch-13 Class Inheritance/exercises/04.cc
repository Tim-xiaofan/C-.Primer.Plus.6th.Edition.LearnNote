#include <iostream>
#include <memory>
#include <cstring>

using std::cout;
using std::endl;
using std::unique_ptr;
using std::ostream;

class Port
{
	public:
		Port(const char* br = "none", const char* st = "none", int b = 0);
		Port(const Port& p); // copy constructor
		virtual ~Port() {}
		Port& operator=(const Port& p);
		Port& operator+=(int b) // adds b to bottles
		{ bottles += b; return *this; }
		Port& operator-=(int b) // subtracts b from bottles, ifavailable
		{ if(bottles >= b) { bottles -= b; } return *this; }
		int BottleCount() const { return bottles; }
		virtual void Show() const;
		friend ostream& operator<<(ostream& os, const Port& p);
	private:
		unique_ptr<char[]> brand;
		char style[20]; // i.e., tawny, ruby, vintage
		int bottles;
};



Port::Port(const char* br, const char* st, int b)
		:bottles(b)
{
	char* tmp = new char[strlen(br) + 1];
	strcpy(tmp, br);
	brand.reset(tmp);
	strcpy(style, st);
}

void Port::Show() const
{
	cout << "Brand: " << brand.get() << endl;
	cout << "Style: " << style << endl;
	cout << "Bottles: " << bottles << endl;
}

ostream& operator<<(ostream& os, const Port& p)
{
	os << p.brand.get() << ", "
		<< p.style << ", "
		<< p.bottles;
	return os;
}

class VintagePort : public Port // style necessarily = "vintage"
{
	public:
		VintagePort();
		VintagePort(const char* br, int b, const char* nn, int y);
		VintagePort(const VintagePort& vp);
		~VintagePort() { }
		VintagePort& operator=(const VintagePort& vp);
		void Show() const override;
		friend ostream& operator<<(ostream& os, const VintagePort& vp);
	private:
		unique_ptr<char[]> nickname; // i.e., "The Noble" or "Old Velvet", etc.
		int year; // vintage year
};

VintagePort::VintagePort()
		:Port(),
		year(0)
{
	char* tmp = new char[strlen("none")];
	strcpy(tmp, "none");
	nickname.reset(tmp);
}

void VintagePort::Show() const
{
	Port::Show();
	cout << "Nickname: " << nickname.get() << endl;
	cout << "Year: " << year << endl;
}

ostream& operator<<(ostream& os, const VintagePort& vp)
{
	os << static_cast<const Port&>(vp) << ", "
		<< vp.nickname.get() << ", "
		<< vp.year;
	return os;
}

int main(void)
{	
	Port p;
	p.Show();
	cout << p << endl;
	
	cout << endl;
	VintagePort vp;
	vp.Show();
	cout << vp << endl;
	return 0;
}
