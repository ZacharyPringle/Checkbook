#include <iostream>
#include <string>

using namespace std;

struct Check{
    int checkNum=6;
    float checkAmount;
    string checkMemo;
};

const int N=5;

class CheckBook{
public:
    CheckBook(): balance(0), numOfChecks(0){}
    CheckBook(float num): numOfChecks(0){balance=num;}
    Check check[N];
    void lastDeposit(){
        cout << "\n____________________________________\n" <<"Check amount: " << check[numOfChecks-1].checkAmount << "\nCheck Number: " << numOfChecks << "\nCheck Memo: " << check[numOfChecks-1].checkMemo << "\n____________________________________\n" << endl;
    };
    float getBalance(){return balance;}
    int getNumOfChecks(){return numOfChecks;}
    void setNumOfChecks(int num){numOfChecks+=num;}
    void deposit(float num){balance+=num;}
    void displayChecks(){
        for(int i=0;i<5;i++) {
            if (check[i].checkNum < 5) {
                cout << "\n____________________________________\n" << i + 1 << ". Check amount = " << check[i].checkAmount << "\nCheck number = " << check[i].checkNum << "\nCheck Memo: " << check[i].checkMemo << "\n____________________________________\n" << endl;
            }
        }
    };
    bool writeCheck(float amount, string memo){
        if (amount<=balance & numOfChecks<checkLimit){
            check[numOfChecks].checkAmount=amount;
            check[numOfChecks].checkNum=numOfChecks+1;
            balance-=amount;
            check[numOfChecks].checkMemo = memo;
            numOfChecks++;
            return true;
        }
        else
            return false;
    }
private:
    float balance;
    int numOfChecks, checkLimit=N;
};


int main() {
    float initialBalance = 1000;
    CheckBook checkBook(initialBalance);
    float amount=0;
    string memo;
    while(checkBook.getNumOfChecks()<5) {
        cout << "\n\nEnter Amount of check" << endl;
        cin >> amount;
        cin.ignore();
        cout << "Enter Check Memo\n";
        getline(cin, memo);
        checkBook.writeCheck(amount, memo);
        checkBook.displayChecks();
        cout << "Balance = " << checkBook.getBalance() << endl;
        cout << "\nNumber of Checks = " << checkBook.getNumOfChecks() << "\n" << endl;
        cout << "Last Check Deposited:";
        checkBook.lastDeposit();
    }

    return 0;
}