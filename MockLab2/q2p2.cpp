#include <iostream>
#include <string>
using namespace std;

class Broker{
    private:
        string name;
        float buyPrice;
        Broker* nextBuyer;
    public:
        Broker(string name, float buyPrice) : name(name), buyPrice(buyPrice), nextBuyer(nullptr) {}

        void showTransactions(Broker* broker){
            cout << broker->name <<": Bought the house for $" << broker->buyPrice << endl;
            while(broker != nullptr && broker->nextBuyer != nullptr){ 
                cout << broker->name << " ---> " << broker->nextBuyer->name << ". Price: $" << broker->nextBuyer->buyPrice << endl;
                broker = broker->nextBuyer;
            }
        }

        void showLowestProfit(Broker* broker) {
            float lowestProfit = broker->nextBuyer->buyPrice - broker->buyPrice;
            string name = broker->name;
            while (broker != nullptr && broker->nextBuyer != nullptr)
            {
                if (broker->nextBuyer->buyPrice - broker->buyPrice < lowestProfit)
                {
                    lowestProfit = broker->nextBuyer->buyPrice - broker->buyPrice;
                    name = broker->name;
                }
                
                broker = broker->nextBuyer;
            }
            cout << "Broker with lowest profit: " << name << " with $"<< lowestProfit <<" in profit." << endl;
        }

        void setNextBuyer(Broker* broker){
            this->nextBuyer = broker;
        }

};

int main(){
    Broker broker1("David", 800);
    Broker broker2("John", 1000);
    Broker broker3("Peter", 1200);
    Broker broker4("Luna", 1800);
    Broker broker5("Sophia", 3500);

    broker1.setNextBuyer(&broker2);
    broker2.setNextBuyer(&broker3);
    broker3.setNextBuyer(&broker4);
    broker4.setNextBuyer(&broker5);

    broker1.showTransactions(&broker1);
    broker1.showLowestProfit(&broker1);
}