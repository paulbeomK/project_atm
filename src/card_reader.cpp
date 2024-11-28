#include "CardReader.h"

CardReader::CardReader()
    : card_inserted_(false) {}

CardReader::~CardReader() {}

void CardReader::insert_card(const std::string& card_num){
    card_num_ = card_num;
    card_inserted_ = true;
}

void CardReader::eject_card(){
    card_num_.clear();
    card_inserted_ = false;
}

std::string CardReader::get_card_num() const{
    return card_num_;
}

bool CardReader::is_card_inserted() const{
    return card_inserted_;
}

