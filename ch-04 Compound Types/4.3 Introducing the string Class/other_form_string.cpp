/*20201217 22:55,zyj,GUANG DONG*/
// other_form_string.cpp

#include <iostream>
#include <string> // make string class available
#include <cstring> // C-style string library
int main()
{
	using namespace std;
	wchar_t title[] = L"Chief Astrogator"; // w_char string
	char16_t name[] = u"Felonia Ripova"; // char_16 string
	char32_t car[] = U"Humber Super Snipe"; // char_32 string
	cout << "sizeof(wchar_t):" << sizeof(wchar_t) << "	sizeof(title):" << sizeof(title)<< endl;
	cout << "sizeof(char16_t):" << sizeof(char16_t) << "	sizeof(name):" << sizeof(name)<< endl;
	cout << "sizeof(char32_t):" << sizeof(char32_t) << "	sizeof(car):" << sizeof(car)<< endl;
}

