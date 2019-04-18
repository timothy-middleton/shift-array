/*Instructions: Write a C++ program that uses a function to shift an array and store the result in a separate array.
The shift operation performed will be a left shift.*/

//Written By: Timothy Middleton 900382146


#include <iostream>
#include <string>
using namespace std;

// Functions that performs left shift of the character array 'array' by specified
// number of shifts. The results is stored in the array 'shiftedArray'.
void shiftArray(const char* array, char * shiftedArray, const int arraySize, const int shiftNumber);

void shiftArray(const char* array, char * shiftedArray, const int arraySize, const int shiftNumber)
{
	int rotations = 0;
	// compute actual shift number in order to work out case where shift number is
	// greater than the size of the array  
	if (shiftNumber > 0) {
		rotations = shiftNumber % arraySize;
	}
	// fill up output array with characters shifted by rotations number
	for (int i = 0; i < arraySize - rotations; i++) {
		shiftedArray[i] = array[i + rotations];
	}
	// process the remaining characters
	for (int i = arraySize - rotations, j = 0; i < arraySize; i++, j++) {
		shiftedArray[i] = array[j];
	}
	// add termination character
	shiftedArray[arraySize] = '\0';
}

int main() 
{
	char arr1[7]; // 6 + termination character
	char arr2[4]; // 3 + termination character 
	char shiftedArr1[7];
	char shiftedArr2[4];
	int shift1;
	int shift2;

	cout << "Enter 6 characters: ";
	cin >> arr1;
	cout << "How many times do you want to shift those characters? ";
	cin >> shift1;
	shiftArray(arr1, shiftedArr1, 6, shift1);
	cout << "The following is the shifted array: " << shiftedArr1 << endl;
	cout << "***********************************" << endl << endl;

	cout << "Enter 3 characters: ";
	cin >> arr2;
	cout << "How many times do you want to shift those characters? ";
	cin >> shift2;
	shiftArray(arr2, shiftedArr2, 3, shift2);
	cout << "The following is the shifted array: " << shiftedArr2 << endl;
	cout << "***********************************" << endl << endl;

	system("pause");
	return 0;
}

