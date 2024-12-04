#pragma once
#include <iostream>
#include <optional>
#include <enums.h>
#include <models/account.h>

class chit_account : public account {
public:
    chit_account(std::string account_name, double monthly_budget,
                 double accumulated_balance = 0.0,
                 std::optional<double> mature_amount = std::nullopt,
                 std::optional<std::string> mature_date = std::nullopt,
                 std::optional<std::string> last_added_date = std::nullopt)
        : account(account_name, account_type::CHIT_ACCOUNT),
          _monthly_budget(monthly_budget),
          _accumulated_balance(accumulated_balance),
          _mature_amount(mature_amount),
          _mature_date(mature_date),
          _last_added_date(last_added_date) {}

    // Getters
    double get_monthly_budget() const { return _monthly_budget; }
    double get_accumulated_balance() const { return _accumulated_balance; }
    std::optional<double> get_mature_amount() const { return _mature_amount; }
    std::optional<std::string> get_mature_date() const { return _mature_date; }
    std::optional<std::string> get_last_added_date() const { return _last_added_date; }

    // Setters
    void set_monthly_budget(double monthly_budget) { _monthly_budget = monthly_budget; }
    void set_accumulated_balance(double accumulated_balance) { _accumulated_balance = accumulated_balance; }
    void set_mature_amount(std::optional<double> mature_amount) { _mature_amount = mature_amount; }
    void set_mature_date(std::optional<std::string> mature_date) { _mature_date = mature_date; }
    void set_last_added_date(std::optional<std::string> last_added_date) { _last_added_date = last_added_date; }

private:
    double _monthly_budget;
    double _accumulated_balance;
    std::optional<double> _mature_amount;
    std::optional<std::string> _mature_date;
    std::optional<std::string> _last_added_date;
};
