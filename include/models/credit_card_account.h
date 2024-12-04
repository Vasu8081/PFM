#pragma once
#include <iostream>
#include <optional>
#include <enums.h>
#include <models/account.h>

class credit_card_account : public account {
public:
    credit_card_account(std::string account_name, std::string card_number, double credit_limit, double balance_due, std::string statement_date, std::string billing_date, std::string expiry_date, int cvv)
        : account(account_name, account_type::CREDIT_CARD_ACCOUNT),
          _card_number(card_number), _credit_limit(credit_limit),
          _balance_due(balance_due), _statement_date(statement_date),
          _billing_date(billing_date), _expiry_date(expiry_date), _cvv(cvv) {}

    // Getters
    std::string get_card_number() const { return _card_number; }
    double get_credit_limit() const { return _credit_limit; }
    double get_balance_due() const { return _balance_due; }
    std::string get_statement_date() const { return _statement_date; }
    std::string get_billing_date() const { return _billing_date; }
    std::string get_expiry_date() const { return _expiry_date; }
    int get_cvv() const { return _cvv; }

    // Setters
    void set_card_number(const std::string& card_number) { _card_number = card_number; }
    void set_credit_limit(double credit_limit) { _credit_limit = credit_limit; }
    void set_balance_due(double balance_due) { _balance_due = balance_due; }
    void set_statement_date(const std::string& statement_date) { _statement_date = statement_date; }
    void set_billing_date(const std::string& billing_date) { _billing_date = billing_date; }
    void set_expiry_date(const std::string& expiry_date) { _expiry_date = expiry_date; }
    void set_cvv(int cvv) { _cvv = cvv; }

private:
    std::string _card_number;
    double _credit_limit;
    double _balance_due;
    std::string _statement_date;
    std::string _billing_date;
    std::string _expiry_date;
    int _cvv;
};