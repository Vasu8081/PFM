#pragma once

#include <string>
#include <unordered_map>
#include <optional>
#include <models/account.h>

class bank_account : public account, public virtual entity {
public:
    bank_account();
    bank_account(std::string account_number,
                 std::string bank_name, double balance,
                 double hold_amount = 0, std::optional<std::string> ifsc_code = std::nullopt);

    // Getters
    std::string account_name() const override { return _bank_name; }
    std::string account_number() const;
    std::string bank_name() const;
    double balance() const;
    double hold_amount() const;
    std::optional<std::string> ifsc_code() const;

    // Setters

    void account_number(const std::string& account_number);
    void bank_name(const std::string& bank_name);
    void balance(double balance);
    void hold_amount(double hold_amount);
    void ifsc_code(std::optional<std::string> ifsc_code);
    void income(double amount) override { _balance += amount; };
    void expense(double amount) override { _balance -= amount; };

    // DB specific methods
    std::string table_name() const override;
    std::unordered_map<std::string, std::string> get() const override;
    void set(const std::unordered_map<std::string, std::string>& fields) override;
    void save() override;
    void load() override;
    void print() const override;
    std::string details() const override;

private:
    std::string _account_number;
    std::string _bank_name;
    double _balance;
    double _hold_amount;
    std::optional<std::string> _ifsc_code;
};
