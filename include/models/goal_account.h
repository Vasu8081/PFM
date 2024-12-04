#pragma once
#include <iostream>
#include <optional>
#include <enums.h>
#include <models/account.h>

class goal_account : public account {
public:
    goal_account(std::string account_name, std::string parent_account_id,
                 double monthly_budget, double current_balance = 0.0,
                 double target_amount = 0.0,
                 std::optional<std::string> target_date = std::nullopt,
                 std::optional<std::string> last_added_date = std::nullopt)
        : account(account_name, account_type::GOAL_ACCOUNT),
          _parent_account_id(parent_account_id),
          _monthly_budget(monthly_budget),
          _current_balance(current_balance),
          _target_amount(target_amount),
          _target_date(target_date),
          _last_added_date(last_added_date) {}

    // Getters
    std::string get_parent_account_id() const { return _parent_account_id; }
    double get_monthly_budget() const { return _monthly_budget; }
    double get_current_balance() const { return _current_balance; }
    double get_target_amount() const { return _target_amount; }
    std::optional<std::string> get_target_date() const { return _target_date; }
    std::optional<std::string> get_last_added_date() const { return _last_added_date; }

    // Setters
    void set_parent_account_id(const std::string& parent_account_id) { _parent_account_id = parent_account_id; }
    void set_monthly_budget(double monthly_budget) { _monthly_budget = monthly_budget; }
    void set_current_balance(double current_balance) { _current_balance = current_balance; }
    void set_target_amount(double target_amount) { _target_amount = target_amount; }
    void set_target_date(std::optional<std::string> target_date) { _target_date = target_date; }
    void set_last_added_date(std::optional<std::string> last_added_date) { _last_added_date = last_added_date; }

private:
    std::string _parent_account_id;
    double _monthly_budget;
    double _current_balance;
    double _target_amount;
    std::optional<std::string> _target_date;
    std::optional<std::string> _last_added_date;
};
