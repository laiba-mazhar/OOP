/*
Laiba Mazhar
i22-1855
OOP_A
Assignment 1
Question 4
*/
#include <iostream>
using namespace std;
const int max_val = 100;
//`````````````````````````````````` OCCURANCES DISPLAY ````````````````````````````````
void DisplayOccurrences(int* frequencies, int num)
{
    if (num < 0)
    {
        return;
    }
    if (frequencies[num] > 0)
    {
        cout << num << "         " << frequencies[num] << "\n";
    }

    DisplayOccurrences(frequencies, num - 1);

}
//```````````````````````````````````````` OCCURANCES `````````````````````````````````````
void FindOccurrences(int* A, int size, int* occurrences, int i)
{
    if (i < size)
    {
        occurrences[A[i]]++;
        FindOccurrences(A, size, occurrences, i + 1);
    }
}
//````````````````````````````````````````` MAIN ```````````````````````````````````````````
int main()
{
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;
    int* arr = new int[n];
    cout << "Enter elements in the array: ";
    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }
    int* occurs = new int[max_val + 1]();
    FindOccurrences(arr, n, occurs, 0);
    DisplayOccurrences(occurs, max_val);
    delete[] arr;
    delete[] occurs;
    return 0;
}