#pragma once

#include <string>
#include <unordered_map>
#include <optional>
#include <models/account.h>

class borrow_give_account : public account, public virtual entity {
public:
    borrow_give_account();
    borrow_give_account(std::string person_name, double balance_due,
                        std::optional<std::string> due_date = std::nullopt);

    // Getters
    std::string person_name() const;
    double balance_due() const;
    std::optional<std::string> due_date() const;

    // Setters
    void person_name(const std::string& person_name);
    void balance_due(double balance_due);
    void due_date(std::optional<std::string> due_date);

    // DB specific methods
    std::string table_name() const override;
    std::unordered_map<std::string, std::string> get() const override;
    void set(const std::unordered_map<std::string, std::string>& fields) override;
    void print() const override;

private:
    std::string _person_name;
    double _balance_due;
    std::optional<std::string> _due_date;
};
