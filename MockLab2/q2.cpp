#include <iostream>
#include <string>
using namespace std;

class Broker {
    private:
    string name;
    float buyPrice;
    Broker* nextBuyer;
    float profit;

    public:
    Broker(string name, int buyPrice) : name (name), buyPrice(buyPrice), nextBuyer(nullptr){}

    void showTransaction(){
        cout << name << ": bought the house for $" << buyPrice << endl;
    }

    void setNextBuyer(Broker* broker){
        nextBuyer = broker;
    }

    void findLowestProfit(Broker* broker){
        float lowestProfit = broker->nextBuyer->buyPrice - broker->buyPrice;
        string brokerName;

        while(broker != nullptr && broker->nextBuyer != nullptr){
            broker->profit = broker->nextBuyer->buyPrice - broker->buyPrice;  

            if (broker->profit <= lowestProfit)
            {
                lowestProfit = broker->profit;
                brokerName = broker->name;
            }
            
            broker = broker->nextBuyer;
        }

        cout << "Broker with the least profit is " << brokerName << " with the profit of $" << lowestProfit << endl;
    }

    void printTransaction(Broker* broker){
        while(broker != nullptr && broker->nextBuyer != nullptr){
            cout << broker->name << " ---> " << broker->nextBuyer->name << ": price = $"<< broker->nextBuyer->buyPrice << endl;
            broker = broker->nextBuyer;
        }
    }

};

int main () {
    Broker broker1("David", 800);
    Broker broker2("John", 1000);
    Broker broker3("Peter", 1200);
    Broker broker4("Luna", 1800);
    Broker broker5("Sophia", 3500);

    broker1.setNextBuyer(&broker2); 
    broker2.setNextBuyer(&broker3);
    broker3.setNextBuyer(&broker4);
    broker4.setNextBuyer(&broker5);

    broker1.showTransaction();
    broker1.printTransaction(&broker1);

    broker1.findLowestProfit(&broker1); 
}