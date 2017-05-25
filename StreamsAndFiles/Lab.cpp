#include "stdafx.h"
#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <sstream>

using namespace std;

int main() {
	thefunction();
	return 0;
}

void thefunction() {
	int total;
	int current;
	string name;
	string input;
	stringstream data;
	fstream iofile("donation_total.txt", ios_base::app);;
	
	if (iofile.is_open()) {
		iofile >> total;
		cout << "Current total: $" << total << endl;
		cout << "Enter name and donation: " << endl;
		getline(cin, input);
		data.str(input);
		data >> name >> current;
		total = total + current;
		iofile << total;
		iofile.close();
		//thefunction();
	}
	else {
		cout << "Couldn't open the file" << endl;
	}

	
}