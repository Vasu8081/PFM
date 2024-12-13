#include <models/bank_account.h>


bank_account::bank_account() = default;

bank_account::bank_account(std::string account_number,
                           std::string bank_name, double balance,
                           double hold_amount, std::optional<std::string> ifsc_code)
    : account("", enums::account_type::BANK_ACCOUNT),
      _account_number(account_number), _bank_name(bank_name),
      _balance(balance), _hold_amount(hold_amount), _ifsc_code(ifsc_code) {}

// Getter definitions
std::string bank_account::account_number() const {
    return _account_number;
}

std::string bank_account::bank_name() const {
    return _bank_name;
}

double bank_account::balance() const {
    return _balance;
}

double bank_account::hold_amount() const {
    return _hold_amount;
}

std::optional<std::string> bank_account::ifsc_code() const {
    return _ifsc_code;
}

// Setter definitions
void bank_account::account_number(const std::string& account_number) {
    _account_number = account_number;
}

void bank_account::bank_name(const std::string& bank_name) {
    _bank_name = bank_name;
}

void bank_account::balance(double balance) {
    _balance = balance;
}

void bank_account::hold_amount(double hold_amount) {
    _hold_amount = hold_amount;
}

void bank_account::ifsc_code(std::optional<std::string> ifsc_code) {
    _ifsc_code = ifsc_code;
}

// DB specific method definitions
std::string bank_account::table_name() const {
    return "bank_accounts";
}

std::unordered_map<std::string, std::string> bank_account::get() const {
    std::unordered_map<std::string, std::string> fields;
    fields["id"] = id();
    fields["account_number"] = account_number();
    fields["bank_name"] = bank_name();
    fields["balance"] = std::to_string(balance());
    fields["hold_amount"] = std::to_string(hold_amount());
    fields["ifsc_code"] = _ifsc_code.value_or("NULL");
    return fields;
}

void bank_account::set(const std::unordered_map<std::string, std::string>& fields) {
    id(fields.at("id"));
    account_number(fields.at("account_number"));
    bank_name(fields.at("bank_name"));
    balance(std::stod(fields.at("balance")));
    hold_amount(std::stod(fields.at("hold_amount")));
    ifsc_code(fields.at("ifsc_code"));
}

void bank_account::save() {
    account::save();
    auto fields = get();
    db->insert(fields, table_name());
    set(fields);
}

void bank_account::print() const {
    std::stringstream text;
    text << "account_type: " << account_t(account_type()) << std::endl;
    text << "account id: " << id() << std::endl;
    text << "account_number: " << account_number() << std::endl;
    text << "bank_name: " << bank_name() << std::endl;
    text << "balance: " << balance() << std::endl;
    text << "hold_amount: " << hold_amount() << std::endl;
    text << "IFSC code: " << _ifsc_code.value_or("NULL");
    std::cout << text.str() << std::endl;
}
