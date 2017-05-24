// StreamsAndFiles.cpp : Defines the entry point for the console application.
// Code for Module 4 of the EdX Intermediate C++ course

#include "stdafx.h"
#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>

using namespace std;

double pi = 3.141592656;

class tempStat {
public:
	double minimum, maximum;

	tempStat(double min = 0.0, double max = 0.0) :
		minimum(min), maximum(max) {}

	void write(ostream & os) {
		os.write((char*)&minimum, sizeof(double));
		os.write((char*)&maximum, sizeof(double));
	}

	void read(istream & is) {
		is.read((char*)&minimum, sizeof(double));
		is.read((char*)&maximum, sizeof(double));
	}

};

void basicio();
void stringio();
void manipulators();
void filewrite();
void fileread();
void tempwrite();
void tempread();

int main() {
	

    return 0;
}



void tempread() {
	ifstream ifile("file3.txt", ios_base::binary);
	if (ifile.is_open())
	{
		while (!ifile.eof())
		{
			tempStat ts;
			ts.read(ifile);

			if (ifile.gcount() == 0)
			{
				break;  // If no bytes read, we're done.
			}
			//cout << "Read temperature stats: " << ts << std::endl;
		}
		ifile.close();

		cout << "Finished reading binary data from file3.txt" << std::endl;
	}
	else
	{
		cerr << "Couldn't open file3.txt for reading." << std::endl;
	}
}

void tempwrite() {
	ofstream ofile("file3.txt", ios_base::binary);
	if (ofile.is_open()) {
		tempStat(-2.5, 7.5).write(ofile);
		tempStat(0, 9.9).write(ofile);
		tempStat(2.5, 11.0).write(ofile);
		tempStat(5.5, 14.5).write(ofile);
		tempStat(7.0, 17.7).write(ofile);
		tempStat(10.5, 23.7).write(ofile);
		tempStat(11.7, 29.5).write(ofile);
		tempStat(7.6, 22.9).write(ofile);
		tempStat(7.2, 21.5).write(ofile);
		tempStat(2.0, 16.0).write(ofile);
		tempStat(-4.7, 12.5).write(ofile);
		tempStat(-1.9, 8.5).write(ofile);
		cout << "Finished writing to file3.txt" << endl;
	}
	else {
		cout << "Couldn't find file3.txt" << endl;
	}
	ofile.close();
}



void fileread() {
	ifstream ifile("file2.txt");
	string line;

	if (ifile.is_open()) {
		cout << "File is open! Now reading!" << endl;
		while (getline(ifile, line)) {
			cout << line << endl;
		}
	}
	else {
		cout << "Unable to read file" << endl;
		return;
	}

	

	ifile.close();
}


void filewrite() {
	fstream iofile1("file1.txt");

	//ofile.open("file1.txt");
	if (iofile1.is_open()) {
		cout << "file1 is open" << endl;
		
	}
	else {
		cout << "file1 not open" << endl;
		return;
	}
	iofile1 << "Here is a line" << "\t" << 245 << " " << 1.67 << endl;
	
	cout << "Finished writing to file" << endl;

	iofile1.close();
	cout << "File is closed" << endl;
}



void manipulators() {
	string something = "Hello";

	cout << "[" << setw(5) << something << "]" << endl;
	cout << internal << setw(10) << -123.45 << endl;

	cout << "Value of pi general format: " << pi << endl;
	cout << fixed << "Value of pi fixed format: " << pi << endl;
	cout << scientific << "Value of pi scientific format: " << pi << endl;

}

void stringio() {
	string name;
	cout << "Full name: ";
	//cin >> name; 
	getline(cin, name); // Can take in more than just a word
	cout << "Name: " << name << endl;
}

void basicio() {
	double unitPrice;
	int quantity;

	cout << "What is the unit price? $";
	cin >> unitPrice;

	cout << endl << "How many do you want? ";
	cin >> quantity;

	cout << endl << "Total cost is: $" << unitPrice * quantity << endl;
}
