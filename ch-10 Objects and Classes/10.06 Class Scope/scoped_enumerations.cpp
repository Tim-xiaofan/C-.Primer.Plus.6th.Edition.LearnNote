/*20210126 21:55,zyj,GuangDong*/
/* coped_enumerations.cpp -- 
   1.enumerators conflict between two enum difinitions
   2.
 */
#include <iostream>
//#define CONFLICT 1

#ifdef CONFLICT
enum egg {Small, Medium, Large, Jumbo};
enum t_shirt {Small, Medium, Large, Xlarge};
#else
//c++ 11 avoid conflict
enum class egg {Small, Medium, Large, Jumbo};
enum class t_shirt {Small, Medium, Large, Xlarge};
#endif

int main()
{

}
