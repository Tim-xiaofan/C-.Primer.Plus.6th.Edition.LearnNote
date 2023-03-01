#include <iostream>

using std::cout;
using std::endl;

class move
{
	private:
		double x;
		double y;
	public:
		move(double a = 0, double b = 0); // sets x, y to a, b
		
		void show() const; // shows current x, y values
		
		// this function adds x of m to x of invoking object to get new x,
		// adds y of m to y of invoking object to get new y, creates a new
		// move object initialized to new x, y values and returns it
		move add(const move & m) const;
		void reset(double a = 0, double b = 0); // resets x,y to a, b
};

move::move(double a, double b)
		:x(a),
		y(b)
{}

void move::show(void) const
{
	cout << "<" << x << ", " << y << ">\n";
}

move move::add(const move& m) const
{
	return move(x + m.x, y + m.y);
}

void move::reset(double a, double b)
{
	x = a;
	y = b;
}

int main(void)
{
	move m1(1, 1);
	cout << "m1: ";
	m1.show();
	move m2(2, 2);
	cout << "m2: ";
	m2.show();
	move m3 = m1.add(m2);
	cout << "m3: ";
	m3.show();
	m3.reset();
	cout << "after reseting, m3: ";
	m3.show();
	return 0;
}
