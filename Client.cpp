#include "Client.h"

BankAccount& Client::getBankAccount()
{
  return *bankAccount;
}

void Client::setBankAccount(BankAccount& account)
{
  bankAccount = &account;
}

void Client::setName(string name)
{
  this->name = name;
}

string Client::getName()
{
  return name;
}

void Client::setAddress(string address)
{
  this->address = address;
}

string Client::getAddress()
{
  return address;
}

void Client::setPhoneNumber(int Number)
{
  this->phoneNumber = Number;
}

int Client::getPhoneNumber()
{
  return phoneNumber;
}

void Client::DisplayInfo()
{
  cout << "\nName: " << name << "\nAddress: " << address << " Phone: " << phoneNumber << "\nAccount ID: " << this->bankAccount->getID() << "(" << this->bankAccount->getAccType() << ")\nBalance: " << this->bankAccount->getBalance() << endl;
}

