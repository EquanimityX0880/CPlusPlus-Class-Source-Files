// Name: Ryan Zacharias
// Description: Digital menu for "Double Burger"
// Date: 10-14-2020

#include <iostream>
#include <fstream> 
#include <string>
#include <iomanip>

using namespace std;

// checks for the given files and closes the program with an error if a filename is not found
void checkInputFile(ifstream &inFile, string fileName) {
	inFile.open(fileName);
	if (!inFile.is_open()) {
		cout << "Input file not found. Exiting..." << endl;
		cin.get();
		exit(1);
	}
	else
		/*cout << fileName << " found" << endl;*/
	inFile.close();
}

// opens input file, reads item name, reads price, reads quantity, tracks position across parallel arrays, and closes input file.
void readInputFile(ifstream &inFile, string fileName, string menu[], double price[], int quantity[], int &counter) {
	inFile.open(fileName);
	while (!inFile.eof()) {
		getline(inFile, menu[counter]);
		inFile >> price[counter];
		inFile >> quantity[counter];
		inFile.ignore();

		//cout << menu[counter] << endl;
		//cout << "Counter: " << counter << endl;
		//system("pause");

		counter++;
	}
	inFile.close();
}

// Order here
void menuSubMenu(string menuName, int counter, string menu[], double price[], int quantity[], double &subTotal, int &selection, string sdup[], double pdup[], int qdup[], int &dupCounter) {
	while (!selection == 0)
	{
		// variables neeeded exclusively here
		int qSelection = 0;
		bool quan = true;
		bool subMenu = true;

		system("cls");

		cout << menuName << endl;
		cout << "Please choose an item listed below" << endl;

		// list everything in the arrays for selected menu
		for (int i = 0; i < counter; i++) {
			cout << i + 1 << ". " << menu[i] << endl;
			cout << "\t$" << price[i] << endl;
			if (quantity[i] == 0)
				cout << "\t Current Servings: SOLD OUT" << endl;
			else
				cout << "\tCurrent Servings: " << quantity[i] << endl;
		}

		// Selection system
		while (subMenu)
		{
			cout << "Subtotal: $" << subTotal << endl;

			cout << "Enter Selection (0 to exit): ";
			cin >> selection;

			if (selection == 0) {
				subMenu = false;
				quan = false;
			}

			while (quan) {
				cout << "Enter Quantity: ";
				cin >> qSelection;
				

				if (quantity[selection - 1] < qSelection)
					cout << "Quantity is greater than the prepared servings. " << endl;
				else {
					quantity[selection - 1] -= qSelection;

					subTotal += qSelection * price[selection - 1];
					quan = false;
					subMenu = false;

					sdup[dupCounter] = menu[selection - 1];
					pdup[dupCounter] = price[selection - 1];
					qdup[dupCounter] = qSelection;

					dupCounter++;
				}

			}
		}

	}
}

// Outputs all ordered items to the screen, calculates tax, asks for payment
void checkout(double subTotal, string sdup[], double pdup[], int qdup[], int dupCounter, ofstream &outFile) {
	double payment;
	double total = subTotal * 1.1;
	double  paidSum = 0; // total - paidSum = what is owed


	system("cls");
	cout << "Receipt" << endl;
	cout << "Subtotal: $" << subTotal << endl;
	cout << "Tax: $" << total - subTotal << endl;
	cout << "Total: $" << total << endl;
	for (int i = 0; i < dupCounter; i++)
		cout << "\t" << sdup[i] << "\tx" << qdup[i] << "\t$" << pdup[i] << "\t...$" << qdup[i] * pdup[i] << endl;

	// make sure customer pays enough

	cout << "Please input payment here: $" << endl;
	cin >> payment;
	paidSum += payment;
	cout << endl << endl;

	while (paidSum < total) {
			cout << "The entered value is not enough to pay the bill. Please pay more." << endl;
				cout << "Sum Owed: $" << total - paidSum << endl;
				cout << "Please input payment here: $" << endl;
				cin >> payment;
				paidSum += payment;
				cout << endl;
	}

	if (paidSum > total)
		cout << "You paid too much. Your cashback is: $" << abs(paidSum - total) << endl;
	cout << "Leave a tip? $";
	cin >> payment;

	cout << endl << "Total money spent: $" << total + payment << endl;
	cout << "Have a nice day!" << endl;

	outFile.open("output.txt");
	// output file
	outFile << fixed << showpoint << setprecision(2);
	outFile << "Double Burger Receipt" << endl;
	outFile << "Subtotal: $ " << subTotal << endl;
	outFile << "Tax: $" << total - subTotal << endl;
	outFile << "Tip: $" << payment << endl;
	outFile << "Total: $" << total + payment << endl;
	for (int i = 0; i < dupCounter; i++)
		outFile << "\t" << sdup[i] << "\tx" << qdup[i] << "\t$" << pdup[i] << "\t...$" << qdup[i] * pdup[i] << endl;
	
	system("pause");
	exit(1);
}

void main() {
	cout << fixed << showpoint << setprecision(2);

	// variables
	const int x = 35;
	int counter1 = 0, counter2 = 0, counter3 = 0, counter4 = 0;

	// menu variables
	int  selection = 0;
	double subTotal = 0;
	double total = 0;

	// arrays 
	string appetizers[x], entrees[x], desserts[x], drinks[x];
	double appetizersP[x], entreesP[x], dessertsP[x], drinksP[x];
	int quantityEntrees[x], quantityAppetizers[x], quantityDesserts[x], quantityDrinks[x];

	// used for reciept
	string sdup[x];
	double pdup[x];
	int qdup[x];
	int dupCounter = 0;

	// file stuff
	ifstream inFile;
	ofstream outFile;
	
	// checks for given files and closes the program with an error if a filename is not found
	checkInputFile(inFile, "appetizers.txt");
	checkInputFile(inFile, "desserts.txt");
	checkInputFile(inFile, "drinks.txt");
	checkInputFile(inFile, "entrees.txt");
	
	// reads each line from each file and passes it to the appropriate variable for later calculations
	readInputFile(inFile, "appetizers.txt", appetizers, appetizersP, quantityAppetizers, counter1);
	readInputFile(inFile, "desserts.txt", desserts, dessertsP, quantityDesserts, counter2);
	readInputFile(inFile, "drinks.txt", drinks, drinksP, quantityDrinks, counter3);
	readInputFile(inFile, "entrees.txt", entrees, entreesP, quantityEntrees, counter4);
	
	// menu core
	while (1) {
		system("cls");

		cout << "Welcome to Double Burger" << endl;
		cout << "Please choose from a category below" << endl;
		cout << "1. Appetizers \n2. Entrees \n3. Drinks \n4. Desserts" << endl;
		cout << "Subtotal: $" << subTotal << endl;

		cout << "Enter Selection (0 to exit to checkout): ";
		cin >> selection;

		// Checkout 
		if (selection == 0)
			checkout(subTotal, sdup, pdup, qdup, dupCounter, outFile);
		// 1 Appetizers
		else if (selection == 1)
			menuSubMenu("Appetizer Menu", counter1, appetizers, appetizersP, quantityAppetizers, subTotal, selection, sdup, pdup, qdup, dupCounter);
		// 2 Entrees
		else if (selection == 2)
			menuSubMenu("Entree Menu", counter4, entrees, entreesP, quantityEntrees, subTotal, selection, sdup, pdup, qdup, dupCounter);
		// 3 Drinks
		else if (selection == 3)
			menuSubMenu("Drinks Menu", counter3, drinks, drinksP, quantityDrinks, subTotal, selection, sdup, pdup, qdup, dupCounter);
		// 4 Desserts
		else if (selection == 4)
			menuSubMenu("Desserts Menu", counter2, desserts, dessertsP, quantityDesserts, subTotal, selection, sdup, pdup, qdup, dupCounter);
		else {
			cout << "\aInput not recognized. Please try again." << endl << endl;
			system("pause");
		}
	} // End of menu core
}