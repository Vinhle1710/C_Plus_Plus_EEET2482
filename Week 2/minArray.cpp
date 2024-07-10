#include <iostream>
using std::cout;
using std::cin;

int minnArr(int size, int arr[]){
    int min = arr[0];
    for (int i = 0; i < size; i++){
        if (min > arr[i]){
            min = arr[i];
        }
    }
    return min;
}

int main(){
    int size = 6;
    int arr[5];
    cout << "Enter 6 numbers: ";
    for (int i = 0; i < size; i++){
        cin >> arr[i];
    }
    cout << "The smallest value is: " << minnArr(size, arr) << "\n";
    return 0;
}