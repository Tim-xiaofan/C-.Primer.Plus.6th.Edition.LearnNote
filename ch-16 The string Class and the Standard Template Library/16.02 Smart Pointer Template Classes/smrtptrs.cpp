/* 20210304 22:29, zyj, GuangDong*/
// requires support of C++11 shared_ptr and unique_ptr
#include <iostream>
#include <string>
#include <memory>
class Report
{
	private:
		std::string str;
	public:
		Report(const std::string s) : str(s)
	{ std::cout << "Object created!\n"; }
		~Report() { std::cout << "Object deleted!\n"; }
		void comment() const { std::cout << str << "\n"; }
};

std::auto_ptr<int> test(void)
{
	std::auto_ptr<int> pi (new int);
	*pi = 15;
	return pi;
}

int main()
{
	{
		std::auto_ptr<Report> ps (new Report("using auto_ptr"));
		ps->comment(); // use -> to invoke a member function
	}

	{
		std::shared_ptr<Report> ps (new Report("using shared_ptr"));
		ps->comment();
	}

	{
		std::unique_ptr<Report> ps (new Report("using unique_ptr"));
		ps->comment();
	}

	return 0;
}
