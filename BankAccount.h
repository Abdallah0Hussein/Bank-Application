#ifndef BANKACCOUNT_H_
#define BANKACCOUNT_H_

#include "Client.h"
#include <bits/stdc++.h>

class Client;

using namespace std;


class BankAccount
{    
private:
    string accType = "Basic";
    string accID;
    double balance;
    Client* owner;
public:
    BankAccount(BankAccount& account);  
    BankAccount():balance(0){};
    BankAccount(double startBalance):balance(startBalance){};
    //~BankAccount();
    void setOwner(Client& client);
    Client& getOwner();
    string getID();
    void setID(string ID);
    double getBalance();
    void setBalance(double money);
    virtual string getAccType();
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
    SavingBankAcc(double startBalance, double minBalance);
    SavingBankAcc(SavingBankAcc& account);
    //~SavingBankAcc();
    string getAccType(){return accType;};
    double getMinBalance();
    int withdraw(double amount);
    int deposit(double amount);
};

#endif