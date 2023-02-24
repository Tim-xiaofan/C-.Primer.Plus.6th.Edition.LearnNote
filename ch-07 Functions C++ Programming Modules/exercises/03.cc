#include <iostream>

using std::cout;
using std::endl;
using std::cin;

struct box
{
	char maker[40];
	float height;
	float width;
	float length;
	float volume;
};

static void print(struct box b)
{
	cout << "maker: " << b.maker << endl;
	cout << "height: " << b.height << endl;
	cout << "width: " << b.width << endl;
	cout << "length: " << b.length << endl;
	cout << "volume: " << b.volume << endl;
}

static void caculate_volume(struct box* b)
{
	b->volume = b->height * b->width * b->length;
}

int main(void)
{
	struct box b = {"YiWu", 75, 60, 80, 0};
	caculate_volume(&b);
	print(b);
	return 0;
}
