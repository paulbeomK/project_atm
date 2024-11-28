#include "Controller.h"
#include "CardReader.h"
#include "BankAPI.h"
#include "Account.h"

Controller::Controller()
    : cardReader_(std::make_unique<CardReader>()),
        bankAPI_(std::make_unique<BankAPI>()),
        is_authenticated_(false){}

Controller::~Controller(){
}

void Controller::insert_card(const std::string& card_num){
    cardReader_->insert_card(card_num);
    is_authenticated_ = false;
    currentaccount_.reset();
}

bool Controller::enter_pin(const std::string& pin){
    if (cardReader_->is_card_inserted()){
        is_authenticated_ = bankAPI_->authenticate(cardReader_->get_card_num(), pin);
        return is_authenticated_;
    }
    return false;
}

std::vector<std::string> Controller::get_accounts() const{
    if (is_authenticated_){
        auto accounts = bankAPI_->get_accounts(cardReader_-> get_card_num());
        std::vector<std::string> account_numbers;
        for (const auto& account: accounts){
            account_numbers.push_back(account->get_account_number());
        }
        return account_numbers;
    }
    return {};
}

int Controller::check_balance(const std::string& account_num) const {
    if (is_authenticated_){
        auto account = bankAPI_->get_account(account_num);
        if (account){
            return account->get_balance();
        }
    }
    return -1; // if not authorized -> no account ...
}

bool Controller::deposit(const std::string& account_num, int amount){
    if (is_authenticated_ && amount > 0){
        auto account = bankAPI_->get_account(account_num);
        if (account){
            account->deposit(amount);
            return true;
        }
    }
    return false;
}

bool Controller::withdraw(const std::string& account_num, int amount){
    if (is_authenticated_ && amount > 0){
        auto account = bankAPI_->get_account(account_num);
        if (account && account->withdraw(amount)){
            return true;
        }
    }
    return false;
}

void Controller::eject_card(){
    cardReader_->eject_card();
    is_authenticated_ = false;
    currentaccount_.reset();
}
