#ifndef CLIENT_H_
#define CLIENT_H_

#include<bits/stdc++.h>
#include "BankAccount.h"

class Client
{
private:
    string name;
    string address;
    int phoneNumber;
    BankAccount* bankAccount;
public:
    Client() = default;
    void setName(string name);
    void setAddress(string address);
    void setPhoneNumber(int phoneNumber);
    void setBankAccount(BankAccount& bankAccount);
    string getName();
    string getAddress();
    int getPhoneNumber();
    BankAccount& getBankAccount();
    void DisplayInfo();
};



#endif