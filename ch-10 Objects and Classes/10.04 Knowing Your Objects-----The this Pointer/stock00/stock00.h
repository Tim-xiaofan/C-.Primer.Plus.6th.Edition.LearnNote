/*20210124 15:52,zyj,GuangDong*/

// stock00.h -- Stock class interface
// version 00
#ifndef STOCK00_H_
#define STOCK00_H_
#include <string>


class Stock // class declaration
{
	private:
		std::string company;
		long shares;
		double share_val;
		double total_val;
		/* Any function with a definition in the class declaration 
		   automatically becomes an inline function*/
		void set_tot();
	public:
		Stock(const std::string & co = "\0", long n = 0 , double pr = 0.0);
		~Stock(void);
		void acquire(const std::string & co, long n, double pr);
		void buy(long num, double price);
		void sell(long num, double price);
		void update(double price);
		void show (void) const;
		const Stock &topval(const Stock &s)const;
}; // note semicolon at the end

inline void Stock::set_tot(void)
{
	total_val = share_val * shares;
}
#endif
