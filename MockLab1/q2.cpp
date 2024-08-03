#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <sstream>
#include <istream>
using namespace std;

class Student {
    private:
        string name;
        int scores[3];
    public:
        Student(string name, int scores[3]){
            this-> name = name;
            for (int i = 0; i < 3; i++){
                this-> scores[i] = scores[i];
            }
        }
        Student(){
            this-> name = "Nguyen Van A";
            this-> scores[10, 10, 10];
        }
        void showInfo(){
            cout << "This student's name is " << name << endl;
            cout << "This student's scores are " << scores[0] << ", " << scores[1] << ", " << scores[2] << endl;
        }
        void inputData(){
            cout << "Enter student's name: " << endl;
            getline(cin, name);
            cout << "Enter 1st scores: " << endl;
            cin >> scores[0];
            cout << "Enter 2nd scores: " << endl;
            cin >> scores[1];
            cout << "Enter 3rd scores: " << endl;
            cin >> scores[2];
            cin.ignore(256,'\n');
        }

        bool operator > (Student &stud){
            int total1 = 0, total2 = 0;
            float ave1, ave2;

            for (int i = 0; i < 3; i++){
                total1 += this->scores[i];
                total2 += stud.scores[i];
            }

            ave1 = (float)total1/3;
            ave2 = (float)total2/3;

            if (ave1 > ave2) 
                return true;
            else
                return false;
        }

        void setScores(int scores[]){
            for (int i = 0; i < 3; i++){
                this->scores[i] = scores[i];
            }
        }

        void setName(string name){
            this->name = name;
        }

        friend ostream& operator << (ostream &out, Student &obj);
        friend istream& operator >> (istream &in, Student &obj);
        friend Student operator + (int n, Student &stud);
};

ostream& operator << (ostream &out, Student &stud){
    stud.showInfo();
    return out;
}

istream& operator >> (istream &in, Student &stud){
    stud.inputData();
    return in;
}

Student operator + (int n, Student &stud){
    Student tmp;
    string name;
    cout << "Enter name: ";
    cin >> name;

    if(name == stud.name){
        tmp.name = stud.name;
        for (int i = 0; i < 3; i++){
            tmp.scores[i] = n + stud.scores[i];
        }
        
    }
    return tmp;
}

int main(){
    //a)
    Student stuA;
    stuA.inputData();
    stuA.showInfo();

    //b)
    Student stuB;
    cin >> stuB;
    cout << stuB;

    if(stuA > stuB){
        cout << "student A's scores are larger" << endl;
    } else {cout << "student B's scores are larger" << endl;}
    
    Student result;
    int incre;
    cout << "Increment value: " << endl;
    cin >> incre;    
    result = incre + stuB;
    cout << result;


    // //c)
    // ifstream ifile;
    // string tname, scoresstr;
    // int scores[3], total, stuIndex = 0;
    // float ave[10];
    // stringstream ss;


    // ifile.open("data.txt");
    // Student stuArr[10];

    // if(!ifile){
    //     cout << "File not opened" << endl;
    // }

    // while(stuIndex < 10){
    //     ss.clear();
    //     total = 0;
        
    //     getline(ifile, tname, ',');
    //     getline(ifile, scoresstr, '\n');

    //     ss << scoresstr;

    //     for (int i = 0; i < 3; i++){
    //         ss >> scores[i];
    //         total += scores[i];
    //     }

    //     ave[stuIndex] = (float)total / 3;
    //     stuArr[stuIndex].setName(tname);
    //     stuArr[stuIndex].setScores(scores);
       
    //     cout << stuArr[stuIndex];
    //     stuIndex++;
    // }
    // ifile.close();

    // float maxAve = ave[0];
    // for (int i = 1; i < 10; i ++){
    //     if (ave[i] > maxAve){
    //         maxAve = ave[i];
    //         stuIndex = i;
    //     }
    // }
    // cout << "The student with the highest average score is: "<< stuArr[stuIndex] << endl;
    // cout << "Their average score is: " << fixed << setprecision(2) << maxAve << endl;

    return 0;
}