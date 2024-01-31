#include <iostream>
#include <iomanip>
#include <map>

using namespace std;
struct Items {
    string name;
    double price;
    int quantity;
};
map < int, Items > items;

//Welcome words and the menu
void displayMenu() {
    cout << "Welcome, what would you like?" << endl;
    cout << "Menu:" << endl;


    for (const auto& pair : items) {
        cout << setw(2) << pair.first << ". " << setw(2) << pair.second.name << char (156) << pair.second.price;
        if (pair.second.quantity > 0) {
            cout << " (Available: " << pair.second.quantity << ")";
// use online sourse to find information about how to make this line
        }
        cout << endl;
    }
    cout << endl;
}
void vendingMachine() {
    cout << "Please insert money." << endl;
    double money;
    cin >> money;
    while (true) {
        displayMenu();

        cout << "Please enter item code (0 to exit): ";//user selecting what they want by enetring item code (for example "1" for water)

        int choice;
        cin >> choice;

        if (choice == 0) {
            break;
        }

        if (items.find(choice) != items.end() && items[choice].quantity > 0) {
            double itemPrice = items[choice].price;

            if (money >= itemPrice) {
                money -= itemPrice;


                items[choice].quantity--;
                cout << "Dispensing " << items[choice].name << "..." << endl;
                if(items[choice].name == "Water "){
                    cout << "Because you bought " << items[choice].name << "we suggest you buy " << "Candy Bar" << endl;
                }
                else if(items[choice].name == "Chocolate chip cookie "){
                    cout << "Because you bought " << items[choice].name << "we suggest you buy " << "Orange Juice" << endl;
                }
                else if(items[choice].name == "Candy Bar "){
                    cout << "Because you bought " << items[choice].name << "we suggest you buy " << "Water" << endl;
                }
                else if(items[choice].name == "Orange Juice "){
                    cout << "Because you bought " << items[choice].name << "we suggest you buy " << "Chocolate chip cookie" << endl;
                }
                
                
                cout << "Change:" << char (156) << money << endl;
            }
            else {
                cout << "Insufficient funds! Please add more money." << endl;// in case user didn't input enough money, this message will appear
            }
        }
        else {
            cout << "Invalid selection or item out of stock. Try again." << endl;// this code is for situation when user entering invalid item code or the item is out of stock
        }
        cout << endl;
    }

    cout << "Thank you! Enjoy!" << endl;//Thanking user for using vending machine
}



int main() {
    //Items in the vending machine
    items[1] = {"Water ", 1.30, 10};
    items[2] = {"Chocolate chip cookie ", 2.00, 5};
    items[3] = {"Candy Bar ", 1.80, 4};
    items[4] = {"Orange Juice ", 1.55, 7};


    vendingMachine();
    
    return 0;
}






