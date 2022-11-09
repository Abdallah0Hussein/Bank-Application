#include "BankAccount.h"

void BankAccount::DisplayInfo()
{
  cout << "Account ID: " << accID << "\nAccount Type: " << accType << "\nBalance: " << balance << endl;
}

virtual int BankAccount::withdraw(double amount)
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

virtual int BankAccount::deposit(double amount)
{
  balance += amount;
  cout << "Thank you.\nAccount ID: " << accID << "\nNew Balance: " << balance << endl;
  return 0;
}

string BankAccount::getID()
{
  return accID;
}

string BankAccount::setID(string ID)
{
  accID = ID;
}

double BankAccount::getBalance()
{
  return balance;
}

double BankAccount::setBalance(double money)
{
  balance = money;
}

string BankAccount::getAccType()
{
  return accType;
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
