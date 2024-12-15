#pragma once
#define VERSION "0.0.1"

#include <string>
class transaction;
class account;

struct database_config {
  std::string database_name = "finance_app";
  std::string user_name = "quickwitted";
  std::string password;
  std::string hostname = "localhost";
  std::string port = "5432";
};

struct config {
  std::string user_id;
  database_config db_config;
  std::map<std::string, std::shared_ptr<account>> accounts;
  std::map<std::string, std::shared_ptr<transaction>> transactions;
};

extern config global_config;