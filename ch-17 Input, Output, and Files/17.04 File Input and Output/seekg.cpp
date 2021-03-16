/* 20210316 21:07, zyj, GuangDong*/
// seekg.cpp -- usage of seekg member function
#include <iostream> // not required by most systems
#include <fstream>
#include <iomanip>
#include <cstdlib> // for exit()

inline void eatline() { while (std::cin.get() != '\n') continue; }
struct planet
{
	char name[20]; // name of planet
	double population; // its population
	double g; // its acceleration of gravity
};

const char * file = "planets.dat";

int main()
{
	using namespace std;
	planet pl;
	cout << fixed << right;

	fstream finout; // read and write streams
	finout.open(file,ios::in | ios::out |ios::binary);
	//NOTE: Some Unix systems require omitting | ios::binary
	int ct = 0;
	if (finout.is_open())
	{
		finout.seekg(0); // go to beginning
		cout << "Here are the current contents of the "
			<< file << " file:\n";
		while (finout.read((char *) &pl, sizeof pl))
		{
			cout << ct++ << ": " << setw(20) << pl.name << ": "
				<< setprecision(0) << setw(12) << pl.population
				<< setprecision(2) << setw(6) << pl.g << endl;
			//finout.seekg(finout.tellg() + sizeof(struct planet)); // skip a record
		}
		if (finout.eof())
		  finout.clear(); // clear eof flag
		else
		{
			cerr << "Error in reading " << file << ".\n";
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		cerr << file << " could not be opened -- bye.\n";
		exit(EXIT_FAILURE);
	}

	/** If it is not cleared, this cannot work*/
	cout << "Enter the record number you wish to change: ";
	long rec;
	cin >> rec;
	eatline(); // get rid of newline
	if (rec < 0 || rec >= ct)
	{
		cerr << "Invalid record number -- bye\n";
		exit(EXIT_FAILURE);
	}
	streampos place = rec * sizeof pl; // convert to streampos type
	finout.seekg(place); // random access

	finout.read((char *) &pl, sizeof pl);
	cout << "Your selection:\n";
	cout << rec << ": " << setw(20) << pl.name << ": "
		<< setprecision(0) << setw(12) << pl.population
		<< setprecision(2) << setw(6) << pl.g << endl;
	if (finout.eof())
	  finout.clear(); // clear eof flag

	cout << "Enter planet name: ";
	cin.get(pl.name, 20);
	eatline();
	cout << "Enter planetary population: ";
	cin >> pl.population;
	cout << "Enter planet's acceleration of gravity: ";
	cin >> pl.g;
	finout.seekp(place);/** go back*/
	finout.write((char *) &pl, sizeof(struct planet));

	if (finout.fail())
	{
		cerr << "Error on attempted write\n";
		exit(EXIT_FAILURE);
	}

	// show revised file
	ct = 0;
	finout.seekg(0); // go to beginning of file
	cout << "Here are the new contents of the " << file
		<< " file:\n";
	while (finout.read((char *) &pl, sizeof pl))
	{
		cout << ct++ << ": " << setw(20) << pl.name << ": "
			<< setprecision(0) << setw(12) << pl.population
			<< setprecision(2) << setw(6) << pl.g << endl;
	}
	finout.close();
	cout << "Done.\n";
	return 0;
}

