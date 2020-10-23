// Name: Ryan Zacharias
// Description: Data Structures
// Date: 10/21/2020

#include <iostream>
#include <vector>
#include <fstream> 
#include <string>
#include <iomanip>

using namespace std;

/* input file format:
	Formatting the input file:
	vector<string> firstName, 
	vector<string> lastName, 
	vector<string> jobTitle;
	vector<int> idNumber;

	vector<int> deductionsClaimed;
	vector<double> hoursWorked, 
	vector<double> wage; 
*/

struct employeeStruct
{
	vector<string> firstName, lastName, jobTitle;
	vector<int> idNumber;
	vector<int> deductionsClaimed;
	vector<double> hoursWorked, wage;

	vector<double> grossPay, netPay, tax;
};

void checkForInputFile(ifstream &inputFile, string fileName) {
	inputFile.open(fileName);
	if (!inputFile.is_open()) 
	{
		cout << "Input file " << fileName << " not found. Closing program..." << endl;
		cin.get();
		exit(0);
	}
	cout << "Input file " << fileName << " found. Continuing..." << endl << endl;
	inputFile.close();
}

void readInputFile(ifstream& inputFile, string fileName, string stringTemp, int intTemp, double doubleTemp, employeeStruct& employee) {
	inputFile.open(fileName);
	while (!inputFile.eof())
	{
		getline(inputFile, stringTemp);
		employee.firstName.push_back(stringTemp);

		getline(inputFile, stringTemp);
		employee.lastName.push_back(stringTemp);

		getline(inputFile, stringTemp);
		employee.jobTitle.push_back(stringTemp);

		inputFile >> intTemp;
		employee.idNumber.push_back(intTemp);

		inputFile >> intTemp;
		employee.deductionsClaimed.push_back(intTemp);

		inputFile >> doubleTemp;
		employee.hoursWorked.push_back(doubleTemp);

		inputFile >> doubleTemp;
		employee.wage.push_back(doubleTemp);
		inputFile.ignore();

		employee.grossPay.push_back(0);
		employee.netPay.push_back(0);
		employee.tax.push_back(0);

		inputFile >> ws;
	}
	inputFile.close();
}

void getGrossPay(employeeStruct& employee) {
	double overtime = 1.5;
	for (int i = 0; i < employee.firstName.size(); i++)
		if (employee.hoursWorked[i] > 40)
			employee.grossPay[i] = employee.wage[i] * overtime * (employee.hoursWorked[i] - 40);
		else
			employee.grossPay[i] = employee.wage[i] * (employee.hoursWorked[i]);
}

void getNetPay(employeeStruct& employee) {
	double taxRate = 0.30;
	double deductions = 0;
	for (int i = 0; i < employee.firstName.size(); i++) {
		deductions = employee.deductionsClaimed[i] * 0.05;
		if (employee.deductionsClaimed[i] >= 4)
			deductions = 0.20;
		employee.tax[i] = employee.grossPay[i] * (taxRate - deductions);
		employee.netPay[i] = employee.grossPay[i] - employee.tax[i];
	}
}

void output(employeeStruct &employee) {
	for (int i = 0; i < employee.firstName.size(); i++) {
		cout << employee.firstName[i] << " " << employee.lastName[i] << ", " << employee.jobTitle[i] << endl
			<< "Employee ID: " << employee.idNumber[i] << endl
			<< "Deductions Claimed: " << employee.deductionsClaimed[i] << endl
			<< "Hours Worked: " << employee.hoursWorked[i] << "\tWage: $" << employee.wage[i] << endl
			<< "Gross Pay: $" << employee.grossPay[i] << endl
			<< "Tax: $" << employee.tax[i] << endl
			<< "Net Pay: $" << employee.netPay[i] << endl << endl;
	}
}

int main() {
	cout << fixed << showpoint << setprecision(2);
	employeeStruct employee;
	double taxRate = 0.30;

	string stringTemp;
	int intTemp = 0;
	double doubleTemp = 0;

	ifstream iFile;

	checkForInputFile(iFile, "input.txt");
	readInputFile(iFile, "input.txt", stringTemp, intTemp, doubleTemp, employee);

	getGrossPay(employee);
	getNetPay(employee);

	output(employee);

	system("pause");
	return 0;
}