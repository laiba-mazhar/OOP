/*
Laiba Mazhar
i22-1855
Assignment-2
Animal-Header
*/
#pragma once
#include <iostream>
#include <string>
using namespace std;
//`````````````````````` ANIMAL ``````````````````````
class Animal
{
private:
    string name;
    string species;
    int age;
    bool availability_status;

public:
    static int number_of_animals;
    Animal();
    Animal(string n, string sp, int a, bool av);
    Animal(const Animal& other);
    ~Animal();
    bool check_availability() const;
    void set_unavailability();
    void set_availability();
    void display_animal_information() const;
    string get_name() const;
    string get_species() const;
    int get_age() const;
    static int get_number_of_animals();
    friend void displayAnimalInfo(const Animal& animal);
    friend void sortAnimalsByCriteria(Animal* a, int num_anima);
};