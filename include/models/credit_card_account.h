#pragma once

#include <string>
#include <unordered_map>
#include <optional>
#include <models/account.h>

class credit_card_account : public account, public virtual entity {
public:
    credit_card_account();
    credit_card_account(std::string card_name, std::string card_number,
                        std::string expiry_date, unsigned int cvv, double credit_limit,
                        double balance_due, unsigned int statement_day, unsigned int billing_date);

    // Getters
    std::string card_name() const;
    std::string card_number() const;
    std::string expiry_date() const;
    unsigned int cvv() const;
    double credit_limit() const;
    double balance_due() const;
    unsigned int statement_day() const;
    unsigned int billing_date() const;

    // Setters
    void card_name(const std::string& card_name);
    void card_number(const std::string& card_number);
    void expiry_date(const std::string& expiry_date);
    void cvv(unsigned int cvv);
    void credit_limit(double credit_limit);
    void balance_due(double balance_due);
    void statement_day(unsigned int statement_day);
    void billing_date(unsigned int billing_date);

    // DB specific methods
    std::string table_name() const override;
    std::unordered_map<std::string, std::string> get() const override;
    void set(const std::unordered_map<std::string, std::string>& fields) override;
    void save() override;
    void load() override;
    void print() const override;

private:
    std::string _card_name;
    std::string _card_number;
    std::string _expiry_date;
    unsigned int _cvv;
    double _credit_limit;
    double _balance_due;
    unsigned int _statement_day;
    unsigned int _billing_date;
};