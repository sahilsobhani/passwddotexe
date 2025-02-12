

#ifndef PASSWORDMANAGER_H
#define PASSWORDMANAGER_H

#include <string>
#include <vector>

using namespace std;
struct PasswordEntry {

string account;
string username;
string password;

};

class PasswordManager{

private:

    vector<PasswordEntry> entries;
    string filename;
    string masterPassword;
    
    string xorEncryptDecrpyt(const string &data, const string key);

public: 

    PasswordManager(const string &file, const string &masterPwd);
    bool loadEntries();
    bool saveEntries();

    void addEntry(const string &account, const string &username, const string &password);
    void listEntry() const;
    bool retrieveEntry(const string &account , PasswordEntry &entry) const;
    bool deleteEntry(const string &account);

    string generatePassword(int length) const;
};

#endif


