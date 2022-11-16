// FCAI – OOP – 2022 - Assignment 2
// Program: Bank-Application 
// Author: Abdallah Hussein Ibrahim Hussein - Ahmad Reda Bayoumi
// IDs: 20210235 - 20210019
// Date: November 2022
// ...........................................................................................
#include "BankAccount.h"

void BankAccount::DisplayInfo()
{
  cout << "Account ID: " << accID << "\nAccount Type: " << this->getAccType() << "\nBalance: " << balance << endl;
}

int BankAccount::withdraw(double amount)
{
  if (amount <= balance)
  {
    balance -= amount;
    cout << "Thank you.\nAccount ID: " << accID << "\nNew Balance: " << balance << endl;
    return 0;
  }
  else
  {
    cout << "Sorry. This is more than what you can withdraw." << endl;
    return 1;
  }
}

int BankAccount::deposit(double amount)
{
  balance += amount;
  cout << "Thank you.\nAccount ID: " << accID << "\nNew Balance: " << balance << endl;
  return 0;
}

string BankAccount::getID()
{
  return accID;
}

void BankAccount::setID(string ID)
{  
  stringstream finalForm;
  finalForm << "FCAI-" << setfill('0') << setw(3) << ID;
  accID = finalForm.str();
}

double BankAccount::getBalance()
{
  return balance;
}

void BankAccount::setBalance(double money)
{
  balance = money;
}

string BankAccount::getAccType()
{
  return this->accType;
}

void BankAccount::setOwner(Client& client)
{
  owner = &client;
}

Client& BankAccount::getOwner()
{
  return *owner;
}

BankAccount::BankAccount(BankAccount& account): accType("Basic"), accID(account.accID), balance(account.balance)
{
  owner = new Client();
  owner->setName((account.getOwner()).getName());
  owner->setAddress((account.getOwner()).getAddress());
  owner->setPhoneNumber((account.getOwner()).getPhoneNumber());
  owner->setBankAccount(*this);          
}

// ___________________________________________

SavingBankAcc::SavingBankAcc(double startBalance, double minBalance)
{
  this->minBalance = minBalance;

  if(startBalance >= minBalance)
  {
    this->setBalance(startBalance);
  }
}

double SavingBankAcc::getMinBalance()
{
  return this->minBalance;
}

int SavingBankAcc::withdraw(double amount)
{
  double currentBalance = getBalance();
  // withdrawable balance = current balance - minimum balance;
  double withdrawable = currentBalance - minBalance; 
   
  if (amount <= withdrawable)
  {
    // New Balance
    setBalance(currentBalance - amount);
    cout << "Thank you.\nAccount ID: " << getID() << "\nNew Balance: " << getBalance() << endl;
    return 0;
  }
  else
  {
    cout << "Sorry. This is more than what you can withdraw." << endl;
    return 1;
  }
}

int SavingBankAcc::deposit(double amount) 
{
  if (amount >= 100)
  {
    //BankAccount::deposit(amount);
    setBalance(getBalance() + amount);
    cout << "Thank you.\nAccount ID: " << getID() << "\nNew Balance: " << getBalance() << endl;
    return 0;
  }
  else
  {
    cout << "Sorry. you can only deposit 100 L.E or more each time." << endl;
    return 1;
  }
  
}

SavingBankAcc::SavingBankAcc(SavingBankAcc& account) : accType("Saving"), minBalance(account.getMinBalance())
{
  // FCAI-501 => 501
  // Give me the str number from index 5 and give me 3 characters from there.
  string ID = account.getID().substr(5, 3);
  
  this->setBalance(account.getBalance());
  this->setID(ID);
  this->setOwner(*new Client());
  (this->getOwner()).setName((account.getOwner()).getName());
  (this->getOwner()).setAddress((account.getOwner()).getAddress());
  (this->getOwner()).setPhoneNumber((account.getOwner()).getPhoneNumber());
  (this->getOwner()).setBankAccount(*this);          
} 

