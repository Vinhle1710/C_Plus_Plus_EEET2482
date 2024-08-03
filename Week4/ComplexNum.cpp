#include <iostream>
using namespace std;

class ComplNum{
private:
    double imag;
    double real;
public:
    ComplNum(){
        this->imag = 1;
        this->real = 1;
    }

    ComplNum(double real, double imag) {
        this->real = real;
        this->imag = imag;
    }

    ComplNum operator - (ComplNum num1) {
        ComplNum temp;
        
        //Same imag: minus amounts
        if (this->imag == num1.imag){
            temp.imag = this->imag;
            temp.real = this->real - num1.real;
            return temp;
        }
    }

    ComplNum operator - (double num){
        ComplNum temp;
        temp.imag = this->imag;
        temp.real = this->real - num;
        return temp;
    }

    void showinfo(){
        cout << "Number = " << real << "+" << imag << "i" << endl;
    }
};



main(){
    ComplNum num1, num2(3, 1);
    num1.showinfo();
    num2.showinfo();

    ComplNum result; //obj - obj
    result = num2 - num1;
    result.showinfo();

    ComplNum result2; //obj - double
    result2 = num2 - 3;
    result2.showinfo();

    return 0;
}