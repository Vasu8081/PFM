#include <database/database_functions.h>

void create_tables(std::unique_ptr<pqxx::connection> conn)
{
    try {
        std::vector<std::string> table_creation_queries = {
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
                    account_name VARCHAR(100) NOT NULL,
                    account_type VARCHAR(50) NOT NULL
                );
            )",
            R"(
                CREATE TABLE IF NOT EXISTS bank_accounts (
                    id UUID PRIMARY KEY REFERENCES accounts(id) DEFAULT uuid_generate_v4(),
                    account_number VARCHAR(30) NOT NULL,
                    bank_name VARCHAR(100) NOT NULL,
                    ifsc_code VARCHAR(11),
                    balance DECIMAL(17, 4) NOT NULL,
                    hold_amount DECIMAL(17, 4) NOT NULL DEFAULT 0
                );
            )",
            R"(
                CREATE TABLE IF NOT EXISTS credit_card_accounts (
                    id UUID PRIMARY KEY REFERENCES accounts(id) DEFAULT uuid_generate_v4(),
                    card_number VARCHAR(30) NOT NULL,
                    expiry_date DATE NOT NULL,
                    cvv NUMERIC(5, 0),
                    credit_limit DECIMAL(17, 4) NOT NULL,
                    balance_due DECIMAL(17, 4) NOT NULL,
                    statement_date DATE NOT NULL,
                    billing_date DATE NOT NULL
                );
            )",
            R"(
                CREATE TABLE IF NOT EXISTS loan_accounts (
                    id UUID PRIMARY KEY REFERENCES accounts(id) DEFAULT uuid_generate_v4(),
                    principal_amount DECIMAL(17, 4) NOT NULL,
                    remaining_principal DECIMAL(17, 4) NOT NULL,
                    interest_rate DECIMAL(5, 2) NOT NULL,
                    installment_start_date DATE NOT NULL,
                    term_in_months INT NOT NULL
                );
            )",
            R"(
                CREATE TABLE IF NOT EXISTS borrow_give_accounts (
                    id UUID PRIMARY KEY REFERENCES accounts(id) DEFAULT uuid_generate_v4(),
                    balance_due DECIMAL(17, 4) NOT NULL,
                    due_date DATE
                );
            )",
            R"(
                CREATE TABLE IF NOT EXISTS category_accounts (
                    id UUID PRIMARY KEY REFERENCES accounts(id) DEFAULT uuid_generate_v4(),
                    parent_account_id UUID REFERENCES bank_accounts(id),
                    monthly_budget DECIMAL(17,4),
                    current_balance DECIMAL(17,4) NOT NULL DEFAULT 0,
                    last_added_date DATE
                );
            )",
            R"(
                CREATE TABLE IF NOT EXISTS goal_accounts (
                    id UUID PRIMARY KEY REFERENCES accounts(id) DEFAULT uuid_generate_v4(),
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

        pqxx::work txn(*conn);
        for (const auto& query : table_creation_queries) {
            txn.exec(query);
        }
        txn.commit();

        std::cout << "Tables checked and created if not existing." << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}
