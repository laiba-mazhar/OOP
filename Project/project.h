//Laiba Mazhar
//i22-1855
//laibamazhar.000@gmail.com
#pragma once
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
using namespace std;
//``````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````
//'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''USER CLASS '''''''''''''''`'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
//``````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````
class user
{
private:
    string name;
    string role;
    int id;
    string password;
public:
    user();
    user(string n, string r, int i);
    void set_UserName(string newName);
    void set_UserType(string newRole);
    void set_UserID(int newId);
    void set_Password(string newPassword);
    string get_UserName() const;
    string get_UserType() const;
    int get_UserID() const;
    string get_Password() const;
    void registration();
    bool login(string username, string pass);
    bool check_reg_password(const string& password);
    string get_Password();
    bool check_UserName(string s);
    //virtual void displayUserType() const;
};



user::user()
{
    name = "";
    role = "";
    id = 0;;
    password = "";

}




//-----------------------------PARAMETERIZED -----------------------------
user::user(string n, string r, int i)
{
    this->name = n;
    this->role = r;
    this->id = i;
}
//-----------------------------SETTERS -----------------------------
void user::set_UserName(string newName)
{
    name = newName;
}
void user::set_UserType(string newRole)
{
    role = newRole;
}

void user::set_UserID(int newId)
{
    id = newId;
}

void user::set_Password(string newPassword)
{
    password = newPassword;
}
//----------------------------- GETTERS -----------------------------
string user::get_UserName() const
{
    return name;
}

string user::get_UserType() const
{
    return role;
}

int user::get_UserID() const
{
    return id;
}

string user::get_Password() const
{
    return password;
}
//----------------------------- CHECKING PASSWORD -----------------------------
bool user::check_reg_password(const string& password)
{
    size_t length = password.length();

    if (length < 6)
    {
        cout << "Enter a password of length 6 or above " << endl << endl;
        return false;
    }
    else
    {
        bool upper_case = false;
        bool lower_case = false;
        bool digits = false;
        bool special = false;

        for (int i = 0; i < length; i++)
        {
            if (password[i] >= 65 && password[i] < 91)
            {
                upper_case = true;
            }

            if (password[i] >= 97 && password[i] <= 122)
            {
                lower_case = true;
            }

            if ((password[i] >= 33 && password[i] <= 47) || (password[i] >= 58 && password[i] <= 64) || (password[i] >= 91 && password[i] <= 96) || (password[i] >= 123 && password[i] <= 126))
            {
                special = true;
            }

            if (password[i] >= 48 && password[i] <= 57)
            {
                digits = true;
            }
        }

        if (upper_case && lower_case && digits && special)
        {
            return true;
        }
        else
        {
            cout << "Password must contain at least one uppercase letter, one lowercase letter, one digit, and one special character." << endl << endl;
            return false;
        }
    }
}

//----------------------------- GET PASSWORD -----------------------------
string user::get_Password()
{
    string password;
    while (true)
    {
        cout << endl;
        cout << "Enter the password             : ";
        getline(cin, password);
        cout << "------------------------------------------------------------------------------------------------" << endl;
        cout << endl;
        if (check_reg_password(password))
        {
            return password;
        }
    }
}
//----------------------------- REGISTRATION  -----------------------------
void user::registration()
{
    ofstream file_user("username.txt");
    if (file_user.is_open())
    {
        file_user << name << endl;
        file_user.close();
    }
    password = get_Password();
    ofstream file_pass("password.txt");
    if (file_pass.is_open())
    {
        file_pass << password << endl;
        file_pass.close();
    }
}
//----------------------------- CHECK USERNAME -----------------------------
bool user::check_UserName(string s)
{
    ifstream file("username.txt");
    if (file.is_open())
    {
        string file_username;
        while (getline(file, file_username))
        {
            if (s == file_username)
            {
                file.close();
                return true;
            }
        }
        file.close();
    }
    else
    {
        cout << "Failed to open the username file." << endl;
    }
    return false;
}

//----------------------------- LOGIN -----------------------------
bool user::login(string username, string pass)
{
    ifstream user_file("username.txt");
    ifstream pass_file("password.txt");
    if (!user_file.is_open() || !pass_file.is_open())
    {
        cout << "\t\t\t\t\tError opening username or password file." << endl;
        return false;
    }

    string file_username, file_password;
    bool found = false;

    while (getline(user_file, file_username) && getline(pass_file, file_password))
    {
        if (username == file_username && pass == file_password)
        {
            cout << endl;
            cout << "\t\t\t\t\tLogin Successful!!" << endl;
            found = true;
            system("cls");
            system("pause");
        }
    }
    user_file.close();
    pass_file.close();
    if (!found)
    {
        cout << endl;
        cout << "\t\t\t\tIncorrect username or password. Login failed :( " << endl;
    }
    return found;
}

string read_pass()
{
    // to add asteriks on terminal while getting input!!
    char check;
    string pwd;
    // an infinite loop
    for (;;)
    {
        check = _getch();
        if (check == '\r')
        {
            // to check if there is enter key
            //present
            // if present, we break the code
            //
            break;
        }
        if (check == '\b')
        {
            // To handle backspaces
            if (!pwd.empty())
            {
                // remove the characters from the string
                pwd.pop_back();
                // remove the last asterik
                cout << "\b \b" << endl;
            }
        }
        else
        {
            // using push functionality to add
            // some more characters to the
            // pwd string
            pwd.push_back(check);
            // displaying asteriks 
            cout << '*';
        }
    }
    // returning password 
    // to be displayed
    return pwd;
}
//``````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````
//''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''MENUITEM CLASS'''''`'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
//``````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````

class MenuItem
{
private:
public:
    int ItemID;
    string Item_Name;
    string Item_Description;
    float Price;
    int QuantityInStock;
    //--------------------------- MENU ITEM CONSTRUCTOR ----------------------------
    MenuItem()
    {
        ItemID = 0;
        Item_Name = "";
        Item_Description = "";
        Price = 0;
        QuantityInStock = 0;
    }
    //--------------------------- UPDATE STOCK -----------------------------
    void updatestock(int new_quantity, int menuIndex)
    {
        QuantityInStock += new_quantity;

        string fileName = "menu" + to_string(menuIndex + 1) + ".txt";
        fstream menufile(fileName, ios::in | ios::out);
        if (menufile.is_open())
        {
            // Finding  the position to update based on ItemID
            while (menufile >> ItemID >> Item_Name >> Item_Description >> Price >> QuantityInStock)
            {
                if (menufile.eof())
                    break;

                if (ItemID == this->ItemID)
                {
                    menufile.seekp(menufile.tellg() - streamoff(1), ios::beg);
                    menufile << ItemID << " " << Item_Name << " " << Item_Description << " " << Price << " " << QuantityInStock << endl;
                    break;
                }
            }
            menufile.close();
        }
        else
        {
            cout << "Unable to open menu file for updating." << endl;
        }
    }
};







//``````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````
//''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''`'''PAYEMENT CLASS'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
//````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````
class Payment
{
private:
    int PaymentID;
    int OrderID;
    int Amount;
    bool PaymentStatus;
public:
    Payment()
    {
        PaymentID = 0;
        OrderID = 0;
        Amount = 0;
        PaymentStatus = false;
    }
    Payment(int orderID, int amount);
    void ProcessPayment();
    friend ostream& operator<<(ostream& output, const Payment& pay);
};

Payment::Payment(int orderID, int amount)
{
    PaymentID = 0;
    OrderID = orderID;
    Amount = amount;
    PaymentStatus = false;
}

void Payment::ProcessPayment()
{
    PaymentStatus = 1;
    cout << "Processing payment for Order ID " << OrderID << "..." << endl;

    cout << "Payment processing, please wait..." << endl;

    this_thread::sleep_for(chrono::seconds(2));

    cout << "Payment processed successfully!" << endl;
}



ostream& operator<<(ostream& output, const Payment& pay)
{
    output << pay.OrderID << " " << pay.PaymentID << " " << pay.Amount << " " << pay.PaymentStatus;
    return output;
}











//````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````
//''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''`'''ORDER CLASS'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
//``````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````
class Order
{
private:
    int OrderID;
    int CustomerID;
    int itemCount;
    float TotalPrice;
    string OrderStatus;
    MenuItem* ItemsOrdered;  // Array to store ordered items (COMPOSITION)
public:
    Order();
    Order(int orderID, int customerID);
    int get_orderID() const;
    int getCustomerID() const;
    int getItemCount() const;
    const string& getOrderStatus() const;
    MenuItem* getItemsOrdered() const;
    void setItemsOrdered(MenuItem* itemsOrdered);
    void AddItem(const MenuItem& menuItem);
    void RemoveItem(int itemID);
    float CalculateTotal();
    void ConfirmOrder();
    //void CancelOrder();
    ~Order();
    friend ostream& operator<<(ostream& output, Order& order);
};

Order::Order()
{
    OrderID = 0;
    CustomerID = 0;
    itemCount = 0;
    TotalPrice = 0.0;
    OrderStatus = "";
}
Order::Order(int orderID, int customerID)
{
    this->OrderID = orderID;
    this->CustomerID = customerID;
    this->ItemsOrdered = nullptr;
    itemCount = 0;
    TotalPrice = 0.0;
    OrderStatus = "Pending";
    ItemsOrdered = new MenuItem[50];
}
int Order::get_orderID() const
{
    return OrderID;
}

int Order::getCustomerID() const
{
    return CustomerID;
}

int Order::getItemCount() const {
    return itemCount;
}

const string& Order::getOrderStatus() const {
    return OrderStatus;
}
MenuItem* Order::getItemsOrdered() const {
    return ItemsOrdered;
}

void Order::setItemsOrdered(MenuItem* itemsOrdered)
{
    ItemsOrdered = itemsOrdered;
}
void Order::AddItem(const MenuItem& menuItem)
{
    if (itemCount < 50)
    {
        ItemsOrdered[itemCount++] = menuItem;
        TotalPrice += menuItem.Price; // Assuming Price is a member variable in MenuItem
        cout << "Item added to the order." << endl;
    }
    else
    {
        cout << "Cannot add more items to the order. Limit reached." << endl;
    }
}
void Order::RemoveItem(int itemID)
{
    int index = -1;
    for (int i = 0; i < itemCount; ++i)
    {
        if (ItemsOrdered[i].ItemID == itemID)
        {
            index = i;
            break;
        }
    }

    if (index != -1)
    {
        for (int i = index; i < itemCount - 1; ++i)
        {
            ItemsOrdered[i] = ItemsOrdered[i + 1];
        }
        --itemCount;
        TotalPrice -= ItemsOrdered[index].Price; // Assuming Price is a member variable in MenuItem
        cout << "Item removed from the order." << endl;
    }
    else
    {
        cout << "Item with ItemID " << itemID << " not found in the order." << endl;
    }
}

float Order::CalculateTotal()
{
    return TotalPrice;
}

void Order::ConfirmOrder()
{
    if (itemCount == 0)
    {
        cout << "Cannot confirm an empty order." << endl;
        return;
    }
    OrderStatus = "Confirmed";

    cout << "Order confirmed successfully." << endl;
    cout << "Order ID     : " << OrderID << endl;
    cout << "Items Ordered" << endl;
    for (int i = 0; i < itemCount; ++i)
    {
        cout << "  " << ItemsOrdered[i].Item_Name << " - PKR" << ItemsOrdered[i].Price << endl;
    }


    cout << "Total Price : PKR " << CalculateTotal() << endl;
    cout << "Order Status: " << OrderStatus << endl;


    Payment p1(OrderID, static_cast<int>(CalculateTotal()));
    p1.ProcessPayment();

}

Order::~Order()
{
    delete[] ItemsOrdered;
}

ostream& operator<<(ostream& output, Order& order)
{
    output << "Order ID   : " << order.get_orderID() << endl;
    output << "Customer ID: " << order.getCustomerID() << endl;
    output << "Item Count : " << order.getItemCount() << endl;
    output << "Total Price: " << order.CalculateTotal() << endl;
    output << "Order Status: " << order.getOrderStatus() << endl;

    const MenuItem* itemsOrdered = order.getItemsOrdered();
    for (int i = 0; i < order.getItemCount(); ++i)
    {
        output << "Item " << i + 1 << ": " << itemsOrdered[i].Item_Name << " - PKR" << itemsOrdered[i].Price << endl;
    }

    output << endl; // Separate entries with a newline

    return output;
}

class Order;
//``````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````
//''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''FILEMANAGER CLASS''''`'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
//``````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````
class FileManager
{
public:



    void  SavePaymentToFile(Payment bill)
    {
        ofstream paymentfile("payment.txt", ios::app);
        if (paymentfile.is_open())
        {
            paymentfile << bill << endl;
            paymentfile.close();
            cout << " Your ratings for the order has been stored successfully! " << endl;
        }
        else
        {
            cout << " Sorry, data can not be stored :( " << endl;
            cout << "Unable to fetch the file! " << endl;
        }
    }
    void SaveOrderToFile(Order& o1)
    {
        ofstream file_order("orders.txt", ios::app);
        if (file_order.is_open())
        {
            file_order << o1;           // Use the operator<< to write the order information
            file_order.close();
            cout << "Your order has been saved to the file!" << endl;
        }
        else
        {
            cout << "Sorry, data cannot be stored :(" << endl;
        }
    }


    //---------------------------  SAVE FILE -----------------------------
    void SaveMenultemToFile(const MenuItem& m, int menuIndex, string filename)
    {
        static bool headingsPrinted[] = { false, false, false }; // One flag for each menu

        filename = "menu" + to_string(menuIndex + 1) + ".txt"; // Adjust to 1-based index for file name

        ofstream menufile(filename, ios::app);

        if (menufile.is_open())
        {
            if (!headingsPrinted[menuIndex])
            {
                menufile << setw(8) << "Item ID" << setw(20) << "Item Name" << setw(30) << "Item Description"
                    << setw(15) << "Item Price" << setw(15) << "Item Quantity" << endl;

                headingsPrinted[menuIndex] = true;
            }
            menufile << setw(8) << m.ItemID << setw(20) << m.Item_Name << setw(30) << m.Item_Description
                << setw(15) << m.Price << setw(15) << m.QuantityInStock << endl
                << endl;

            menufile.close();
        }
        else
        {
            cout << "Sorry, data cannot be stored :(" << endl;
        }
    }

    //--------------------------- LOAD FILE  -----------------------------
    void LoadMenuFromFile(MenuItem* menuItems, int& itemCount, int menuIndex)
    {
        ifstream menufile("menu" + to_string(menuIndex + 1) + ".txt"); // Adjust to 1-based index for file name
        if (menufile.is_open())
        {
            while (menufile >> menuItems[itemCount].ItemID >> menuItems[itemCount].Item_Name >>
                menuItems[itemCount].Item_Description >> menuItems[itemCount].Price >> menuItems[itemCount].QuantityInStock)
            {
                itemCount++;
            }
            menufile.close();
        }
        else
        {
            cout << "Unable to open menu file." << endl;
        }
    }
    //--------------------------- UPDATE FILE  -----------------------------
    void UpdateMenuFile(MenuItem* menuItems, int itemCount, int menuIndex)
    {
        string filename = "menu" + to_string(menuIndex + 1) + ".txt"; // Adjust to 1 index for file name

        ofstream menufile(filename);

        if (menufile.is_open())
        {
            for (int i = 0; i < itemCount; i++)
            {
                menufile << setw(8) << "Item ID" << setw(20) << "Item Name" << setw(30) << "Item Description"
                    << setw(15) << "Item Price" << setw(15) << "Item Quantity" << endl;

                menufile << setw(8) << menuItems[i].ItemID << setw(20) << menuItems[i].Item_Name
                    << setw(30) << menuItems[i].Item_Description << setw(15) << menuItems[i].Price
                    << setw(15) << menuItems[i].QuantityInStock << endl;
            }

            menufile.close();
        }
        else
        {
            cout << "Unable to open menu file for updating." << endl;
        }
    }
};












//``````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````
//'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''ADMINISTRATOR CLASS'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
//``````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````
class Administrator :public user, public MenuItem, public FileManager
{
private:

    FileManager fileManager;
    int itemCounts[3];  // An array for each menu
    const int maxMenuItems = 50;
    MenuItem* menus[3];

public:
    Administrator()
    {
        for (int i = 0; i < 3; i++)
        {
            itemCounts[i] = 0;
            menus[i] = new MenuItem[maxMenuItems];
        }
    }
    Administrator(int userID, const string& userName)
        : user(userName, "Administrator", userID)
    {
        for (int i = 0; i < 3; ++i)
        {
            menus[i] = new MenuItem[maxMenuItems];
            itemCounts[i] = 0;
        }
    }

    //--------------------------- VIEW MENU  -----------------------------
    void ViewMenu(int menuIndex)
    {
        cout << endl;
        cout << "------------------------------------------------------------------------------------------------" << endl;
        cout << "Enter the menu number you want to display: ";
        cin >> menuIndex;
        cin.ignore();
        cout << endl << endl;
        if (menuIndex == 1)
        {
            ifstream f1("menu2.txt");
            if (f1.is_open())
            {
                if (f1.peek() == ifstream::traits_type::eof())
                {
                    cout << "No items to display. The menu is empty." << endl;
                }
                else
                {
                    string line;
                    while (getline(f1, line))
                    {
                        cout << line << endl;
                    }
                }
                f1.close();
            }
            else
            {
                cout << "Unable to open menu file." << endl;
            }
        }
        if (menuIndex == 2)
        {
            ifstream f1("menu3.txt");
            if (f1.is_open())
            {
                if (f1.peek() == ifstream::traits_type::eof())
                {
                    cout << "No items to display. The menu is empty." << endl;
                }
                else
                {
                    string line;
                    while (getline(f1, line))
                    {
                        cout << line << endl;
                    }
                }
                f1.close();
            }
            else
            {
                cout << "Unable to open menu file." << endl;
            }
        }

        if (menuIndex == 3)
        {
            ifstream f1("menu4.txt");
            if (f1.is_open())
            {
                if (f1.peek() == ifstream::traits_type::eof())
                {
                    cout << "No items to display. The menu is empty." << endl;
                }
                else
                {
                    string line;
                    while (getline(f1, line))
                    {
                        cout << line << endl;
                    }
                }
                f1.close();
            }
            else
            {
                cout << "Unable to open menu file." << endl;
            }
        }
    }

    //--------------------------- ADD ITEM -----------------------------
    void add_item()
    {
        cout << "Select a menu to add an item to:" << endl;
        for (int i = 0; i < 3; ++i)
        {
            cout << i + 1 << ". Menu " << i + 1 << endl;
        }
        cout << endl;
        int selectedMenu;
        cout << "Enter the menu number: ";
        if (!(cin >> selectedMenu) || selectedMenu < 1 || selectedMenu > 3)
        {
            cout << "Invalid input. Please enter a valid menu number." << endl;
            return;
        }
        int menu_index = selectedMenu - 1;
        if (itemCounts[menu_index] < maxMenuItems)
        {
            MenuItem m1;

            cout << "Enter ItemID (Numerical only)    : ";
            cin >> m1.ItemID;
            cin.ignore();

            cout << "Enter Item Name                  : ";
            getline(cin, m1.Item_Name);

            cout << "Enter Item Description           : ";
            getline(cin, m1.Item_Description);

            cout << "Enter Item Price (Numerical only): ";
            cin >> m1.Price;

            cout << "Enter Quantity in Stock          : ";
            cin >> m1.QuantityInStock;
            menus[menu_index][itemCounts[menu_index]++] = m1;
            string fileName = "menu" + to_string(menu_index + 1) + ".txt";
            fileManager.SaveMenultemToFile(m1, menu_index + 1, fileName);
            cout << "Menu item added successfully to Menu " << menu_index + 1 << "!" << endl;
            menus[menu_index][itemCounts[menu_index] - 1].updatestock(m1.QuantityInStock, menu_index);
            fileManager.UpdateMenuFile(menus[menu_index], itemCounts[menu_index], menu_index + 1);
        }
        else
        {
            cout << "Cannot add more menu items. Limit reached for Menu " << menu_index + 1 << "." << endl;
        }
    }
    //--------------------------- REMOVE ITEM -----------------------------
    void remove_item()
    {
        int menu_index;
        cout << "Select a menu to you want to remove an item from :" << endl;
        cout << "1. Menu 1" << endl;
        cout << "2. Menu 2" << endl;
        cout << "3. Menu 3" << endl;
        cout << endl;
        cout << "Enter:  ";
        cin >> menu_index;
        cin.ignore();
        cout << endl;
        if (menu_index < 1 || menu_index > 3)
        {
            cout << "Invalid menu index. Please enter a valid index." << endl;
            return;
        }

        int itemID;
        cout << "Enter the ItemID of the menu item to remove: ";
        cin >> itemID;

        int index = -1;
        for (int i = 0; i < itemCounts[menu_index - 1]; ++i)
        {
            if (menus[menu_index - 1][i].ItemID == itemID)
            {
                index = i;
                break;
            }
        }
        if (index != -1)
        {
            // Shift elements to fill the removed item's place
            for (int i = index; i < itemCounts[menu_index - 1] - 1; ++i)
            {
                menus[menu_index - 1][i] = menus[menu_index - 1][i + 1];
            }
            --itemCounts[menu_index - 1];
            fileManager.UpdateMenuFile(menus[menu_index - 1], itemCounts[menu_index - 1], menu_index);

            cout << "Menu item removed successfully from menu " << menu_index << endl;
        }
        else
        {
            cout << "Menu item with ItemID " << itemID << " not found in menu " << menu_index << endl;
        }
    }
    // --------------------------- MANAGE INVENTARY -----------------------------
    void ManageInventory()
    {
        int menu_index;
        cout << "Select a menu to update inventory:" << endl;
        cout << "1. Menu 1" << endl;
        cout << "2. Menu 2" << endl;
        cout << "3. Menu 3" << endl;
        cout << endl;
        cout << "Enter: ";
        cin >> menu_index;
        cin.ignore();
        cout << endl;

        if (menu_index < 1 || menu_index > 3)
        {
            cout << "Invalid menu index. Please enter a valid index." << endl;
            return;
        }

        int itemID;
        cout << "Enter the ItemID of the menu item to update: ";
        cin >> itemID;

        int index = -1;
        for (int i = 0; i < itemCounts[menu_index - 1]; ++i)
        {
            if (menus[menu_index - 1][i].ItemID == itemID)
            {
                index = i;
                break;
            }
        }

        if (index != -1)
        {
            int newQuantity;
            cout << "Enter the new Quantity in Stock: ";

            if (!(cin >> newQuantity))
            {
                cout << "Invalid input for new Quantity. Please enter a numeric value." << endl;
                return;
            }
            menus[menu_index - 1][index].QuantityInStock = newQuantity;
            cout << "Updated Quantity in Stock: " << menus[menu_index - 1][index].QuantityInStock << endl;
            // Save the updated menu to the file
            UpdateMenuFile(menus[menu_index - 1], itemCounts[menu_index - 1], menu_index);
            cout << "Inventory updated successfully for Menu " << menu_index << "!" << endl;
        }
        else
        {
            cout << "Menu item with ItemID " << itemID << " not found in menu " << menu_index << endl;
        }
    }
    //--------------------------- DISCOUNTS -----------------------------
    void ApplyDiscount()
    {
        int menuIndex;
        cout << "Enter the menu number: ";
        cin >> menuIndex;

        if (menuIndex < 1 || menuIndex > 3)
        {
            cout << "Invalid menu index. Please enter a valid index." << endl;
            return;
        }

        int itemID;
        cout << "Enter the ItemID of the menu item to apply discount: ";
        cin >> itemID;

        int index = -1;
        for (int i = 0; i < itemCounts[menuIndex - 1]; ++i)
        {
            if (menus[menuIndex - 1][i].ItemID == itemID)
            {
                index = i;
                break;
            }
        }

        if (index != -1)
        {
            double discountPercentage;
            cout << "Enter the discount percentage: ";

            while (!(cin >> discountPercentage) || discountPercentage < 0 || discountPercentage > 100)
            {
                cout << "Invalid input. Please enter a valid discount percentage: ";
                cin.clear();
                while (cin.get() != '\n');
            }

            // yaha pr calculating  discounted price
            double discountedPrice = menus[menuIndex - 1][index].Price * (1.0 - discountPercentage / 100.0);

            // Updating the price of the menu item
            menus[menuIndex - 1][index].Price = discountedPrice;

            // Save the updated menu to the file
            UpdateMenuFile(menus[menuIndex - 1], itemCounts[menuIndex - 1], menuIndex);

            cout << "Discount applied successfully for Menu " << menuIndex << ", ItemID " << itemID << "!" << endl;
        }
        else
        {
            cout << "Menu item with ItemID " << itemID << " not found in menu " << menuIndex << endl;
        }
    }
    int getItemCount(int menuIndex) const
    {
        return itemCounts[menuIndex];
    }

    // Add a getter for menus

    const MenuItem* getMenu(int men) const
    {
        return menus[1];
    }

    const MenuItem* getMenu(int menuIndex)
    {
        if (menuIndex >= 1 && menuIndex <= 3)
        {
            // Perform any necessary update here before returning the menu

            // Example: Assume you want to update the menu by reading from the file
            string fileName = "menu" + to_string(menuIndex) + ".txt";
            fileManager.LoadMenuFromFile(menus[menuIndex - 1], itemCounts[menuIndex - 1], 1);

            // Return the updated menu
            return menus[menuIndex - 1];
        }
        else
        {
            // Return a valid default or handle the out-of-range case accordingly

        }
    }

    ~Administrator()
    {
        for (int i = 0; i < 3; ++i)
        {
            delete[] menus[i];
        }
    }
};










//``````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````
//''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''`'''CAFE STAFF CLASS'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
//````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````
class Cafestaff : public Administrator  //Have access to all the menus.Can edit and view all menus
{
private:
    Order* curr_order;
    Order o1[1000];
public:
    Cafestaff()
    {
        curr_order = nullptr;
        for (int i = 0; i < 1000; i++)
        {
            o1[i] = Order(i + 1, 0);
        }
    }
    void Cafe_ProcessPayment()
    {
        int orderID;
        cout << "Enter the Order ID for which you want to process payment: ";
        cin >> orderID;
        cin.ignore();

        // Assuming you have a function to retrieve the order based on the orderID
        curr_order = get_order_by_id(orderID);

        if (curr_order != nullptr)
        {
            Payment payment(curr_order->get_orderID(), static_cast<int>(curr_order->CalculateTotal()));
            payment.ProcessPayment();
            curr_order->ConfirmOrder();
        }
        else
        {
            cout << "Order not found for Order ID " << orderID << "." << endl;
        }
    }

    void CafeStaff_ViewMenu()
    {
        int menu_type;
        cout << " Which menu do you want to view ? " << endl;
        cout << " [1]. STUDENTS" << endl;
        cout << " [2]. FACULTY" << endl;
        cout << " [3]. NON - FACULTY" << endl;
        cout << "Enter: ";
        cin >> menu_type;
        cin.ignore();
        Administrator::ViewMenu(menu_type);
    }
    Order* getCurrentOrder() const
    {
        return curr_order;
    }
    Order* get_order_by_id(int orderID)
    {
        for (int i = 0; i < 100; ++i)
        {
            if (o1[i].get_orderID() == orderID)
            {
                return &o1[i];
            }
        }
        return nullptr;  // Return nullptr if order not found
    }

    void AddMenuItem()
    {
        Administrator::add_item();
    }

    void RemoveMenultem()
    {
        Administrator::remove_item();
    }

    bool Logout()
    {
        return true;
    }
};








//````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````
//``````````````````````````````````````````` CUSTOMER INCLUDES (STUDENTS CLASS,FACULTY CLASS, NON-FACULTY CLASS)`````````````````````````````````````````````````````
//````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````



//````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````
//'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''STUDENTS''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''`'
//````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````
class Student : public user, public Administrator, public MenuItem
{
    Order o1;
public:
    Student() {}

    void Stu_ViewMenu()
    {
        Administrator::ViewMenu(1);
    }
    void stu_PlaceOrder()
    {
        Stu_ViewMenu();
        cout << endl;
        int p;
        cout << "Enter ItemID of the Item You want to place: ";
        cin >> p;
        cin.ignore();
        cout << endl;
        ifstream menuFile("menu2.txt");
        ofstream orderFile("order_stu.txt", ios::app);
        cout << "Item Found in the menu " << endl << endl;
        if (menuFile.is_open() && orderFile.is_open())
        {
            orderFile << menuFile.rdbuf();
            menuFile.close();
            orderFile.close();

            cout << "Order placed successfully" << endl;
        }
        else
        {
            cout << "Unable to open." << endl;
        }
    }

    void Stu_ViewOrderHistory()
    {
        ifstream orderFile("order.txt");

        if (orderFile.is_open())
        {

            cout << orderFile.rdbuf() << endl;

            orderFile.close();
        }
        else
        {
            cout << "Unable to open order.txt for viewing order history." << endl;
        }
    }
    /*  void displayUserType() const override
      {
          cout << "User Type: Student" << endl;
      }*/

};














//````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````
//''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''FACULTY''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''`'
//````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````
class Faculty : public user, public Administrator, public MenuItem
{
    Order o1;
public:
    Faculty() {}
    void fac_ViewMenu()
    {
        int laiba_menu;
        cout << "Which menu you want to select (Student Menu(1)/Faculty Menu(2))? ";
        cin >> laiba_menu;
        cin.ignore();
        Administrator::ViewMenu(laiba_menu);
    }

    void fac_PlaceOrder()
    {
        fac_ViewMenu();
        cout << endl;
        int p;
        cout << "Enter ItemID of the Item You want to place: ";
        cin >> p;
        cin.ignore();
        cout << endl;
        ifstream menuFile("menu3.txt");
        ofstream orderFile("order_fac.txt", ios::app);
        cout << "Item Found in the menu " << endl << endl;
        if (menuFile.is_open() && orderFile.is_open())
        {
            orderFile << menuFile.rdbuf();
            menuFile.close();
            orderFile.close();

            cout << "Order placed successfully" << endl;
        }
        else
        {
            cout << "Unable to open." << endl;
        }
    }

    void fac_ViewOrderHistory()
    {
        ifstream orderFile("order_fac.txt");
        if (orderFile.is_open())
        {

            cout << orderFile.rdbuf() << endl;

            orderFile.close();
        }
        else
        {
            cout << "Unable to open." << endl;
        }
    }
    /*  void displayUserType() const override
      {
          cout << "User Type: Faculty" << endl;
      }*/


};














//````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````
//''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''NON-FACULTY''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''`'
//````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````
class non_faculty : public user, public Administrator
{
    Order o1;
public:
    non_faculty() {}
    void nfac_ViewMenu()
    {
        Administrator::ViewMenu(3);
    }
    void nfac_PlaceOrder()
    {
        nfac_ViewMenu();
        cout << endl;
        int p;
        cout << "Enter ItemID of the Item You want to place: ";
        cin >> p;
        cin.ignore();
        cout << endl;
        ifstream menuFile("menu4.txt");
        ofstream orderFile("order_fac.txt", ios::app);
        cout << "Item Found in the menu " << endl << endl;
        if (menuFile.is_open() && orderFile.is_open())
        {
            orderFile << menuFile.rdbuf();
            menuFile.close();
            orderFile.close();

            cout << "Order placed successfully" << endl;
        }
        else
        {
            cout << "Unable to open." << endl;
        }
    }

    void nfac_ViewOrderHistory()
    {
        ifstream orderFile("order_nfav.txt");
        if (orderFile.is_open())
        {

            cout << orderFile.rdbuf() << endl;

            orderFile.close();
        }
        else
        {
            cout << "Unable to open." << endl;
        }
    }
    /*  void displayUserType() const override
      {
          cout << "User Type: Non-Faculty" << endl;
      }*/

};











//````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````
//'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''NOTIFICATION CLASS'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''`'
//````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````
class Notification
{
private:
    string type;
    time_t timestamp;
    bool is_Delivered;
public:
    Notification(string notificationType);
    const time_t getTimestamp() const;
    void setTimestamp(time_t new_time);
    bool getIsDelivered() const;
    void setIsDelivered(bool new_del);
    virtual void handle_notification() = 0;
    virtual ~Notification() = default;
};
Notification::Notification(string notificationType) : type(notificationType), timestamp(0), is_Delivered(false) {}
const time_t Notification::getTimestamp() const
{
    return timestamp;
}
void Notification::setTimestamp(time_t new_time)
{
    timestamp = new_time;
}
bool Notification::getIsDelivered() const
{
    return is_Delivered;
}
void Notification::setIsDelivered(bool new_del)
{
    is_Delivered = new_del;
}












//````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````
//''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''UPDATE NOTIFICATION CLASS'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''`'
//````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````
class UpdateNotification : public Notification
{
public:
    UpdateNotification();
    void handle_notification() override;
};

UpdateNotification::UpdateNotification() : Notification("Update.txt") {}
void UpdateNotification::handle_notification()
{


    ofstream update("update.txt");
    if (update.is_open())
    {
        string data;
        cout << "Enter the notification you want to update: ";
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear input buffer
        getline(cin, data);

        cout << endl;
        update << "This is an update notification.\n";
        update << "Timestamp: " << getTimestamp() << "\n";
        update << "Updated Notification: " << data << endl;
        update.close();
    }
}














//````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````
//'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''DEADLINE  NOTIFICATION CLASS''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''`'
//````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````
class DeadlineNotification : public Notification
{
public:
    DeadlineNotification();
    void handle_notification() override;
};

DeadlineNotification::DeadlineNotification() : Notification("Notification.txt") {}

void DeadlineNotification::handle_notification()
{
    ifstream notification("notification.txt");
    if (notification.is_open())
    {
        string content;
        while (getline(notification, content))
        {

            cout << content << endl;
        }
        notification.close();
    }
    else
    {
        cout << "Unable to open notification file." << endl;
    }
}















//````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````
//'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''``````````````''''''RATING  CLASS''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''`'
//````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````

class Rating {
private:
    int RatingID;
    int MenultemID;
    int CustomerID;
    int Score;
    string Comment;

public:
    Rating();
    Rating(int Rating_ID, int MenuItem_ID, int Customer_ID, int score, const string& comment);
    void Rate();  
    friend ostream& operator<<(ostream& os, const Rating& rate);
};

Rating::Rating() {}

Rating::Rating(int Rating_ID, int MenuItem_ID, int Customer_ID, int score, const string& comment)
    : RatingID(Rating_ID), MenultemID(MenuItem_ID), CustomerID(Customer_ID), Score(score), Comment(comment) {}

void Rating::Rate() 
{
    // Save the rating to a file
    ofstream outFile("ratings.txt", ios::app);
    if (outFile.is_open()) {
        outFile << *this << endl;
        outFile.close();
        cout << "Rating saved to file successfully." << endl;
    }
    else {
        cerr << "Unable to open file for saving rating." << endl;
    }
}

ostream& operator<<(ostream& os, const Rating& rate) {
    os << rate.RatingID << " " << rate.MenultemID << " " << rate.CustomerID << " " << rate.Score << " \"" << rate.Comment << "\"";
    return os;
}












