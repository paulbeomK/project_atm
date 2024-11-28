# Project_atm
-------------------------------------------
A simple ATM controller implemented in C++.


### Description
-------------------------------------------
Main application (main.cpp)
- Demo through a consol-based simulation.
- Feature
    - Card Insertion & Ejection
    - PIN Authentication
    - Balance Inquiry
    - Deposit
    - Withdrawal
    - Multiple Accounts per card

### Requirements
-------------------------------------------
- C++17 or later
- CMake 3.10 or later
- C++ compiler

### Build & Test
-------------------------------------------
```bash
git clone https://github.com/paulbeomK/project_atm.git
cd project_atm
cmake CMakeLists.txt
make
```

- Main
    - `./project_atm`
- Unit_test
    - `./test_atm`


- Sample card info for test 
    (can be found in src/bank_api.cpp)
    - card_num
        - `'SampleCard123'`
    - PIN
        - `1234`
    - Accounts
        - Multiple (2 accounts)
