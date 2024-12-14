#pragma once

#include <database/database.h>

class entity {
public:
  entity(): db(std::make_shared<database>()) {};
  virtual ~entity() = default;
  virtual std::string id() const = 0;
  virtual void id(std::string id) = 0;
  virtual std::string table_name() const = 0;
  virtual void print() const = 0;
  virtual std::unordered_map<std::string, std::string> get() const = 0;
  virtual void set(const std::unordered_map<std::string, std::string>& map) = 0;
  virtual void save() = 0;
  virtual void load() = 0;
protected:
  std::shared_ptr<database> db;
};