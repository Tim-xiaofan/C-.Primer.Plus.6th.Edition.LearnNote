/** 20200214 15:29, zyj, GuangDong*/
// Base Class Using DMA
#ifndef DMA_H_
#define DMA_H_
#include <iostream>
// Base Class Using DMA
class baseDMA
{
	private:
		char * label;
		int rating;
	public:
		baseDMA(const char * l = "null", int r = 0);
		baseDMA(const baseDMA & rs);
		virtual ~baseDMA();
		virtual void type(void) { std::cout << "class baseDMA\n"; };
		baseDMA & operator=(const baseDMA & rs);
		friend std::ostream & operator<<(std::ostream & os,
					const baseDMA & rs);
};

// derived class with DMA
class hasDMA :public baseDMA
{
	private:
		char * style;
	public:
		hasDMA(const char * s = "none", const char * l = "null",
					int r = 0);
		hasDMA(const char * s, const baseDMA & rs);
		hasDMA(const hasDMA & hs);
		~hasDMA();
		hasDMA & operator=(const hasDMA & rs);
		friend std::ostream & operator<<(std::ostream & os,
					const hasDMA & rs);
};

#endif //!!!
