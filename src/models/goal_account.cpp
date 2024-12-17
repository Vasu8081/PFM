#include <models/goal_account.h>

goal_account::goal_account()  {
    account_type(enums::account_type::GOAL_ACCOUNT);
}

goal_account::goal_account(std::string goal_name, std::string parent_account_id,
                           double monthly_budget, double current_balance,
                           double target_amount, std::optional<std::string> target_date,
                           std::optional<std::string> last_added_date)
    : account("", enums::account_type::GOAL_ACCOUNT),
      _goal_name(goal_name), _parent_account_id(parent_account_id),
      _monthly_budget(monthly_budget), _current_balance(current_balance),
      _target_amount(target_amount), _target_date(target_date),
      _last_added_date(last_added_date) {}

// Getter definitions
std::string goal_account::goal_name() const {
    return _goal_name;
}

std::string goal_account::parent_account_id() const {
    return _parent_account_id;
}

double goal_account::monthly_budget() const {
    return _monthly_budget;
}

double goal_account::current_balance() const {
    return _current_balance;
}

double goal_account::target_amount() const {
    return _target_amount;
}

std::optional<std::string> goal_account::target_date() const {
    return _target_date;
}

std::optional<std::string> goal_account::last_added_date() const {
    return _last_added_date;
}

// Setter definitions
void goal_account::goal_name(const std::string& goal_name) {
    _goal_name = goal_name;
}

void goal_account::parent_account_id(const std::string& parent_account_id) {
    _parent_account_id = parent_account_id;
}

void goal_account::monthly_budget(double monthly_budget) {
    _monthly_budget = monthly_budget;
}

void goal_account::current_balance(double current_balance) {
    _current_balance = current_balance;
}

void goal_account::target_amount(double target_amount) {
    _target_amount = target_amount;
}

void goal_account::target_date(std::optional<std::string> target_date) {
    _target_date = target_date;
}

void goal_account::last_added_date(std::optional<std::string> last_added_date) {
    _last_added_date = last_added_date;
}

// DB specific method definitions
std::string goal_account::table_name() const {
    return "goal_accounts";
}

std::unordered_map<std::string, std::string> goal_account::get() const {
    std::unordered_map<std::string, std::string> fields;
    fields["id"] = id();
    fields["goal_name"] = goal_name();
    fields["parent_account_id"] = parent_account_id();
    fields["monthly_budget"] = std::to_string(monthly_budget());
    fields["current_balance"] = std::to_string(current_balance());
    fields["target_amount"] = std::to_string(target_amount());
    fields["target_date"] = _target_date.value_or("NULL");
    fields["last_added_date"] = _last_added_date.value_or("NULL");
    return fields;
}

void goal_account::set(const std::unordered_map<std::string, std::string>& fields) {
    id(fields.at("id"));
    goal_name(fields.at("goal_name"));
    parent_account_id(fields.at("parent_account_id"));
    monthly_budget(std::stod(fields.at("monthly_budget")));
    current_balance(std::stod(fields.at("current_balance")));
    target_amount(std::stod(fields.at("target_amount")));
    target_date(fields.at("target_date"));
    last_added_date(fields.at("last_added_date"));
}

void goal_account::save() {
    auto fields = get();
    if (id().empty()) {
        account::save();
        fields["id"] = id();
        db->insert(fields, table_name());
    }
    else {
        db->update(fields, table_name());
    }
    set(fields);
}

void goal_account::load() {
    account::load();
    auto fields = get();
    db->fetch(fields, table_name());
    set(fields);
}

void goal_account::print() const {
    std::cout << details() << std::endl;
}

std::string goal_account::details() const {
    std::stringstream text;
    text << "account_type: " << account_t(account_type()) << std::endl;
    text << "account id: " << id() << std::endl;
    text << "goal_name: " << goal_name() << std::endl;
    text << "parent_account_id: " << parent_account_id() << std::endl;
    text << "monthly_budget: " << monthly_budget() << std::endl;
    text << "current_balance: " << current_balance() << std::endl;
    text << "target_amount: " << target_amount() << std::endl;
    text << "target_date: " << _target_date.value_or("NULL") << std::endl;
    text << "last_added_date: " << _last_added_date.value_or("NULL");
    return text.str();
}
