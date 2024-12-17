#pragma once

#include <string>
#include <unordered_map>
#include <optional>
#include <models/account.h>

class category_account : public account, public virtual entity {
public:
    category_account();
    category_account(std::string category_name, std::string parent_account_id,
                     double monthly_budget, double current_balance,
                     std::optional<std::string> last_added_date = std::nullopt);

    // Getters
    std::string account_name() const override{ return _category_name; }
    std::string category_name() const;
    std::string parent_account_id() const;
    double monthly_budget() const;
    double current_balance() const;
    std::optional<std::string> last_added_date() const;

    // Setters
    void category_name(const std::string& category_name);
    void parent_account_id(const std::string& parent_account_id);
    void monthly_budget(double monthly_budget);
    void current_balance(double current_balance);
    void last_added_date(std::optional<std::string> last_added_date);
    void income(double amount) override { _current_balance += amount; };
    void expense(double amount) override { _current_balance -= amount; };

    // DB specific methods
    std::string table_name() const override;
    std::unordered_map<std::string, std::string> get() const override;
    void set(const std::unordered_map<std::string, std::string>& fields) override;
    void save() override;
    void load() override;
    void print() const override;
    std::string details() const override;

private:
    std::string _category_name;
    std::string _parent_account_id;
    double _monthly_budget;
    double _current_balance;
    std::optional<std::string> _last_added_date;
};
