#pragma once

#include <pqxx/pqxx>
#include <vector>
#include <config.h>
#include <iostream>

class database {
public:
  database();
  void create_tables();
  pqxx::result execute_query(const std::string& query);
  void insert(std::unordered_map<std::string, std::string>& fields, std::string table);
  void update(std::unordered_map<std::string, std::string>& fields, std::string table);
  void remove(std::unordered_map<std::string, std::string>& fields, std::string table);
  void fetch(std::unordered_map<std::string, std::string>& fields, std::string table);
  std::vector<std::unordered_map<std::string, std::string>> select(std::unordered_map<std::string, std::string>& fields, std::string table);

private:
  pqxx::connection _connection;
};