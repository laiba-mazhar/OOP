/*
Laiba Mazhar
i22-1855
Assignment-2
int main (cpp)
*/
#include <iostream>
#include"jungle.h"
#include"Animal.h"
#include <string>
using namespace std;
//`````````````````````````````` MAIN `````````````````````````````````````````
int main()
{
    cout << "\033[1;36m" << endl;
    cout << "\t\t\t\t___________________________________________" << endl;
    cout << "\t\t\t\t|    JUNGLE & ANIMAL MANAGEMENT SYSTEM    |" << endl;
    cout << "\t\t\t\t|_________________________________________|" << endl;
    cout << endl << endl;
    //`````````````````````` Display Animal Information ``````````````````````````  
    cout << "-------------------------------------------------------------------" << endl;
    Animal Monkey("chimon", "Capuchin", 20, 1);
    Monkey.display_animal_information();
    cout << "-------------------------------------------------------------------" << endl;
    Animal Donkey("tashi", "Simba", 8, 1);
    Donkey.display_animal_information();
    cout << "-------------------------------------------------------------------" << endl;
    Animal Elephant("dubbo", "Elephant", 10, 1);
    Elephant.display_animal_information();
    cout << "-------------------------------------------------------------------" << endl;
    Animal Tiger("sheroo", "Tiger", 4, 1);
    Tiger.display_animal_information();
    cout << "-------------------------------------------------------------------" << endl;
    Animal Giraffe("jeri", "Giraffe", 15, 1);
    Giraffe.display_animal_information();
    cout << "-------------------------------------------------------------------" << endl;
    Animal Zebra("deezeb", "Equus", 18, 1);
    Zebra.display_animal_information();
    cout << "-------------------------------------------------------------------" << endl;
    Animal Rabbit("peter", "Reptile", 2, 1);
    Rabbit.display_animal_information();
    cout << "-------------------------------------------------------------------" << endl;
    Animal Peacock("parrpea", "Congoo", 3, 1);
    Peacock.display_animal_information();
    cout << "-------------------------------------------------------------------" << endl;
    Animal Chimpanzee(Monkey);
    Chimpanzee.display_animal_information();
    cout << "-------------------------------------------------------------------" << endl;
    Animal Deer(Zebra);
    Deer.display_animal_information();
    cout << "-------------------------------------------------------------------" << endl;
    Animal Parrot(Peacock);
    Parrot.display_animal_information();
    cout << "-------------------------------------------------------------------" << endl;
    Animal Hippotamuses("hippo", "Amphibian", 1, 1);
    Hippotamuses.display_animal_information();
    cout << "-------------------------------------------------------------------" << endl;
    Animal Ostrich("osto", "Somali", 5, 1);
    Ostrich.display_animal_information();
    cout << "-------------------------------------------------------------------" << endl;
    Jungle j1;
    string a;
    cout << "Enter animal name for which you want detailed information: ";
    getline(cin, a);
    if (a == "chimon")
    {
        displayAnimalInfo(Monkey);
    }
    else if (a == "tashi")
    {
        displayAnimalInfo(Donkey);
    }
    else if (a == "dubbo")
    {
        displayAnimalInfo(Elephant);
    }
    else if (a == "sheroo")
    {
        displayAnimalInfo(Tiger);
    }
    else if (a == "jeri")
    {
        displayAnimalInfo(Giraffe);
    }
    else if (a == "deezeb")
    {
        displayAnimalInfo(Zebra);
    }
    else if (a == "peter")
    {
        displayAnimalInfo(Rabbit);
    }
    else if (a == "parrpea")
    {
        displayAnimalInfo(Peacock);
    }
    else if (a == "hippo")
    {
        displayAnimalInfo(Hippotamuses);
    }
    else if (a == "osto")
    {
        displayAnimalInfo(Ostrich);
    }
    else
    {
        cout << "You entered invalid name " << endl;
    }
    //`````````````````````` Sorting ``````````````````````````
    cout << endl;
    cout << "-------------------------------------------------------------------" << endl;
    cout << "\t\t\t________________________" << endl;
    cout << "\t\t\t|   SORTING W.R.T AGE  |" << endl;
    cout << "\t\t\t|______________________|" << endl;
    cout << endl;
    Animal arr_sort[] = { Monkey, Donkey, Elephant, Tiger, Giraffe, Zebra, Rabbit, Peacock, Chimpanzee, Deer, Parrot, Hippotamuses, Ostrich };
    int total_animal = sizeof(arr_sort) / sizeof(arr_sort[0]);
    sortAnimalsByCriteria(arr_sort, total_animal);

    //``````````````````````` Jungle Class ``````````````````````````````````````````````````````
    while (true)
    {

        cout << "___________________________________________________" << endl;
        cout << "|              Select from the List                |" << endl;
        cout << "|__________________________________________________|" << endl;
        cout << "| 1) Add an Animal                                 |" << endl;
        cout << "|__________________________________________________|" << endl;
        cout << "| 2) Remove an Animal                              |" << endl;
        cout << "|__________________________________________________|" << endl;
        cout << "| 3) Search Animals                                |" << endl;
        cout << "|__________________________________________________|" << endl;
        cout << "| 4) Display Animals                               |" << endl;
        cout << "|__________________________________________________|" << endl;
        cout << "| 5) Display total number of avalible animals      |" << endl;
        cout << "|__________________________________________________|" << endl;
        cout << "| 6) Exit                                          |" << endl;
        cout << "|__________________________________________________|" << endl;
        cout << "Enter your choice: ";
        int choice;
        cin >> choice;
        cin.ignore();

        switch (choice)
        {
            //````````````````````````````````` Case 1 ``````````````````````````````````
        case 1:
        {
            j1.add_animal(Monkey);
            j1.add_animal(Donkey);
            j1.add_animal(Elephant);
            j1.add_animal(Tiger);
            j1.add_animal(Zebra);
            j1.add_animal(Rabbit);
            j1.add_animal(Peacock);
            j1.add_animal(Chimpanzee);
            j1.add_animal(Deer);
            j1.add_animal(Parrot);
            j1.add_animal(Hippotamuses);
            j1.add_animal(Ostrich);

            string name, species;
            int age;
            bool avaliable = 1;

            cout << "Enter the name of the animal: ";
            getline(cin, name);

            cout << "Enter the species of the animal: ";
            getline(cin, species);

            cout << "Enter the age of the animal: ";
            cin >> age;

            Animal ani1(name, species, age, 1);
            j1.add_animal(ani1);
            break;
        }
        //````````````````````````````````` Case 2 ``````````````````````````````````
        case 2:
        {
            string a;
            cout << "Enter the name of the animal which you want to remove: ";
            getline(cin, a);
            j1.remove_animal(a);
            break;
        }
        //````````````````````````````````` Case 3 ``````````````````````````````````
        case 3:
        {
            int search;
            cout << "__________________________" << endl;
            cout << "|    Search Animal By    |" << endl;
            cout << "| 1) Press 1 for Name    |" << endl;
            cout << "| 2) Press 2 for Specie  |" << endl;
            cout << "| 3) Press 3 for Age     |" << endl;
            cout << "|________________________|" << endl;
            cin >> search;
            cin.ignore();
            if (search == 1)
            {
                string name;
                cout << "Enter the name of the animal you want to search: ";
                getline(cin, name);
                j1.search_animals(name, "", 0);
            }
            else if (search == 2)
            {
                string specie;
                cout << "Enter the specie of animal you want to search: ";
                getline(cin, specie);
                j1.search_animals("", specie, 0);
            }
            else if (search == 3)
            {
                int age;
                cout << "Enter the age of animal you want to search: ";
                cin >> age;
                j1.search_animals("", "", age);

            }
            break;
        }
        //````````````````````````````````` Case 4 ``````````````````````````````````
        case 4:
        {
            j1.display_all_available_animals();
            cout << endl;
            return 0;
            break;
        }
        //````````````````````````````````` Case 5 ``````````````````````````````````
        case 5:
        {
            j1.total_available_animals();
        }
        //````````````````````````````````` Case 6 ``````````````````````````````````
        case 6:
        {
            exit(0);
        }
        default:
            cout << "Invalid choice. Please select a valid option." << endl;
        }
    }
}