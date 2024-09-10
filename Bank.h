#ifndef BANK_H
#define BANK_H

#include <vector>
#include <algorithm>
#include "Account.h"
using namespace std;

class Bank {
private:
    vector<Account> accounts;
    int nextAccountNumber;

public:
    Bank() {
        nextAccountNumber = 1000;
    }

    void createAccount(const string& name, double initialBalance) {
        accounts.push_back(Account(nextAccountNumber, name, initialBalance));
        cout << "Account created successfully. Account number: " << nextAccountNumber << endl;
        nextAccountNumber++;
    }

    void deposit(int accountNumber, double amount) {
        auto it = find_if(accounts.begin(), accounts.end(),
                               [&accountNumber](const Account& acc) { return acc.getAccountNumber() == accountNumber; });
        if (it != accounts.end()) {
            it->deposit(amount);
        } else {
            cout << "Account not found." << endl;
        }
    }

    void withdraw(int accountNumber, double amount) {
        auto it = find_if(accounts.begin(), accounts.end(),
                               [accountNumber](const Account& acc) { return acc.getAccountNumber() == accountNumber; });
        if (it != accounts.end()) {
            it->withdraw(amount);
        } else {
            cout << "Account not found." << endl;
        }
    }

    void checkBalance(int accountNumber) {
        auto it = find_if(accounts.begin(), accounts.end(),
                               [accountNumber](const Account& acc) { return acc.getAccountNumber() == accountNumber; });
        if (it != accounts.end()) {
            cout << "Account balance: " << it->getBalance() << endl;
        } else {
            cout << "Account not found." << endl;
        }
    }

    void listAllAccounts() {
        cout << "All Accounts:\n";
        for (const auto& acc : accounts) {
            cout << "Account Number: " << acc.getAccountNumber()
                      << ", Name: " << acc.getAccountHolderName()
                      << ", Balance: " << acc.getBalance() << endl;
        }
    }
};

#endif