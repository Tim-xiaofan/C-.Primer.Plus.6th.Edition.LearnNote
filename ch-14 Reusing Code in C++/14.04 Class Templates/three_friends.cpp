/** 20210216 23:42, zyj, GuangDong */
//three_friends.cpp -- three categories friends
#include <iostream>

template <class T>
class HasFriend
{
	public:
		/** friend to all HasFriend instantiations */
		friend void counts();
		/** bound template friend */
		friend void report(HasFriend &)
		{
			std::cout << "report: bound template friend\n";
		}
};

int main()
{
	using std::string;
	using std::cout;
	using std::cin;
	using std::endl;

	HasFriend<string> hfs;
	report(hfs);
	return 0;
}

void counts()
{
	std::cout << "counts : friends to all instantiations\n";
}

//void report(HasFriend<std::string> & hf)
//{
//	std::cout << "report: bound template friend to string\n";
//}
