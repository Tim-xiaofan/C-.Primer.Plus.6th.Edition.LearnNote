/** 20210215 22:29, zyj, GuangDong*/
#include "studentc.h"

/** private methods*/
std::ostream & Student::arr_out(std::ostream & os) const
{
	int i;
	int lim = scores.size();
	if (lim > 0)
	{
		for (i = 0; i < lim; i++)
		{
			os << scores[i];
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
	if (scores.size() > 0)
	  return scores.sum()/scores.size();
	else
	  return 0;
}

const std::string & Student::Name() const
{
	return name;
}

double & Student::operator[](int i)
{
	return scores[i];
}

double Student::operator[](int i) const
{
	return scores[i];
}

/** friend methods*/
// input
std::istream & operator>>(std::istream & is,
			Student & stu) // 1 word
{
	is >> stu.name;
	return is;
}

std::istream & getline(std::istream & is,
			Student & stu) // 1 line
{
	getline(is, stu.name);
	return is;
}

// output
std::ostream & operator<<(std::ostream & os,
			const Student & stu)
{
	os << "Scores for " << stu.name << ":\n";
	stu.arr_out(os);
	return os;
}
