#include <iostream>
#include <sstream>
#include <iomanip>

using namespace std;

int doubleVal(int intParam){
    return (intParam * 2);
}

float doubleVal(float floatParam){
    return (floatParam * 2);
}

int doubleVal(string hexParam){
    int hexValue;
    stringstream ss;
    ss << hexParam;
    ss >> hex >> hexValue;
    return (hexValue * 2);
}

int main(int argc, char *argv[]){
    if(argc != 2)
    {
        cerr << "Insufficient arguments\n.";
    }
    else
    {
        float floatNum;
        int intNum, hexNum;

        string input(argv[1]);
        stringstream ss;

        int pos = input.find_first_of(".xX");

        if(pos != string::npos){
            if(input[pos] == '.'){
                ss << input;
                ss >> floatNum;
                floatNum = doubleVal(floatNum);
                cout << fixed << setprecision(2) << floatNum << endl;
            }else if(input[pos] == 'x' || input[pos] == 'X'){
                hexNum = doubleVal(input);
                cout << showbase << hex << hexNum << endl;
            }
        }else{
            ss << input;
            ss >> intNum;
            intNum = doubleVal(intNum);
            cout << intNum << endl;
        }
    }
    return 0;
}