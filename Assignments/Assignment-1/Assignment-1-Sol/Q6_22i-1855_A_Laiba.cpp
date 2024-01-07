/*
Laiba Mazhar
i22-1855
OOP_A
Assignment 1
Question 6
*/
#include <iostream>
using namespace std;
int main()
{
    int s;
    cout << "Enter the size of an array: " << endl;
    cin >> s;
    cout << "------------------------------------------------------" << endl << endl;
    int** array = new int* [s];
    for (int i = 0; i < s; i++)
    {
        array[i] = new int[s];
    }
    cout << "Enter the elements of the array:" << endl;
    for (int i = 0; i < s; i++)
    {
        for (int j = 0; j < s; j++)
        {
            cin >> array[i][j];
        }
    }
    cout << "------------------------------------------------------" << endl << endl;
    int even_sum = 0;
    int odd_sum = 0;
    for (int i = 0; i < s; i++)
    {
        for (int j = 0; j < s; j++)
        {
            if (array[i][j] % 2 == 0)
            {
                even_sum += array[i][j];
            }
            else
            {
                odd_sum += array[i][j];
            }
        }
    }
    cout << "Sum of even numbers: " << even_sum << endl;
    cout << "------------------------------------------------------" << endl << endl;
    cout << "Sum of odd numbers: " << odd_sum << endl;
    for (int i = 0; i < s; i++)
    {
        delete[] array[i];
    }
    delete[] array;
    return 0;
}