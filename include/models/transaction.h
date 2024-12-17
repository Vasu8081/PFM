#pragma once

#include <string>
#include <unordered_map>
#include <optional>
#include <database/entity.h>

class transaction : public virtual entity {
public:
    // Constructors
    transaction();
    transaction(std::string description, double amount,
                std::string transaction_type, std::string from_account_id,
                std::string to_account_id, std::string category_account_id,
                std::string moved_from_account, std::string date,
                std::optional<std::string> proof_document = std::nullopt);

    // Getters
    std::string id() const override;
    std::string description() const;
    double amount() const;
    std::string transaction_type() const;
    std::string from_account_id() const;
    std::string to_account_id() const;
    std::string category_account_id() const;
    std::string moved_from_account() const;
    std::string date() const;
    std::optional<std::string> proof_document() const;

    // Setters
    void id(std::string id) override;
    void description(const std::string& description);
    void amount(double amount);
    void transaction_type(const std::string& transaction_type);
    void from_account_id(const std::string& from_account_id);
    void to_account_id(const std::string& to_account_id);
    void category_account_id(const std::string& category_account_id);
    void moved_from_account(const std::string& moved_from_account);
    void date(const std::string& date);
    void proof_document(std::optional<std::string> proof_document);

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
    std::string _description;
    double _amount;
    std::string _transaction_type;
    std::string _from_account_id;
    std::string _to_account_id;
    std::string _category_account_id;
    std::string _moved_from_account;
    std::string _date;
    std::optional<std::string> _proof_document;
};
