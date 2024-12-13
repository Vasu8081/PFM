#pragma once

#include <iostream>
#include <models/account.h>
#include <models/bank_account.h>
#include <models/credit_card_account.h>
#include <utils/utils.h>
#include <database/database.h>
#include <pqxx/pqxx>

class account_db {
public:
  account_db(std::string user_id, database &db)
  : _user_id(user_id), _db(db) {};

  void add_account(std::shared_ptr<account> account);
  void delete_account(std::shared_ptr<account> acc);
  void update_account(std::shared_ptr<account> acc);
  void get_account(std::shared_ptr<account> acc);
  std::vector<std::shared_ptr<account>> get_all_accounts();
  std::vector<std::shared_ptr<account>> get_accounts(enums::account_type account_type);

private:
  std::string _user_id;
  database &_db;
  std::shared_ptr<account> get_pointer(enums::account_type account_type);
};