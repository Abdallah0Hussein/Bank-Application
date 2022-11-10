#ifndef CLIENT_H_
#define CLIENT_H_

#include "BankAccount.h"
#include <string>

using namespace std;

class BankAccount;

class Client
{
private:
    string name;
    string address;
    string phoneNumber;
    BankAccount* bankAcc;
public:
    Client() = default;
    BankAccount& getBankAccount();
    void setBankAccount(BankAccount& account);
    void setName(string name);
    void setAddress(string address);
    void setPhoneNumber(string number);
    string getName();
    string getAddress();
    string getPhoneNumber();
    void DisplayInfo();
};



#endif