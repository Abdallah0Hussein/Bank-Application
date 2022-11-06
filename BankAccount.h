#include "BankApp.h"
class BankAccount
{
private:
    string accID;
    double balance;

public:
    BankAccount();
    int withdraw(double amount);
    int deposit(double amount);
};

BankAccount::BankAccount() {}
int BankAccount::withdraw(double amount) {}
int BankAccount::deposit(double amount) {}

class SavingBankAcc : public BankAccount
{
private:
    double MinBalance;

public:
    SavingBankAcc();
    int withdraw(double amount);
    int deposit(double amount);
};
int SavingBankAcc::withdraw(double amount) {}
int SavingBankAcc::deposit(double amount) {}