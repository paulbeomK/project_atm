cmake_minimum_required(VERSION 3.10)
project(project_atm)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(SOURCES
    src/main.cpp
    src/controller.cpp
    src/card_reader.cpp
    src/bank_api.cpp
    src/account.cpp
    src/transaction.cpp)

include_directories(src)

add_executable(project_atm src/main.cpp ${SOURCES})

set(TEST_SOURCES
    tests/test.cpp
    src/controller.cpp
    src/card_reader.cpp
    src/bank_api.cpp
    src/account.cpp
    src/transaction.cpp)

add_executable(test_atm tests/test.cpp ${TEST_SOURCES})