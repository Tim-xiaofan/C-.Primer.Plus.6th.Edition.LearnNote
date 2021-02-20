/** 20210220 17:17, zyj, GungDong*/
// frnd2tmp.cpp -- template class with non-template friends
#include <iostream>
#include <typeinfo>
#include <string>
using std::cout;
using std::endl;
using std::string;

static std::string getTypeName(const std::type_info & id);

template <typename T>
class HasFriend
{
	private:
		T item;
		static int ct;
	public:
		HasFriend(const T & i) : item(i) {ct++;}
		~HasFriend() {ct--; }
		friend void counts();
		friend void reports(HasFriend<T> & hf) // template parameter
		{
			cout << " HasFriend<" << getTypeName(typeid(T)) 
				<< ">: " << hf.item << endl;
		}
};

// each specialization has its own static data member
template <typename T>
int HasFriend<T>::ct = 0;

// non-template friend to all HasFriend<T> classes
void counts()
{
	cout << "int count: " << HasFriend<int>::ct << "; ";
	cout << "double count: " << HasFriend<double>::ct << endl;
}

// non-template friend to the HasFriend<int> class
//void reports(HasFriend<int> & hf)
//{
//	cout <<"HasFriend<int>: " << hf.item << endl;
//}
//
//// non-template friend to the HasFriend<double> class
//void reports(HasFriend<double> & hf)
//{
//	cout <<"HasFriend<double>: " << hf.item << endl;
//}

int main()
{
	cout << "No objects declared: ";
	counts();
	HasFriend<int> hfi1(10);
	cout << "After hfi1 declared: ";
	counts();
	HasFriend<int> hfi2(20);
	cout << "After hfi2 declared: ";
	counts();
	HasFriend<double> hfdb(10.5);
	cout << "After hfdb declared: ";
	counts();
	HasFriend<string> hfs("string");
	cout << "After hfs declared: ";
	reports(hfi1);
	reports(hfi2);
	reports(hfdb);
	reports(hfs);
	return 0;
}

static std::string getTypeName(const std::type_info & id)
{
	if (id == typeid(int)) return "int";
	if (id == typeid(double)) return "double";
	if (id == typeid(std::string)) return "string";
	return "unknow type";
}
