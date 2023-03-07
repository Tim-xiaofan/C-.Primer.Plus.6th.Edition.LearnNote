/** 20200214 15:29, zyj, GuangDong, 20230307 15:48*/
// Base Class Using DMA
#ifndef DMA_H_
#define DMA_H_
#include <iostream>

// Abstract Base Class

class abcDMA
{
	public:
		abcDMA(){}
		virtual ~abcDMA() {}
		virtual void type(void) const = 0;
		virtual void view(void) const = 0;
};

// Base Class Using DMA: Doesn’t Use new
class baseDMA : public abcDMA
{
	public:
		baseDMA(const char* l = "null", int r = 0);
		baseDMA(const baseDMA& rs);
		baseDMA& operator=(const baseDMA& rs);
		~baseDMA();
		void type(void) const override { std::cout << "class baseDMA\n"; };
		void view(void) const override { std::cout << *this << std::endl; }
		friend std::ostream& operator<<(std::ostream& os,
					const baseDMA& rs);
	private:
		char* label;
		int rating;
};

// derived class with DMA : uses new
class hasDMA : public baseDMA
{
	private:
		char* style;
	public:
		hasDMA(const char* s = "none", const char* l = "null",
					int r = 0);
		hasDMA(const hasDMA& hs);
		~hasDMA();
		virtual void type(void) const override{ std::cout << "class hasDMA\n"; };
		void view(void) const override{ std::cout << *this << std::endl; }
		hasDMA & operator=(const hasDMA& rs);
		friend std::ostream& operator<<(std::ostream& os,
					const hasDMA& rs);
};

// derived class without DMA: Doesn’t Use new
class lacksDMA : public baseDMA
{
	public:
		lacksDMA(const char* c = "red", const char* l = "null", int r = 0);
		virtual void type(void) const override{ std::cout << "class lacksDMA\n"; };
		void view(void) const override { std::cout  << *this << std::endl; }
		friend std::ostream& operator<<(std::ostream& os,
					const lacksDMA& lk);
	private:
		char color[40];
};

#endif //!!!
