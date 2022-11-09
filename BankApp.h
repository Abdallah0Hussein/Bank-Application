#ifndef BANKAPP_H_
#define BANKAPP_H_

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

BankApplication::BankApplication()
{
    int choice;
    do
    {
        cout << "Welcome to FCAI Banking Application\n1. Create a New Account\n2. List Clients and Accounts\n3. Withdraw Money\n4. Deposit Money\nPlease Enter Choice: ";
        cin >> choice;
    }
    while(choice < 1 || choice > 4);

    if(choice == 1)
    {
        addClient();
    }
    else if(choice == 2)
    {
        listAccounts();
    }
    else if(choice == 3)
    {
        string ID;
        cout << "Please Enter Account ID (e.g.,FCAI-015): ";
        getline(cin, ID);
        cin.ignore();
        // Normal for loop to get the actual account not a copy from it 
        for(int i  = 0; i < accounts.size(); i++)
        {
            if (accounts[i]->getID() == ID)
            (
                double amount;
                accounts[i]->DisplayInfo();
                do
                {
                    cout << "Please Enter The Amount to Withdraw: ";
                    cin >> amount;
                }
                while(accounts[i]->withdraw(amount) == 1);
                break;
            )
        }
        
    }
    else if(choice == 4)
    {
        string ID;
        cout << "Please Enter Account ID (e.g.,FCAI-015): ";
        getline(cin, ID);
        cin.ignore();
        // Normal for loop to get the actual account not a copy from it 
        for(int i  = 0; i < accounts.size(); i++)
        {
            if (accounts[i]->getID() == ID)
            (
                double amount;
                accounts[i]->DisplayInfo();
                do
                {
                    cout << "Please Enter The Amount to deposit: ";
                    cin >> amount;
                }
                while(accounts[i]->deposit(amount) == 1);
                break;
            )
        }
    }
}

bool BankApplication::addClient()
{
    
}

void BankApplication::listAccounts()
{
    
}

#endif