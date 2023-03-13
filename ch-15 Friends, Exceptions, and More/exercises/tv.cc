/** 20210221 15:46, zyj, GuangDong, 20230313 10:13*/
// tv.cpp -- methods for the Tv class (Remote methods are inline)
#include <iostream>
#include "tv.h"

using std::cout;
using std::endl;

bool Tv::volup()
{
	if (volume < MaxVal)
	{
		volume++;
		return true;
	}
	else
	  return false;
}

bool Tv::voldown()
{
	if (volume > MinVal)
	{
		volume--;
		return true;
	}
	else
	  return false;
}

void Tv::chanup()
{
	if (channel < maxchannel)
	  channel++;
	else
	  channel = 1;
}

void Tv::chandown()
{
	if (channel > 1)
	  channel--;
	else
	  channel = maxchannel;
}

void Tv::settings() const
{
	cout << "TV is " << (state == Off? "Off" : "On") << endl;
	if (state == On)
	{
		cout << "Volume setting = " << volume << endl;
		cout << "Channel setting = " << channel << endl;
		cout << "Mode = "
			<< (mode == Antenna? "antenna" : "cable") << endl;
		cout << "Input = "
			<< (input == TV? "TV" : "DVD") << endl;
	} 
}

void Tv::set_remote_control(Remote& r) const
{
	if(ison())
	{
		if(r.control == Remote::NORMAL)
		{
			r.control = Remote::INTERACTIVE;
		}
		else if(r.control == Remote::INTERACTIVE)
		{
			r.control = Remote::NORMAL;
		}
	}
}

void Remote::show_control(void) const
{
	if(control == NORMAL)
	{
		cout << "control is NORMAL" << endl;
	}
	else if(control == INTERACTIVE)
	{
		cout << "control is INTERACTIVE" << endl;
	}
}
