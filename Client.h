#ifndef CLIENT_H_
#define CLIENT_H_

#include "BankAccount.h"
#include <string>

using namespace std;

class Client
{
private:
    string name;
    string address;
    int phoneNumber;
    BankAccount* bankAcc;
public:
    Client() = default;
    BankAccount& getBankAccount();
    void setBankAccount(BankAccount& account);
    void setName(string name);
    void setAddress(string address);
    void setPhoneNumber(int number);
    string getName();
    string getAddress();
    int getPhoneNumber();
    void DisplayInfo();
};



#endif