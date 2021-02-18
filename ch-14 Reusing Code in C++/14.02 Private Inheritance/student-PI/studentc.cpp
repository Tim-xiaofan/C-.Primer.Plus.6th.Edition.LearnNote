/** 20210215 22:29, zyj, GuangDong*/
#include "studentc.h"

/** private methods*/
std::ostream & Student::arr_out(std::ostream & os) const
{
	int i;
	int lim = ArrayDb::size();
	if (lim > 0)
	{
		for (i = 0; i < lim; i++)
		{
			os << ArrayDb::operator[](i);
			if (i % 5 == 4)
			  os << std::endl;
			else
			  os << " ";
		}
		if (i % 5 != 0)
		  os << std::endl;
	}
	else
	  os << " empty array ";
	return os;
}

/** public methods*/
double Student::Average() const
{
	if (ArrayDb::size() > 0)
	  return ArrayDb::sum()/ArrayDb::size();
	else
	  return 0;
}

const std::string & Student::Name() const
{
	return (const std::string &) (*this);
}

void Student::Name(const std::string & mname)
{
	(std::string &) (*this) = mname;
}

const std::valarray<double> & Student::Scores() const
{
	return (const ArrayDb &) (*this);
}

double Student::Sum() const
{
	return std::valarray<double>::sum();
}

double & Student::operator[](int i)
{
	return ArrayDb::operator[](i);
}

double Student::operator[](int i) const
{
	return ArrayDb::operator[](i);
}

/** friend methods*/
// input
std::istream & operator>>(std::istream & is,
			Student & stu) // 1 word
{
	is >> (std::string &) stu;
	return is;
}

std::istream & getline(std::istream & is,
			Student & stu) // 1 line
{
	getline(is, (std::string &) stu);
	return is;
}

// output
std::ostream & operator<<(std::ostream & os,
			const Student & stu)
{
	os << "Scores for " << (const std::string &) stu << ":\n";
	stu.arr_out(os);
	return os;
}
