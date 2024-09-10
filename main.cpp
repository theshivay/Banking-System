// main.cpp
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Account {
private:
    int accountNumber;
    string accountHolderName;
    double balance;

public:
    Account(int accNumber, string name, double initialBalance) {
        accountNumber = accNumber;
        accountHolderName = name;
        balance = initialBalance;
    }

    int getAccountNumber() {
        return accountNumber;
    }

    string getAccountHolderName() {
        return accountHolderName;
    }

    double getBalance() {
        return balance;
    }

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposit successful. New balance: " << balance << endl;
        } else {
            cout << "Invalid deposit amount." << endl;
        }
    }

    bool withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "Withdrawal successful. New balance: " << balance << endl;
            return true;
        } else {
            cout << "Invalid withdrawal amount or insufficient funds." << endl;
            return false;
        }
    }
};

class Bank {
private:
    vector<Account> accounts;
    int nextAccountNumber;

public:
    Bank() {
        nextAccountNumber = 1000;
    }

    void createAccount(string name, double initialBalance) {
        Account newAccount(nextAccountNumber, name, initialBalance);
        accounts.push_back(newAccount);
        cout << "Account created successfully. Account number: " << nextAccountNumber << endl;
        nextAccountNumber++;
    }

    Account* findAccount(int accountNumber) {
        for (int i = 0; i < accounts.size(); i++) {
            if (accounts[i].getAccountNumber() == accountNumber) {
                return &accounts[i];
            }
        }
        return NULL;
    }

    void deposit(int accountNumber, double amount) {
        Account* account = findAccount(accountNumber);
        if (account != NULL) {
            account->deposit(amount);
        } else {
            cout << "Account not found." << endl;
        }
    }

    void withdraw(int accountNumber, double amount) {
        Account* account = findAccount(accountNumber);
        if (account != NULL) {
            account->withdraw(amount);
        } else {
            cout << "Account not found." << endl;
        }
    }

    void checkBalance(int accountNumber) {
        Account* account = findAccount(accountNumber);
        if (account != NULL) {
            cout << "Account balance: " << account->getBalance() << endl;
        } else {
            cout << "Account not found." << endl;
        }
    }

    void listAllAccounts() {
        cout << "All Accounts:\n";
        for (int i = 0; i < accounts.size(); i++) {
            cout << "Account Number: " << accounts[i].getAccountNumber()
                      << ", Name: " << accounts[i].getAccountHolderName()
                      << ", Balance: " << accounts[i].getBalance() << endl;
        }
    }
};

int main() {
    Bank bank;
    int choice;
    
    do {
        cout << "\nBanking System Menu:\n";
        cout << "1. Create Account\n";
        cout << "2. Deposit\n";
        cout << "3. Withdraw\n";
        cout << "4. Check Balance\n";
        cout << "5. List All Accounts\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        
        switch(choice) {
            case 1: {
                string name;
                double initialBalance;
                cout << "Enter name: ";
                cin >> name;
                cout << "Enter initial balance: ";
                cin >> initialBalance;
                bank.createAccount(name, initialBalance);
                break;
            }
            case 2: {
                int accountNumber;
                double amount;
                cout << "Enter account number: ";
                cin >> accountNumber;
                cout << "Enter deposit amount: ";
                cin >> amount;
                bank.deposit(accountNumber, amount);
                break;
            }
            case 3: {
                int accountNumber;
                double amount;
                cout << "Enter account number: ";
                cin >> accountNumber;
                cout << "Enter withdrawal amount: ";
                cin >> amount;
                bank.withdraw(accountNumber, amount);
                break;
            }
            case 4: {
                int accountNumber;
                cout << "Enter account number: ";
                cin >> accountNumber;
                bank.checkBalance(accountNumber);
                break;
            }
            case 5:
                bank.listAllAccounts();
                break;
            case 0:
                cout << "Thank you for using our Banking System!\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 0);
    
    return 0;
}