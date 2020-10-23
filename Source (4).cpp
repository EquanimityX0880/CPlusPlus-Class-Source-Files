// Name: Ryan Zacharias
// Description: Bubble Sort
// Date: 9/26/2020

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

// Reads first and last names from an input file.
void readInput(ifstream &iFile, string fName[], string lName[], int &counter) {
	iFile.open("input.txt");
	if (!iFile.is_open())
	{
		cout << "input file not  found" << endl;
		cin.get();
		exit(1);
	}

	while (!iFile.eof()) {
		iFile >> fName[counter];
		iFile >> lName[counter];

		counter++;
	}
}

// Sort and output data. Generic code, generic output
void sortData(int counter, string name1[], string name2[], string temp, bool swap) {
	// bubble sort code goes here
	for (int a = 0; a < counter; a++) {
		for (int b = 0; b < counter - 1; b++)
		{
			if (name1[b] > name1[b + 1])
			{
				// name1
				temp = name1[b];
				name1[b] = name1[b + 1];
				name1[b + 1] = temp;

				//name2
				temp = name2[b];
				name2[b] = name2[b + 1];
				name2[b + 1] = temp;

				swap = true;
			}
		}
		if (swap == true)
			swap = false;
		else
			break;
	}
	
	// Generic output
	for (int a = 0; a < counter; a++)
		cout << name1[a] << " " << name2[a] << endl;
}

void menu(int choice, int counter, string fName[], string lName[], string temp, bool swap) {
	cout << "Select option from below choices" << endl;
	cout << "1. Sort on first name" << endl;
	cout << "2. Sort on last name" << endl;
	cin >> choice;

	if (choice == 1)
		sortData(counter, fName, lName, temp, swap);
	else if (choice == 2)
		sortData(counter, lName, fName, temp, swap);
}

int main() {
	// Variables
	bool swap = false;
	int choice = 0;
	int counter = 0;
	ifstream iFile;
	string temp;
	string fName[100], lName[100];

	//Functions
	readInput(iFile, fName, lName, counter);
	menu(choice, counter, fName, lName, temp, swap);

	system("pause");
	return 0;
}