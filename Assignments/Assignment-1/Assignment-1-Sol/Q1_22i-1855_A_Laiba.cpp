/*
Laiba Mazhar
i22-1855
OOP_A
Assignment 1
Question 1
*/
#include <iostream>
using namespace std;
//`````````````````````````````````````````` CHANGE LOCATION `````````````````````````````````
void ChangeLocation(char* Array, int b1, int b2)
{
	if (b1 >= b2)
	{
		return;
	}
	char c = NULL;
	Array[b1] = c;
	c = Array[b2];
	Array[b1] = Array[b2];
	ChangeLocation(Array, b1 + 1, b2 - 1);
}
//`````````````````````````````````````````` MAIN `````````````````````````````````
int main()
{
	char array[8] = { 'P','A','K','I','S','T','A','N' };
	int b1 = 2;
	int b2 = 6;
	cout << "\t\t\t\t\t___________________" << endl;
	cout << "\t\t\t\t\t|  Orignal Array  |" << endl;
	cout << "\t\t\t\t\t|_________________|" << endl;
	for (int i = 0; i < 8; i++) {
		cout << array[i] << " ";
	}
	cout << endl;
	cout << "--------------------------------------------------------------------------------------------" << endl;
	cout << endl;
	ChangeLocation(array, b1, b2);
	cout << "\t\t\t\t\t____________________" << endl;
	cout << "\t\t\t\t\t|  Modified Array  |" << endl;
	cout << "\t\t\t\t\t|__________________|" << endl;
	for (int i = 0; i < 8; i++) {
		cout << array[i] << " ";
	}
	cout << endl << endl;
	return 0;
}