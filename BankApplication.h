#ifndef BANKAPPLICATION_H_
#define BANKAPPLICATION_H_

#include<bits/stdc++.h>
#include "BankAccount.h"
#include "Client.h"

using namespace std;

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
    void withdraw();
    void deposit();
};

#endif