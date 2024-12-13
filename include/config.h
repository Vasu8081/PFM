#pragma once
#define VERSION "0.0.1"

#include <string>

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
};

extern config global_config;