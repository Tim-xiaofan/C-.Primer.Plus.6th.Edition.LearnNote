//20230308 11:22, zyj, GunagDong
// type_traits的基本理解：特化和偏特化
#include <iostream>

using std::endl;
using std::cout;

template<typename T>
struct is_void
{
	static const bool value = false;
	constexpr operator bool()
	{ return value; }
};

template<>
struct is_void<void> // 特化
{
	static const bool value = true;
	constexpr operator bool()
	{ return value; }
};

template<typename T>
struct is_pointer
{
	static const bool value = false;
};

template<typename T>
struct is_pointer<T*>
{
	static const bool value = true;
};

template<typename T>
struct is_reference
{
	static const bool value = false;
};

template<typename T>
struct is_reference<T&>
{
	static const bool value = true;
};

template<typename T>
struct is_array
{
	static const bool value = false;
};

template<typename T>
struct is_array<T[]>
{
	static const bool value = true;
};

template<typename T, typename U>
struct is_same
{
	static const bool value = false;
};

template<typename T>
struct is_same<T, T>
{
	static const bool value = true;
};


static_assert(is_void<int>::value == false);
static_assert(is_void<void>::value == true);
static_assert(is_void<int>() == false);
static_assert(is_void<void>() == true);

static_assert(is_pointer<int>::value == false);
static_assert(is_pointer<int*>::value == true);
static_assert(is_pointer<const int*>::value == true);
static_assert(is_pointer<int>::value == false);

static_assert(is_reference<int>::value == false);
static_assert(is_reference<int&>::value == true);
static_assert(is_reference<const int&>::value == true);

static_assert(is_array<int[]>::value == true);
static_assert(is_array<const int[]>::value == true);
static_assert(is_array<int*>::value == false);

static_assert(is_same<int, int>::value == true);
static_assert(is_same<int, long>::value == false);
static_assert(is_same<int, int&>::value == false);
static_assert(is_same<int, int*>::value == false);
static_assert(is_same<int, const int>::value == false);
static_assert(is_same<int[], int*>::value == false);

int main(void)
{
	{
		cout << "is_void\n";
		cout << "int: " << std::boolalpha << is_void<int>::value << endl;
		cout << "void: " << std::boolalpha << is_void<void>::value << endl;
	}

	{
		cout << "\nis_pointer:\n";
		cout << "int: " << std::boolalpha << is_pointer<int>::value << endl;
		cout << "int*: " << std::boolalpha << is_pointer<int*>::value << endl;
		cout << "const int*: " << std::boolalpha << is_pointer<const int*>::value << endl;
		cout << "int[]: " << std::boolalpha << is_pointer<int[]>::value << endl;
	}

	{
		cout << "\nis_reference:\n";
		cout << "int: " << std::boolalpha << is_reference<int>::value << endl;
		cout << "int&: " << std::boolalpha << is_reference<int&>::value << endl;
		cout << "const int&: " << std::boolalpha << is_reference<const int&>::value << endl;
	}

	{
		cout << "\nis_array:\n";
		cout << "int[]: " << std::boolalpha << is_array<int[]>::value << endl;
		cout << "const int[]: " << std::boolalpha << is_array<const int[]>::value << endl;
		int a[10];
		int* pa = a;
		cout << "pointer to array: " << std::boolalpha << is_array<decltype(pa)>::value << endl;
	}

	{
		cout << "\nis_same:\n";
		cout << "int vs int: " << std::boolalpha << is_same<int, int>::value << endl;
		cout << "int vs long: " << std::boolalpha << is_same<int, long>::value << endl;
		cout << "int vs int&: " << std::boolalpha << is_same<int, int&>::value << endl;
		cout << "int vs int*: " << std::boolalpha << is_same<int, int*>::value << endl;
		cout << "int vs const int: " << std::boolalpha << is_same<int, const int>::value << endl;
		cout << "int[] vs int*: " << std::boolalpha << is_same<int[], int*>::value << endl;
	}

	return 0;
}
