#include <models/account.h>

account::account() = default;

account::account(std::string id) : _id(id), _account_type(enums::account_type::ACCOUNT_TYPE_UNKNOWN) {}

account::account(std::string id, enums::account_type account_type)
    : _id(id), _account_type(account_type) {}

account::account(std::string id, std::string user_id, enums::account_type account_type)
    : _id(id), _user_id(user_id), _account_type(account_type) {}

account::account(const std::unordered_map<std::string, std::string>& fields) {
    account::set(fields);
}

std::string account::id() const {
    return _id;
}

std::string account::user_id() const {
    return _user_id;
}

enums::account_type account::account_type() const {
    return _account_type;
}

void account::id(std::string id) {
    _id = id;
}

void account::user_id(std::string user_id) {
    _user_id = user_id;
}

void account::account_type(enums::account_type account_type) {
    _account_type = account_type;
}

std::string account::table_name() const {
    return "accounts";
}

std::unordered_map<std::string, std::string> account::get() const {
    std::unordered_map<std::string, std::string> fields;
    fields["id"] = _id;
    fields["user_id"] = _user_id;
    fields["account_type"] = account_t(account_type());
    return fields;
}

void account::set(const std::unordered_map<std::string, std::string>& fields) {
    _id = fields.at("id");
    _user_id = fields.at("user_id");
    _account_type = account_t(fields.at("account_type"));
}

void account::print() const {
    std::stringstream text;
    text << "ID: " << _id << std::endl;
    text << "User ID: " << _user_id << std::endl;
    text << "Account_type: " << account_t(account_type()) << std::endl;
}
