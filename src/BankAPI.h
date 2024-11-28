#ifndef BANK_API_H
#define BANK_API_H

#include <string>
#include <vector>
#include <memory>

class Account;

class BankAPI{
public:
    BankAPI();
    ~BankAPI();

    bool authenticate(const std::string& card_num, const std::string& pin);
    std::vector<std::shared_ptr<Account>> get_accounts(const std::string& card_num) const;
    std::shared_ptr<Account> get_account(const std::string& account_num) const;

private:
    struct UserData{
        std::string card_num;
        std::string pin;
        std::vector<std::shared_ptr<Account>> accounts;
    };
    std::vector<UserData> users_;

    void init_data();

};
#endif