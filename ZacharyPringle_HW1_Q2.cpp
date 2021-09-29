#include <iostream>
#include <string>

using namespace std;

class Check{
public:
    Check():checkAmount(0), checkNum(0), checkMemo(){};
    void setCheckNum(int num){checkNum=num;}
    void setCheckMemo(string memo){checkMemo=memo;}
    void setCheckAmount(float amount){checkAmount=amount;}
    int getCheckNum(){return checkNum;}
    string getCheckMemo(){return checkMemo;}
    float getCheckAmount(){return checkAmount;}

private:
   int checkNum;
   string checkMemo;
   float checkAmount;
};

const int N=5;

class CheckBook{
public:
    CheckBook(): balance(0), numberOfChecks(0), allChecks(0){}
    CheckBook(int num): numberOfChecks(0), allChecks(0) {balance=num;}
    Check checks[N];
    bool writeCheck(float amount, int i);
    void displayChecks(){
        for (int i=4;i>=0;i--) {
            if (checks[i].getCheckAmount()!=0){
                cout << checks[i].getCheckAmount() << " " << i << " " << checks[i].getCheckMemo() << endl;
            }
        }
    }
    int getNumberOfChecks(){return numberOfChecks;}
    int getallChecks(int numofcheck1, int numofcheck2){
        allChecks = numofcheck1+numofcheck2;
        return allChecks;}
private:
    float balance;
    int numberOfChecks,allChecks;
};

int main() {
    CheckBook cb1(1000), cb2(500);

    for (int i=0; i<10; i++)
    {
        cb1.writeCheck(150, i);
        cb2.writeCheck(130, i);
    }

    cout << "cb1 check details" << endl;
    cb1.displayChecks();
    cout << "cb2 check details" << endl;
    cb2.displayChecks();

    cout << cb1.getallChecks(cb1.getNumberOfChecks(), cb2.getNumberOfChecks()) << endl;
    cout << cb2.getallChecks(cb1.getNumberOfChecks(), cb2.getNumberOfChecks()) << endl;

    return 0;
}

bool CheckBook::writeCheck(float amount, int i) {
    if(numberOfChecks<N && allChecks<10 && amount <= balance){
        string memo;
        checks[i].setCheckAmount(amount);
        balance = balance - amount;
        numberOfChecks++;
        cout << "Memo?" << endl;
        cin >> memo;
        checks[i].setCheckMemo(memo);
    }
}