/** 20210130 17:09,zyj,GunagDong*/
// stonewt.h -- definition for the Stonewt class
#ifndef STONEWT_H_
#define STONEWT_H_

//#define EXPLICIT 1
//#define AMBIGUOUS 1
#define CONVERSION 1
class Stonewt
{
	private:
		enum {Lbs_per_stn = 14}; // pounds per stone 1石等于14磅
		int stone; // whole stones
		double pds_left; // fractional pounds
		double pounds; // entire weight in pounds
	public:
#ifdef EXPLICIT
		explicit
#endif
		Stonewt(double lbs); // constructor for double pounds
#ifdef EXPLICIT
		explicit
#endif
#ifdef AMBIGUOUS
		Stonewt(long lbs); 
#endif
		Stonewt(int stn, double lbs); // constructor for stone, lbs
		Stonewt(); // default constructor
		~Stonewt();
		void show_lbs() const; // show weight in pounds format
		void show_stn() const; // show weight in stone format
#ifdef CONVERSION
		/* conversion functions*/
		operator int() const;
		operator long() const;
		operator double() const;
#endif 
};

#endif
