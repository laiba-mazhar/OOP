/*
Laiba Mazhar
i22-1855
OOP_A
Assignment 1
Question 3
*/
#include <iostream>
#include <cstring> 
using namespace std;
bool CheckSubsequent(char* str1, char* str2, int i, int j)
{
	int size_1 = strlen(str1);
	int size_2 = strlen(str2);
	if (j == size_2)
	{
		return true;
	}
	if (i == size_1)
	{
		return false;
	}
	if (str1[i] == str2[j])
	{
		return CheckSubsequent(str1, str2, i + 1, j + 1);
	}
	else
	{
		return CheckSubsequent(str1, str2, i + 1, 0);
	}
}

int main()
{
	char Array1[100];
	char Array2[100];
	cout << "Enter the first string: " << endl;
	cin >> Array1;
	cout << "Enter the second string: " << endl;
	cin >> Array2;
	bool result = CheckSubsequent(Array1, Array2, 0, 0);
	if (result)
	{
		cout << "Output: True " << endl;
	}
	else
	{
		cout << "Output: False " << endl;
	}
	return 0;
}