#pragma once
#include <iostream>
#include <enums.h>

class account {
public:
  account(std::string account_name, account_type account_type)
  : _account_name(account_name), _account_type(account_type) {}

  // Getters
  std::string id() const { return _id; }
  std::string user_id() const { return _user_id; }
  std::string account_name() const { return _account_name; }
  account_type account_type() const { return _account_type; }

  // Setters
  void id(std::string id) { _id = id; }
  void user_id(std::string user_id) { _user_id = user_id; }
  void account_name(const std::string& account_name) { _account_name = account_name; }
  void account_type(enum account_type account_type) { _account_type = account_type; }

private:
  std::string _id;
  std::string _user_id;
  std::string _account_name;
  enum account_type _account_type;
};