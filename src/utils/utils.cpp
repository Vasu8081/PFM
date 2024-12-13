#include <utils/utils.h>
#include <enums.h>
#include <models/bank_account.h>
#include <models/borrow_give_account.h>
#include <models/category_account.h>
#include <models/chit_account.h>
#include <models/credit_card_account.h>
#include <models/goal_account.h>
#include <models/loan_account.h>

std::string account_t(enums::account_type type) {
  using namespace enums;
    switch (type) {
        case ACCOUNT_TYPE_UNKNOWN:
            return "UNKNOWN";
        case BANK_ACCOUNT:
            return "BANK";
        case CREDIT_CARD_ACCOUNT:
            return "CREDIT";
        case LOAN_ACCOUNT:
            return "LOAN";
        case BORROW_GIVE_ACCOUNT:
            return "BORROW";
        case ASSET_ACCOUNT:
            return "ASSET";
        case CATEGORY_ACCOUNT:
            return "CATEGORY";
        case GOAL_ACCOUNT:
            return "GOAL";
        case CHIT_ACCOUNT:
            return "CHIT";
        default:
            return "UNKNOWN";
    }
}

enums::account_type account_t(std::string type){
  using namespace enums;
    if (type == "UNKNOWN") {
        return ACCOUNT_TYPE_UNKNOWN;
    }
    if (type == "BANK") {
        return BANK_ACCOUNT;
    }
    if (type == "CREDIT") {
        return CREDIT_CARD_ACCOUNT;
    }
    if (type == "LOAN") {
        return LOAN_ACCOUNT;
    }
    if (type == "BORROW") {
        return BORROW_GIVE_ACCOUNT;
    }
    if (type == "ASSET") {
        return ASSET_ACCOUNT;
    }
    if (type == "CATEGORY") {
        return CATEGORY_ACCOUNT;
    }
    if (type == "GOAL") {
        return GOAL_ACCOUNT;
    }
    if (type == "CHIT") {
        return CHIT_ACCOUNT;
    }
    return ACCOUNT_TYPE_UNKNOWN;
}

std::shared_ptr<account> get_account_pointer(std::string table_name)
{
    if (table_name == "bank_accounts") {
        return std::make_shared<bank_account>();
    }
    if (table_name == "credit_card_accounts") {
        return std::make_shared<credit_card_account>();
    }
    if (table_name == "loan_accounts") {
        return std::make_shared<loan_account>();
    }
    if (table_name == "borrow_give_accounts") {
        return std::make_shared<borrow_give_account>();
    }
    if (table_name == "category_accounts") {
        return std::make_shared<category_account>();
    }
    if ( table_name == "goal_accounts") {
        return std::make_shared<goal_account>();
    }
    if (table_name == "chit_accounts") {
        return std::make_shared<chit_account>();
    }
    return nullptr;
}