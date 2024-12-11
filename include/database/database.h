#pragma once

#include <pqxx/pqxx>
#include <iostream>
#include <vector>

class database {
public:
  database(std::string db_name, std::string db_user, std::string db_password, std::string db_host, std::string db_port);
  void create_tables();
  pqxx::result execute_query(const std::string& query);

private:
  pqxx::connection _connection;
};