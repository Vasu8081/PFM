#include <database/database.h>

database::database()
:     _connection("dbname=" + global_config.db_config.database_name +
              " user=" + global_config.db_config.user_name +
              " password=" + global_config.db_config.password +
              " host=" + global_config.db_config.hostname +
              " port=" + global_config.db_config.port)
{
    try {
        if (!_connection.is_open()) {
            throw std::runtime_error("Failed to connect to the database: " + global_config.db_config.database_name);
        }
    } catch (const std::exception& e) {
        throw std::runtime_error(std::string("Database connection error: ") + e.what());
    }
    create_tables();
}

pqxx::result database::execute_query(const std::string& query){
  try{
    pqxx::work txn(_connection);
    auto result = txn.exec(query);
    txn.commit();
    return result;
  }
  catch (const std::exception& e){
    std::cout << "QUERY IS: "<<query<<"\n";
    std::cout << e.what() << std::endl;
  }
  return {};
}

void database::insert(std::unordered_map<std::string, std::string>& fields, std::string table){
    std::ostringstream columns, values;
    for (const auto& [key, value] : fields) {
        if (!value.empty()) {
            if (!columns.str().empty()) {
                columns << ", ";
                values << ", ";
            }
            columns << key;
            values << "'" << pqxx::to_string(value) << "'";
        }
    }
    std::string query = "INSERT INTO " + table + " (" + columns.str() + ") VALUES (" + values.str() + ") RETURNING id";
    auto result = execute_query(query);
    std::string id = result[0][0].c_str();
    fields["id"] = id;
}

void database::update(std::unordered_map<std::string, std::string>& fields, std::string table){
    std::string id = fields["id"];
    fields.erase("id");
    std::ostringstream updates;
    for (const auto& [key, value] : fields) {
        if (!value.empty()) {
            if (!updates.str().empty()) updates << ", ";
            updates << key << " = '" << pqxx::to_string(value) << "'";
        }
    }
    std::string query = "UPDATE " + table + " SET " + updates.str() + " WHERE id = '" + id + "'";
    execute_query(query);
}

void database::remove(std::unordered_map<std::string, std::string>& fields, std::string table){
    std::string id = fields["id"];
    std::string query = "DELETE FROM " + table + " WHERE id = '" + id + "'";
    execute_query(query);
}

void database::fetch(std::unordered_map<std::string, std::string>& fields, std::string table){
    std::string id = fields["id"];
    std::string query = "SELECT * FROM " + table + " WHERE id = '" + id + "'";
    auto result = execute_query(query);
    std::unordered_map<std::string, std::string> record;
    auto row = result[0];
    for (const auto& field : row) {
        fields[field.name()] = field.as<std::string>();
    }
}

std::vector<std::unordered_map<std::string, std::string>> database::select(std::unordered_map<std::string, std::string>& filters, std::string table)
{
    std::ostringstream where_clause;
    for (const auto& [key, value] : filters) {
        if (!value.empty()) {
            if (!where_clause.str().empty()) where_clause << " AND ";
            where_clause << key << " = '" << pqxx::to_string(value) << "'";
        }
    }
    std::string query = "SELECT * FROM " + table;
    if (!filters.empty()) {
        query += " WHERE " + where_clause.str();
    }
    auto result = execute_query(query);
    std::vector<std::unordered_map<std::string, std::string>> rows;
    for (const auto& row : result) {
        std::unordered_map<std::string, std::string> record;
        for (const auto& field : row) {
            record[field.name()] = field.as<std::string>();
        }
        rows.push_back(record);
    }
    return rows;
}

void database::create_tables()
{
    try {
        std::vector<std::string> table_creation_queries = {
            R"(CREATE EXTENSION IF NOT EXISTS "uuid-ossp";)",
            R"(
                CREATE TABLE IF NOT EXISTS users (
                    id UUID PRIMARY KEY DEFAULT uuid_generate_v4(),
                    name VARCHAR(100),
                    email VARCHAR(100),
 					mobile NUMERIC(15, 0),
                    password VARCHAR(100)
                );
            )",
            R"(
                CREATE TABLE IF NOT EXISTS accounts (
                    id UUID PRIMARY KEY DEFAULT uuid_generate_v4(),
                    user_id UUID NOT NULL,
                    account_type VARCHAR(50) NOT NULL
                );
            )",
            R"(
                CREATE TABLE IF NOT EXISTS bank_accounts (
                    id UUID PRIMARY KEY REFERENCES accounts(id) DEFAULT uuid_generate_v4(),
                    bank_name VARCHAR(100) NOT NULL,
                    account_number VARCHAR(30) NOT NULL,
                    ifsc_code VARCHAR(11),
                    balance DECIMAL(17, 4) NOT NULL,
                    hold_amount DECIMAL(17, 4) NOT NULL DEFAULT 0
                );
            )",
            R"(
                CREATE TABLE IF NOT EXISTS credit_card_accounts (
                    id UUID PRIMARY KEY REFERENCES accounts(id) DEFAULT uuid_generate_v4(),
                    card_name VARCHAR(50) NOT NULL,
                    card_number VARCHAR(30) NOT NULL,
                    expiry_date DATE NOT NULL,
                    cvv NUMERIC(5, 0) NOT NULL,
                    credit_limit DECIMAL(17, 4) NOT NULL,
                    balance_due DECIMAL(17, 4) NOT NULL,
                    statement_day NUMERIC(2,0) NOT NULL,
                    billing_date NUMERIC(2,0) NOT NULL
                );
            )",
            R"(
                CREATE TABLE IF NOT EXISTS loan_accounts (
                    id UUID PRIMARY KEY REFERENCES accounts(id) DEFAULT uuid_generate_v4(),
                    loan_name VARCHAR(50) NOT NULL,
                    loan_account_number VARCHAR(30) NOT NULL,
                    principal_amount DECIMAL(17, 4) NOT NULL,
                    remaining_principal DECIMAL(17, 4) NOT NULL,
                    interest_rate_per_annum DECIMAL(5, 2) NOT NULL,
                    installment_start_date DATE NOT NULL,
                    term_in_months INT NOT NULL
                );
            )",
            R"(
                CREATE TABLE IF NOT EXISTS borrow_give_accounts (
                    id UUID PRIMARY KEY REFERENCES accounts(id) DEFAULT uuid_generate_v4(),
                    person_name VARCHAR(50) NOT NULL,
                    balance_due DECIMAL(17, 4) NOT NULL,
                    due_date DATE
                );
            )",
            R"(
                CREATE TABLE IF NOT EXISTS category_accounts (
                    id UUID PRIMARY KEY REFERENCES accounts(id) DEFAULT uuid_generate_v4(),
                    category_name VARCHAR(50) NOT NULL,
                    parent_account_id UUID REFERENCES bank_accounts(id),
                    monthly_budget DECIMAL(17,4),
                    current_balance DECIMAL(17,4) NOT NULL DEFAULT 0,
                    last_added_date DATE
                );
            )",
            R"(
                CREATE TABLE IF NOT EXISTS goal_accounts (
                    id UUID PRIMARY KEY REFERENCES accounts(id) DEFAULT uuid_generate_v4(),
                    goal_name VARCHAR(50) NOT NULL,
                    parent_account_id UUID REFERENCES bank_accounts(id),
                    monthly_budget DECIMAL(17,4),
                    current_balance DECIMAL(17,4) NOT NULL DEFAULT 0,
                    target_amount DECIMAL(17,4),
                    target_date DATE,
                    last_added_date DATE
                );
            )",
            R"(
                CREATE TABLE IF NOT EXISTS chit_accounts (
                    id UUID PRIMARY KEY REFERENCES accounts(id) DEFAULT uuid_generate_v4(),
                    chit_name VARCHAR(50) NOT NULL,
                    monthly_budget DECIMAL(17,4),
                    accumulated_balance DECIMAL(17,4) NOT NULL DEFAULT 0,
                    mature_amount DECIMAL(17,4),
                    mature_date DATE,
                    last_added_date DATE
                );
            )",
            R"(
                CREATE TABLE IF NOT EXISTS asset_accounts (
                    id UUID PRIMARY KEY REFERENCES accounts(id) DEFAULT uuid_generate_v4(),
                    asset_name VARCHAR(50) NOT NULL,
                    asset_type VARCHAR(50) NOT NULL,
                    cost_of_ownership DECIMAL(17,4) NOT NULL,
                    paid_amount DECIMAL(17,4) NOT NULL DEFAULT 0,
                    current_market_value DECIMAL(17,4),
                    purchase_date DATE NOT NULL
                );
            )",
            R"(
                CREATE TABLE IF NOT EXISTS transactions (
                    id UUID PRIMARY KEY DEFAULT uuid_generate_v4(),
                    from_account_id UUID REFERENCES accounts(id),
                    to_account_id UUID REFERENCES accounts(id),
                    category_account_id UUID REFERENCES category_accounts(id),
                    moved_from_account UUID REFERENCES accounts(id),
                    amount DECIMAL(17, 4) NOT NULL,
                    transaction_type VARCHAR(20) NOT NULL,
                    description VARCHAR(255),
                    date DATE NOT NULL,
                    proof_document BYTEA
                );
            )"
        };

        pqxx::work txn(_connection);
        for (const auto& query : table_creation_queries) {
            txn.exec(query);
        }
        txn.commit();

        std::cout << "Tables checked and created if not existing." << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}
