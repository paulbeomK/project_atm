#include "Account.h"

Account::Account(const std::string& account_number, int inital_balance)
    : account_number_(account_number), balance_(inital_balance) {}

Account::~Account(){}

const std::string& Account::get_account_number() const {
    return account_number_;
}

int Account::get_balance() const{
    return balance_;
}

void Account::deposit(int amount){
    balance_ += amount;
}

bool Account::withdraw(int amount){
    if (balance_ >= amount){
        balance_ -= amount;
        return true;
    }
    return false;
}