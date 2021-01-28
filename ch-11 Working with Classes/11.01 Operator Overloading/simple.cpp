/*20210127 21:38,zyj,GuangDong*/
//simple.cpp ------- usage of operator overloading
#include <iostream>

class XY
{
	private:
		double x;
		double y;
	public:
		XY(double m_x = 0.0, double m_y = 0.0);
		void show(void)const;
		XY operator+(const XY &xy)const;
};

XY::XY(double m_x, double m_y)
{
	x = m_x;
	y = m_y;
}

void XY::show(void) const
{
	std::cout << "(" << x 
		<< "," << y << ")"
		<< std::endl;
}

XY XY::operator+(const XY &xy)const
{
	XY ret;
	ret.x = xy.x + x;
	ret.y = xy.y + y;
	return ret;
}

int main()
{
	using std::cout;
	using std::endl;
	XY xy1(3,4), xy2(7, 53);
	xy1.show();
	xy2.show();
	cout << "after + : \n";
	(xy1 + xy2).show();
	return 0;
}
