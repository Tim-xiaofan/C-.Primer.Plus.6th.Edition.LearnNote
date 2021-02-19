/** 20210216 23:42, zyj, GuangDong */
//three_friends.cpp -- three categories friends
#include <iostream>

template <class T>
class HasFriend
{
	public:
		/** friend to all HasFriend instantiations */
		friend void counts(); 
};

void counts()
{
	std::cout << "counts : friends to all instantiations\n";
}

int main()
{
	HasFriend<string> hfs;
	return 0;
}
