#include <iostream>
#include <string>
using namespace std;

class Book{
    private:
        string name;
        int price;

    public:
        Book(){
            this->name = "Harry Potter";
            this->price = 400;
        }

        Book(string name, int price){
            this->name = name;
            this->price = price;
        }

        void showinfo(){
            cout << "\nName: " << name << "\nPrice: " << price << endl;
        }

        void setname(string name_val){
            name = name_val;
        }

        string getname(){
            return name;
        }

        void setprice(int price_val){
            price = price_val;
        }

        int getprice(){
            return price;
        }
};

int main(){
    //a)
    Book* b1 = new (std::nothrow) Book("The Catcher in the Rye", 100);
    if (b1 == NULL)
    {
        cout << "b1 dynamic memory allocation failed";
    }
    
    Book* b2 = new (std::nothrow) Book("The Old Man and the Sea", 200);
    if (b2 == NULL)
    {
        cout << "b2 dynamic memory allocation failed";
    }

    Book* b3 = new (std::nothrow) Book("Lord of The Rings", 300);
    if (b3 == NULL)
    {
        cout << "b3 dynamic memory allocation failed";
    }

    //b)
    int booknum;
    try{
        cout << "Enter number of book: ";
        cin >> booknum;
        //request memory allocation (very large size will)
    } catch (std::bad_alloc & ba){ //Handles bad_alloc
        cerr << "bad_alloc exeption caught\n" << ba.what() << endl;
    } catch (...) { //Handles generic exeption
        cerr << "Generic Exeption!\n";
    }

    Book* ptr = new (std::nothrow) Book[booknum];

    for (int i = 0; i < booknum; i++){
        string temp_name;
        int temp_price;

        cout << "Book " << i + 1 << ":\n\tEnter book's name: ";
        cin >> temp_name;
        ptr[i].setname(temp_name);

        cout << "\n\tEnter book's price: ";
        cin >> temp_price;
        ptr[i].setprice(temp_price);
    }
    
    for (int i = 0; i < booknum; i++){
        cout << "Book " << i + 1 <<": \n\t";
        ptr[i].showinfo();
    }

    int max = ptr[0].getprice();
    for (int i = 0; i < booknum; i++)
    {
        if (ptr[i].getprice() > max)
        {
            max = ptr[i].getprice();
        }
    }
    
    for (int i = 0; i < booknum; i++)
    {
        if (ptr[i].getprice() == max){
            ptr[i].showinfo();
        }
    }
    delete[] ptr;

    return 0;

}