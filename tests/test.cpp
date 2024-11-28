// unit_test
#include "../src/Controller.h"
#include <cassert>
#include <iostream>

void testController(){
    Controller atm;

    // sample test target from ../src/bank_api.cpp

    // test case 1 - card insertion
    atm.insert_card("SampleCard123");
    assert(atm.enter_pin("1234") == true);

    // test case 2 - get accounts
    auto accounts = atm.get_accounts();
    assert(!accounts.empty());

    // test case 3 - check balance (smaple init balance = 5000)
    int balance = atm.check_balance(accounts[0]);
    assert(balance == 5000);

    // test case 4 - deposit
    atm.deposit(accounts[0], 500);
    assert(atm.check_balance(accounts[0]) == 5500);

    // test case 5 - withdraw
    atm.withdraw(accounts[0], 300);
    assert(atm.check_balance(accounts[0]) == 5200);

    atm.eject_card();

}

int main(){
    testController();
    std::cout << "All tests are successfully fininshed. " << std::endl;
    return 0;
}