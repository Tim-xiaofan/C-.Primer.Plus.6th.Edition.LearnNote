/** 20210220 20:53, zyj, GuangDong*/
// tv.h -- Tv and Remote classes
#ifndef TV_H_
#define TV_H_

class Remote;

class Tv
{
	public:
		friend class Remote; // Remote can access Tv private parts
		enum {Off, On};
		enum {MinVal, MaxVal = 20};
		enum {Antenna, Cable};
		enum {TV, DVD};
		Tv(int s = Off, int mc = 125) : state(s), volume(5),
		maxchannel(mc), channel(2), mode(Cable), input(TV) {}
		void onoff() {state ^= 1;}
		bool ison() const {return state == On;}
		bool volup();
		bool voldown();
		void chanup();
		void chandown();
		void set_mode() {mode = (mode == Antenna)? Cable : Antenna;}
		void set_input() {input = (input == TV)? DVD : TV;}
		void settings() const; // display all settings
		void set_remote_control(Remote& r) const;
	private:
		int state; // on or off
		int volume; // assumed to be digitized
		int maxchannel; // maximum number of channels
		int channel; // current channel setting
		int mode; // broadcast or cable
		int input; // TV or DVD
};

class Remote
{
	private:
		friend class Tv;
		int mode; // controls TV or DVD
		int control; // normal or interactive mode
		enum {NORMAL, INTERACTIVE};
	public:
		Remote(int m = Tv::TV, int c = NORMAL) : mode(m), control(c) {}
		bool volup(Tv & t) { return t.volup();}
		bool voldown(Tv & t) { return t.voldown();}
		void onoff(Tv & t) { t.onoff(); }
		void chanup(Tv & t) {t.chanup();}
		void chandown(Tv & t) {t.chandown();}
		void set_chan(Tv & t, int c) {t.channel = c;}
		void set_mode(Tv & t) {t.set_mode();}
		void set_input(Tv & t) {t.set_input();}
		void show_control(void) const;
};
#endif
