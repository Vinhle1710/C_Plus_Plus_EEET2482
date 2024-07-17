#include <iostream>
#include <fstream>
#include <string>
using namespace std;
using std::string;

int main (){
    string pwd;
    int a = 0;
    int choice;
    while (a==0) {
        cout << "Password management program:\n1. Save your password\n2. Read your password\n3. Cancel\n";
        cout << "Your choice: ";
        cin >> choice;
        
        fstream file;

        switch (choice){

            case 1:
            cout << "\nEnter the password: ";    
            cin >> pwd;
            file.open("pwd.dat", std::ios::out);

            if(!file){
                std::cerr << "Failed to open fil";
                return -1;
            }
            
            file >> pwd;
            cout << "Saved to the file!\n\n";
            file.close();
            break;

            case 2:
            file.open("pwd.dat");
            cout << "Your password is: ";
            file >> pwd;
            cout << pwd << "\n\n";
            break;

            case 3:
            a = 1;
            break;

            default:
            cout << "Input not valid! \n\n";
            break;
        }
        return 0;
    }

}