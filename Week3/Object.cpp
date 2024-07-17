#include <iostream>
using namespace std;
#define PWD_KEY 42069

class Student{
private: 
    int age = 18;
public: 
    string name = "Nguyen Van A";
    int score = 100;

    Student() { //Default constructor with no parameter
        cout << "Default constructor is called \n";
    }

    Student (string name_val, int score_val){
        cout << "Parameterized constructor is called \n";
        name = name_val;
        score = score_val;
    }

    int get_age() {
        return age;
    }

    void showinfo(){
        cout << "Name: " << name << "\nAge: "<< age << endl;
        cout << "Score: " << score << endl;
    }

    void set_age(int new_val){
        int pwd;
        cout << "Enter password: "; cin >> pwd;
        if (pwd == PWD_KEY){
            age = new_val;
            cout << "Age updated!\n";
        } else {
            cout << "Invalid password!\n";
        }
    }
};

int main(){
    Student StudentA;
    cout << "Student's name is: " << StudentA.name << endl;

    Student Nam("Ngo Huy Hai Nam", 90), Vinh("Le Pham Gia Vinh", 91);
    cout << "First Student's info:\nName: " << Nam.name << "\nScore: " << Nam.score << endl;
    cout << "Second Student's info:\nName: " << Vinh.name << "\nScore: " << Vinh.score << endl;
     
    Student student_list[4] = {
        {"Ngo Huy Hai Nam", 90},
        {"Le Khoi", 0},
        {"Tran Minh Phong", 50},
        {"Nguyen Tung Bach", 80}
    };

    student_list[3].set_age(16);
    student_list[3].showinfo();

    int max = student_list[0].score;
    int student_number = 0;
    for (int i = 0; i < 3; i++){
        if (max < student_list[i].score){
            max = student_list[i].score;
            student_number = i;
        }
    }
    cout << "The student with the highest score is: \n";
    student_list[student_number].showinfo();
}
