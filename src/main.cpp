#include <iostream>
#include "Controller.h"

int main(){
    // system test flow.
    // sample card - SampleCard123, (current_pin - 1234)
    // Insert Card => PIN number => Select Account => See Balance/Deposit/Withdraw
    Controller atm;

    std::string card_num = "SampleCard123";
    atm.insert_card(card_num);

    std::string pin;
    std::cout << "Input Pin number: ";
    std::cin >> pin;
    if(!atm.enter_pin(pin)){
        std::cout << "Authentication failed. exit." << std::endl;
        atm.eject_card();
        return 0;
    }

    auto accounts = atm.get_accounts();
    if (accounts.empty()){
        std::cout << "No available account." << std::endl;
        atm.eject_card();
        return 0;
    }

    std::cout << "Available accounts: " << std::endl;
    for (std::size_t i=0; i< accounts.size(); ++i){
        std::cout << i+1 << ". account num: " << accounts[i] << std::endl;
    }

    int account_choice;
    std::cout << "Select the number of accounts (input number): ";
    std::cin >> account_choice;

    if (account_choice < 1 || account_choice > accounts.size()){
        std::cout << "wrong selection." << std::endl;
        atm.eject_card();
        return 0;
    }
    std::string selected_account = accounts[account_choice -1];

    int action;
    std::cout << "Select operation:\n1. check account\n2. deposit\n3. withdraw\nselected: ";
    std::cin >> action;

    if (action==1){
        int balance = atm.check_balance(selected_account);
        std::cout << "current balance($): " << balance << std::endl;
    }
    else if (action ==2){
        int amount;
        std::cout << "Input amount to deposit: ";
        std::cin >> amount;
        if (atm.deposit(selected_account, amount)){
            std::cout << "Success. current balance($): " << atm.check_balance(selected_account) << std::endl;
        }
        else{
            std::cout << "Failed deposit." << std::endl;
        }
    }
    else if (action == 3){
        int amount;
        std::cout << "Input amount to withdraw: ";
        std::cin >> amount;
        if (atm.withdraw(selected_account, amount)){
            std::cout << "Success. current balance($): " << atm.check_balance(selected_account) << std::endl;
        }
        else{
            std::cout << "Failed withdraw. insufficient balance. "<< std::endl;
        }
    }
    else{
        std::cout << "Invalid selection." << std::endl;
    }

    atm.eject_card();
    std::cout << "Card is ejected. Thank you." << std::endl;

    return 0;
}