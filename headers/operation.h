#ifndef OPERATION_H
#define OPERATION_H

#include "account.h"

class Operation {
public:
    static void deposit(Account* account, double amount);
    static void withdraw(Account* account, double amount);
    static void saveOperationToFile(const std::string& operationType, int accountNumber, double amount);
};

#endif
