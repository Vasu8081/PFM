#pragma once

#include <pqxx/pqxx>
#include <iostream>


class entity {
public:
  entity() = default;
  virtual ~entity() = default;
  virtual std::string table_name() const = 0;
  virtual void print() const = 0;
  virtual std::unordered_map<std::string, std::string> get() const = 0;
  virtual void set(const std::unordered_map<std::string, std::string>& map) = 0;
};