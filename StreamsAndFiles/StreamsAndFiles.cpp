// StreamsAndFiles.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

int main() {

	double unitPrice;
	int quantity;

	cout << "What is the unit price? $";
	cin >> unitPrice;

	cout << endl << "How many do you want? ";
	cin >> quantity;

	cout << endl << "Total cost is: $" << unitPrice * quantity << endl;

    return 0;
}

