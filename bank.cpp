#include <iostream>
using namespace std;

class Bank {
public:
    string name;
    int accNo;
    double balance;

    void create(string n, int no, double b) {
        name = n;
        accNo = no;
        balance = b;
    }

    void deposit(double amount) {
        balance += amount;
        cout << "Deposited: " << amount << ", New Balance: " << balance << endl;
    }

    void withdraw(double amount) {
        if (amount <= balance) {
            balance -= amount;
            cout << "Withdrawn: " << amount << ", New Balance: " << balance << endl;
        } else {
            cout << "Not enough balance!" << endl;
        }
    }

    void show() {
        cout << "Name: " << name << ", Acc No: " << accNo << ", Balance: " << balance << endl;
    }

    void fdr(double amount, int years) {
        double interest = 0.08; // 8%
        double total = amount + (amount * interest * years);
        cout << "FDR after " << years << " years = " << total << endl;
    }

    void dps(double monthly, int years) {
        double interest = 0.06; // 6%
        double total = monthly * 12 * years;
        double finalAmount = total + (total * interest);
        cout << "DPS after " << years << " years = " << finalAmount << endl;
    }
};

int main() {
    Bank users[10];
    for (int i = 0; i < 10; i++) {
        users[i].create("User" + to_string(i + 1), 1000 + i, 1000);
    }

    int ch, acc, years;
    double amt, monthly;

    while (true) {
        cout << "\n1.Show 2.Deposit 3.Withdraw 4.FDR 5.DPS 6.Exit\nChoice: ";
        cin >> ch;
        if (ch == 6) break;

        cout << "Enter Account No: ";
        cin >> acc;

        int index = acc - 1000;
        if (index < 0 || index >= 10) {
            cout << "Invalid Account!" << endl;
            continue;
        }

        switch (ch) {
            case 1: users[index].show(); break;
            case 2: cout << "Amount: "; cin >> amt; users[index].deposit(amt); break;
            case 3: cout << "Amount: "; cin >> amt; users[index].withdraw(amt); break;
            case 4: cout << "Amount: "; cin >> amt; cout << "Years: "; cin >> years;
                    users[index].fdr(amt, years); break;
            case 5: cout << "Monthly Amount: "; cin >> monthly; cout << "Years: "; cin >> years;
                    users[index].dps(monthly, years); break;
            default: cout << "Wrong choice!" << endl;
        }
    }

    return 0;
}
