#include <iostream>
#include "user.h"

int main() {
    User* user = new User("snof", "123456789");

    if (user->login("snof", "123456789")) {
        std::cout << "Login successful!\n";
        user->registerUser("snof", "123456789");
        user->createNewAccount("Savings", 500.0);

        user->displayAccountInfo(1);

        user->deleteAccount(1);
    } else {
        std::cout << "Login failed.\n";
    }

    delete user;
    return 0;
}
