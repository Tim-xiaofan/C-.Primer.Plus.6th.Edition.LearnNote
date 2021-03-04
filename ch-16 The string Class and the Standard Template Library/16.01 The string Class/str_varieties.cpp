/* 20210304 21:26, zyj, GuangDong*/
// str_varieties.cpp

#include <iostream>
#include <string>
int main()
{
	using namespace std;
	cout << "sizeof(string) = " 
		<< sizeof(string) << endl;
	cout << "sizeof(wstring) = " 
		<< sizeof(wstring) << endl;
	cout << "sizeof(u16string) = " 
		<< sizeof(u16string) << endl;
	cout << "sizeof(u32string) = " 
		<< sizeof(u32string) << endl;
	
	cout << "sizeof(char) = " 
		<< sizeof(char) << endl;
	cout << "sizeof(wchar_t) = " 
		<< sizeof(wchar_t) << endl;
	cout << "sizeof(char16_t) = " 
		<< sizeof(char16_t) << endl;
	cout << "sizeof(char32_t) = " 
		<< sizeof(char32_t) << endl;

	//wstring wstr("123456");
}
