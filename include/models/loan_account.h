#pragma once
#include <iostream>
#include <optional>
#include <enums.h>
#include <models/account.h>

class loan_account : public account {
public:
    loan_account(std::string account_name, double principal_amount,
                 double remaining_principal, double interest_rate,
                 std::string installment_start_date, int term_in_months)
        : account(account_name, account_type::LOAN_ACCOUNT),
          _principal_amount(principal_amount),
          _remaining_principal(remaining_principal),
          _interest_rate(interest_rate),
          _installment_start_date(installment_start_date),
          _term_in_months(term_in_months) {}

    // Getters
    double get_principal_amount() const { return _principal_amount; }
    double get_remaining_principal() const { return _remaining_principal; }
    double get_interest_rate() const { return _interest_rate; }
    std::string get_installment_start_date() const { return _installment_start_date; }
    int get_term_in_months() const { return _term_in_months; }

    // Setters
    void set_principal_amount(double principal_amount) { _principal_amount = principal_amount; }
    void set_remaining_principal(double remaining_principal) { _remaining_principal = remaining_principal; }
    void set_interest_rate(double interest_rate) { _interest_rate = interest_rate; }
    void set_installment_start_date(const std::string& installment_start_date) {
        _installment_start_date = installment_start_date;
    }
    void set_term_in_months(int term_in_months) { _term_in_months = term_in_months; }

private:
    double _principal_amount;
    double _remaining_principal;
    double _interest_rate;
    std::string _installment_start_date;
    int _term_in_months;
};
