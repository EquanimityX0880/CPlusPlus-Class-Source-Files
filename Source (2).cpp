// Name: Ryan Zacharias
// Description: Parallel Arrays
// Date: 9/1/2020

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void checkInputFile(ifstream &iFile, ofstream &oFile) {
	iFile.open("input.txt");

	if (!iFile.is_open())
		cout << "Input file not found.\n\n";
	else
		cout << "Input file found. Continuing...\n\n";

	oFile.open("output.txt");
}
void readInputFile(ifstream &iFile, int &counter, string fName[], string lName[], string major[], string favoriteClass[], string leastFavoriteClass[], int tNum[], int credHours[], int gradYear[], double gpa[]) {
	while (!iFile.eof())
	{
		getline(iFile, fName[counter]);
		getline(iFile, lName[counter]);
		getline(iFile, major[counter]);
		getline(iFile, favoriteClass[counter]);
		getline(iFile, leastFavoriteClass[counter]);
		iFile >> tNum[counter];
		iFile >> credHours[counter];
		iFile >> gradYear[counter];
		iFile >> gpa[counter];
		iFile >> ws;

		counter++;
	}
}
void outputInfo(ifstream &iFile, ofstream &oFile, int &counter, string fName[], string lName[], string major[], string favoriteClass[], string leastFavoriteClass[], int tNum[], int credHours[], int gradYear[], double gpa[]) {
	for (int i = 0; i <= counter-1; i++)
	{
		// output to Console
		cout << fName[i] << endl;
		cout << lName[i] << endl;
		cout << major[i] << endl;
		cout << favoriteClass[i] << endl;
		cout << leastFavoriteClass[i] << endl;
		cout << tNum[i] << endl;
		cout << credHours[i] << endl;
		cout << gradYear[i] << endl;
		cout << gpa[i] << endl;
		cout << endl;

		// output to Output File
		oFile << fName[i] << endl;
		oFile << lName[i] << endl;
		oFile << major[i] << endl;
		oFile << favoriteClass[i] << endl;
		oFile << leastFavoriteClass[i] << endl;
		oFile << tNum[i] << endl;
		oFile << credHours[i] << endl;
		oFile << gradYear[i] << endl;
		oFile << gpa[i] << endl;
		oFile << endl;
	}
}
void outputInfoReverse(ifstream &iFile, ofstream &oFile, int &counter, string fName[], string lName[], string major[], string favoriteClass[], string leastFavoriteClass[], int tNum[], int credHours[], int gradYear[], double gpa[]) {
	for (int i = counter-1; i >= 0; i--)
	{
		// output to Console
		cout << fName[i] << endl;
		cout << lName[i] << endl;
		cout << major[i] << endl;
		cout << favoriteClass[i] << endl;
		cout << leastFavoriteClass[i] << endl;
		cout << tNum[i] << endl;
		cout << credHours[i] << endl;
		cout << gradYear[i] << endl;
		cout << gpa[i] << endl;
		cout << endl;

		// output to Output File
		oFile << fName[i] << endl;
		oFile << lName[i] << endl;
		oFile << major[i] << endl;
		oFile << favoriteClass[i] << endl;
		oFile << leastFavoriteClass[i] << endl;
		oFile << tNum[i] << endl;
		oFile << credHours[i] << endl;
		oFile << gradYear[i] << endl;
		oFile << gpa[i] << endl;
		oFile << endl;
	}
}
void outputHighestCreditHours(int counter, int credHours[], int sortHr[], int posH, string fName[], string lName[]) {
	// Duplicate the CredHours array
	for (int i = 0; i <= counter - 1; i++)
		sortHr[i] = credHours[i];

	// Compare and replace values if the "next" value is higher
	for (int i = 0; i <= counter - 1; i++) {
		if (sortHr[0] < sortHr[i]) {
			sortHr[0] = sortHr[i];
			posH = i;
		}
	}

	// Output the student's information
	cout << fName[posH] + ' ' + lName[posH] + ' ' << "has signed up for the most credit hours in the class. They are taking " << sortHr[0] << " credit hours." << endl << endl;
}
void outputHighestGPA(int counter, double gpa[], double sortG[], int posG, string fName[], string lName[]) {
	// Duplicate the GPA array
	for (int i = 0; i <= counter - 1; i++)
		sortG[i] = gpa[i];

	// Compare and replace values if the "next value is higher
	for (int i = 0; i <= counter - 1; i++) {
		if (sortG[0] < sortG[i]) {
			sortG[0] = sortG[i];
			posG = i;
		}
	}

	// Output the student's information
	cout << fName[posG] + ' ' + lName[posG] + ' ' << "has the highest GPA in their class. Their GPA is " << sortG[0] << '.' << endl << endl;
}

int main() {
	// Variables

	const int x = 35;
	int counter = 0;
	string fName[x], lName[x], major[x], favoriteClass[x], leastFavoriteClass[x];

	int tNum[x], credHours[x], gradYear[x];
	double gpa[x];

	ifstream iFile;
	ofstream oFile;

	// More complex variables
	int sortHr[x];
	double sortG[x];
	int posH = 0;
	double posG = 0;

	// Functions
	checkInputFile(iFile, oFile);
	readInputFile(iFile, counter, fName, lName, major, favoriteClass, leastFavoriteClass, tNum, credHours, gradYear, gpa);
	outputInfo(iFile, oFile, counter, fName, lName, major, favoriteClass, leastFavoriteClass, tNum, credHours, gradYear, gpa);
	outputInfoReverse(iFile, oFile, counter, fName, lName, major, favoriteClass, leastFavoriteClass, tNum, credHours, gradYear, gpa);

	outputHighestCreditHours(counter, credHours, sortHr, posH, fName, lName);
	outputHighestGPA(counter, gpa, sortG, posG, fName, lName);

	system("pause");
	return 0;
}