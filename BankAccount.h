#ifndef BANKACCOUNT_H_
#define BANKACCOUNT_H_

#include<bits/stdc++.h>
#include "Client.h"

using namespace std;

class BankAccount
{    
private:
    string accType = "Basic";
    string accID;
    double balance;
    Client* owner;
public:

    BankAccount():balance(0){};
    BankAccount(double startBalance):balance(startBalance){};
    void setOwner(Client& client);
    Client& getOwner();
    string getID();
    void setID(string ID);
    double getBalance();
    void setBalance(double money);
    string getAccType();
    void DisplayInfo();
    virtual int withdraw(double amount);
    virtual int deposit(double amount);
};

class SavingBankAcc: public BankAccount
{
private:
    double minBalance = 1000;
    string accType = "Saving";
public:
    SavingBankAcc(double startBalance);
    string getType(){return "Saving";};
    int withdraw(double amount);
    int deposit(double amount);
};

#endif