#pragma once
#include <iostream>
#include <optional>
#include <enums.h>
#include <models/account.h>

class borrow_give_account : public account {
public:
    borrow_give_account(std::string account_name, double balance_due,
                        std::optional<std::string> due_date = std::nullopt)
        : account(account_name, account_type::BORROW_GIVEN_ACCOUNT),
          _balance_due(balance_due), _due_date(due_date) {}

    // Getters
    double get_balance_due() const { return _balance_due; }
    std::optional<std::string> get_due_date() const { return _due_date; }

    // Setters
    void set_balance_due(double balance_due) { _balance_due = balance_due; }
    void set_due_date(std::optional<std::string> due_date) { _due_date = due_date; }

private:
    double _balance_due;
    std::optional<std::string> _due_date;
};
