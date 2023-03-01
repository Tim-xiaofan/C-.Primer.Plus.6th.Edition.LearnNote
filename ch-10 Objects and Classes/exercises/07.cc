#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

inline size_t min(size_t a, size_t b)
{
	return (a > b) ? b : a;
}

class plorg
{
	public:
		plorg()
			:name_("Plorga")
		{}
		plorg(const string& name, int ci)
			:name_(name.data(), min(name.size(), NAME_LIMIT)),
			ci_(ci)
		{}
		void ci(int ci) { ci_ = ci; }
		void show(void) const
		{
			cout << "{" << name_ << ", " << ci_ << "}\n";
		}
	private:
		static const int NAME_LIMIT = 19;
		string name_;
		int ci_;
};

int main(void)
{
	plorg p1("p1", 50);
	p1.show();
	p1.ci(60);
	p1.show();

	plorg p2;
	p2.show();
	return 0;
}
