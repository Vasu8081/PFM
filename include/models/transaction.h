#pragma once
#include <iostream>
#include <optional>

class transaction {
public:
    transaction(std::string from_account_id, std::string to_account_id,
                double amount, std::string transaction_type,
                std::string date,
                std::optional<std::string> category_account_id = std::nullopt,
                std::optional<std::string> moved_from_account = std::nullopt,
                std::optional<std::string> description = std::nullopt,
                std::optional<std::vector<uint8_t>> proof_document = std::nullopt)
        : _from_account_id(from_account_id),
          _to_account_id(to_account_id),
          _amount(amount),
          _transaction_type(transaction_type),
          _date(date),
          _category_account_id(category_account_id),
          _moved_from_account(moved_from_account),
          _description(description),
          _proof_document(proof_document) {}

    // Getters
    std::string get_from_account_id() const { return _from_account_id; }
    std::string get_to_account_id() const { return _to_account_id; }
    double get_amount() const { return _amount; }
    std::string get_transaction_type() const { return _transaction_type; }
    std::string get_date() const { return _date; }
    std::optional<std::string> get_category_account_id() const { return _category_account_id; }
    std::optional<std::string> get_moved_from_account() const { return _moved_from_account; }
    std::optional<std::string> get_description() const { return _description; }
    std::optional<std::vector<uint8_t>> get_proof_document() const { return _proof_document; }

    // Setters
    void set_from_account_id(const std::string& from_account_id) { _from_account_id = from_account_id; }
    void set_to_account_id(const std::string& to_account_id) { _to_account_id = to_account_id; }
    void set_amount(double amount) { _amount = amount; }
    void set_transaction_type(const std::string& transaction_type) { _transaction_type = transaction_type; }
    void set_date(const std::string& date) { _date = date; }
    void set_category_account_id(std::optional<std::string> category_account_id) { _category_account_id = category_account_id; }
    void set_moved_from_account(std::optional<std::string> moved_from_account) { _moved_from_account = moved_from_account; }
    void set_description(std::optional<std::string> description) { _description = description; }
    void set_proof_document(std::optional<std::vector<uint8_t>> proof_document) { _proof_document = proof_document; }

private:
    std::string _from_account_id;
    std::string _to_account_id;
    double _amount;
    std::string _transaction_type;
    std::string _date;
    std::optional<std::string> _category_account_id;
    std::optional<std::string> _moved_from_account;
    std::optional<std::string> _description;
    std::optional<std::vector<uint8_t>> _proof_document;
};
