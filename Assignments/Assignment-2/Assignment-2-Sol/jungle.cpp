/*
Laiba Mazhar
i22-1855
Assignment-2
Jungle-cpp
*/

#include <iostream>
#include"jungle.h"
#include"Animal.h"
#include <string>
using namespace std;


//`````````````````````````` Default Constructor ``````````````````````````````````
Jungle::Jungle()
{
    capacity = 30;
    length = 0;
    animals = new Animal * [capacity];
}



//``````````````````````` Parameterized Constructor ``````````````````````````````````
Jungle::Jungle(int c, int l)
{
    capacity = c;
    length = l;
    animals = new Animal * [capacity];
}



//````````````````````````````````` Destructor `````````````````````````````````````
Jungle::~Jungle()
{
    for (int i = 0; i < length; i++)
    {
        delete animals[i];
    }
    delete[] animals;
}



//````````````````````````````````` Add Animal ```````````````````````````````````````
void Jungle::add_animal(const Animal animal)
{
    if (length < capacity)
    {
        animals[length] = new Animal(animal);
        length++;
    }
    else
    {
        cout << "Jungle is full :( " << endl;
    }
}



//````````````````````````````````` Remove Animal ```````````````````````````````````````
void Jungle::remove_animal(string name)
{
    int location = -1;
    for (int i = 0; i < length; i++)
    {
        if (animals[i]->get_name() == name)
        {
            location = i;
            break;
        }
    }

    if (location != -1)
    {
        animals[location] = nullptr;
        for (int i = location; i < length - 1; i++)
        {
            animals[i] = animals[i + 1];
        }
        length--;
        cout << "Animal with name " << name << " removed. " << endl;
    }
    else
    {
        cout << "Animal with name " << name << " not found. " << endl;
    }
}



//````````````````````````````````` Search Animal ```````````````````````````````````````
void Jungle::search_animals(const string name, const string specie, const int age) const
{
    bool found = false;

    for (int i = 0; i < length; i++)
    {
        const Animal* animal = animals[i];
        bool m = true;

        if (name != "" && animal->get_name() != name)
        {
            m = false;
        }

        if (specie != "" && animal->get_species() != specie)
        {
            m = false;
        }

        if (age != 0 && animal->get_age() != age)
        {
            m = false;
        }

        if (m)
        {
            animal->display_animal_information();
            found = true;
        }
    }

    if (!found)
    {
        cout << "No animals matches the search" << endl;
    }
}




//````````````````````````````````` Display Avaliable Animals ```````````````````````````````````````
void Jungle::display_all_available_animals() const
{
    for (int i = 0; i < length; i++)
    {
        if (animals[i]->check_availability())
        {
            animals[i]->display_animal_information();
            cout << "-------------------------------------------------------------------" << endl;
        }
    }
}



//``````````````````````````````````` Total Avaliable Animals ``````````````````````````````````````
void Jungle::total_available_animals()
{
    int total_available_animals_amount = 0;
    for (int i = 0; i < length; i++)
    {
        if (animals[i]->check_availability())
        {
            total_available_animals_amount++;
        }
    }
    cout << "Total availble are: " << total_available_animals_amount << endl;
}