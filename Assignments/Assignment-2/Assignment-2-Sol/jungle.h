/*
Laiba Mazhar
i22-1855
Assignment-2
Jungle-Header
*/
#pragma once
#include <iostream>
#include"Animal.h"
#include <string>
using namespace std;
//````````````````````` JUNGLE `````````````````````````````
class Jungle
{
private:
    Animal** animals;
    int capacity;
    int length;
public:
    Jungle();
    Jungle(int c, int l);
    ~Jungle();
    void add_animal(const Animal animal);
    void remove_animal(string name);
    void search_animals(const string name, const string specie, const int age)const;
    void display_all_available_animals() const;
    void total_available_animals();
};