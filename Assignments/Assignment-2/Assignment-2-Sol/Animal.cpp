/*
Laiba Mazhar
i22-1855
Assignment-2
Animal-cpp
*/
#include <iostream>
#include"jungle.h"
#include"Animal.h"
#include <string>
using namespace std;

int Animal::number_of_animals = 0;


//`````````````````````````` Default Constructor ``````````````````````````````````
Animal::Animal()
{
    name = "";
    species = "";
    age = 0;
    availability_status = true;
    number_of_animals++;
}


//``````````````````````` Parameterized Constructor ``````````````````````````````````
Animal::Animal(string n, string sp, int a, bool av)
{
    name = n;
    species = sp;
    age = a;
    availability_status = av;
    number_of_animals++;
}



//```````````````````````````` Copy Constructor ``````````````````````````````````
Animal::Animal(const Animal& other)
{
    name = other.name;
    species = other.species;
    age = other.age;
    availability_status = other.availability_status;
    number_of_animals++;
}



//````````````````````````````````` Destructor `````````````````````````````````````
Animal::~Animal()
{
    number_of_animals--;
}




//````````````````````````````` Check Avaliabilty ``````````````````````````````````
bool Animal::check_availability() const
{
    return availability_status;
}




//`````````````````````````````` Set unavaliabilty ``````````````````````````````````
void Animal::set_unavailability()
{
    availability_status = false;
}




//`````````````````````````````` Set Avaliabilty `````````````````````````````````````
void Animal::set_availability()
{
    availability_status = true;
}




//````````````````````````````` Display Animal Information ``````````````````````````
void Animal::display_animal_information() const
{
    cout << "The name of the animal is   : " << name << endl;
    cout << "The species of the animal is: " << species << endl;
    cout << "The age of the animal is    : " << age << endl;
    if (availability_status)
    {
        cout << "The animal is in the jungle" << endl;
    }
    else
    {
        cout << "The animal is not in the jungle" << endl;
    }
}






//`````````````````````````````` GETTERS ``````````````````````````````````
string Animal::get_name() const
{
    return name;
}





string Animal::get_species() const
{
    return species;
}





int Animal::get_age() const
{
    return age;
}



int Animal::get_number_of_animals()
{
    return number_of_animals;
}




//`````````````````````````````` Display Animal Info ``````````````````````````````````
void displayAnimalInfo(const Animal& animal)
{
    cout << "The name of the animal is   : " << animal.name << endl;
    cout << "The species of the animal is: " << animal.species << endl;
    cout << "The age of the animal is    : " << animal.age << endl;
    if (animal.availability_status)
    {
        cout << "The animal is in the jungle" << endl;
    }
    else
    {
        cout << "The animal is not in the jungle" << endl;
    }
}





//``````````````````````````````````` Sorting ````````````````````````````````````````
void sortAnimalsByCriteria(Animal* a, int num_anima)
{
    int k = 1;
    for (int i = 0; i < num_anima - k; i++)
    {
        for (int j = 0; j < num_anima - i - k; j++)
        {
            if (a[j].age < a[j + 1].age)
            {
                int temp = a[j].age;
                a[j].age = a[j + 1].age;
                a[j + 1].age = temp;
            }
        }
    }
    for (int i = 0; i < num_anima; i++)
    {
        a[i].display_animal_information();
        cout << "-------------------------------------------------------------------" << endl;
        cout << endl;
    }
}