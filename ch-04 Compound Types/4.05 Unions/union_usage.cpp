/*20201219 14:34,zyj,GuangDong*/
// union_usage.capp
#include <iostream>
#include <cstring>
using namespace std;

struct widget
{
	char brand[20];
	int type;
	union id // format depends on widget type
	{
		long id_num; // type 1 widgets
		char id_char[20]; // other widgets
	} id_val;
};
union one4all
{
	int int_val;
	long long_val;
	double double_val;
};

void log_widget(const struct widget *wg)
{
	cout << "brand:"<< wg->brand << endl;
	cout << "type:"<< wg->type << endl;
	if(wg->type == 1) cout << "id:" << wg->id_val.id_num << endl;
	else cout << "id:" << wg->id_val.id_char << endl;
}

int main(int argc, char* argv[])
{
	/*declare and initiate*/
	cout << "sizeof(union one4all) = " << sizeof(union one4all) << endl;
	one4all pail;
	pail.int_val = 15; // store an int
	cout << pail.int_val << endl;
	pail.double_val = 1.38; // store a double, int value is lost
	cout << pail.double_val << endl;
	struct widget wg1 = {"Huawei", 1, 0};
	//struct widget wg2 = {"OPPO", 2, "vivo"};/*error: invalid conversion from ‘const char*’ to ‘long int’*/
	//struct widget wg2 = {/*指定初始化(Designated Initializer)*/
	//	.brand = "OPPO",/*error: C99 designator ‘brand’ outside aggregate initializer*/ 
	//	.type = 2
	//};
	struct widget wg2 = {/*指定初始化(Designated Initializer)*/
		.brand = {'O','P','P','O'}, 
		.type = 2
	};
	memcpy(wg2.id_val.id_char, "VIVO", 20);
	log_widget(&wg1);
	log_widget(&wg2);
	return 0;
}
/*
output:
 sizeof(union one4all) = 8
 15
 1.38
 brand:Huawei
 type:1
 id:0
 brand:OPPO
 type:2
 id:VIVO
 */
