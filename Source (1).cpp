// Name: Ryan Zacharias
// Program Description: Review. I/O for string array to file and console
// Date: 8/28/2020

#include<iostream>
#include<fstream>
#include<string>

using namespace std;

void fileCheck(ifstream &iFile, ofstream &oFile) {
	iFile.open("input.txt");
	cout << "Checking for input file... " << endl << endl;
	if (iFile.is_open())
	{
		cout << "Input file found. Continuing... " << endl << endl;
	}

	oFile.open("output.txt");
}

// 3: Feeding input file to array
void readNames(ifstream &iFile, string heroName[], int &counter) {
	while (!iFile.eof()) {
		getline(iFile, heroName[counter]);
		counter++;
	}
}

// 4: Outputting names to console and oFile
void nameOutput(string heroName[], int counter, ofstream &oFile) {
	cout << "Name Output" << endl;
	for (int i = 0; i < counter; i++)
	{
		cout << heroName[i] << endl;
		oFile << heroName[i] << endl;
	}
}

void nameOutputReverse(int counter, string heroName[], ofstream &oFile) {
	cout << endl << "Name Output Reverse" << endl;

	for (int i = counter-1; i >= 0; i--) {
		cout << heroName[i] << endl;
		oFile << heroName[i] << endl;
	}
}

void closeFiles(ifstream &iFile, ofstream &oFile) {
	iFile.close();
	oFile.close();
}

// 5: Functions created

int main() {
	// 2: Created i/o files
	ifstream iFile;
	ofstream oFile;

	int counter = 0;
	const int x = 25;

	// 1: Created string array
	string heroName[x];
	
	fileCheck(iFile, oFile);
	readNames(iFile, heroName, counter);
	nameOutput(heroName, counter, oFile);
	nameOutputReverse(counter, heroName, oFile);
	closeFiles(iFile, oFile);

	system("pause");
	return 0;
}