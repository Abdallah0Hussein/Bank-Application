// FCAI – OOP – 2022 - Assignment 2
// Program: BigReal Class
// Author: Abdallah Hussein Ibrahim Hussein - Ahmad Reda Bayoumi
// IDs: 20210235 - 20210019
// Date: November 2022
// ...........................................................................................
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