// Name: Ryan Zacharias
// Program Description: HTML Tag Removal
// Date: 9/16/2020 

#include <iostream>
#include <string>

using namespace std;

void A(string& string1) {
	cout << "Enter string value: " << endl;
	getline(cin, string1);

}

void B(int& int1, int& int2, string& string1) {
	// Reads entire string
	for (int int1 = int2; int1 <= string1.length(); int1++) {
		// If < is read
		if (string1[int1] == '<') {
			// reads where first sign was read
			for (int2 = int1; int2 < string1.length(); int2++) {
				// If > is read
				if (string1[int2] == '>') {
					// Erase everything in between and adjusts to correct position
					string1.erase(int1, (int2 - int1 + 1));
					int1--;
					break;
				}
			}
		}
	}
}

void C(string& string1) {
	cout << string1 << endl;
}

int main()
{
	string string1;
	int int1 = 0, int2 = 0;

	A(string1);
	B(int1, int2, string1);
	C(string1);

	system("pause");
	return 0;
}