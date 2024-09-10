#include <iostream>
#include <string>
using namespace std;

class Employee {
    protected: 
        string name;
        double salary;
    public:
        Employee(string name, double salary) : name(name), salary(salary) {}

        void showInfo(){
            cout << "Name: " << name << "\nSalary: " << salary << endl;
        }

};

class Manager : public Employee {
    private:
        double allowance;
    public:
        Manager(string name, double salary, double allowance) : Employee(name, salary), allowance(allowance){}

        void showinfo() {
            Employee::showInfo();
            cout << "Allowance: " << allowance << endl;
        }

        double getIncome() { return allowance + salary;}
};

int main() {
    Employee emp1("Quang", 100);
    Manager man1("Quan", 100, 50);
    emp1.showInfo();
    man1.showInfo();

    Manager* managers = new (nothrow) Manager[5]{
        Manager("Hoang", 100, 30),
        Manager("Ana", 100,10),
        Manager("Quang", 100,100),
        Manager("Huy", 90, 104),
        Manager("Nam", 120, 120)
    };

    int total = 0;
    for (int i = 0; i < 5; i++){
        total += managers[i].getIncome();
    }
    
    cout << "Average income: " << total/5 << endl;
    delete managers;
    return 0;
}