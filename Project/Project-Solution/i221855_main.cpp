/*
BISMILLAHI ARAHMAN I RAHEEEM
Laiba Mazhar
i22-1855
laibamazhar.000@gmail.com
*/
#include<iostream>
#include<string>
#include<cstring>
#include<sstream>
#include<fstream>
#include<ctime>
#include<cstdlib>
#include<cstdio>
#include<conio.h>
#include <thread>
#include <chrono>
#include<iomanip>
#include"project.h"
using namespace std;
//````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````
//''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''INT MAIN''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''`'
//````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````
int main()
{
/*
Laiba Mazhar
i22-1855
OOP-A
*/
    cout << "\033[38;5;85m";
    cout << "\n";
    cout << "\t\t\t\t\t__________________________________" << endl;
    cout << "\t\t\t\t\t|      CAFE MANAGEMENT SYSTEM    |" << endl;
    cout << "\t\t\t\t\t|________________________________|" << endl;
    cout << endl;

    cout << "____________________________" << endl;
    cout << "|   Select From The List   |" << endl;
    cout << "|__________________________|" << endl;
    cout << "|    1: REGISTER           |" << endl;
    cout << "|__________________________|" << endl;
    cout << "|    2: LOGIN              |" << endl;
    cout << "|__________________________|" << endl;
    cout << "|    3: EXIT               |" << endl;
    cout << "|__________________________|" << endl;
    cout << endl;
    MenuItem m1;
    int choice = 0;
    cout << "Enter: ";
    cin >> choice;
    cin.ignore();
    string n = "";
    string ro = "";
    int id = 0;
    string password;
    cout << "------------------------------------------------------------------------------------------------" << endl;
    cout << "Enter your name                : ";
    getline(cin, n);
    cout << endl << endl;
    cout << "Enter your role (Admin, Staff ): ";
    getline(cin, ro);
    cout << endl << endl;
    cout << "Enter your ID                  : ";
    while (!(cin >> id))
    {
        cout << endl;
        cout << "Enter a Valid ID              : ";
        cin.clear();
        while (cin.get() != '\n')
        {
            continue;
        }
    }
    cin.ignore();
    cout << endl;
    user u1(n, ro, id);


    if (choice == 1)
    {
        u1.registration();
        system("cls");

        cout << "____________________________" << endl;
        cout << "|   Select From The List   |" << endl;
        cout << "|__________________________|" << endl;
        cout << "|    1: REGISTER           |" << endl;
        cout << "|__________________________|" << endl;
        cout << "|    2: LOGIN              |" << endl;
        cout << "|__________________________|" << endl;
        cout << "|    3: EXIT               |" << endl;
        cout << "|__________________________|" << endl;
        cout << endl;
        cout << "Enter: ";
        cin >> choice;
        cin.ignore();
    }


    if (choice == 2)
    {
    l1:
        string username, password;
        cout << "------------------------------------------------------------------------------------------------" << endl;
        cout << "Enter your username: ";
        getline(cin, username);
        cout << endl;
        cout << "Enter your password: ";
        password = read_pass();
        cout << endl;
        Administrator a1(u1.get_UserID(), u1.get_UserName());
        Cafestaff c1;
        Student s1;
        Faculty f1;
        non_faculty nf1;




        // Login
        if (u1.login(username, password))
        {
            //ADMINISTRATOR
            if (u1.get_UserType() == "Administrator" || u1.get_UserType() == "admin" || u1.get_UserType() == "Admin")
            {
                while (true)
                {
                    cout << endl << endl;
                    cout << "\t\t\t\t\t        ADMINISTRATOR'S MENU      " << endl << endl;
                    cout << "\t\t\t\t\t__________________________________" << endl;
                    cout << "\t\t\t\t\t|      Select From The List       |" << endl;
                    cout << "\t\t\t\t\t|_________________________________|" << endl;
                    cout << "\t\t\t\t\t|  1:  View Menu                  |" << endl;
                    cout << "\t\t\t\t\t|_________________________________|" << endl;
                    cout << "\t\t\t\t\t|  2:  Add Item                   |" << endl;
                    cout << "\t\t\t\t\t|_________________________________|" << endl;
                    cout << "\t\t\t\t\t|  3:  Remove Item                |" << endl;
                    cout << "\t\t\t\t\t|_________________________________|" << endl;
                    cout << "\t\t\t\t\t|  4:  Manage Inventory           |" << endl;
                    cout << "\t\t\t\t\t|_________________________________|" << endl;
                    cout << "\t\t\t\t\t|  5:  Manage Discount            |" << endl;
                    cout << "\t\t\t\t\t|_________________________________|" << endl;
                    cout << "\t\t\t\t\t|  6:  View Order History         |" << endl;
                    cout << "\t\t\t\t\t|_________________________________|" << endl;
                    cout << "\t\t\t\t\t|  7:  Add/Remove Notification    |" << endl;
                    cout << "\t\t\t\t\t|_________________________________|" << endl;
                    cout << "\t\t\t\t\t|  8:  Rate Menu Item             |" << endl;
                    cout << "\t\t\t\t\t|_________________________________|" << endl;
                    cout << "\t\t\t\t\t|  9:  View user's from file      |" << endl;
                    cout << "\t\t\t\t\t|_________________________________|" << endl;
                    cout << "\t\t\t\t\t|  10: View order's from file     |" << endl;
                    cout << "\t\t\t\t\t|_________________________________|" << endl;
                    cout << "\t\t\t\t\t|  11: View ratings from file     |" << endl;
                    cout << "\t\t\t\t\t|_________________________________|" << endl;
                    cout << "\t\t\t\t\t|  12: View Payments from file    |" << endl;
                    cout << "\t\t\t\t\t|_________________________________|" << endl;
                    cout << "\t\t\t\t\t|  13: Calculate Montly Earnings  |" << endl;
                    cout << "\t\t\t\t\t|_________________________________|" << endl;
                    cout << "\t\t\t\t\t|  14: Logout                     |" << endl;
                    cout << "\t\t\t\t\t|_________________________________|" << endl;
                    cout << endl << endl;
                    int l;
                    cout << "Enter: ";
                    cin >> l;
                    cin.ignore();
                    cout << endl;
                    int menuIndex = 0;
                    if (l == 1)
                    {
                        a1.ViewMenu(menuIndex);
                    }
                    else if (l == 2)
                    {
                        int num_add;
                        cout << "Enter the number of items to add: ";
                        cin >> num_add;
                        cin.ignore();
                        cout << endl;
                        cout << "------------------------------------------------------------------------------------------------" << endl;
                        for (int i = 0; i < num_add; ++i)
                        {
                            cout << "Adding menu item " << i + 1 << endl << endl;
                            a1.add_item();
                            cout << "------------------------------------------------------------------------------------------------" << endl;
                        }
                    }
                    else if (l == 3)
                    {
                        int num_remove;
                        cout << "Enter the number of items to be removed: ";
                        cin >> num_remove;
                        cin.ignore();
                        cout << endl;
                        cout << "------------------------------------------------------------------------------------------------" << endl;
                        for (int i = 0; i < num_remove; ++i)
                        {
                            cout << "Removing menu item " << i + 1 << endl << endl;
                            a1.remove_item();
                            cout << "------------------------------------------------------------------------------------------------" << endl;
                        }

                    }
                    else if (l == 4)
                    {
                        cout << "------------------------------------------------------------------------------------------------" << endl << endl;
                        cout << " Managing Inventory !" << endl;
                        a1.ManageInventory();
                    }
                    else if (l == 5)
                    {
                        cout << "------------------------------------------------------------------------------------------------" << endl << endl;
                        cout << " Managing Discount !" << endl;
                        a1.ApplyDiscount();
                    }
                    else if (l == 6)
                    {
                        s1.Stu_ViewOrderHistory();

                    }
                    else if (l == 7)
                    {
                        int val = 0;
                        cout << "\t\t\t\t\t___________________________" << endl;
                        cout << "\t\t\t\t\t|  Select From The List   |" << endl;
                        cout << "\t\t\t\t\t|_________________________|" << endl;
                        cout << "\t\t\t\t\t|  1) Update Notification |" << endl;
                        cout << "\t\t\t\t\t|_________________________|" << endl;
                        cout << "\t\t\t\t\t|  2) View Notificaton    |" << endl;
                        cout << "\t\t\t\t\t|_________________________|" << endl;
                        cout << "\t\t\t\t\t|  3) Exit                |" << endl;
                        cout << "\t\t\t\t\t|_________________________|" << endl;
                        cout << endl;
                        cout << "Enter : ";
                        cin >> val;
                        cout << endl;
                        if (val == 1)
                        {
                            UpdateNotification obj_update;
                            obj_update.setTimestamp(time(0) + 1321);
                            obj_update.handle_notification();
                        }
                        else if (val == 2)
                        {
                            DeadlineNotification dead_obj;
                            dead_obj.setTimestamp(time(0) + 32213);
                            dead_obj.handle_notification();
                        }
                        else if (val == 3)
                        {
                            break;
                        }

                    }
                    else if (l == 8)
                    {
                        cout << "------------------------------------------------------------------------------------------------" << endl << endl;
                        cout << " Rating an item !" << endl;
                        int rating_id;
                        int menu_id;
                        int customer_id;
                        int score;
                        string comment;
                        cout << "Enter Rating ID,Menu ID, Customer ID, Score:  ";
                        cin >> rating_id >> menu_id >> customer_id >> score;
                        cout << endl;
                        cout << "Enter comment for Rating: ";
                        getline(cin, comment);
                        Rating r1(rating_id, menu_id, customer_id, score, comment);
                        r1.Rate();
                    }
                    else if (l == 9)
                    {
                        cout << "-----------------------------------------------------------------------------------------------" << endl << endl;
                        cout << " Rating an item !" << endl;

                    }
                    else if (l == 10)
                    {
                        cout << "------------------------------------------------------------------------------------------------" << endl << endl;
                        cout << " Rating an item !" << endl;

                    }
                    else if (l == 11)
                    {
                        cout << "------------------------------------------------------------------------------------------------" << endl << endl;
                        cout << " Rating an item !" << endl;

                    }
                    else if (l == 12)
                    {
                        cout << "------------------------------------------------------------------------------------------------" << endl << endl;
                        cout << " Rating an item !" << endl;

                    }
                    else if (l == 13)
                    {
                        cout << "------------------------------------------------------------------------------------------------" << endl << endl;
                        cout << " Rating an item !" << endl;

                    }
                    else if (l == 14)
                    {
                        exit(0);
                    }
                }
            }
            //STAFF
            else if (u1.get_UserType() == "Staff" || u1.get_UserType() == "staff")
            {
                while (true)
                {
                    cout << endl << endl;
                    cout << "\t\t\t\t\t      CAFE'STAFF MENU           " << endl << endl;
                    cout << "\t\t\t\t\t________________________________" << endl;
                    cout << "\t\t\t\t\t|     Select From The List     |" << endl;
                    cout << "\t\t\t\t\t|______________________________|" << endl;
                    cout << "\t\t\t\t\t|  1:  View Menu               |" << endl;
                    cout << "\t\t\t\t\t|______________________________|" << endl;
                    cout << "\t\t\t\t\t|  2:  Process Order           |" << endl;
                    cout << "\t\t\t\t\t|______________________________|" << endl;
                    cout << "\t\t\t\t\t|  3:  Add Item                |" << endl;
                    cout << "\t\t\t\t\t|______________________________|" << endl;
                    cout << "\t\t\t\t\t|  4:  Remove Item             |" << endl;
                    cout << "\t\t\t\t\t|______________________________|" << endl;
                    cout << "\t\t\t\t\t|  5:  Logout                  |" << endl;
                    cout << "\t\t\t\t\t|______________________________|" << endl;
                    cout << endl << endl;
                    int a;
                    cout << "Enter: ";
                    cin >> a;
                    cin.ignore();
                    cout << endl;
                    if (a == 1)
                    {
                        c1.CafeStaff_ViewMenu();
                    }
                    else if (a == 2)
                    {

                    }
                    else if (a == 3)
                    {
                        c1.AddMenuItem();
                    }
                    else if (a == 4)
                    {
                        c1.RemoveMenultem();
                    }
                    else if (a == 5)
                    {
                        exit(0);
                    }
                }
            }
            else if (u1.get_UserType() == "Stu" || u1.get_UserType() == "Student" || u1.get_UserType() == "student" || u1.get_UserType() == "stu")
            {
                while (true)
                {
                    cout << endl << endl;
                    cout << "\t\t\t\t\t       STUDENT'S MENU           " << endl << endl;
                    cout << "\t\t\t\t\t________________________________" << endl;
                    cout << "\t\t\t\t\t|     Select From The List     |" << endl;
                    cout << "\t\t\t\t\t|______________________________|" << endl;
                    cout << "\t\t\t\t\t|  1:  View Menu               |" << endl;
                    cout << "\t\t\t\t\t|______________________________|" << endl;
                    cout << "\t\t\t\t\t|  2:  Place Order             |" << endl;
                    cout << "\t\t\t\t\t|______________________________|" << endl;
                    cout << "\t\t\t\t\t|  3:  View Order History      |" << endl;
                    cout << "\t\t\t\t\t|______________________________|" << endl;
                    cout << "\t\t\t\t\t|  4:  Logout                  |" << endl;
                    cout << "\t\t\t\t\t|______________________________|" << endl;
                    cout << endl << endl;
                    int stu;
                    cout << "Enter: ";
                    cin >> stu;
                    cin.ignore();
                    cout << endl;
                    if (stu == 1)
                    {
                        s1.Stu_ViewMenu();
                    }
                    else if (stu == 2)
                    {
                        s1.stu_PlaceOrder();
                    }
                    else if (stu == 3)
                    {
                        s1.Stu_ViewOrderHistory();
                    }
                    else if (stu == 4)
                    {
                        exit(0);
                    }

                }

            }


            else if (u1.get_UserType() == "faculty" || u1.get_UserType() == "Faculty" || u1.get_UserType() == "Fac" || u1.get_UserType() == "fac")
            {
                while (true)
                {
                    cout << endl << endl;
                    cout << "\t\t\t\t\t       FACULTY'S MENU           " << endl << endl;
                    cout << "\t\t\t\t\t________________________________" << endl;
                    cout << "\t\t\t\t\t|     Select From The List     |" << endl;
                    cout << "\t\t\t\t\t|______________________________|" << endl;
                    cout << "\t\t\t\t\t|  1:  View Menu               |" << endl;
                    cout << "\t\t\t\t\t|______________________________|" << endl;
                    cout << "\t\t\t\t\t|  2:  Place Order             |" << endl;
                    cout << "\t\t\t\t\t|______________________________|" << endl;
                    cout << "\t\t\t\t\t|  3:  View Order History      |" << endl;
                    cout << "\t\t\t\t\t|______________________________|" << endl;
                    cout << "\t\t\t\t\t|  4:  Logout                  |" << endl;
                    cout << "\t\t\t\t\t|______________________________|" << endl;
                    cout << endl << endl;
                    int fac;
                    cout << "Enter: ";
                    cin >> fac;
                    cin.ignore();
                    cout << endl;
                    if (fac == 1)
                    {
                        f1.fac_ViewMenu();
                    }
                    else if (fac == 2)
                    {
                        f1.fac_PlaceOrder();
                    }
                    else if (fac == 3)
                    {
                        f1.fac_ViewOrderHistory();
                    }
                    else if (fac == 4)
                    {
                        exit(0);
                    }

                }

            }

            else if (u1.get_UserType() == "non-faculty" || u1.get_UserType() == "non-Faculty" || u1.get_UserType() == "n-fac" || u1.get_UserType() == "nfac")
            {
                while (true)
                {
                    cout << endl << endl;
                    cout << "\t\t\t\t\t      NON-FACULTY'S MENU        " << endl << endl;
                    cout << "\t\t\t\t\t________________________________" << endl;
                    cout << "\t\t\t\t\t|     Select From The List     |" << endl;
                    cout << "\t\t\t\t\t|______________________________|" << endl;
                    cout << "\t\t\t\t\t|  1:  View Menu               |" << endl;
                    cout << "\t\t\t\t\t|______________________________|" << endl;
                    cout << "\t\t\t\t\t|  2:  Place Order             |" << endl;
                    cout << "\t\t\t\t\t|______________________________|" << endl;
                    cout << "\t\t\t\t\t|  3:  View Order History      |" << endl;
                    cout << "\t\t\t\t\t|______________________________|" << endl;
                    cout << "\t\t\t\t\t|  4:  Logout                  |" << endl;
                    cout << "\t\t\t\t\t|______________________________|" << endl;
                    cout << endl << endl;
                    int nfac;
                    cout << "Enter: ";
                    cin >> nfac;
                    cin.ignore();
                    cout << endl;
                    if (nfac == 1)
                    {
                        nf1.nfac_ViewMenu();
                    }
                    else if (nfac == 2)
                    {
                        nf1.nfac_PlaceOrder();
                    }
                    else if (nfac == 3)
                    {
                        nf1.nfac_ViewOrderHistory();
                    }
                    else if (nfac == 4)
                    {
                        exit(0);
                    }



                }

            }
        }
        else
        {
            goto l1;
        }
    }
}