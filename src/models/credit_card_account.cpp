#include <models/credit_card_account.h>

credit_card_account::credit_card_account() = default;

credit_card_account::credit_card_account(std::string card_name, std::string card_number,
                                         std::string expiry_date, unsigned int cvv, double credit_limit,
                                         double balance_due, unsigned int statement_day, unsigned int billing_date)
    : account("", enums::account_type::CREDIT_CARD_ACCOUNT),
      _card_name(card_name), _card_number(card_number), _expiry_date(expiry_date),
      _cvv(cvv), _credit_limit(credit_limit), _balance_due(balance_due),
      _statement_day(statement_day), _billing_date(billing_date) {}

// Getter definitions
std::string credit_card_account::card_name() const {
    return _card_name;
}

std::string credit_card_account::card_number() const {
    return _card_number;
}

std::string credit_card_account::expiry_date() const {
    return _expiry_date;
}

unsigned int credit_card_account::cvv() const {
    return _cvv;
}

double credit_card_account::credit_limit() const {
    return _credit_limit;
}

double credit_card_account::balance_due() const {
    return _balance_due;
}

unsigned int credit_card_account::statement_day() const {
    return _statement_day;
}

unsigned int credit_card_account::billing_date() const {
    return _billing_date;
}

// Setter definitions
void credit_card_account::card_name(const std::string& card_name) {
    _card_name = card_name;
}

void credit_card_account::card_number(const std::string& card_number) {
    _card_number = card_number;
}

void credit_card_account::expiry_date(const std::string& expiry_date) {
    _expiry_date = expiry_date;
}

void credit_card_account::cvv(unsigned int cvv) {
    _cvv = cvv;
}

void credit_card_account::credit_limit(double credit_limit) {
    _credit_limit = credit_limit;
}

void credit_card_account::balance_due(double balance_due) {
    _balance_due = balance_due;
}

void credit_card_account::statement_day(unsigned int statement_day) {
    _statement_day = statement_day;
}

void credit_card_account::billing_date(unsigned int billing_date) {
    _billing_date = billing_date;
}

// DB specific method definitions
std::string credit_card_account::table_name() const {
    return "credit_card_accounts";
}

std::unordered_map<std::string, std::string> credit_card_account::get() const {
    std::unordered_map<std::string, std::string> fields;
    fields["id"] = id();
    fields["card_name"] = card_name();
    fields["card_number"] = card_number();
    fields["expiry_date"] = expiry_date();
    fields["cvv"] = std::to_string(cvv());
    fields["credit_limit"] = std::to_string(credit_limit());
    fields["balance_due"] = std::to_string(balance_due());
    fields["statement_day"] = std::to_string(statement_day());
    fields["billing_date"] = std::to_string(billing_date());
    return fields;
}

void credit_card_account::set(const std::unordered_map<std::string, std::string>& fields) {
    id(fields.at("id"));
    card_name(fields.at("card_name"));
    card_number(fields.at("card_number"));
    expiry_date(fields.at("expiry_date"));
    cvv(std::stoi(fields.at("cvv")));
    credit_limit(std::stod(fields.at("credit_limit")));
    balance_due(std::stod(fields.at("balance_due")));
    statement_day(std::stoi(fields.at("statement_day")));
    billing_date(std::stoi(fields.at("billing_date")));
}

void credit_card_account::save() {
    account::save();
    auto fields = get();
    db->insert(fields, table_name());
    set(fields);
}

void credit_card_account::print() const {
    std::stringstream text;
    text << "account_type: " << account_t(account_type()) << std::endl;
    text << "account id: " << id() << std::endl;
    text << "card_name: " << card_name() << std::endl;
    text << "card_number: " << card_number() << std::endl;
    text << "expiry_date: " << expiry_date() << std::endl;
    text << "cvv: " << cvv() << std::endl;
    text << "credit_limit: " << credit_limit() << std::endl;
    text << "balance_due: " << balance_due() << std::endl;
    text << "statement_day: " << statement_day() << std::endl;
    text << "billing_date: " << billing_date() << std::endl;
    std::cout << text.str() << std::endl;
}