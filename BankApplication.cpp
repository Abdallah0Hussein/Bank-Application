#include "BankApplication.h"

static int nAccounts = 0;

BankApplication::BankApplication()
{
  int choice;
  accounts.reserve(999);
  while(true)
  {
    do
    {
      cout << "Welcome to FCAI Banking Application\n1. Create a New Account\n2. List Clients and Accounts\n3. Withdraw Money\n4. Deposit Money\n5. Exit\nPlease Enter Choice: ";
      cin >> choice;
      cin.ignore();
    }
    while(choice < 1 || choice > 5);

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
      this->withdraw();
    }
    else if(choice == 4)
    {
      this->deposit();
    }
    else if (choice == 5)
    {
      break;
    }
  }
}

void BankApplication::withdraw()
{
    string ID;
    cout << "Please Enter Account ID (e.g.,FCAI-015): ";
    getline(cin, ID);
    // Normal for loop to get the actual account not a copy from it 
    for(int i  = 0; i < nAccounts; i++)
    {
        if (accounts[i]->getID() == ID)
        {
            double amount;
            accounts[i]->DisplayInfo();
            do
            {
              cout << "Please Enter The Amount to Withdraw: ";
              cin >> amount;
              cin.ignore();
            }
            while(accounts[i]->withdraw(amount) == 1);
            break;
        }
    }
}

void BankApplication::deposit()
{
    string ID;
    cout << "Please Enter Account ID (e.g.,FCAI-015): ";
    getline(cin, ID);
    // Normal for loop to get the actual account not a copy from it 
    for(int i  = 0; i < nAccounts; i++)
    {
        if (accounts[i]->getID() == ID)
        {
            double amount;
            accounts[i]->DisplayInfo();
            do
            {
              cout << "Please Enter The Amount to deposit: ";
              cin >> amount;
              cin.ignore();
            }
            while(accounts[i]->deposit(amount) == 1);
            break;
        }
    }
}

bool BankApplication::addClient()
{
  static int ID = 0;
  static int index = 0;

  Client client;
  string name;
  string address;
  string phone;
  string type;
  double balance;
  double minBalance;

  cout << "Please Enter Client Name: ";
  getline(cin, name);
  client.setName(name);

  cout << "Please Enter Client Address: ";
  getline(cin, address);
  client.setAddress(address);

  cout << "Please Enter Client Phone: ";
  getline(cin, phone);
  client.setPhoneNumber(phone);

  do
  {
    cout << "What Type of Account Do You Like? (1) Basic (2) Saving.\nType 1 or 2: ";
    getline(cin, type);
    type.erase(remove_if(type.begin(), type.end(), ::isspace), type.end());
  }
  while (stoi(type) > 2 || stoi(type) < 1);

  if (type == "1")
  {
    do
    {
      cout << "Please Enter the Starting Balance: ";
      cin >> balance;
      cin.ignore();
    } 
    while(balance < 0);

    BankAccount account(balance);
    account.setID(to_string(++ID));
    client.setBankAccount(account);
    account.setOwner(client);
    accounts[index++] = new BankAccount(account);
    nAccounts++;

    (accounts[0]->getOwner()).DisplayInfo();

    cout << "An account was created with ID " << account.getID() << " and Starting Balance "<< account.getBalance() << " L.E." << endl; 
    return 1;
  }
  else if (type == "2")
  {
    do
    {
      cout << "Please Enter the minimum Balance (cannot withdraw it as long as the account is open) to open your Saving Account (must be above or equal 1000 L.E.): ";
      cin >> minBalance;
      cin.ignore();
    } 
    while(minBalance < 1000);

    do
    {
      cout << "Please Enter the Starting Balance (must be above or equal " << minBalance << " L.E.): ";
      cin >> balance;
      cin.ignore();
    } 
    while(balance < minBalance);

    SavingBankAcc account(balance, minBalance);
    account.setID(to_string(++ID));
    client.setBankAccount(account);
    account.setOwner(client);
    accounts[index++] = new SavingBankAcc(account);
    ++nAccounts;
    cout << "An account was created with ID " << account.getID() << " and Starting Balance "<< account.getBalance() << " L.E." << endl; 
    return 1;
  }
  return 0;
}

void BankApplication::listAccounts()
{
  for (int i = 0; i < nAccounts; i++)
  {
    (accounts[i]->getOwner()).DisplayInfo();
    cout << "----------------------------------" << endl;
  }
}