#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <string>

class Account {
private:
    int accountNumber;
    std::string accountType;
    double balance;
    static int nextAccountNumber;

public:
    Account(const std::string& accountType, double initialBalance);
    ~Account();

    int getAccountNumber() const;
    std::string getAccountType() const;
    double getBalance() const;

    void deposit(double amount);
    void withdraw(double amount);
    void displayInfo() const;

    void saveAccountToFile() const;
    static Account* loadAccountFromFile(int accountNumber);
};

#endif
