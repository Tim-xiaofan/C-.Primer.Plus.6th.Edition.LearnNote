//20230307, zyj, GUANGDONG
#include <iostream>
#include <cstring>

using std::cout;
using std::endl;

// base class
class Cd 
{ // represents a CD disk
	private:
		char* performers;
		char* label;
		int selections; // number of selections
		double playtime; // playing time in minutes
	public:
		Cd(const char* s1, const char* s2, int n, double x);
		Cd();
		virtual ~Cd() 
		{ delete [] performers; delete [] label;};
		virtual void Report() const; // reports all CD data
		Cd & operator=(const Cd & d);
};

Cd::Cd(const char* s1, const char* s2, int n, double x)
		:performers(new char[strlen(s1) + 1]),
		label(new char[strlen(s2) + 1]),
		selections(n),
		playtime(x)
{
	strcpy(performers, s1);
	strcpy(label, s2);
}

Cd::Cd()
{
	performers = new char[1];
	performers[0] = '\0';
	label = new char[1];
	label[0] = '\0';
	selections = 0;
	playtime = 0.0;
}

static void
realloc_and_copy(char** dst, const char* src)
{
	delete [] *dst;
	*dst = new char[strlen(src) + 1];
	strcpy(*dst, src);
}

Cd& Cd::operator=(const Cd& rhs)
{
	if(&rhs != this)
	{
		realloc_and_copy(&performers, rhs.performers);
		realloc_and_copy(&label, rhs.label);
		selections = rhs.selections;
		playtime = rhs.playtime;
	}
	return *this;
}

void Cd::Report() const
{
	cout << performers << ", ";
	cout << label << ", ";
	cout << selections << ", ";
	cout << playtime << endl;
}

class Classic: public Cd
{
	public:
		Classic(const char* s1, const char* s2, const char* s3, int n, double x);
		Classic();
		~Classic(){ delete [] primary_work; }
		Classic& operator=(const Classic& rhs);
		void Report() const override;
	private:
		char* primary_work;
};

Classic::Classic(const char* s1, const char* s2, const char* s3, int n, double x)
		:Cd(s1, s2, n, x),
		primary_work(new char[strlen(s3) + 1])
{
	strcpy(primary_work, s3);
}

Classic::Classic()
		:Cd()
{
	primary_work = new char[1];
	primary_work[0] = '\0';
}

Classic& Classic::operator=(const Classic& rhs)
{
	if(&rhs != this)
	{
		const Cd& base = rhs;
		Cd::operator=(base);
		realloc_and_copy(&primary_work, rhs.primary_work);
	}
	return *this;
}

void Classic::Report() const
{
	Cd::Report();
	cout << primary_work << endl;
}

void Bravo(const Cd & disk)
{
	disk.Report();
}

int main(void)
{
	Cd c1("Beatles", "Capitol", 14, 35.5);
	Classic c2 = Classic("Piano Sonata in B flat, Fantasia in C",
				"Alfred Brendel", "Philips", 2, 57.17);
	cout << "Using object directly:\n";
	c1.Report(); // use Cd method
	c2.Report(); // use Classic method

	cout << "\nUsing type cd * pointer to objects:\n";
	Cd *pcd = &c1;
	pcd->Report(); // use Cd method for cd object
	pcd = &c2;
	pcd->Report(); // use Classic method for classic object

	cout << "\nCalling a function with a Cd reference argument:\n";
	Bravo(c1);
	Bravo(c2);

	cout << "\nTesting assignment: \n";
	Classic copy;
	copy = c2;
	copy.Report();
	return 0;
}
