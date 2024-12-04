#pragma once
#include <iostream>
#include <enums.h>

class account {
public:
    account(std::string account_name, account_type account_type)
        : _account_name(account_name), _account_type(account_type) {}

    // Getters
    std::string get_account_name() const { return _account_name; }
    account_type get_account_type() const { return _account_type; }

    // Setters
    void set_account_name(const std::string& account_name) { _account_name = account_name; }
    void set_account_type(account_type account_type) { _account_type = account_type; }

private:
    std::string _account_name;
    account_type _account_type;
};