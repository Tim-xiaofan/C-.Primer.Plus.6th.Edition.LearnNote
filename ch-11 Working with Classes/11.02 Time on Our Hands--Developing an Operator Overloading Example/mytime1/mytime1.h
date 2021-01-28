/*20210127 22:20,zyj,GuangDong*/
// mytime1.h -- Time class before operator overloading
#ifndef MYTIME0_H_
#define MYTIME0_H_
#define FRIEND 1
class Time
{
	private:
		int hours;
		int minutes;
	public:
		Time();
		Time(int h, int m = 0);
		void AddMin(int m);
		void AddHr(int h);
		void Reset(int h = 0, int m = 0);
		Time operator+(const Time & t) const;
		Time operator-(const Time & t) const;
		Time operator*(double mult) const;
		bool operator>(const Time & t) const;
		bool operator=(const Time & t) const;
		bool operator<(const Time & t) const;
		bool operator>=(const Time & t) const;
		bool operator<=(const Time & t) const;
		void Show() const;
#ifdef FRIEND
		friend Time operator*(double mult, const Time &t);
		friend std::ostream & operator<<(std::ostream &os, const Time &t);
#endif
};


#endif
