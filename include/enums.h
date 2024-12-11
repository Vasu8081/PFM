#pragma once
#include <iostream>

enum account_type {
  ACCOUNT_TYPE_UNKNOWN = 0,
  BANK_ACCOUNT = 1,
  CREDIT_CARD_ACCOUNT = 2,
  LOAN_ACCOUNT = 3,
  BORROW_GIVEN_ACCOUNT = 4,
  ASSET_ACCOUNT = 5,
  CATEGORY_ACCOUNT = 6,
  GOAL_ACCOUNT = 7,
  CHIT_ACCOUNT = 8,
};

std::string account_type_to_string(account_type type) {
  switch (type) {
    case ACCOUNT_TYPE_UNKNOWN:
      return "UNKNOWN";
    case BANK_ACCOUNT:
      return "BANK";
    case CREDIT_CARD_ACCOUNT:
      return "CREDIT";
    case LOAN_ACCOUNT:
      return "LOAN";
    case BORROW_GIVEN_ACCOUNT:
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

account_type string_to_account_type(std::string type){
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
    return BORROW_GIVEN_ACCOUNT;
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