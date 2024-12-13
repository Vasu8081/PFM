#include <models/borrow_give_account.h>

borrow_give_account::borrow_give_account() = default;

borrow_give_account::borrow_give_account(std::string person_name, double balance_due,
                                         std::optional<std::string> due_date)
    : account("", enums::account_type::BORROW_GIVE_ACCOUNT),
      _person_name(person_name), _balance_due(balance_due), _due_date(due_date) {}

// Getter definitions
std::string borrow_give_account::person_name() const {
    return _person_name;
}

double borrow_give_account::balance_due() const {
    return _balance_due;
}

std::optional<std::string> borrow_give_account::due_date() const {
    return _due_date;
}

// Setter definitions
void borrow_give_account::person_name(const std::string& person_name) {
    _person_name = person_name;
}

void borrow_give_account::balance_due(double balance_due) {
    _balance_due = balance_due;
}

void borrow_give_account::due_date(std::optional<std::string> due_date) {
    _due_date = due_date;
}

// DB specific method definitions
std::string borrow_give_account::table_name() const {
    return "borrow_give_accounts";
}

std::unordered_map<std::string, std::string> borrow_give_account::get() const {
    std::unordered_map<std::string, std::string> fields;
    fields["id"] = id();
    fields["person_name"] = person_name();
    fields["balance_due"] = std::to_string(balance_due());
    fields["due_date"] = _due_date.value_or("NULL");
    return fields;
}

void borrow_give_account::set(const std::unordered_map<std::string, std::string>& fields) {
    id(fields.at("id"));
    person_name(fields.at("person_name"));
    balance_due(std::stod(fields.at("balance_due")));
    due_date(fields.at("due_date"));
}

void borrow_give_account::save() {
    account::save();
    auto fields = get();
    db->insert(fields, table_name());
    set(fields);
}

void borrow_give_account::print() const {
    std::stringstream text;
    text << "account_type: " << account_t(account_type()) << std::endl;
    text << "account id: " << id() << std::endl;
    text << "person_name: " << person_name() << std::endl;
    text << "balance_due: " << balance_due() << std::endl;
    text << "due_date: " << _due_date.value_or("NULL");
    std::cout << text.str() << std::endl;
}
