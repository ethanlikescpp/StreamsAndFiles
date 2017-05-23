// StreamsAndFiles.cpp : Defines the entry point for the console application.
// Code for Module 4 of the EdX Intermediate C++ course

#include "stdafx.h"
#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>

using namespace std;

class Point {
public:
	int x, y;
};

double pi = 3.141592656;

void basicio();
void stringio();
void manipulators();
void filestreams();

/*
istream & operator >> (istream & is, Point &p) {
	is >> p.x >> p.y;
	return is;
}
*/

int main() {
	
	filestreams();

    return 0;
}

void filestreams() {
	fstream iofile1("file1.txt", ios_base::binary);

	//ofile.open("file1.txt");
	if (iofile1.is_open()) {
		cout << "file1 is open" << endl;
	}
	else {
		cout << "file1 not open" << endl;
	}

	iofile1.close();
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



