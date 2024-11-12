#include "user.h"
#include <fstream>
#include <iostream>

User::User(const std::string& username, const std::string& password)
    : username(username), password(password) {}

User::~User() {
    for (auto account : accounts) {
        delete account;
    }
}

bool User::login(const std::string& username, const std::string& password) {
    return this->username == username && this->password == password;
}

void User::registerUser(const std::string& username, const std::string& password) {
    this->username = username;
    this->password = password;
    saveUserToFile();
    std::cout << "User registered successfully!\n";
}

void User::createNewAccount(const std::string& accountType, double initialBalance) {
    Account* newAccount = new Account(accountType, initialBalance);
    accounts.push_back(newAccount);
    newAccount->saveAccountToFile();
    std::cout << "Account created with account number: " << newAccount->getAccountNumber() << "\n";
}

void User::deleteAccount(int accountNumber) {
    for (auto it = accounts.begin(); it != accounts.end(); ++it) {
        if ((*it)->getAccountNumber() == accountNumber) {
            delete *it;
            accounts.erase(it);
            std::cout << "Account deleted successfully.\n";
            return;
        }
    }
    std::cout << "Account not found.\n";
}
void User::makeOperation(int accountNumber, const std::string& operationType, double amount) {
    for (auto& account : accounts) {
        if (account->getAccountNumber() == accountNumber) {
            if (operationType == "deposit") {
                Operation::deposit(account, amount);
            } else if (operationType == "withdraw") {
                Operation::withdraw(account, amount);
            } else {
                std::cout << "Invalid operation type.\n";
            }
            return;
        }
    }
    std::cout << "Account not found.\n";
}
void User::displayAccountInfo(int accountNumber) const {
    for (const auto& account : accounts) {
        if (account->getAccountNumber() == accountNumber) {
            account->displayInfo();
            return;
        }
    }
    std::cout << "Account not found.\n";
}

void User::saveUserToFile() const {
    std::ofstream file("data/users.txt", std::ios::app);
    file << username << " " << password << "\n";
    file.close();
}

User* User::loadUserFromFile(const std::string& username) {
    std::ifstream file("data/users.txt");
    std::string uname, pass;
    while (file >> uname >> pass) {
        if (uname == username) {
            file.close();
            return new User(uname, pass);
        }
    }
    file.close();
    return nullptr;
}
