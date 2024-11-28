#ifndef ACCOUNT_H
#define ACCOUNT_H
#include <string>

class Account{
private:
    std::string account_id_;
    int balance_;

public:
    Account(const std::string& id, int inital_balance);
    const std::string& get_account_id() const;
    int get_balance() const;
    void deposit(int amount);
    void Withdraw(int amount);

};
#endif