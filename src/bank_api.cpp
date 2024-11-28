#include "BankAPI.h"
#include "Account.h"

BankAPI::BankAPI(){
    init_data();
}

BankAPI::~BankAPI(){}

void BankAPI::init_data(){
    // initialize with virtual sample data
    // assumption: one sample_card can possess more than one account ...
    //      For that reason, pin number is shared.
    auto account1 = std::make_shared<Account>("1104123456", 5000);
    auto account2 = std::make_shared<Account>("1103456789", 10000);

    UserData user={
        "SampleCard123",    //sample card_num
        "1234",            //sample pin num
        {account1, account2},
    };
    users_.push_back(user);
}

bool BankAPI::authenticate(const std::string& card_num, const std::string& pin){
    for (const auto& user: users_){
        if (user.card_num == card_num && user.pin == pin){
            return true;
        }
    }
    return false;
}

std::vector<std::shared_ptr<Account>> BankAPI::get_accounts(const std::string& card_num) const{
    for (const auto& user : users_){
        if (user.card_num == card_num){
            return user.accounts;
        }
    }
    return {};
}

std::shared_ptr<Account> BankAPI::get_account(const std::string& account_num) const{
    for (const auto& user : users_){
        for (const auto& account: user.accounts){
            if (account -> get_account_number() == account_num){
                return account;
            }
        }
    }
    return nullptr;
}


