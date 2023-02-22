#include <string>
#include <iostream>

using std::cout;
using std::cin;
using std::endl;
using std::string;

struct pizza
{
	string company_name;
	float diameter;
	float weight;
};

int main(void)
{
	struct pizza* pz = new struct pizza;

	cout << "Enter diameter of pizza: ";
	cin >> pz->diameter;
	cin.get();
	
	cout << "Enter name of pizza company: ";
	getline(cin, pz->company_name);

	cout << "Enter weight of pizza: ";
	cin >> pz->weight;

	cout << pz->company_name << ", "
		<< pz->diameter << ", "
		<< pz->weight << endl;

	delete pz;
	return 0;
}
