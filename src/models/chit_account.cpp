#include <models/chit_account.h>

chit_account::chit_account()  {
    account_type(enums::account_type::CHIT_ACCOUNT);
}

chit_account::chit_account(std::string chit_name, double monthly_budget, double accumulated_balance,
                           double mature_amount, std::optional<std::string> mature_date,
                           std::optional<std::string> last_added_date)
    : account("", enums::account_type::CHIT_ACCOUNT),
      _chit_name(chit_name), _monthly_budget(monthly_budget),
      _accumulated_balance(accumulated_balance), _mature_amount(mature_amount),
      _mature_date(mature_date), _last_added_date(last_added_date) {}

// Getter definitions
std::string chit_account::chit_name() const {
    return _chit_name;
}

double chit_account::monthly_budget() const {
    return _monthly_budget;
}

double chit_account::accumulated_balance() const {
    return _accumulated_balance;
}

double chit_account::mature_amount() const {
    return _mature_amount;
}

std::optional<std::string> chit_account::mature_date() const {
    return _mature_date;
}

std::optional<std::string> chit_account::last_added_date() const {
    return _last_added_date;
}

// Setter definitions
void chit_account::chit_name(const std::string& chit_name) {
    _chit_name = chit_name;
}

void chit_account::monthly_budget(double monthly_budget) {
    _monthly_budget = monthly_budget;
}

void chit_account::accumulated_balance(double accumulated_balance) {
    _accumulated_balance = accumulated_balance;
}

void chit_account::mature_amount(double mature_amount) {
    _mature_amount = mature_amount;
}

void chit_account::mature_date(std::optional<std::string> mature_date) {
    _mature_date = mature_date;
}

void chit_account::last_added_date(std::optional<std::string> last_added_date) {
    _last_added_date = last_added_date;
}

// DB specific method definitions
std::string chit_account::table_name() const {
    return "chit_accounts";
}

std::unordered_map<std::string, std::string> chit_account::get() const {
    std::unordered_map<std::string, std::string> fields;
    fields["id"] = id();
    fields["chit_name"] = chit_name();
    fields["monthly_budget"] = std::to_string(monthly_budget());
    fields["accumulated_balance"] = std::to_string(accumulated_balance());
    fields["mature_amount"] = std::to_string(mature_amount());
    fields["mature_date"] = _mature_date.value_or("NULL");
    fields["last_added_date"] = _last_added_date.value_or("NULL");
    return fields;
}

void chit_account::set(const std::unordered_map<std::string, std::string>& fields) {
    id(fields.at("id"));
    chit_name(fields.at("chit_name"));
    monthly_budget(std::stod(fields.at("monthly_budget")));
    accumulated_balance(std::stod(fields.at("accumulated_balance")));
    mature_amount(std::stod(fields.at("mature_amount")));
    mature_date(fields.at("mature_date"));
    last_added_date(fields.at("last_added_date"));
}

void chit_account::save() {
    account::save();
    auto fields = get();
    db->insert(fields, table_name());
    set(fields);
}


void chit_account::print() const {
    std::stringstream text;
    text << "account_type: " << account_t(account_type()) << std::endl;
    text << "account id: " << id() << std::endl;
    text << "chit_name: " << chit_name() << std::endl;
    text << "monthly_budget: " << monthly_budget() << std::endl;
    text << "accumulated_balance: " << accumulated_balance() << std::endl;
    text << "mature_amount: " << mature_amount() << std::endl;
    text << "mature_date: " << _mature_date.value_or("NULL") << std::endl;
    text << "last_added_date: " << _last_added_date.value_or("NULL");
    std::cout << text.str() << std::endl;
}
