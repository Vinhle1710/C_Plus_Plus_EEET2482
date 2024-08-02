#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
using namespace std;

int doubleVal(int num){
    return num *2;
}

float doubleVal(float num){
    return num*2;
}

int doubleVal(string num){
    stringstream ss;
    ss << num;
    int doubleValue;
    ss >> hex >> doubleValue;
    return doubleValue*2;
}

int main (int argc, char* argv[]) {
    
    if (argc != 2){
        cout << "invalid arguments" << endl;
    } else {
        int intNum, HexNum;
        float FloatNum;
        string input(argv[1]);
        stringstream ss;

        if (input.find(".") != string::npos){
            ss << input;
            ss >> FloatNum;
            FloatNum = doubleVal(FloatNum);
            cout << fixed << setprecision(2) << FloatNum << endl;

        } else if (input.find("x") != string::npos || input.find("X") != string::npos){
            HexNum = doubleVal(input);
            cout << showbase << hex << HexNum << endl;
            cout << "hii";

        } else {
            ss << input;
            ss >> intNum;
            cout << doubleVal(intNum) << endl;
        }
    }    
}