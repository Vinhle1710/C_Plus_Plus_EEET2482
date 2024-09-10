#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Product{
    private:
        string productName;
        float price;
    public:
        Product(string name, float price):productName(name), price(price) {}
        void showInfo(){
            cout << "\tName: " << productName << "\n\tPrice: " << price << endl;
        }

        float getPrice(){
            return price;
        }

};

class Shop {
    private:
        string shopName;
        vector<Product> prodList;
    public:
        Shop(string name, vector<Product> product):shopName(name), prodList(product){}

        void showInfo() {
            cout << "\nShop: " << shopName << endl;
            cout << "-------------------\n";
            int counter = 1;
            for (Product prod : prodList){
                cout << "Product "<< counter << ": \n";
                prod.showInfo();
                counter++;
            }
            cout << endl;
        }
};

class Order {
    private:
    int orderID;
    vector<Product> orderedList;
    float totalPrice;

    public:
    Order(int ID, vector<Product> list, float totalPrice) : orderID(ID), orderedList(list), totalPrice(totalPrice){}

    void showInfo() {
        cout << "Order ID: " << orderID << endl;
        cout << "Bought items: " << endl;
        
        int counter = 1;
        for (Product prod : orderedList) {
            cout << "Product " << counter << ": \n";
            prod.showInfo();
            
            counter++;
        }

        cout << "Total price: " << totalPrice << endl;
        cout << endl;
    }
};

class Customer {
    private:
    string customerName;
    vector<Order> orderList;
    bool isGoldMember = false; // false for normal account, true for gold member account

    public:
    Customer(string customerName, bool accType) : customerName(customerName), isGoldMember(accType){}
    
    void buyProduct(vector<Product> prodList) {
        double totalPrice = 0;
        for (Product prod : prodList) {
            if (isGoldMember) {
                totalPrice += prod.getPrice() - prod.getPrice() * 5 / 100;
            } else {
                totalPrice += prod.getPrice();
            }
        }

        int orderID = orderList.size() + 1;
        orderList.push_back(Order(orderID, prodList, totalPrice));
    }

    void showInfo(){
        cout << "Customer: " << customerName << endl;
        cout << "Account Type: ";
        if (isGoldMember)
        {
            cout << "Gold Member\n";
        } else {
            cout << "Normal Account\n";
        }
         
        cout << "------------------------\n";

        int counter = 1;
        
        for (Order ord  : orderList) {
            cout << "Order " << counter << ": " << endl;
            ord.showInfo();
            counter++;
        }

    }

};

int main() {
    Product p1("Hot Wheels", 1), p2("MiniGT", 10), p3("HotWheels Premium", 5), p4("Tarmac Works", 12);
    Shop s1("DucStore", {p1, p2, p3, p4});
    Customer c1("Vinh", true), c2("Phuong", false);

    s1.showInfo();

    c1.buyProduct({p1, p2});
    c2.buyProduct({p1, p4});
    c1.showInfo();
    c2.showInfo();

}