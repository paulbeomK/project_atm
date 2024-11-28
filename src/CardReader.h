#ifndef CARD_READER_H
#define CARD_READER_H

#include <string>

class CardReader{
public:
    CardReader();
    ~CardReader();

    void insert_card(const std::string& card_num);
    void eject_card();
    std::string get_card_num() const;

private:
    std::string card_num_;
    bool card_inserted_;

};

#endif
