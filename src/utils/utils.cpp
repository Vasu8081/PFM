#include <utils/utils.h>
#include <enums.h>

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