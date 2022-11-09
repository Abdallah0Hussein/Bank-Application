#ifndef BANKAPP_H_
#define BANKAPP_H_

#include<bits/stdc++.h>
#include "BankAccount.h"
#include "Client.h"

class BankApplication
{
private:
    //vector of pointers to apply polymorphism on bankaccount and savingbankacc using virtual methods
    vector<BankAccount*> accounts;
    //vector<SavingBankAcc> savingAccounts;
public:
    BankApplication();
    bool addClient();
    void listAccounts();
    void withdraw(double money);
    void deposit(double money);
};

#endif