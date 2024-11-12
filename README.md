# Bank System C++ Project

This is a simple C++ project implementing a basic banking system.

## Project Structure

The project is organized into the following folders:

* **data:** Contains data files for accounts (`accounts.txt`) and users (`users.txt`).
* **headers:** Contains header files for the classes:
    * `account.h`
    * `operation.h`
    * `user.h`
* **src:** Contains the source code files:
    * `account.cpp`
    * `bankSystem.cpp`
    * `operation.cpp`
    * `user.cpp`

## Compilation

The project can be compiled using the following command:

```bash
g++ -v src/bankSystem.cpp src/user.cpp src/account.cpp src/operation.cpp -I headers -o bankSystem22
./bankSystem22.exe
