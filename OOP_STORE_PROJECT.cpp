#include <iostream>
#include <vector>
#include <map>
#include <conio.h>
#include <iomanip>
using namespace std;

class store {
private:
    //-------------------
    // ADMIN INFO
    //-------------------
    string Admin_Username = "c";
    string Admin_Password = "c";
    //-------------------
    // CUSTOMER INFO
    //-------------------
    map<string, string> Customers;  // map to store username-password pairs
    string Current_Customer;
    //-------------------
    // STOCK INFO
    //-------------------
    vector<string> Product_Name = {"Milk", "Apples", "Mangoes"};
    vector<int> Product_Quantity = {20, 25, 15};
    vector<int> Product_Price = {12, 10, 17};
    //-------------------
    // CART INFO
    //-------------------
    vector<string> Cart_Items_Names;
    vector<int> Cart_Items_Quantity;
    vector<int> Cart_Items_Price;
    //------------------
    // REGISTRATION
    //------------------
    void Admin_Authorization() {
        system("cls");
        string Admin_username, Admin_password;
        cout << "Enter Username: ";
        cin >> Admin_username;
        cout << "Enter Password: ";
        cin >> Admin_password;
        if (Admin_username == Admin_Username && Admin_password == Admin_Password) {
            cout << "login Done." << endl << "Press Any Key To Enter Admin Menu.\n";
            getch();
            Admin_Menu();
        } else {
            cout << "Wrong Info. Access Denied!\nPress.\n1)Try Again\n2)Exit.\n";
            int choice;
            cin >> choice;
            switch (choice) {
                case 1:
                    Admin_Authorization();
                    break;
                case 2:
                    Run();
                    break;
                default:
                    cout << "Invalid Choice.\nPress Any Key To Exit.\n";
                    exit(0);
                    Run();
            }
        }
    }

    void Customer_Registration() {
        system("cls");
        cout << "1)Register.\n2)Login.\n3)Exit.\n";
        int choice;
        cout << "Choose An Option.\n";
        cin >> choice;
        switch (choice) {
            case 1: {
                string username, password;
                cout << "Enter Username: ";
                cin >> username;
                cout << "Enter Password: ";
                cin >> password;
                if (Customers.find(username) == Customers.end()) {
                    Customers[username] = password;
                    system("cls");
                    cout << "Registered Successfully.\nPress Any Key To Return To Login Page.\n";
                } else {
                    cout << "Username already exists. Try again.\n";
                }
                getch();
                Customer_Registration();
                break;
            }
            case 2:
                Customer_Authorization();
                break;
            case 3:
                Run();
                break;
            default:
                cout << "Invalid Option.\nPress Any key To Try Again.\n";
                getch();
                Customer_Registration();
        }
    }

    void Customer_Authorization() {
        system("cls");
        string username, password;
        cout << "Enter Username: ";
        cin >> username;
        cout << "Enter Password: ";
        cin >> password;
        if (Customers.find(username) != Customers.end() && Customers[username] == password) {
            Current_Customer = username;
            system("cls");
            cout << "Login Done." << endl;
            cout << "Press Any Key To View Items." << endl;
            getch();
            system("cls");
            Customer_Menu();
        } else {
            cout << "Invalid credentials.\nPress Any Key To Try Again.\n";
            getch();
            Customer_Registration();
        }
    }
    //------------------
    // ADMIN MENU
    //------------------
    void Admin_Menu() {
        system("cls");
        cout << "=========================================="<<endl;
        cout << "1)Display Stock\n2)Edit Current Stock\n3)Add New Product\n4)Exit\n";
        cout << "==========================================";
        cout<<endl;
        int choice;
        cin >> choice;
        switch (choice) {
            case 1:
                Display_Stock();
                break;
            case 2:
                Edit_Stock();
                break;
            case 3:
                Add_Newproduct();
                break;
            case 4:
                Run();
                break;
            default:
                cout << "Invalid choice!";
                getch();
                Admin_Menu();
        }
    }

    void Display_Stock() {
        system("cls");
        cout << "========================================="<<endl;
        cout <<"|               STOCK ITEMS                |"<<endl;
        cout << "========================================="<<endl;
        cout << setw(5) << left << "No" << setw(20) << left << "Item" << setw(15) << left <<
             "Quantity" << setw(10) << left << "Price" << endl;
        cout << "-----------------------------------------"<<endl;     
        for (size_t i = 0; i < Product_Name.size(); i++) {
            cout << setw(5) << left << i + 1 << setw(20) << left << Product_Name[i] <<
                 setw(15) << left << Product_Quantity[i] << setw(10) << left << Product_Price[i]
                 << endl;
        }
        cout << "==========================================";
        cout << endl;
        cout << "Press Any Key To Return.\n";
        getch();
        system("cls");
        Admin_Menu();
    }

    void Edit_Stock() {
        system("cls");
        cout << "========================================="<<endl;
        cout <<"|               STOCK ITEMS                |"<<endl;
        cout << "========================================="<<endl;
        cout << endl;
        cout << setw(5) << left << "No" << setw(15) << left << "Item"
             << setw(15) << left << "Quantity"
             << setw(10) << left << "Price" << endl;
        cout << "--------------------------------------------" << endl;
        for (size_t i = 0; i < Product_Name.size(); i++) {
            cout << setw(5) << left << i + 1 << setw(15) << left << Product_Name[i]
                 << setw(15) << left << Product_Quantity[i]
                 << fixed << setprecision(2) // Set precision for price
                 << "$" << Product_Price[i] << endl;
        }
        cout << "==========================================";
        cout << endl;
        cout << endl;

        int itemNumber;
        cout << "Enter the number of the item you want to edit: ";
        cin >> itemNumber;

        if (itemNumber < 1 || itemNumber > Product_Name.size()) {
            cout << "Invalid item number!" << endl;
            getch();
            Admin_Menu();
            return;
        }

        itemNumber -= 1; // Adjust for array index

        string Name;
        int Quantity;
        double Price;

        cout << "Enter new name for " << Product_Name[itemNumber] << ": ";
        cin >> Name;
        cout << "Enter new quantity: ";
        cin >> Quantity;
        cout << "Enter new price: $";
        cin >> Price;

        Product_Name[itemNumber] = Name;
        Product_Quantity[itemNumber] = Quantity;
        Product_Price[itemNumber] = Price;
        cout << endl;

        cout << "Stock updated successfully!" << endl;
        getch();
        Admin_Menu();
    }

    void Add_Newproduct() {
        system("cls");
        string Name;
        int Quantity;
        double Price;

        cout << "Enter Product Name: ";
        cin >> Name;
        cin.ignore();
        cout << "Quantity: ";
        cin >> Quantity;
        cin.ignore();
        cout << "Price: $";
        cin >> Price;
        cin.ignore();

        Product_Name.push_back(Name);
        Product_Quantity.push_back(Quantity);
        Product_Price.push_back(Price);
        cout << endl;

        cout << "New stock item added successfully...";
        getch();
        Admin_Menu();
    }
    //-------------------
    // USER MENU
    //-------------------
    void Customer_Menu() {
        char choice;

        system("cls");
        cout << "========================================="<<endl;
        cout <<"|               STOCK ITEMS                |"<<endl;
        cout << "========================================="<<endl;
        cout << endl;
        cout << setw(5) << left << "No" << setw(15) << left << "Item"
             << setw(15) << left << "Quantity"
             << setw(10) << left << "Price" << endl;
        cout << "------------------------------------------" << endl;
        for (size_t i = 0; i < Product_Name.size(); i++) {
            cout << setw(5) << left << i + 1 << setw(15) << left << Product_Name[i]
                 << setw(15) << left << Product_Quantity[i]
                 << fixed << setprecision(2) // Set precision for price
                 << "$" << Product_Price[i] << endl;
        }
        cout << "==========================================";
        cout << endl;
        cout << endl;  //User Menu
        cout << "==========================================";
        cout<<endl;
        cout << "1) Add to cart" << endl;
        cout << "2) View Cart" << endl;
        cout << "3) Logout" << endl;
        cout << "==========================================";
        cout << endl;
        cout << "Choose: ";
        cin >> choice;

        switch (choice) {
            case '1':
                Cart_Manipulation();
                break;
            case '2':
                View_Cart();
                break;
            case '3':
                Run();
                break;
            default:
                cout << "Invalid choice!!!";
                getch();
                Customer_Menu();
                break;
        }
    }

    void Cart_Manipulation() {
        char choice;
        system("cls");
        cout << "STOCK ITEMS" << endl;
        cout << endl;
        cout << setw(5) << left << "No" << setw(15) << left << "Item"
             << setw(15) << left << "Quantity"
             << setw(10) << left << "Price" << endl;
        cout << "--------------------------------------------------" << endl;
        for (size_t i = 0; i < Product_Name.size(); i++) {
            cout << setw(5) << left << i + 1 << setw(15) << left << Product_Name[i]
                 << setw(15) << left << Product_Quantity[i]
                 << fixed << setprecision(2) // Set precision for price
                 << "$" << Product_Price[i] << endl;
        }
        cout << endl;

        do {
            cout << "Press E/e to Exit: \n";
            cout << "Choose No: ";
            cin >> choice;

            int productIndex = choice - '1'; // Convert choice to index

            if (productIndex >= 0 && productIndex < Product_Name.size()) {
                if (Product_Quantity[productIndex] > 0) {
                    bool found = false;
                    for (size_t i = 0; i < Cart_Items_Names.size(); i++) {
                        if (Cart_Items_Names[i] == Product_Name[productIndex]) {
                            found = true;
                            Cart_Items_Quantity[i] += 1;
                            Cart_Items_Price[i] += Product_Price[productIndex];
                            break;
                        }
                    }
                    if (!found) {
                        Cart_Items_Names.push_back(Product_Name[productIndex]);
                        Cart_Items_Quantity.push_back(1);
                        Cart_Items_Price.push_back(Product_Price[productIndex]);
                    }
                    Product_Quantity[productIndex] -= 1;
                } else {
                    cout << "No More Left" << endl;
                    getch();
                }
            } else if (choice == 'e' || choice == 'E') {
                Customer_Menu();
                return;
            } else {
                cout << "Invalid Choice!" << endl;
                getch();
            }
        } while (true);
    }

    void View_Cart() {
        system("cls");
        cout << "========================================="<<endl;
        cout <<"|                   CART                  |"<<endl;
        cout << "========================================="<<endl;
        cout << endl;
        cout << endl;
        cout << setw(5) << left << "No" << setw(15) << left << "Item"
             << setw(15) << left << "Quantity"
             << setw(10) << left << "Cost" << endl;
        cout << "-----------------------------------------"<<endl; 
        for (size_t i = 0; i < Cart_Items_Names.size(); i++) {
            cout << setw(5) << left << i + 1 << setw(15) << left << Cart_Items_Names[i]
                 << setw(15) << left << Cart_Items_Quantity[i]
                 << fixed << setprecision(2) // Set precision for price
                 << "$" << Cart_Items_Price[i] << endl;
        }
        cout << "==========================================";
        double cart_item_total_price = 0;
        for (size_t i = 0; i < Cart_Items_Price.size(); i++) {
            cart_item_total_price += Cart_Items_Price[i];
        }

        cout << endl;
        cout << endl;
        cout << "---------------------------" << endl;
        cout << "Total items: " << Cart_Items_Names.size() << endl;
        cout << "Total Checkout price: $" << cart_item_total_price << endl;
        cout << "---------------------------" << endl;
        cout << endl;
        cout << endl;
        cout << "Press any key to return to User Menu...";
        getch();
        Customer_Menu();
    }

public:
    void Run() {
        system("cls");
        cout << "--------------------------------------------------" << endl;
        cout << "\tWelcome to Store Management System" << endl;
        cout << "--------------------------------------------------" << endl;
        cout << endl;
        cout << "Choose An Option: " << endl;
        cout << "1)Admin." << endl << "2)Customer." << endl << "3)Exit." << endl;
        int choice;
        cout << "Choose An Option:\n";
        cin >> choice;
        switch (choice) {
            case 1:
                Admin_Authorization();
                break;
            case 2:
                Customer_Registration();
                break;
            case 3:
                cout<<"Programme Exited Successfully!"<<endl;
                exit(0);
                
            default:
                system("cls");
                cout << "Invalid Choice.";
                cout<<"Press Any Key Other Than 3 To Return To Login Page."<<endl;
                getch();
                Run();
                break;
        }
    }
};

int main() {
    store S;
    S.Run();
    return 0;
}
