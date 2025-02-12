
// Macros
#ifndef PASSWORDMANAGER_H
#define PASSWORDMANAGER_H

// Header imports
#include <string>
#include <vector>

using namespace std;

//Structure for a single password entry

struct PasswordEntry {

string account;
string username;
string password;

};

// Monolith class for the password manager

class PasswordManager{

private:

    vector<PasswordEntry> entries;
    string filename;
    string masterPassword;
    
    //Simple XOR encryption and decryption function for password in data file
    std::string xorEncryptDecrypt(const std::string &data, const std::string &key);

public: 

    // Constructor to create a password manager
    PasswordManager(const string &file, const string &masterPwd);
    
    // Function to load and save entries in a file
    bool loadEntries();
    bool saveEntries();

    // CRUD operations - Functions on a particular entry
    void addEntry(const string &account, const string &username, const string &password);
    void listEntries() const;
    bool retrieveEntry(const string &account , PasswordEntry &entry) const;
    bool deleteEntry(const string &account);

    // Function to generate a password
    string generatePassword(int length) const;
};

#endif


