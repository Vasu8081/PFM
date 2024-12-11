#pragma once

#include <models/account.h>
#include <database/database.h>
#include <pqxx/pqxx>

class account_db {
public:
  account_db(std::string user_id, database &db)
  : _user_id(user_id), _db(db) {};

  void add_account(account& account);
  void delete_account(account& account);
  void update_account(account& account);
  account get_account(std::string account_id);
  std::vector<account> get_all_accounts();
  std::vector<account> get_accounts(account_type account_type);

private:
  std::string _user_id;
  database &_db;
};