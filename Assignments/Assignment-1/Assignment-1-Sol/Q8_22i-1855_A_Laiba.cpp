/*
Laiba Mazhar
i22-2041
OOP-A
Assignment-1
Question 8
*/
#include <iostream>
using namespace std;
void CheckEqualSumArrays(int** A1, int** A2, int** A3)
{
    int** sum_arrays = new int* [2];
    for (int i = 0; i < 2; i++)
    {
        sum_arrays[i] = new int[2];
        for (int j = 0; j < 2; j++)
        {
            sum_arrays[i][j] = A1[i][j] + A2[i][j];
        }
    }
    bool is_equal = true;
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            if (sum_arrays[i][j] != A3[i][j])
            {
                is_equal = false;
                break;
            }
        }
    }
    if (is_equal)
    {
        cout << "Sum of 1st Array and 2nd Array is equal to 3rd Array " << endl;
    }
    else
    {
        cout << "Sum of 1st Array and 2nd Array is not equal to 3rd Array" << endl;
    }
    for (int i = 0; i < 2; i++)
    {
        delete[] sum_arrays[i];
    }
    delete[] sum_arrays;
}
void CheckDifferentArrays(int** A1, int** A2, int** A3)
{
    bool is_equal = true;
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            if (A1[i][j] - A2[i][j] != A3[i][j] && A2[i][j] - A1[i][j] != A3[i][j])
            {
                is_equal = false;
                break;
            }
        }
    }
    if (is_equal)
    {
        cout << "Difference of any two arrays is equal to third one" << endl;
    }
    else
    {
        cout << "Difference of two arrays is not equal to third one" << endl;
    }
}
void CheckEqualArrays(int** A1, int** A2, int** A3)
{
    bool is_equal = false;
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            if (A1[i][j] == A2[i][j] || A1[i][j] == A3[i][j] || A2[i][j] == A3[i][j])
            {
                is_equal = true;
                break;
            }
        }
        if (is_equal)
            break;
    }
    if (is_equal)
    {
        cout << "Two arrays are equal" << endl;
    }
    else
    {
        cout << "Any of the Arrays are not equal" << endl;
    }
}
void FindSameRows(int** A1, int** A2, int** A3)
{
    bool is_equal = true;

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            if (A1[i][j] != A2[i][j] || A1[i][j] != A3[i][j] || A2[i][j] != A3[i][j])
            {
                is_equal = false;
                break;
            }
        }

        if (is_equal)
        {
            cout << "Row " << i + 1 << " is the same in all arrays." << endl;
        }
        else
        {
            cout << "Row " << i + 1 << " is not the same in all arrays." << endl;
        }
        is_equal = true;
    }
}
void RotateArrays(int** A1, int** A2, int** A3)
{
    int r = 2;
    int** R1 = new int* [r];
    int** R2 = new int* [r];
    int** R3 = new int* [r];
    for (int i = 0; i < r; i++)
    {
        R1[i] = new int[r];
    }
    for (int i = 0; i < r; i++)
    {
        R2[i] = new int[r];
    }
    for (int i = 0; i < r; i++)
    {
        R3[i] = new int[r];
    }
    cout << "\t\t\t\t\t_____________________" << endl;
    cout << "\t\t\t\t\t| Rotated 1st Array |" << endl;
    cout << "\t\t\t\t\t|___________________|" << endl;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < r; j++)
        {
            R1[i][j] = A1[r - 1 - j][i];
            cout << R1[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    cout << "\t\t\t\t\t_____________________" << endl;
    cout << "\t\t\t\t\t| Rotated 2nd Array |" << endl;
    cout << "\t\t\t\t\t|___________________|" << endl;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < r; j++)
        {
            R2[i][j] = A2[r - 1 - j][i];
            cout << R2[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    cout << "\t\t\t\t\t_____________________" << endl;
    cout << "\t\t\t\t\t| Rotated 3rd Array |" << endl;
    cout << "\t\t\t\t\t|___________________|" << endl;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < r; j++)
        {
            R3[i][j] = A3[r - 1 - j][i];
            cout << R3[i][j] << " ";
        }
        cout << endl;
    }
    for (int i = 0; i < r; i++)
    {
        delete[] R1[i];
        delete[] R2[i];
        delete[] R3[i];
    }
    delete[] R1;
    delete[] R2;
    delete[] R3;
}
int main()
{
    int r;
    cout << "Enter the rows: " << endl;
    cin >> r;
    int c;
    cout << "Enter the columns: " << endl;
    cin >> c;
    cout << "--------------------------------------------------------------------------" << endl;
    int** array_one = new int* [r];
    for (int i = 0; i < r; i++)
    {
        array_one[i] = new int[c];
    }

    int** array_two = new int* [r];
    for (int i = 0; i < r; i++)
    {
        array_two[i] = new int[c];
    }

    int** array_three = new int* [r];
    for (int i = 0; i < r; i++)
    {
        array_three[i] = new int[c];
    }
    cout << "Enter 1st Array: " << endl;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> array_one[i][j];
        }
    }
    cout << endl;
    cout << "--------------------------------------------------------------------------" << endl;
    cout << "Enter 2nd Array: " << endl;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> array_two[i][j];
        }
    }
    cout << endl;
    cout << "--------------------------------------------------------------------------" << endl;
    cout << "Enter 3rd Array: " << endl;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> array_three[i][j];
        }
    }
    cout << endl;
    cout << "--------------------------------------------------------------------------" << endl;
    cout << "\t\t\t\t\t_____________" << endl;
    cout << "\t\t\t\t\t| 1st Array |" << endl;
    cout << "\t\t\t\t\t|___________|" << endl;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cout << array_one[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    cout << "--------------------------------------------------------------------------" << endl;
    cout << "\t\t\t\t\t_____________" << endl;
    cout << "\t\t\t\t\t| 2nd Array |" << endl;
    cout << "\t\t\t\t\t|___________|" << endl;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cout << array_two[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    cout << "--------------------------------------------------------------------------" << endl;
    cout << "\t\t\t\t\t_____________" << endl;
    cout << "\t\t\t\t\t| 3rd Array |" << endl;
    cout << "\t\t\t\t\t|___________|" << endl;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cout << array_three[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    cout << "--------------------------------------------------------------------------" << endl;
    CheckEqualSumArrays(array_one, array_two, array_three);
    cout << endl;
    cout << "--------------------------------------------------------------------------" << endl;
    CheckDifferentArrays(array_one, array_two, array_three);
    cout << endl;
    cout << "--------------------------------------------------------------------------" << endl;
    CheckEqualArrays(array_one, array_two, array_three);
    cout << endl;
    cout << "--------------------------------------------------------------------------" << endl;
    FindSameRows(array_one, array_two, array_three);
    cout << endl;
    cout << "--------------------------------------------------------------------------" << endl;
    RotateArrays(array_one, array_two, array_three);
    for (int i = 0; i < r; i++)
    {
        delete[] array_one[i];
        delete[] array_two[i];
        delete[] array_three[i];
    }
    delete[] array_one;
    delete[] array_two;
    delete[] array_three;
    return 0;
}
