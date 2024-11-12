#include "operation.h"
#include <fstream>

void Operation::deposit(Account* account, double amount) {
    account->deposit(amount);
    saveOperationToFile("deposit", account->getAccountNumber(), amount);
}

void Operation::withdraw(Account* account, double amount) {
    account->withdraw(amount);
    saveOperationToFile("withdraw", account->getAccountNumber(), amount);
}

void Operation::saveOperationToFile(const std::string& operationType, int accountNumber, double amount) {
    std::ofstream file("data/operations.txt", std::ios::app);
    file << operationType << " " << accountNumber << " " << amount << "\n";
    file.close();
}
