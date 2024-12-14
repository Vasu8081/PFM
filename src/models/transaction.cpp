#include <models/transaction.h>
#include <iostream>
#include <sstream>
#include <unordered_map>

// Default constructor
transaction::transaction() = default;

// Constructor with parameters
transaction::transaction(std::string description, double amount,
                         std::string transaction_type, std::string from_account_id,
                         std::string to_account_id, std::string category_account_id,
                         std::string moved_from_account, std::string date,
                         std::optional<std::string> proof_document)
    : _description(description), _amount(amount), _transaction_type(transaction_type),
      _from_account_id(from_account_id), _to_account_id(to_account_id),
      _category_account_id(category_account_id), _moved_from_account(moved_from_account),
      _date(date), _proof_document(proof_document) {}

// Getter definitions
std::string transaction::id() const { return _id; }
std::string transaction::description() const { return _description; }
double transaction::amount() const { return _amount; }
std::string transaction::transaction_type() const { return _transaction_type; }
std::string transaction::from_account_id() const { return _from_account_id; }
std::string transaction::to_account_id() const { return _to_account_id; }
std::string transaction::category_account_id() const { return _category_account_id; }
std::string transaction::moved_from_account() const { return _moved_from_account; }
std::string transaction::date() const { return _date; }
std::optional<std::string> transaction::proof_document() const { return _proof_document; }

// Setter definitions
void transaction::id(std::string id) { _id = id; }
void transaction::description(const std::string& description) { _description = description; }
void transaction::amount(double amount) { _amount = amount; }
void transaction::transaction_type(const std::string& transaction_type) { _transaction_type = transaction_type; }
void transaction::from_account_id(const std::string& from_account_id) { _from_account_id = from_account_id; }
void transaction::to_account_id(const std::string& to_account_id) { _to_account_id = to_account_id; }
void transaction::category_account_id(const std::string& category_account_id) { _category_account_id = category_account_id; }
void transaction::moved_from_account(const std::string& moved_from_account) { _moved_from_account = moved_from_account; }
void transaction::date(const std::string& date) { _date = date; }
void transaction::proof_document(std::optional<std::string> proof_document) { _proof_document = proof_document; }

std::string transaction::table_name() const {
    return "transactions";
}

std::unordered_map<std::string, std::string> transaction::get() const {
    std::unordered_map<std::string, std::string> fields;
    fields["id"] = id();
    fields["description"] = description();
    fields["amount"] = std::to_string(amount());
    fields["transaction_type"] = transaction_type();
    fields["from_account_id"] = from_account_id();
    fields["to_account_id"] = to_account_id();
    fields["category_account_id"] = category_account_id();
    fields["moved_from_account"] = moved_from_account();
    fields["date"] = date();
    fields["proof_document"] = _proof_document.value_or("NULL");
    return fields;
}

void transaction::set(const std::unordered_map<std::string, std::string>& fields) {
    id(fields.at("id"));
    description(fields.at("description"));
    amount(std::stod(fields.at("amount")));
    transaction_type(fields.at("transaction_type"));
    from_account_id(fields.at("from_account_id"));
    to_account_id(fields.at("to_account_id"));
    category_account_id(fields.at("category_account_id"));
    moved_from_account(fields.at("moved_from_account"));
    date(fields.at("date"));
    proof_document(fields.at("proof_document"));
}

void transaction::save() {
    auto fields = get();
    if (id().empty()) {
        db->insert(fields, table_name());
    }
    db->update(fields, table_name());
    set(fields);
}

void transaction::load() {
    auto fields = get();
    db->fetch(fields, table_name());
    set(fields);
}

void transaction::print() const {
    std::stringstream text;
    text << "Transaction ID: " << id() << std::endl;
    text << "Description: " << description() << std::endl;
    text << "Amount: " << amount() << std::endl;
    text << "Transaction Type: " << transaction_type() << std::endl;
    text << "From Account: " << from_account_id() << std::endl;
    text << "To Account: " << to_account_id() << std::endl;
    text << "Category Account: " << category_account_id() << std::endl;
    text << "Moved From Account: " << moved_from_account() << std::endl;
    text << "Date: " << date() << std::endl;
    text << "Proof Document: " << _proof_document.value_or("None") << std::endl;
    std::cout << text.str() << std::endl;
}
