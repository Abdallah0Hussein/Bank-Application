#ifndef CLIENT_H_
#define CLIENT_H_

#include"BankAccount.h"

class Client
{
private:
    string name;
    string address;
    int phoneNumber;
    BankAccount* bankAccount;
public:
    Client();
    void DisplayInfo();
};

Client::Client() {}


#endif