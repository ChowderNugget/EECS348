/*
EECS 348 Lab Assignment 6
main.py
    calculates and prints answers to all the problems in the assignment

sources:
	- https://www.youtube.com/watch?v=1a8C4rLE3wo&t=41s
		- 2D array file io
	- https://www.digitalocean.com/community/tutorials/two-dimensional-array-in-c-plus-plus
		- adding matrices / neat output
	- https://www.geeksforgeeks.org/c-program-multiply-two-matrices/#
		- multiplying matrices
created:
    Eli Pijanowski - 3049016
    10/19/23

last edited:
    10/21/23
*/

#include <iostream>
#include <fstream>

using namespace std;

// Declare global variables
	const int m = 10;
	int arr1[m][m];
	int arr2[m][m];
	int array_size;
	int add_result[m][m];
	int sub_result[m][m];
	int mult_result[m][m];


void readMatrices();  // Read matrices from input file
void printMatrices();  // Print matrices
void addMatrices(); // add our two matrices then print the result
void multMatrices(); // multiply our two matrices then print the result
void subMatrices(); // subtract our two matrices then print the result

int main() {	
	
	cout << "\nEli Pijanowski\nLab #6: Matrix manipulation\n";
	
	readMatrices();
	printMatrices();
	addMatrices();
	multMatrices();
	subMatrices();
	
    return 0;
}

// Read matrices from input file
void readMatrices() {
	// Open file
	ifstream iFile;
	iFile.open("matrix_input.txt");
	// Read size of array from file
	iFile >> array_size;
	// Read from file into first array
	for (int i = 0; i < array_size; i++) {
		for (int j = 0; j < array_size; j++) {
			iFile >> arr1[i][j];
		}
	}
	// Read from file into second array
	for (int i = 0; i < array_size; i++) {
		for (int j = 0; j < array_size; j++) {
			iFile >> arr2[i][j];
		}
	}
	//Close file
	iFile.close();
};

// Print matrices
void printMatrices() {
	// Print first array
	cout << "\n\t" << "Matrix A:" << endl;
	for (int i = 0; i < array_size; i++) {
		for (int j = 0; j < array_size; j++) {
			cout << "\t" << arr1[i][j];
		}
		cout << endl;
	}
	cout << "\n\t" << "Matrix B:" << endl;
	// Print second array
	for (int i = 0; i < array_size; i++) {
		for (int j = 0; j < array_size; j++) {
			cout << "\t" <<arr2[i][j];
		}
		cout << endl;
	}
};

// add matrices and print result
void addMatrices() {
	cout << "\n\t" << "Matrix Sum (A + B):" << endl;
	for (int i = 0; i < array_size; i++) {
		for (int j = 0; j < array_size; j++) {
			add_result[i][j] = arr1[i][j] + arr2[i][j];  // find result 
			cout << "\t" << add_result[i][j];  // print result
		}
		cout << endl;
	}
};

// multiply matrices and print result
void multMatrices() {
	cout << "\n\t" << "Matrix Product (A * B):" << endl;
	for (int i = 0; i < array_size; i++) {
		for (int j = 0; j < array_size; j++) {
			
			for (int k = 0; k < array_size; k++) {
				// since we have square matrices, the condition in the loop is array_size
				mult_result[i][j] += arr1[i][k] * arr2[k][j];  // this is like I learned in linear algebra
			}
			cout << "\t" << mult_result[i][j];
		}
		cout << endl;
	}
	
};

// add matrices and print result
void subMatrices() {
	cout << "\n\t" << "Matrix Difference (A - B):" << endl;
	for (int i = 0; i < array_size; i++) {
		for (int j = 0; j < array_size; j++) {
			sub_result[i][j] = arr1[i][j] - arr2[i][j];  // find result 
			cout << "\t" << sub_result[i][j];  // print result
		}
		cout << endl;
	}
	cout << endl;
};
