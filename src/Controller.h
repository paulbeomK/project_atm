#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <memory>
#include <string>
#include <vector>

class CardReader;
class BankAPI;
class Account;

class Controller{
public:
    Controller();
    ~Controller();

    void insert_card(const std::string& card_num);
    bool enter_pin(const std::string& pin);
    std::vector<std::string> get_account() const;
    bool deposit(const std::string& account_num, int amount);
    bool withdraw(const std::string& account_num, int amount);
    void eject_card();

private:
    std::unique_ptr<CardReader> cardReader_;
    std::unique_ptr<BankAPI> bankAPI_;
    std::shared_ptr<Account> currentaccount_;
    bool is_authenticated_;

};
#endif