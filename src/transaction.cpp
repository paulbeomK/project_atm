#include "Transaction.h"
#include "Account.h"

Transaction::Transaction(Type type, int amount, std::shared_ptr<Account> account)
    : type_(type), amount_(amount), account_(account) {}

Transaction::~Transaction() {}

Transaction::Type Transaction::get_type() const {
    return type_;
}

int Transaction::get_amount() const {
    return amount_;
}

std::string Transaction::get_account_num() const{
    if (account_){
        return account_ -> get_account_number();
    }
    return "";
}