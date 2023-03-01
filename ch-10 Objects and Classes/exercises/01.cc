#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

class bank_account
{
	public:
		bank_account(const string& name, const string& number, double balance)
			:name_(name),
			number_(number),
			balance_(balance)
	{}
		const string& name(void) const 
		{ return name_; }
		const string& number(void) const
		{ return number_; }
		const double balance(void) const
		{ return balance_; }

		void deposit(double money)
		{ balance_ += money; }

		bool withdraw(double money)
		{
			if(money <= balance_)
			{
				balance_-= money;
				return true;
			}
			return false;
		}

		void show(void) const
		{
			cout << name_ << ", "
				<< number_ << ", "
				<< balance_ << endl;
		}
	private:
		string name_;
		string number_;
		double balance_;
};

int main(void)
{
	bank_account ba("Tom", "11453", 5000.0);
	cout << "origin: ";
	ba.show();
	cout << "after depositing 1000: ";
	ba.deposit(1000);
	ba.show();
	cout << "after withdraw 6500: ";
	ba.withdraw(6500);
	ba.show();
	cout << "after withdraw 400: ";
	ba.withdraw(400);
	ba.show();
	cout << "Bye.\n";
	return 0;
}
