/*
Laiba Mazhar
i22-1855
OOP-A
Assignment 1
Question 7
#include <iostream>
#include <cstring>
using namespace std;
void countingUniqueWords(char* string, char*& uwords, int* size)
{
    if (string == nullptr || size == nullptr)
    {
        cerr << "Invalid input parameters"<<endl;
        return;
    }

    uwords = nullptr;
    *size = 0;

    char* a = strtok(string, " \n");
    while (a != nullptr)
    {
        bool laiba = true;
        for (int i = 0; i < *size; i++)
        {
            if (strcmp(uwords + i * 20, a) == 0)
            {
                laiba = false;
                break;
            }
        }

        if (laiba)
        {
            (*size)++;
            uwords = (char*)realloc(uwords, sizeof(char) * ((*size) * 20 + 1)); 
            strcpy(uwords + ((*size) - 1) * 20, a);
        }

        a = strtok(nullptr, " \n");
    }
}

int main()
{
    cout << "Enter a string :" << endl;
    const int maximum = 50;
    char laiba[maximum];
    cin.getline(laiba, maximum);
    char* uniqueWords;
    int uniqueWordsSize;
    countingUniqueWords(laiba, uniqueWords, &uniqueWordsSize);
    cout << "Unique words and their sizes: " << endl;
    for (int i = 0; i < uniqueWordsSize; i++)
    {
        cout << "Word: " << (uniqueWords + i * 20) << ", Size: " << strlen(uniqueWords + i * 20) << "\n";
    }
    free(uniqueWords);
    return 0;
}
