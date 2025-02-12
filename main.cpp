#include "PasswordManager.h"
#include <iostream>
#include <string>

void showMenu() {
    std::cout << "\n===== Password Manager Menu =====\n" << std::endl;
    std::cout << "1. Add a new entry" << std::endl;
    std::cout << "2. List all accounts" << std::endl;
    std::cout << "3. Retrieve an entry" << std::endl;
    std::cout << "4. Delete an entry" << std::endl;
    std::cout << "5. Generate a random password" << std::endl;
    std::cout << "6. Exit" << std::endl;
    std::cout << "Enter your choice: ";
}

int main() {
    std::string masterPassword;
    std::cout << "Enter master password: ";
    std::getline(std::cin, masterPassword);

    // Initialize the password manager with the data file and master password.
    PasswordManager pm("savefile.dat", masterPassword);
    pm.loadEntries();

    int choice;
    while (true) {
        showMenu();
        std::cin >> choice;
        std::cin.ignore(); // Clear newline from the input buffer

        if (choice == 1) {
            std::string account, username, password;
            std::cout << "Enter account name (e.g., Gmail): ";
            std::getline(std::cin, account);
            std::cout << "Enter username: ";
            std::getline(std::cin, username);
            std::cout << "Enter password (or leave blank to generate one): ";
            std::getline(std::cin, password);
            if (password.empty()) {
                password = pm.generatePassword(12);
                std::cout << "Generated password: " << password << std::endl;
            }
            pm.addEntry(account, username, password);
            std::cout << "Entry added successfully." << std::endl;
        }
        else if (choice == 2) {
            pm.listEntries();
        }
        else if (choice == 3) {
            std::string account;
            std::cout << "Enter account name to retrieve: ";
            std::getline(std::cin, account);
            PasswordEntry entry;
            if (pm.retrieveEntry(account, entry)) {
                std::cout << "\nAccount: " << entry.account << std::endl;
                std::cout << "Username: " << entry.username << std::endl;
                std::cout << "Password: " << entry.password << std::endl;
            } else {
                std::cout << "Entry not found." << std::endl;
            }
        }
        else if (choice == 4) {
            std::string account;
            std::cout << "Enter account name to delete: ";
            std::getline(std::cin, account);
            if (pm.deleteEntry(account)) {
                std::cout << "Entry deleted successfully." << std::endl;
            } else {
                std::cout << "Entry not found." << std::endl;
            }
        }
        else if (choice == 5) {
            int length;
            std::cout << "Enter desired password length: ";
            std::cin >> length;
            std::cin.ignore();
            std::string generated = pm.generatePassword(length);
            std::cout << "Generated password: " << generated << std::endl;
        }
        else if (choice == 6) {
            std::cout << "Exiting Password Manager." << std::endl;
            break;
        }
        else {
            std::cout << "Invalid choice. Please try again." << std::endl;
        }
    }
    return 0;
}

