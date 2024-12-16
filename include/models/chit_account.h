#pragma once

#include <string>
#include <unordered_map>
#include <optional>
#include <models/account.h>

class chit_account : public account, public virtual entity {
public:
    chit_account();
    chit_account(std::string chit_name, double monthly_budget, double accumulated_balance,
                 double mature_amount, std::optional<std::string> mature_date = std::nullopt,
                 std::optional<std::string> last_added_date = std::nullopt);

    // Getters
    std::string account_name() const override{ return _chit_name; }
    std::string chit_name() const;
    double monthly_budget() const;
    double accumulated_balance() const;
    double mature_amount() const;
    std::optional<std::string> mature_date() const;
    std::optional<std::string> last_added_date() const;

    // Setters
    void chit_name(const std::string& chit_name);
    void monthly_budget(double monthly_budget);
    void accumulated_balance(double accumulated_balance);
    void mature_amount(double mature_amount);
    void mature_date(std::optional<std::string> mature_date);
    void last_added_date(std::optional<std::string> last_added_date);

    // DB specific methods
    std::string table_name() const override;
    std::unordered_map<std::string, std::string> get() const override;
    void set(const std::unordered_map<std::string, std::string>& fields) override;
    void save() override;
    void load() override;
    void print() const override;

private:
    std::string _chit_name;
    double _monthly_budget;
    double _accumulated_balance;
    double _mature_amount;
    std::optional<std::string> _mature_date;
    std::optional<std::string> _last_added_date;
};
