#include <models/asset_account.h>

asset_account::asset_account() = default;

asset_account::asset_account(std::string asset_name, std::string asset_type, double cost_of_ownership,
                             double paid_amount, double current_market_value, std::string purchase_date)
    : account("", enums::account_type::ASSET_ACCOUNT),
      _asset_name(asset_name), _asset_type(asset_type),
      _cost_of_ownership(cost_of_ownership), _paid_amount(paid_amount),
      _current_market_value(current_market_value), _purchase_date(purchase_date) {}

// Getter definitions
std::string asset_account::asset_name() const {
    return _asset_name;
}

std::string asset_account::asset_type() const {
    return _asset_type;
}

double asset_account::cost_of_ownership() const {
    return _cost_of_ownership;
}

double asset_account::paid_amount() const {
    return _paid_amount;
}

double asset_account::current_market_value() const {
    return _current_market_value;
}

std::string asset_account::purchase_date() const {
    return _purchase_date;
}

// Setter definitions
void asset_account::asset_name(const std::string& asset_name) {
    _asset_name = asset_name;
}

void asset_account::asset_type(const std::string& asset_type) {
    _asset_type = asset_type;
}

void asset_account::cost_of_ownership(double cost_of_ownership) {
    _cost_of_ownership = cost_of_ownership;
}

void asset_account::paid_amount(double paid_amount) {
    _paid_amount = paid_amount;
}

void asset_account::current_market_value(double current_market_value) {
    _current_market_value = current_market_value;
}

void asset_account::purchase_date(const std::string& purchase_date) {
    _purchase_date = purchase_date;
}

// DB specific method definitions
std::string asset_account::table_name() const {
    return "asset_accounts";
}

std::unordered_map<std::string, std::string> asset_account::get() const {
    std::unordered_map<std::string, std::string> fields;
    fields["id"] = id();
    fields["asset_name"] = asset_name();
    fields["asset_type"] = asset_type();
    fields["cost_of_ownership"] = std::to_string(cost_of_ownership());
    fields["paid_amount"] = std::to_string(paid_amount());
    fields["current_market_value"] = std::to_string(current_market_value());
    fields["purchase_date"] = purchase_date();
    return fields;
}

void asset_account::set(const std::unordered_map<std::string, std::string>& fields) {
    id(fields.at("id"));
    asset_name(fields.at("asset_name"));
    asset_type(fields.at("asset_type"));
    cost_of_ownership(std::stod(fields.at("cost_of_ownership")));
    paid_amount(std::stod(fields.at("paid_amount")));
    current_market_value(std::stod(fields.at("current_market_value")));
    purchase_date(fields.at("purchase_date"));
}

void asset_account::save() {
    account::save();
    auto fields = get();
    db->insert(fields, table_name());
    set(fields);
}

void asset_account::print() const {
    std::stringstream text;
    text << "account_type: " << account_t(account_type()) << std::endl;
    text << "account id: " << id() << std::endl;
    text << "asset_name: " << asset_name() << std::endl;
    text << "asset_type: " << asset_type() << std::endl;
    text << "cost_of_ownership: " << cost_of_ownership() << std::endl;
    text << "paid_amount: " << paid_amount() << std::endl;
    text << "current_market_value: " << current_market_value() << std::endl;
    text << "purchase_date: " << purchase_date();
    std::cout << text.str() << std::endl;
}
