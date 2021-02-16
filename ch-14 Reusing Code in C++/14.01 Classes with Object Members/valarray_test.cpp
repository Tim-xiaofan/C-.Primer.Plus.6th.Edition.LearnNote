/** 20210215 16:44, zyj, GuangDong*/
#include <iostream>
#include <valarray>

template<typename T>
static void valarray_list(const T & t, const char * info = "valarray : ")
{
	using std::endl;
	using std::cout;
	int i, size = t.size();
	cout << info;
	for(i = 0; i < size; i++)
	  cout << t[i] << " ";
	cout << endl;
}

template<typename T>
static void array_list(const T & t, int size, const char * info = "array : ")
{
	using std::endl;
	using std::cout;
	int i;
	cout << info;
	for(i = 0; i < size; i++)
	  cout << t[i] << " ";
	cout << endl;
}

int main()
{
	using std::endl;
	using std::cout;
	using std::valarray;
	valarray<int> q_values; // an array of int
	valarray<double> weights; // an array of double

	cout << q_values.size() << endl;
	double gpa[5] = {3.1, 3.5, 3.8, 2.9, 3.3};
	array_list(gpa, 5, "gpa : ");
	valarray<double> v1; // an array of double, size 0
	valarray_list(v1, "v1 : ");

	valarray<int> v2(8); // an array of 8 int elements
	valarray_list(v2, "v2 : ");
	
	/** an array of 8 int elements, 
	  each set to 10 */
	valarray<int> v3(10, 8); // 
	valarray_list(v3, "v3 : ");
	
	/** an array of 4 elements, initialized by an array 
	  initialized to the first 4 elements of gpa 
	 */
	valarray<double> v4(gpa, 4);
	valarray_list(v4, "v4 : ");
	cout << "max = " << v4.max() 
		<< ", min = " << v4.min() << endl;

	std::string strs[5] = {"stringa", 
		"stringb", "stringc", 
		"stringd", "stringe"};
	valarray<std::string> v5(strs, 5);
	valarray_list(v5, "v5 : ");
	cout << "max = " << v5.max() 
		<< ", min = " << v5.min() << endl;
}
