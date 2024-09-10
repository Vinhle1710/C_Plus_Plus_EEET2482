#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Product {
    private:
    string prodName;
    float prodPrice;

    public:
    Product(string name, float price) : prodName(name), prodPrice(price) {}

    void showInfo(){
        cout << "   Product Name: " << prodName << endl;
        cout << "   Price: $" << prodPrice << endl;
    }

    float getPrice(){
        return prodPrice;
    }
};

class Shop {
    private:
    string shopName;
    vector<Product> productList;

    public:
    Shop(string name, vector<Product> productList) : shopName(name), productList(productList) {}

    void showInfo(){
        cout << "Shop Name: " << shopName << endl;
        cout << "------------------------\n";

        int counter = 1;
        for (Product prod : productList) {
            cout << "Product #" << counter << ":\n";
            prod.showInfo();
            counter++;
        }
    }
};

class Order {
    private:
    int id;
    vector<Product> boughtList;
    float totalPrice;

    public:
    Order(int id, vector<Product> boughtList, float totalPrice) : id(id), boughtList(boughtList), totalPrice(totalPrice){}

    void showInfo(){
        cout << "Order ID: " << id <<endl;
        cout << "------------------------\n";

        int counter = 1;
        for (Product prod : boughtList){
            cout << "Product #"<< counter << ": \n";
            prod.showInfo();
            counter++;
        }
        cout << "Total price: $" << totalPrice <<endl;
        cout << endl;
    }
};

class Customer{
    private:
    string name;
    bool isGoldMember = false;
    vector<Order> ord;

    public:
    Customer(string name, bool isGoldMember = false) : name(name), isGoldMember(isGoldMember) {}

    void buyProd(vector<Product> prodList){
        float totalPrice = 0;
        for (Product prod : prodList){
            if (isGoldMember)
            {
                totalPrice += prod.getPrice() * (1 - 0.05);
            } else {
                totalPrice += prod.getPrice();
            }
        }
        int orderId = ord.size() + 1;
        ord.push_back(Order(orderId, prodList, totalPrice));
    }

    void showInfo(){
        cout << "Customer: " << name << endl;
        cout << "Account Status: " << (isGoldMember ? "Gold" : "Normal") << endl;
        cout << "----------------------------\n";

        int counter = 1;
        for (Order order : ord) {
            cout << "Order #" << counter << ": \n";
            order.showInfo();
            counter++;
        }

    }


};

int main() {
    Product p1("Hot Wheels", 1), p2("MiniGT", 10), p3("HotWheels Premium", 5), p4("Tarmac Works", 12);
    Shop s1("DucStore", {p1, p2, p3, p4});
    Customer c1("Vinh", true), c2("Phuong", false);

    s1.showInfo();
    cout << endl;

    c1.buyProd({p1, p2});
    c1.buyProd({p3, p4});
    c2.buyProd({p1, p4});
    c1.showInfo();
    cout << endl;
    c2.showInfo();

}