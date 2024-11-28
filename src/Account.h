#ifndef ACCOUNT_H
#define ACCOUNT_H
#include <string>
#include <memory>

class Account{
private:
    std::string account_number_;
    int balance_;

public:
    Account(const std::string& account_number, int inital_balance);
    ~Account();
    
    const std::string& get_account_number() const;
    int get_balance() const;
    void deposit(int amount);
    bool withdraw(int amount);

};
#endif