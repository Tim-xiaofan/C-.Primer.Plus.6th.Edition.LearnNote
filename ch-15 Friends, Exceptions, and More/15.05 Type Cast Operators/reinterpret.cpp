/* 20210301 22:03, zyj, GuangDong*/
// reinterpret_cast.cpp -- using reinterpret_cast<>
#include <iostream>
#include <cstdint>
using std::cout;
using std::endl;

union test
{
	uint16_t i;
	uint8_t c;
};

std::string testBigEndin()
{
	/**high---------------->low */
	union test test;
	test.i=0x0102;
    if(test.c== 0x01)/** 符合直觉*/
		return "BIG ENDIAN";
	return "LITTLE ENDIAN";
}

int main()
{
	struct dat {short a; short b;};
	long value = 0xA224B118;
	cout << testBigEndin() << endl;
	dat * pd = reinterpret_cast< dat *> (&value);
	cout << std::hex << value << endl;
	cout << std::hex << pd->a << endl; // display first 2 bytes of value
}
