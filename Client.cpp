#include "Client.h"
#include <string>

using namespace std;

BankAccount& Client::getBankAccount()
{
  return *bankAcc;
}

void Client::setBankAccount(BankAccount& account)
{
  bankAcc = &account;
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

void Client::setPhoneNumber(int number)
{
  this->phoneNumber = number;
}

int Client::getPhoneNumber()
{
  return phoneNumber;
}

void Client::DisplayInfo()
{
  cout << "\nName: " << name << "\nAddress: " << address << " Phone: " << phoneNumber << "\nAccount ID: " << bankAcc->getID() << "(" << bankAcc->getAccType() << ")\nBalance: " << bankAcc->getBalance() << endl;
}

