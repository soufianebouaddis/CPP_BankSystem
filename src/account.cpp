#include "account.h"
#include <fstream>
#include <iostream>

int Account::nextAccountNumber = 1;

Account::Account(const std::string& accountType, double initialBalance)
    : accountType(accountType), balance(initialBalance) {
    accountNumber = nextAccountNumber++;
}

Account::~Account() {}

int Account::getAccountNumber() const {
    return accountNumber;
}

std::string Account::getAccountType() const {
    return accountType;
}

double Account::getBalance() const {
    return balance;
}

void Account::deposit(double amount) {
    balance += amount;
    std::cout << "Deposited " << amount << ". New balance: " << balance << "\n";
}

void Account::withdraw(double amount) {
    if (amount > balance) {
        std::cout << "Insufficient balance.\n";
    } else {
        balance -= amount;
        std::cout << "Withdrew " << amount << ". New balance: " << balance << "\n";
    }
}

void Account::displayInfo() const {
    std::cout << "Account Number: " << accountNumber << "\n"
              << "Account Type: " << accountType << "\n"
              << "Balance: " << balance << "\n";
}

void Account::saveAccountToFile() const {
    std::ofstream file("data/accounts.txt", std::ios::app);
    file << accountNumber << " " << accountType << " " << balance << "\n";
    file.close();
}
