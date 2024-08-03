#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <string>
#include <istream>

using namespace std;

#define SIZE 3
#define PARTCSIZE 10

class Student{
    private:
        string name = "";
        int scores[SIZE] = {0};
    
    public:
        Student(){}

        Student(string name, int scores[]){
            this->name = name;
            int i;
            for(i=0; i<SIZE; i++)
                this->scores[i] = scores[i];
        }

        void inputData(){
            cout << "Please enter name of student: ";
            getline(cin, name);
            cout << "Please enter 3 scores for " << name << ": ";
            int i;
            for(i=0; i<SIZE; i++)
                cin >> scores[i];
        }

        void setName(string name){
            this->name = name;
        }

        void setScores(int scores[]){
            int i;
            for(i=0; i<SIZE; i++)
                this->scores[i] = scores[i];
        }

        void showInfo(){
            cout << "Name: " << name << endl;
            int i;
            for(i=0; i<SIZE; i++)
                cout << "Score " << i+1 << ": " << scores[i] << endl;
        }

        bool operator > (Student &stud){
            int total1 = 0, total2 = 0;
            float ave1, ave2;
            int i;
            for(i=0; i<SIZE; i++){
                total1 += this->scores[i];
                total2 += stud.scores[i];
            }
            ave1 = (float)total1/SIZE;
            ave2 = (float)total2/SIZE;

            if(ave1 > ave2) return true;
            else return false;
        }

        friend istream& operator >> (istream &in, Student &stud);
        friend ostream& operator << (ostream &out, Student &stud);
        friend Student operator + (int n, Student &stud);
};

istream& operator >> (istream &in, Student &stud){
    stud.inputData();
    /*
    cout << "Please enter name of student: ";
    getline(in, stud.name);
    cout << "Please enter 3 scores for " << stud.name << ": ";
    int i;
    for(i=0; i<SIZE; i++)
        in >> stud.scores[i];
    */
    return in;
}

ostream& operator << (ostream &out, Student &stud){
    stud.showInfo();
    /*
    out << "Name: " << stud.name << endl;
    int i;
    for(i=0; i<SIZE; i++)
        out << "Score " << i+1 << ": " << stud.scores[i] << endl;
    */
    return out;
}

Student operator + (int n, Student &stud){
    Student temp;
    string sname;
    int i;
    cout << "Please enter a name: ";
    std::getline(cin, sname);
    if(sname == stud.name){
        temp.name = stud.name;
        for(i=0; i<SIZE; i++)
            temp.scores[i] = n + stud.scores[i];
    }
    return temp;
}

int main()
{   
    // /*(a)*/
    // Student student1;
    // student1.inputData();
    // student1.showInfo();

    // /*(b)*/
    // //exercise for students

    // /*(c)*/
    ifstream ifile;
    
    Student studArr[PARTCSIZE];
    string name, sdata;
    int scores[SIZE] = {0}, i, total = 0, studInd = 0;
    float average[PARTCSIZE] = {0.0};
    stringstream ss;

    ifile.open("data.txt", ios::in);
    if(!ifile){
        cerr << "File could not be opened\n" << endl;
        return -1;
    }

    while(studInd < 10)
    {
        total = 0;
        ss.clear();
;
        std::getline(ifile, name, ',');
        std::getline(ifile, sdata, '\n');
        
        ss << sdata;
        
        for(i=0; i<SIZE; i++)
        {
            ss >> scores[i];
            total += scores[i];
        }

        studArr[studInd].setName(name);
        studArr[studInd].setScores(scores);
        average[studInd] = (float)total/SIZE;
        cout << studArr[studInd];
        studInd++;
    }   
    ifile.close();

    float max = average[0];
    int maxIndex = 0;
    for(i=1; i<PARTCSIZE; i++){
        if(average[i] > max){
            max = average[i];
            maxIndex = i;
        }
    }

    cout << "Student info with highest average score\n";
    cout << studArr[maxIndex];
    cout << "Average: " << fixed << setprecision(2) << max << "\n";
    
    return 0;
}