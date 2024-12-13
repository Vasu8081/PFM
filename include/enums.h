#pragma once
#include <iostream>

namespace enums {
    enum account_type {
        ACCOUNT_TYPE_UNKNOWN = 0,
        BANK_ACCOUNT = 1,
        CREDIT_CARD_ACCOUNT = 2,
        LOAN_ACCOUNT = 3,
        BORROW_GIVE_ACCOUNT = 4,
        ASSET_ACCOUNT = 5,
        CATEGORY_ACCOUNT = 6,
        GOAL_ACCOUNT = 7,
        CHIT_ACCOUNT = 8,
      };
}


std::string account_t(enums::account_type type);

enums::account_type account_t(std::string type);