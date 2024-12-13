#pragma once

#include <pqxx/pqxx>
#include <iostream>
#include <vector>
#include <database/entity.h>

class database {
public:
  database(std::string db_name, std::string db_user, std::string db_password, std::string db_host, std::string db_port);
  void create_tables();
  pqxx::result execute_query(const std::string& query);
  std::string insert(std::shared_ptr<entity> entity);
  void update(std::shared_ptr<entity> entity);
  void remove(std::shared_ptr<entity> entity);
  void fetch(std::shared_ptr<entity> entity);
  std::vector<std::unordered_map<std::string, std::string>> select(std::shared_ptr<entity>entity);

private:
  pqxx::connection _connection;
};