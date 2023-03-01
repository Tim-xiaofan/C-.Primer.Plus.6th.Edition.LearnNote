#ifndef _GOLF_H_
#define _GOLF_H_

#include <string>

class golf
{
	public:
		golf();
		golf(const std::string& name, int hc);
		void handicap(int hc) { handicap_ = hc; }
		void show(void) const;

	private:
		std::string fullname_;
		int handicap_;
};

#endif
