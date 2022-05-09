// hash_map_at.cpp
#include <hash_map>
#include <iostream>

int main(int ac, char *av[])
{
   using namespace std;
   using namespace __gnu_cxx;
   typedef pair <const int, int> cInt2Int;
   hash_map <int, int> hm1;

   // Insert data values
   hm1.insert ( cInt2Int ( 1, 10 ) );
   hm1.insert ( cInt2Int ( 2, 20 ) );
   hm1.insert ( cInt2Int ( 3, 30 ) );

   cout  << "The values of the mapped elements are:";
   for ( int i = 1 ; i <= (int)hm1.size() ; i++ )
      cout << " " << hm1.at(i);
   cout << "." << endl;
}
