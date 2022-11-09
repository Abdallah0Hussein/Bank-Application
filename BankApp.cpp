#include "BankApp.h"

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
  static int ID = 1;

  Client client;
  string name;
  string address;
  int phone;
  int type;
  double balance;

  cin.ignore();
  cout << "Please Enter Client Name: ";
  getline(cin, name);
  cin.ignore();
  client.setName(name);

  cout << "Please Enter Client Address: ";
  getline(cin, address);
  cin.ignore();
  client.setAddress(address);

  cout << "Please Enter Client Phone: ";
  cin >> phone;
  cin.ignore();
  client.setPhone(phone);

  cout << "What Type of Account Do You Like? (1) Basic (2) Saving.\nType 1 or 2: ";

  if (type == 1)
  {
    do
    {
      cout << "Please Enter the Starting Balance: ";
      cin >> balance;
    } 
    while(balance < 0);

    BankAccount account(balance);
    account.setID(to_string(ID++));
    client.setBankAccount(account);
    account.setOwner(client);
    accounts.push_back(&account);
    cout << "An account was created with ID " << account.getID() << " and Starting Balance "<< account.getBalance() << " L.E." << endl; 
    return 1;
  }
  else if (type == 2)
  {
    do
    {
      cout << "Please Enter the Starting Balance (must be above 1000 L.E.): ";
      cin >> balance;
    } 
    while(balance < 1000);

    SavingBankAcc account(balance);
    account.setID(to_string(ID++));
    client.setBankAccount(account);
    account.setOwner(client);
    accounts.push_back(&account);
    cout << "An account was created with ID " << account.getID() << " and Starting Balance "<< account.getBalance() << " L.E." << endl; 
    return 1;
  }
  return 0;
}

void BankApplication::listAccounts()
{
  for (int i = 0; i < accounts.size(); i++)
  {
    (accounts[i]->getOwner()).DisplayInfo();
    cout << "-------------------------------------" << endl;
  }
}