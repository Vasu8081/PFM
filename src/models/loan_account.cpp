#include <models/loan_account.h>

loan_account::loan_account()  {
    account_type(enums::account_type::LOAN_ACCOUNT);
}

loan_account::loan_account(std::string loan_name, std::string loan_account_number,
                           double principal_amount, double remaining_principal,
                           double interest_rate_per_annum, std::string installment_start_date,
                           int term_in_months)
    : account("", enums::account_type::LOAN_ACCOUNT),
      _loan_name(loan_name), _loan_account_number(loan_account_number),
      _principal_amount(principal_amount), _remaining_principal(remaining_principal),
      _interest_rate_per_annum(interest_rate_per_annum),
      _installment_start_date(installment_start_date), _term_in_months(term_in_months) {}

// Getter definitions
std::string loan_account::loan_name() const {
    return _loan_name;
}

std::string loan_account::loan_account_number() const {
    return _loan_account_number;
}

double loan_account::principal_amount() const {
    return _principal_amount;
}

double loan_account::remaining_principal() const {
    return _remaining_principal;
}

double loan_account::interest_rate_per_annum() const {
    return _interest_rate_per_annum;
}

std::string loan_account::installment_start_date() const {
    return _installment_start_date;
}

int loan_account::term_in_months() const {
    return _term_in_months;
}

// Setter definitions
void loan_account::loan_name(const std::string& loan_name) {
    _loan_name = loan_name;
}

void loan_account::loan_account_number(const std::string& loan_account_number) {
    _loan_account_number = loan_account_number;
}

void loan_account::principal_amount(double principal_amount) {
    _principal_amount = principal_amount;
}

void loan_account::remaining_principal(double remaining_principal) {
    _remaining_principal = remaining_principal;
}

void loan_account::interest_rate_per_annum(double interest_rate_per_annum) {
    _interest_rate_per_annum = interest_rate_per_annum;
}

void loan_account::installment_start_date(const std::string& installment_start_date) {
    _installment_start_date = installment_start_date;
}

void loan_account::term_in_months(int term_in_months) {
    _term_in_months = term_in_months;
}

// DB specific method definitions
std::string loan_account::table_name() const {
    return "loan_accounts";
}

std::unordered_map<std::string, std::string> loan_account::get() const {
    std::unordered_map<std::string, std::string> fields;
    fields["id"] = id();
    fields["loan_name"] = loan_name();
    fields["loan_account_number"] = loan_account_number();
    fields["principal_amount"] = std::to_string(principal_amount());
    fields["remaining_principal"] = std::to_string(remaining_principal());
    fields["interest_rate_per_annum"] = std::to_string(interest_rate_per_annum());
    fields["installment_start_date"] = installment_start_date();
    fields["term_in_months"] = std::to_string(term_in_months());
    return fields;
}

void loan_account::set(const std::unordered_map<std::string, std::string>& fields) {
    id(fields.at("id"));
    loan_name(fields.at("loan_name"));
    loan_account_number(fields.at("loan_account_number"));
    principal_amount(std::stod(fields.at("principal_amount")));
    remaining_principal(std::stod(fields.at("remaining_principal")));
    interest_rate_per_annum(std::stod(fields.at("interest_rate_per_annum")));
    installment_start_date(fields.at("installment_start_date"));
    term_in_months(std::stoi(fields.at("term_in_months")));
}

void loan_account::save() {
    account::save();
    auto fields = get();
    db->insert(fields, table_name());
    set(fields);
}


void loan_account::print() const {
    std::stringstream text;
    text << "account_type: " << account_t(account_type()) << std::endl;
    text << "account id: " << id() << std::endl;
    text << "loan_name: " << loan_name() << std::endl;
    text << "loan_account_number: " << loan_account_number() << std::endl;
    text << "principal_amount: " << principal_amount() << std::endl;
    text << "remaining_principal: " << remaining_principal() << std::endl;
    text << "interest_rate_per_annum: " << interest_rate_per_annum() << std::endl;
    text << "installment_start_date: " << installment_start_date() << std::endl;
    text << "term_in_months: " << term_in_months() << std::endl;
    std::cout << text.str() << std::endl;
}
