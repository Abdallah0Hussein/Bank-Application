// FCAI – OOP – 2022 - Assignment 2
// Program: Bank-Application 
// Author: Abdallah Hussein Ibrahim Hussein - Ahmad Reda Bayoumi
// IDs: 20210235 - 20210019
// Date: November 2022
// ...........................................................................................
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
public:
    BankApplication();
    bool addClient();
    void listAccounts();
    void withdraw();
    void deposit();
    ~BankApplication();
};

#endif