// StreamsAndFiles.cpp : Defines the entry point for the console application.
// Code for Module 4 of the EdX Intermediate C++ course

#include "stdafx.h"
#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <sstream>

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
void somestrings();
void setgetstrings();
void createstream();
void extractstream();
void readwriteonly();
void widthchars();

/*
int main() {
	widthchars();

    return 0;
}
*/

void widthchars() {
	wstringstream stream;

	stream << "Jane" << " " << 42 << " " << 15000 << endl;
	wstring formattedString = stream.str();

	wstring name;
	int age;
	double salary;
	stream >> name >> age >> salary;

	wcout << "Name: " << endl;
	wcout << "Age: " << age << endl;
	wcout << "Salary: " << salary << endl;

}

void readwriteonly() {
	ostringstream stream1; // Write only
	stream1 << "Jane " << 42 << " " << 15000 << endl;

	istringstream stream2(stream1.str()); // Read only

	string name;
	int age;
	double salary;
	stream2 >> name >> age >> salary;

	cout << "Name: " << name << endl;
	cout << "Age: " << age << endl;
	cout << "Salary: $" << salary << endl;
}

void extractstream() {
	string str = "Jane 42 15000";
	stringstream stream(str);

	string name;
	int age;
	double salary;
	stream >> name >> age >> salary;

	cout << "Name: " << name << endl;
	cout << "Age: " << age << endl;
	cout << "Salary: " << salary << endl;
}

void createstream() {
	string str = "**********************";
	stringstream stream(str);

	stream << "Jane" << " " << 42 << " " << 15000;
	cout << stream.str() << endl;

}

void setgetstrings() {
	stringstream stream;

	stream.str("Jane 42 15000");

	cout << "Contents of the stream: " << stream.str() << endl;

	string name;
	int age;
	double salary;
	stream >> name >> age >> salary;

	cout << "Name: " << name << endl;
	cout << "Age: " << age << endl;
	cout << "Salary: " << salary << endl;
	
}

void somestrings() {
	stringstream stream;
	string name;
	int age;
	double salary;

	stream << "Jane " << 42 << " " << 150000 << endl;

	stream >> name >> age >> salary;

	cout << "Name: " << name << endl;
	cout << "Age: " << age << endl;
	cout << "Salary: " << salary << endl;
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
