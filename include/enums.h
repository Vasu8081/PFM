#pragma once
#include <iostream>

class account;

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

inline std::vector<std::string> all_account_types = {
    "bank_accounts",
    "credit_card_accounts",
    "loan_accounts",
    "borrow_give_accounts",
    "asset_accounts",
    "category_accounts",
    "goal_accounts",
    "chit_accounts"
};

std::shared_ptr<account> get_account_pointer(std::string table_name);

std::string account_t(enums::account_type type);

enums::account_type account_t(std::string type);