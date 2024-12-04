#pragma once
#include <iostream>
#include <optional>
#include <enums.h>
#include <models/account.h>

class bank_account : public account {
public:
    bank_account(std::string account_name, std::string account_number,
                 std::string bank_name, double balance,
                 double hold_amount = 0, std::optional<std::string> ifsc_code = std::nullopt)
        : account(account_name, account_type::BANK_ACCOUNT),
          _account_number(account_number), _bank_name(bank_name),
          _balance(balance), _hold_amount(hold_amount), _ifsc_code(ifsc_code) {}

    // Getters
    std::string get_account_number() const { return _account_number; }
    std::string get_bank_name() const { return _bank_name; }
    double get_balance() const { return _balance; }
    double get_hold_amount() const { return _hold_amount; }
    std::optional<std::string> get_ifsc_code() const { return _ifsc_code; }

    // Setters
    void set_account_number(const std::string& account_number) { _account_number = account_number; }
    void set_bank_name(const std::string& bank_name) { _bank_name = bank_name; }
    void set_balance(double balance) { _balance = balance; }
    void set_hold_amount(double hold_amount) { _hold_amount = hold_amount; }
    void set_ifsc_code(std::optional<std::string> ifsc_code) { _ifsc_code = ifsc_code; }

private:
    std::string _account_number;
    std::string _bank_name;
    double _balance;
    double _hold_amount;
    std::optional<std::string> _ifsc_code;
};