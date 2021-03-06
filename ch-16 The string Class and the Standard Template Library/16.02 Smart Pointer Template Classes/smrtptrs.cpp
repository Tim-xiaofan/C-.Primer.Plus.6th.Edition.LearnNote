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
		Report(const std::string s) : 
			str(s){ std::cout << "Object created!\n"; }
		~Report() { std::cout << "Object deleted!\n"; }
		void comment() const { std::cout << str << "\n"; }
};

class Integer
{
	private:
	public:
		int i;
		Integer(int mi):i(mi){}
		friend std::ostream & 
		operator<<(std::ostream &os, Integer & i);
};

std::ostream & 
operator<<(std::ostream &os, Integer & i)
{
	std::cout << i.i << std::endl;
}

std::auto_ptr<Integer> 
test(void)
{
	std::auto_ptr<Integer> pi (new Integer(16));
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

	std::auto_ptr<Report> pout;
	{
		std::auto_ptr<Report> pin(new Report ("using auto_ptr in block"));
		pout = pin;
	}
	pout->comment();

	int *pi_out = NULL;
	{
		int *pi_in = new int(1);
		pi_out = pi_in;
		std::cout << "in:*pi_out = " << *pi_out << std::endl;
		delete pi_in;
	}
	std::cout << "out:*pi_out = " << *pi_out << std::endl;

	return 0;
}
