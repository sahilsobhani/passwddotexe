#include "PasswordManager.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <cstdlib>
#include <ctime>

PasswordManager::PasswordManager(const std::string &file, const std::string &masterPwd)
    : filename(file), masterPassword(masterPwd)
{
    // Initialize random seed for the password generator
    std::srand(static_cast<unsigned int>(std::time(0)));
}

std::string PasswordManager::xorEncryptDecrypt(const std::string &data, const std::string &key) {
    std::string result = data;
    for (size_t i = 0; i < data.size(); i++) {
        result[i] = data[i] ^ key[i % key.size()];
    }
    return result;
}

bool PasswordManager::loadEntries() {
    std::ifstream file(filename);
    if (!file.is_open()) {
        // File does not exist yet (first run) – not an error.
        return true;
    }
    entries.clear();
    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string account, username, encryptedPassword;
        // Using '|' as a delimiter
        if (std::getline(iss, account, '|') &&
            std::getline(iss, username, '|') &&
            std::getline(iss, encryptedPassword))
        {
            PasswordEntry entry;
            entry.account = account;
            entry.username = username;
            // Decrypt the stored password using the master password.
            entry.password = xorEncryptDecrypt(encryptedPassword, masterPassword);
            entries.push_back(entry);
        }
    }
    file.close();
    return true;
}

bool PasswordManager::saveEntries() {
    std::ofstream file(filename, std::ios::trunc);
    if (!file.is_open()) {
        std::cerr << "Failed to open file for writing." << std::endl;
        return false;
    }
    // Save each entry with fields separated by '|'
    for (const auto &entry : entries) {
        std::string encryptedPassword = xorEncryptDecrypt(entry.password, masterPassword);
        file << entry.account << "|" << entry.username << "|" << encryptedPassword << "\n";
    }
    file.close();
    return true;
}

void PasswordManager::addEntry(const std::string &account, const std::string &username, const std::string &password) {
    PasswordEntry entry;
    entry.account = account;
    entry.username = username;
    entry.password = password;
    entries.push_back(entry);
    saveEntries();
}

void PasswordManager::listEntries() const {
    if (entries.empty()) {
        std::cout << "No entries found." << std::endl;
        return;
    }
    std::cout << "\nStored accounts:" << std::endl;
    for (const auto &entry : entries) {
        std::cout << "- " << entry.account << std::endl;
    }
}

bool PasswordManager::retrieveEntry(const std::string &account, PasswordEntry &entry) const {
    for (const auto &e : entries) {
        if (e.account == account) {
            entry = e;
            return true;
        }
    }
    return false;
}

bool PasswordManager::deleteEntry(const std::string &account) {
    for (auto it = entries.begin(); it != entries.end(); ++it) {
        if (it->account == account) {
            entries.erase(it);
            saveEntries();
            return true;
        }
    }
    return false;
}

std::string PasswordManager::generatePassword(int length) const {
    const std::string chars = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*()";
    std::string password;
    for (int i = 0; i < length; i++) {
        password.push_back(chars[std::rand() % chars.size()]);
    }
    return password;
}
