/*
Laiba Mazhar
i22-1855
OOP_A
Assignment 1
Question 2

#include <iostream>
using namespace std;
//`````````````````````````````` PATTERN ```````````````````````````````
void pattern(int s, int m, int* comb, int l)
{
    if (s == 0)
    {
        for (int i = 0; i < l; i++)
        {
            cout << comb[i];
            if (i != l - 1)
                cout << " ";
        }
        cout << endl;
        return;
    }
    if (s >= m)
    {
        comb[l] = m;
        pattern(s - m, m, comb, l + 1);
    }
    if (m > 1)
    {
        pattern(s, m - 1, comb, l);
    }
}

//`````````````````````````````` PRINT PATTERN ```````````````````````
void PrintPattern(int& n)
{
    cout << "\t\t\t\t\t_____________________________" << endl;
    cout << "\t\t\t\t\t|  PATTERN BY LAIBA MAZHAR  |" << endl;
    cout << "\t\t\t\t\t|___________________________|" << endl;
    cout << endl;
    int c[10];
    pattern(n, n, c, 0);
}
//````````````````````````````````` MAIN ```````````````````````````````
int main()
{
    int n = 4;
    PrintPattern(n);
    return 0;
}
