#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <string>
#include <memory>

class Account;

class Transaction{
public:
    enum class Type{
        Deposit,
        Withdrawl,
    };

    Transaction(Type type, int amount, std::shared_ptr<Account> account);
    ~Transaction();

    Type get_type() const;
    int get_amount() const;
    std::string get_account_num() const;

private:
    Type type_;
    int amount_;
    std::shared_ptr<Account> account_;

};

#endif