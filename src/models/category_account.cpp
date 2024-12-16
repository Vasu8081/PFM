#include <models/category_account.h>

category_account::category_account()  {
    account_type(enums::account_type::CATEGORY_ACCOUNT);
}

category_account::category_account(std::string category_name, std::string parent_account_id,
                                   double monthly_budget, double current_balance,
                                   std::optional<std::string> last_added_date)
    : account("", enums::account_type::CATEGORY_ACCOUNT),
      _category_name(category_name), _parent_account_id(parent_account_id),
      _monthly_budget(monthly_budget), _current_balance(current_balance),
      _last_added_date(last_added_date) {}

// Getter definitions
std::string category_account::category_name() const {
    return _category_name;
}

std::string category_account::parent_account_id() const {
    return _parent_account_id;
}

double category_account::monthly_budget() const {
    return _monthly_budget;
}

double category_account::current_balance() const {
    return _current_balance;
}

std::optional<std::string> category_account::last_added_date() const {
    return _last_added_date;
}

// Setter definitions
void category_account::category_name(const std::string& category_name) {
    _category_name = category_name;
}

void category_account::parent_account_id(const std::string& parent_account_id) {
    _parent_account_id = parent_account_id;
}

void category_account::monthly_budget(double monthly_budget) {
    _monthly_budget = monthly_budget;
}

void category_account::current_balance(double current_balance) {
    _current_balance = current_balance;
}

void category_account::last_added_date(std::optional<std::string> last_added_date) {
    _last_added_date = last_added_date;
}

// DB specific method definitions
std::string category_account::table_name() const {
    return "category_accounts";
}

std::unordered_map<std::string, std::string> category_account::get() const {
    std::unordered_map<std::string, std::string> fields;
    fields["id"] = id();
    fields["category_name"] = category_name();
    fields["parent_account_id"] = parent_account_id();
    fields["monthly_budget"] = std::to_string(monthly_budget());
    fields["current_balance"] = std::to_string(current_balance());
    fields["last_added_date"] = _last_added_date.value_or("NULL");
    return fields;
}

void category_account::set(const std::unordered_map<std::string, std::string>& fields) {
    id(fields.at("id"));
    category_name(fields.at("category_name"));
    parent_account_id(fields.at("parent_account_id"));
    monthly_budget(std::stod(fields.at("monthly_budget")));
    current_balance(std::stod(fields.at("current_balance")));
    last_added_date(fields.at("last_added_date"));
}

void category_account::save() {
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

void category_account::load() {
    account::load();
    auto fields = get();
    db->fetch(fields, table_name());
    set(fields);
}

void category_account::print() const {
    std::stringstream text;
    text << "account_type: " << account_t(account_type()) << std::endl;
    text << "account id: " << id() << std::endl;
    text << "category_name: " << category_name() << std::endl;
    text << "parent_account_id: " << parent_account_id() << std::endl;
    text << "monthly_budget: " << monthly_budget() << std::endl;
    text << "current_balance: " << current_balance() << std::endl;
    text << "last_added_date: " << _last_added_date.value_or("NULL");
    std::cout << text.str() << std::endl;
}
