#pragma once

#include <string>
#include <unordered_map>
#include <optional>
#include <models/account.h>

class goal_account : public account, public virtual entity {
public:
    goal_account();
    goal_account(std::string goal_name, std::string parent_account_id,
                 double monthly_budget, double current_balance,
                 double target_amount, std::optional<std::string> target_date = std::nullopt,
                 std::optional<std::string> last_added_date = std::nullopt);

    // Getters
    std::string goal_name() const;
    std::string parent_account_id() const;
    double monthly_budget() const;
    double current_balance() const;
    double target_amount() const;
    std::optional<std::string> target_date() const;
    std::optional<std::string> last_added_date() const;

    // Setters
    void goal_name(const std::string& goal_name);
    void parent_account_id(const std::string& parent_account_id);
    void monthly_budget(double monthly_budget);
    void current_balance(double current_balance);
    void target_amount(double target_amount);
    void target_date(std::optional<std::string> target_date);
    void last_added_date(std::optional<std::string> last_added_date);

    // DB specific methods
    std::string table_name() const override;
    std::unordered_map<std::string, std::string> get() const override;
    void set(const std::unordered_map<std::string, std::string>& fields) override;
    void save() override;
    void load() override;
    void print() const override;

private:
    std::string _goal_name;
    std::string _parent_account_id;
    double _monthly_budget;
    double _current_balance;
    double _target_amount;
    std::optional<std::string> _target_date;
    std::optional<std::string> _last_added_date;
};
