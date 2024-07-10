#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

int printStr(){
    //a)
    char str[100];
    cout << "Enter a string: ";
    cin.getline(str, 100);
    for (int i = 0; i < strlen(str); i++){
        cout << str[i] << ' ';
    }
    return 0;
}

int printPadded0(){
    //b) 
    double num = 1.234;
    printf("%.8f \n", num);
    printf("%010.3f", num);
    return 0;
}

int print2fracional(){
    //c) 
    double num = 1.234;
    printf("%.2f", num);
    return 0;
}

int main(){
    char a;
    cout << "Select option a, b, c or d: ";
    cin >> a;
    if (a == 'a'){
        printStr();
    } else if (a =='b'){
        printPadded0();
    } else if (a =='c'){
        print2fracional();
    } else if (a =='d'){

    } 
}