#ifndef USER_H
#define USER_H

#include <string>
#include <vector>
#include "account.h"
#include "operation.h"

class User {
private:
    std::string username;
    std::string password;
    std::vector<Account*> accounts;

public:
    User(const std::string& username, const std::string& password);
    ~User();

    bool login(const std::string& username, const std::string& password);
    void registerUser(const std::string& username, const std::string& password);
    void createNewAccount(const std::string& accountType, double initialBalance);
    void makeOperation(int accountNumber, const std::string& operationType, double amount);     
    void deleteAccount(int accountNumber);
    void displayAccountInfo(int accountNumber) const;
    void saveUserToFile() const;
    static User* loadUserFromFile(const std::string& username);
};

#endif
