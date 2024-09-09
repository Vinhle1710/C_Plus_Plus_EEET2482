/*Question 1 (8 pts)
Define a class namely Employee with two attributes are name (string) and salary (double). Define
subclass namely Manager (derives from the Employee class) which has an additional attribute is
allowance (double).
For each class, provide a constructor to initialize all attributes, and a showInfo() method to print
out all information.
a) Create and initialize an object for each class in main() then print out all information.
b) Create an array of 05 manager objects using dynamic memory allocation. Calculate and
print out the average of their total income. Note: total income = salary + allowance*/

#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string>
using namespace std;

class Employee {
    protected:
    string name;
    double salary;

    public:
    Employee(string name, double salary):name (name), salary (salary){}


    virtual void showInfo(){
        cout << "Show Info:\n";
        cout << "Name: " << name << endl;
        cout << "Salary: " << salary << endl;
    }
};

class Manager : public Employee {
    private:
    double allowance;
    double income;

    public:
    Manager(string name, double salary, double allowance):Employee(name, salary), allowance(allowance){}

    double getIncome() {
        return salary + allowance;
    }

    void showInfo() override {
        cout << "Show Info:\n";
        cout << "Name: " << name << endl;
        cout << "Salary: " << salary << endl;
        cout << "Allowance: " << allowance << endl;
    }
};

int main() {
    Employee emp1("Nam", 10000.14);
    Employee emp2("Huy", 10104.24);
    Manager man1("Manh", 11140.42, 20000);

    emp1.showInfo();
    emp2.showInfo();
    man1.showInfo();

    // b) Create an array of 05 manager objects using dynamic memory allocation
    Manager* managers = new Manager[5]{
        Manager("Kiet", 10000, 3000),
        Manager("Quanh", 11000, 2500),
        Manager("Quan", 12000, 2700),
        Manager("Nhat", 13000, 2800),
        Manager("Khai", 14000, 3500)
    };

    int totalIncome = 0;
    for (int i = 0; i < 5; i++) {
        totalIncome += managers[i].getIncome();
    }
    cout << "The average total income of the 5 managers is: " << totalIncome/5 << endl;

    delete[] managers;
    return 0;
}