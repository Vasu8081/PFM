#pragma once
#include <pqxx/pqxx>
#include <models/user.h>

#define VERSION "0.0.1"

class config {
public:
  config();
  std::unique_ptr<pqxx::connection> conn;
  std::unique_ptr<user> user;
};