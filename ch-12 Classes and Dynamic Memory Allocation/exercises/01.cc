//20230306, zyj, GUANGDONG
#include <iostream>
#include <cstring>

using std::cout;
using std::endl;

class Cow 
{
public:
	Cow();
	Cow(const char * nm, const char * ho, double wt);
	Cow(const Cow& c);
	~Cow();
	Cow& operator=(const Cow& c);
	void show() const; // display all cow data

private:
	char name[20];
	char *hobby;
	double weight;
};

Cow::~Cow()
{
	delete[] hobby;
}

Cow::Cow()
{
	name[0] = '\0';
	hobby = new char[1];
	hobby[0] = '\0';
	weight = 0.0;
}

Cow::Cow(const char *nm, const char *ho, double wt)
{
	strcpy(name, nm);
	hobby = new char[strlen(ho) + 1];
	strcpy(hobby, ho);
	weight = wt;
}

Cow::Cow(const Cow& c)
{
	strcpy(name, c.name);
	hobby = new char[strlen(c.hobby) + 1];
	strcpy(hobby, c.hobby);
	weight = c.weight;
}

Cow& Cow::operator=(const Cow& c)
{
	if(&c == this)
	{
		return *this;
	}
	strcpy(name, c.name);
	delete [] hobby;
	hobby = new char[strlen(c.hobby) + 1];
	strcpy(hobby, c.hobby);
	weight = c.weight;
	return *this;
}

void Cow::show(void) const
{
	cout << name << ", "
		<< hobby << ", "
		<< weight << endl;
}

int main(void)
{
	Cow c1;
	c1.show();

	Cow c2("Tom", "Fishing", 16.25);
	Cow c3 = c2;
	c2.show();
	c3.show();

	c1 = c2;
	c1.show();
	return 0;
}
