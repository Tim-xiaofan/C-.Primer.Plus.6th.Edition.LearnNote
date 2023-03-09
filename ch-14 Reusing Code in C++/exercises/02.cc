//20230309 09:28, zyj, GUANGDONG
#include <iostream>
#include <string>
#include <utility>
#include <valarray>
#include <numeric>

using std::cout;
using std::endl;
using std::string;
using std::cin;
using array_int = std::valarray<int>;
using pair_array = std::pair<array_int, array_int>;

class wine : private string, private pair_array
{
	public:
		wine();
		wine(const string& label, int year_nb, const int years[], const int bottles[]);
		wine(const string& label, int year_nb);
		void set_bottles(void);
		const string& label(void) const { return *this; }
		int sum(void) const;
		void show() const;
};

wine::wine()
		:wine("none", 0)
{
}

wine::wine(const string& label, int year_nb, const int years[], const int bottles[])
		:wine(label, year_nb)
{
	pair_array& years_bottles_ = *this;
	for(int i = 0; i < year_nb; ++i)
	{
		years_bottles_.first[i] = years[i];
		years_bottles_.second[i] = bottles[i];
	}
}

wine::wine(const string& label, int year_nb)
		:string(label),
		pair_array(std::move(array_int(year_nb)), std::move(array_int(year_nb)))
{
}

void wine::set_bottles(void)
{
	pair_array& years_bottles_ = *this;
	int n = years_bottles_.first.size();
	int bottles, year;
	for(int i = 0; i < n; ++i)
	{
		cout << "Enter year: ";
		cin >> year;
		cout << "Enter bottles for that year: ";
		cin >> bottles;
		years_bottles_.first[i] = year;
		years_bottles_.second[i] = bottles;
	}
}

int wine::sum(void) const
{
	const pair_array& years_bottles_ = *this;
	return std::accumulate(std::begin(years_bottles_.second),
				std::end(years_bottles_.second),
				0);
}

void wine::show() const
{
	const string& label_ = *this;
	const pair_array& years_bottles_ = *this;
	cout << "Wine: " << label_ << endl;
	cout << "Year\tBootles" << endl;
	for(size_t i = 0; i < years_bottles_.first.size(); ++i)
	{
		cout << years_bottles_.first[i] << "\t"
			<< years_bottles_.second[i] << endl;
	}
}

int main(void)
{
	cout << "Enter name of wine: ";
	char lab[50];
	cin.getline(lab, 50);
	cout << "Enter number of years: ";
	int yrs;
	cin >> yrs;
	wine holding(lab, yrs); // store label, years, give arrays yrs elements
	holding.set_bottles(); // solicit input for year, bottle count
	holding.show(); // display object contents
	const int YRS = 3;
	int y[YRS] = {1993, 1995, 1998};
	int b[YRS] = { 48, 60, 72};
	// create new object, initialize using data in arrays y and b
	wine more("Gushing Grape Red",YRS, y, b);
	more.show();
	cout << "Total bottles for " << more.label() // use Label() method
		<< ": " << more.sum() << endl; // use sum() method
	cout << "Bye\n";
	return 0;
}
