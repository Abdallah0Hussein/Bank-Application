#include "BankAccount.h"

void BankAccount::DisplayInfo()
{
  cout << "Account ID: " << accID << "\nAccount Type: " << accType << "\nBalance: " << balance << endl;
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

void BankAccount::setOwner(Client* client)
{
  owner = client;
}

Client& BankAccount::getOwner()
{
  return *owner;
}
// ___________________________________________

SavingBankAcc::SavingBankAcc(double startBalance)
{
  if(startBalance >= minBalance)
  {
    this->setBalance(startBalance);
  }
}

int SavingBankAcc::withdraw(double amount)
{
  double currentBalance = move(getBalance());
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
    cout << "Sorry. you can only deposit 100L.E or more each time." << endl;
    return 1;
  }
  
}
