#pragma once

#include <string>
#include <unordered_map>
#include <enums.h>
#include <database/entity.h>
#include <config.h>

class account : public virtual entity {
public:
    account();
    account(std::string id);
    account(std::string id, enums::account_type account_type);
    account(const std::unordered_map<std::string, std::string>& fields);

    ~account() override = default;

    // Getters
    std::string id() const override;
    std::string user_id() const;
    enums::account_type account_type() const;
    virtual std::string account_name() const = 0;

    // Setters
    void id(std::string id) override;
    void user_id(std::string user_id);
    void account_type(enums::account_type account_type);
    virtual void income(double amount) = 0;
    virtual void expense(double amount) = 0;

    // DB specific methods
    std::string table_name() const override;
    std::unordered_map<std::string, std::string> get() const override;
    void set(const std::unordered_map<std::string, std::string>& fields) override;
    void save() override;
    void load() override;
    void print() const override;
    std::string details() const override;

private:
    std::string _id;
    std::string _user_id = global_config.user_id;
    enums::account_type _account_type;
};