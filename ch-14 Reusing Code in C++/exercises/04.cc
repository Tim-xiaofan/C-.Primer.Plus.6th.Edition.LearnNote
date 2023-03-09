//20230309 10:49, zyj, GUANGDONG
#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <vector>

using std::cout;
using std::endl;
using std::string;
using std::cin;

class person
{
	public:
		person(const string& first_name = "none", const string& last_name = "none");
		virtual void show() const;
		virtual ~person() = 0;
	private:
		string first_name_;
		string last_name_;
};

person::person(const string& first_name, const string& last_name)
		:first_name_(first_name),
		last_name_(last_name)
{
}

person::~person()
{
}

void person::show(void) const
{
	cout << "fullname: " << first_name_ << " " << last_name_ << endl;
}

class gunsingler: virtual public person
{
	public:
		gunsingler(const string& first_name="gunsingler",
					const string& last_name="gunsingler",
					double draw_time = -1.0);
		virtual ~gunsingler() {}
		double draw(void) const { return draw_time_;}
		virtual void show(void) const override;
	private:
		double draw_time_;
};

gunsingler::gunsingler(const string& first_name,
			const string& last_name,
			double draw_time)
		:person(first_name, last_name),
		draw_time_(draw_time)
{}

void gunsingler::show(void) const
{
	person::show();
	cout << "draw_time: " << draw_time_ << endl;
}

class card
{
	public:
		card(int numbers = 52);
		int draw() const;
	private:
		int numbers_;
};

card::card(int numbers)
		:numbers_(numbers)
{}

int card::draw() const
{
	return std::rand() % numbers_ + 1;
}

class pokerplayer: virtual public person
{
	public:
		pokerplayer(const string& first_name="pokerplayer",
					const string& last_name="pokerplayer",
					int numbers = 52);
		virtual ~pokerplayer() {}
		int draw(void) const { return card_.draw(); }
	private:
		card card_;
};

pokerplayer::pokerplayer(const string& first_name,
					const string& last_name,
					int numbers)
		:person(first_name, last_name),
		card_(numbers)
{
}

class baddude: public gunsingler, public pokerplayer
{
	public:
		baddude(const string& first_name="baddude",
					const string& last_name="baddude");
		~baddude(){}
		double gdraw(void) const
		{ return gunsingler::draw(); }
		int cdraw(void) const
		{ return pokerplayer::draw(); }
		void show() const;
};

baddude::baddude(const string& first_name, const string& last_name)
		:person(first_name, last_name),
		gunsingler(first_name, last_name, 15.0),
		pokerplayer(first_name, last_name)
{}

void baddude::show() const
{
	person::show();
	cout << "gunsingler draw: "<< gunsingler::draw() << endl;
	cout << "pokerplayer draw: " << pokerplayer::draw() << endl;
}

int main()
{
	std::srand(time(nullptr));
	std::vector<person*> people;
	gunsingler g;
	people.push_back(&g);
	pokerplayer p;
	people.push_back(&p);
	baddude b;
	people.push_back(&b);
	for(const person* p: people)
	{
		p->show();
		cout << endl;
	}
	return 0;
}
