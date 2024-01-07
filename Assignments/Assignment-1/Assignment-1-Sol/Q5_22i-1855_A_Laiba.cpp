/*
/*
Laiba Mazhar
i22-1855
OOP_A
Assignment 1
Question 5
*/
#include <iostream>
using namespace std;
//`````````````````````````` INVERSIONS ````````````````````````````
int func(int** array, int n)
{
	int counter = 0;

	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (array[i][j] > array[j][i])
				counter++;
		}
	}

	return counter;
}
//`````````````````````````````````````` MAIN ````````````````````````````
int main()
{
	int size;
	cout << "Enter the size of the 2D array: ";
	cin >> size;
	cout << "----------------------------------------------------------" << endl;
	int** ptr_array = new int* [size];
	for (int i = 0; i < size; i++)
	{
		ptr_array[i] = new int[size];
	}
	cout << "Enter elements: " << endl;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			cin >> ptr_array[i][j];
		}
		cout << endl;
	}
	int inversions = func(ptr_array, size);
	cout << "----------------------------------------------------------" << endl;
	cout << "Number of inversions in the array: " << inversions << endl;
	for (int i = 0; i < size; i++) 
	{
		delete[] ptr_array[i];
	}
	delete[] ptr_array;

	return 0;
}