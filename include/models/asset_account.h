#pragma once

#include <string>
#include <unordered_map>
#include <optional>
#include <models/account.h>

class asset_account : public account, public virtual entity {
public:
    asset_account();
    asset_account(std::string asset_name, std::string asset_type, double cost_of_ownership,
                  double paid_amount = 0, double current_market_value = 0,
                  std::string purchase_date = "");

    // Getters
    std::string account_name() const override { return _asset_name; }
    std::string asset_name() const;
    std::string asset_type() const;
    double cost_of_ownership() const;
    double paid_amount() const;
    double current_market_value() const;
    std::string purchase_date() const;

    // Setters
    void asset_name(const std::string& asset_name);
    void asset_type(const std::string& asset_type);
    void cost_of_ownership(double cost_of_ownership);
    void paid_amount(double paid_amount);
    void current_market_value(double current_market_value);
    void purchase_date(const std::string& purchase_date);

    // DB specific methods
    std::string table_name() const override;
    std::unordered_map<std::string, std::string> get() const override;
    void set(const std::unordered_map<std::string, std::string>& fields) override;
    void save() override;
    void load() override;
    void print() const override;

private:
    std::string _asset_name;
    std::string _asset_type;
    double _cost_of_ownership;
    double _paid_amount;
    double _current_market_value;
    std::string _purchase_date;
};
