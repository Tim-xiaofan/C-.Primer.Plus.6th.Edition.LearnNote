//20230309 14:14, zyj, GuangDong
#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <vector>

using std::cout;
using std::endl;
using std::string;
using std::cin;

class abstr_emp
{
	private:
		std::string fname; // abstr_emp's first name
		std::string lname; // abstr_emp's last name
		std::string job;
	public:
		abstr_emp();
		abstr_emp(const std::string & fn, const std::string & ln,
					const std::string & j);
		virtual void ShowAll() const; // labels and shows all data
		virtual void SetAll(); // prompts user for values
		// just displays first and last name
		friend std::ostream &
			operator<<(std::ostream & os, const abstr_emp & e);
		virtual ~abstr_emp() = 0; // virtual base class
};

abstr_emp::~abstr_emp()
{}

abstr_emp::abstr_emp()
		:abstr_emp("abstr_emp", "abstr_emp", "abstr_emp")
{}

abstr_emp::abstr_emp(const std::string & fn,
			const std::string & ln,
			const std::string & j)
		:fname(fn),
		lname(ln),
		job(j)
{}

void abstr_emp::ShowAll() const
{
	cout << "First name: " << fname << endl;
	cout << "Last name: " << lname << endl;
	cout << "Job: " << job << endl;
}

void abstr_emp::SetAll()
{
	cout << "Enter first name: ";
	getline(cin, fname); 
	cout << "Enter last name: ";
	getline(cin, lname);
	cout << "Enter job: ";
	getline(cin, job);
}

std::ostream& operator<<(std::ostream& os, const abstr_emp& e)
{
	os << e.fname << " " << e.lname;
	return os;
}

class employee : public abstr_emp
{
	public:
		employee();
		employee(const std::string & fn, const std::string & ln,
					const std::string & j);
		~employee() {}
		//virtual void ShowAll() const override;
		//virtual void SetAll() override;
};

employee::employee()
		:employee("employee", "employee", "employee")
{}

employee::employee(const std::string & fn,
			const std::string & ln,
			const std::string & j)
		:abstr_emp(fn, ln, j)
{}

class manager: virtual public abstr_emp
{
	public:
		manager();
		manager(const std::string & fn, const std::string & ln,
					const std::string & j, int ico = 0);
		manager(const abstr_emp & e, int ico);
		manager(const manager & m);
		virtual ~manager() {}
		virtual void ShowAll() const override;
		virtual void SetAll() override;
	protected:
		int InChargeOf() const { return inchargeof; } // output
		int & InChargeOf(){ return inchargeof; } // input
	private:
		int inchargeof; // number of abstr_emps managed
};

manager::manager()
		:manager("manager","manager", "manager", 0)
{}

manager::manager(const std::string & fn, const std::string & ln,
					const std::string & j, int ico)
		:abstr_emp(fn, ln, j),
		inchargeof(ico)
{
}
manager::manager(const abstr_emp & e, int ico)
		:abstr_emp(e),
		inchargeof(ico)
{}

manager::manager(const manager & m)
		:abstr_emp(m),
		inchargeof(m.inchargeof)
{
}

void manager::ShowAll() const
{
	abstr_emp::ShowAll();
	cout << "Inchargeof: " << inchargeof << endl;
}

void manager::SetAll()
{
	abstr_emp::SetAll();
	cout << "Enter inchargeof: ";
	cin >> inchargeof;
	while(cin.get() != '\n');
}

class fink: virtual public abstr_emp
{
	public:
		fink();
		fink(const std::string & fn, const std::string & ln,
					const std::string & j, const std::string & rpo);
		fink(const abstr_emp & e, const std::string & rpo);
		fink(const fink & e);
		virtual ~fink() {}
		virtual void ShowAll() const override;
		virtual void SetAll() override;
	private:
		std::string reportsto; // to whom fink reports
	protected:
		const std::string ReportsTo() const { return reportsto; }
		std::string & ReportsTo(){ return reportsto; }
};


fink::fink()
		:fink("fink", "fink", "fink", "fink")
{}

fink::fink(const std::string& fn,
			const std::string& ln,
			const std::string& j,
			const std::string& rpo)
		:abstr_emp(fn, ln, j),
		reportsto(rpo)
{}

fink::fink(const abstr_emp & e, const std::string & rpo)
		:abstr_emp(e),
		reportsto(rpo)
{}

fink::fink(const fink & e)
		:abstr_emp(e),
		reportsto(e.reportsto)
{}

void fink::ShowAll() const
{
	abstr_emp::ShowAll();
	cout << "Reportsto: " << reportsto << endl;
}

void fink::SetAll()
{
	abstr_emp::SetAll();
	cout << "Enter reportsto: ";
	getline(cin, reportsto);
}

class highfink: public manager, public fink // management fink
{
	public:
		highfink();
		highfink(const std::string & fn, const std::string & ln,
					const std::string & j, const std::string & rpo,
					int ico);
		highfink(const abstr_emp & e, const std::string & rpo, int ico);
		highfink(const fink & f, int ico);
		highfink(const manager & m, const std::string & rpo);
		highfink(const highfink & h);
		~highfink() {}
		virtual void ShowAll() const override;
		virtual void SetAll() override;
};

highfink::highfink()
		:highfink("highfink", "highfink", "highfink", "highfink", 0)
{}

highfink::highfink(const std::string & fn,
			const std::string & ln,
			const std::string & j,
			const std::string & rpo,
			int ico)
		:abstr_emp(fn, ln, j),
		manager(fn, ln, j, ico),
		fink(fn, ln, j, rpo)
{}

highfink::highfink(const abstr_emp & e, const std::string & rpo, int ico)
		:abstr_emp(e),
		manager(e, ico),
		fink(e, rpo)
{}


highfink::highfink(const fink & f, int ico)
		:abstr_emp(f),
		manager(static_cast<const abstr_emp&>(f), ico),
		fink(f)
{}

highfink::highfink(const manager & m, const std::string & rpo)
		:abstr_emp(m),
		manager(m),
		fink(static_cast<const abstr_emp&>(m), rpo)
{
}

highfink::highfink(const highfink& h)
		:abstr_emp(h),
		manager(h),
		fink(h)
{
}

void highfink::ShowAll() const
{
	abstr_emp::ShowAll();
	cout << "Inchargeof: " << manager::InChargeOf() << endl;
	cout << "Reportsto: " << fink::ReportsTo() << endl;
}

void highfink::SetAll()
{
	abstr_emp::SetAll();
	cout << "Inchargeof: ";
	cin >> manager::InChargeOf();
	while(cin.get() != '\n');
	cout << "Reportsto: ";
	getline(cin, fink::ReportsTo());
}

int main(void)
{
	employee em("Trip", "Harris", "Thumper");
	cout << em << endl;
	em.ShowAll();
	cout << endl;
	employee em1;
	em1 = em;

	manager ma("Amorphia", "Spindragon", "Nuancer", 5);
	cout << ma << endl;
	ma.ShowAll();
	manager ma1;
	ma1 = ma;

	fink fi("Matt", "Oggs", "Oiler", "Juno Barr");
	cout << fi << endl;
	fi.ShowAll();
	highfink hf(ma, "Curly Kew"); // recruitment?
	hf.ShowAll();
	cout << endl;

	cout << "Press a key for next phase:\n";
	cin.get();
	highfink hf2;
	hf2.SetAll();
	cout << endl;
	cout << "Using an abstr_emp * pointer:\n";
	abstr_emp * tri[4] = {&em, &fi, &hf, &hf2};
	for (int i = 0; i < 4; i++)
	{
		tri[i]->ShowAll();
		cout << endl;
	}
	return 0;
}
