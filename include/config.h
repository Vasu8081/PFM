#pragma once
#include <pqxx/pqxx>

#define VERSION "0.0.1"

class config {
public:
  config();
  std::unique_ptr<pqxx::connection> conn;
};