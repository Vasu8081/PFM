#pragma once

#include <string>
#include <unordered_map>
#include <models/account.h>

class loan_account : public account, public virtual entity {
public:
    loan_account();
    loan_account(std::string loan_name, std::string loan_account_number,
                 double principal_amount, double remaining_principal,
                 double interest_rate_per_annum, std::string installment_start_date,
                 int term_in_months);

    // Getters
    std::string account_name() const override{ return _loan_name; }
    std::string loan_name() const;
    std::string loan_account_number() const;
    double principal_amount() const;
    double remaining_principal() const;
    double interest_rate_per_annum() const;
    std::string installment_start_date() const;
    int term_in_months() const;

    // Setters
    void loan_name(const std::string& loan_name);
    void loan_account_number(const std::string& loan_account_number);
    void principal_amount(double principal_amount);
    void remaining_principal(double remaining_principal);
    void interest_rate_per_annum(double interest_rate_per_annum);
    void installment_start_date(const std::string& installment_start_date);
    void term_in_months(int term_in_months);

    // DB specific methods
    std::string table_name() const override;
    std::unordered_map<std::string, std::string> get() const override;
    void set(const std::unordered_map<std::string, std::string>& fields) override;
    void save() override;
    void load() override;
    void print() const override;

private:
    std::string _loan_name;
    std::string _loan_account_number;
    double _principal_amount;
    double _remaining_principal;
    double _interest_rate_per_annum;
    std::string _installment_start_date;
    int _term_in_months;
};
