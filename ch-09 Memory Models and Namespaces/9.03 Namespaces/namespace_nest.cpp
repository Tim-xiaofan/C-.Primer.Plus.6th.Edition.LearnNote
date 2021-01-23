/*20210121 12:46,zyj,GuangDong*/
// namespace_usage.cpp
#include <iostream>

namespace elements
{
	namespace fire
	{
		int flame;
	}
	float water;
}


namespace animals
{
	unsigned int tiger;
	unsigned int cat;
	unsigned int fish;
}

namespace test
{
	int coin;
}

/**Also you can use using directives and using declarations inside namespaces, like this*/
namespace myth
{
	using namespace animals;
	using test::coin;
	using std::cout;
	using std::cin;
}

int main()
{
	using namespace elements;
	water = 2.333;
	//flame = 23.33;//error:nested one cannot access
	using namespace elements::fire;
	flame = 23.33;
	myth::cout <<"myth::cout" << std::endl;
	/**  transitive: places both the myth and the animals namespaces in scope*/
	using namespace myth;
	cout << "cout placed" << std::endl;
	tiger = 2;
	cat = 3;
}
