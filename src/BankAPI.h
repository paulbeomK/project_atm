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

private:
    struct UserData{
        std::string card_num;
        std::string pin_info;
        std::vector<std::shared_ptr<Account>> accounts;
    };
    std::vector<UserData> users_;

};
#endif