// Name: Ryan Zacharias
// Description: Vectors
// Date: 10/5/2020

#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

void checkInputFile(ifstream &iFile, ofstream &oFile) {
	iFile.open("input.txt");
	if (!iFile.is_open()) {
		cout << "Input file not found." << endl;
		exit(1);
	}
	else
		cout << "Input file found. Continuing... \n" << endl;

	oFile.open("output.txt");
}
void readInputFile(ifstream &iFile, string &tempString, int &tempInt, double &tempDouble, vector<string> &fName, vector<string> &lName, vector<string> &major, vector<string> &favoriteClass, vector<string> &leastFavoriteClass, vector<int> &tNum, vector<int> &credHours, vector<int> &gradYear, vector<double> &gpa) {
	while (!iFile.eof())
	{
		getline(iFile, tempString);
		fName.push_back(tempString);

		getline(iFile, tempString);
		lName.push_back(tempString);

		getline(iFile, tempString);
		major.push_back(tempString);

		getline(iFile, tempString);
		favoriteClass.push_back(tempString);

		getline(iFile, tempString);
		leastFavoriteClass.push_back(tempString);

		iFile >> tempInt;
		tNum.push_back(tempInt);

		iFile >> tempInt;
		credHours.push_back(tempInt);

		iFile >> tempInt;
		gradYear.push_back(tempInt);

		iFile >> tempDouble;
		gpa.push_back(tempDouble);

		iFile.ignore();
		iFile >> ws;

	}
}
void outputInfo(ofstream &oFile, vector<string> &fName, vector<string> &lName, vector<string> &major, vector<string> &favoriteClass, vector<string> &leastFavoriteClass, vector<int> &tNum, vector<int> &credHours, vector<int> &gradYear, vector<double> &gpa) {
	for (int i = 0; i <= fName.size() - 1; i++) {
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

		// file output
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
	cout << "++++\n" << endl;
}
void outputInfoReverse(ofstream &oFile, vector<string> &fName, vector<string> &lName, vector<string> &major, vector<string> &favoriteClass, vector<string> &leastFavoriteClass, vector<int> &tNum, vector<int> &credHours, vector<int> &gradYear, vector<double> &gpa) {
	for (int i = fName.size() - 1; i >= 0; i--) {
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

		// file output
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
void outputHighestCreditHours(vector<int> &credHours, int &tempInt, vector<string> &fName, vector<string> &lName) {
	// using tempInt to track index position of highest credit hour count. 
	// Set tempInt to 0 in case the if statement does not run.
	// duplicate the credhours vector.
	vector<int> credHoursDuplicate = credHours;
	// compare and replace values if the next value is higher
	// for length of vector, compare values
	tempInt = 0;
	for (int i = 0; i <= credHoursDuplicate.size() - 1; i++) {
		// If statement only runs if the highest value is not at i = 0
		if (credHoursDuplicate[0] < credHoursDuplicate[i]) {
			credHoursDuplicate[0] = credHoursDuplicate[i];
			tempInt = i;
		}
	}
	// Output student info
	cout << "Credit Hours at " << tempInt << ": " << credHoursDuplicate[tempInt] << endl;
	cout << "They belong to student " << fName[tempInt] << " " << lName[tempInt] << "." << endl;
}
void outputHighestGPA(vector<double> &gpa, int &tempInt, vector<string> &fName, vector<string> &lName) {
	vector<double> gpaDuplicate = gpa;
	tempInt = 0;

	for (int i = 0; i <= gpaDuplicate.size() - 1; i++)
		if (gpaDuplicate[0] < gpaDuplicate[i])
		{
			gpaDuplicate[0] = gpaDuplicate[i];
			tempInt = i;
		}

	cout << "Highest GPA at " << tempInt << ": " << gpaDuplicate[tempInt] << endl;
	cout << "It belongs to student " << fName[tempInt] << " " << lName[tempInt] << "." << endl;
}
int main() {
	// Variables
	ifstream iFile;
	ofstream oFile;

	vector<string> fName, lName, major, favoriteClass, leastFavoriteClass;
	vector<int> tNum, credHours, gradYear;
	vector<double> gpa;

	string tempString;
	int tempInt = 0;
	double tempDouble = 0;

	checkInputFile(iFile, oFile);
	readInputFile(iFile, tempString, tempInt, tempDouble, fName, lName, major, favoriteClass, leastFavoriteClass, tNum, credHours, gradYear, gpa);
	outputInfo(oFile, fName, lName, major, favoriteClass, leastFavoriteClass, tNum, credHours, gradYear, gpa);
	outputInfoReverse(oFile, fName, lName, major, favoriteClass, leastFavoriteClass, tNum, credHours, gradYear, gpa);
	outputHighestCreditHours(credHours, tempInt, fName, lName);
	outputHighestGPA(gpa, tempInt, fName, lName);

	// End of Script
	system("pause");
	return 0;
}