#include <database/account_db.h>

void account_db::add_account(account& account) {
  std::string query =
    "INSERT INTO accounts (id, account_name, account_type) VALUES ('" +
    account.id() + "', '" + account.account_name() + "', '" + account_type_to_string(account.account_type()) + "')";

  _db.execute_query(query);
}

void account_db::delete_account(account& account) {
  std::string query = "DELETE FROM accounts WHERE id = '" + account.id() + "'";
  _db.execute_query(query);
}

void account_db::update_account(account& account) {
  std::string query =
    "UPDATE accounts SET account_name = '" + account.account_name() +
    "', account_type = '" + account_type_to_string(account.account_type()) +
    "' WHERE id = '" + account.id() + "'";

  _db.execute_query(query);
}

account account_db::get_account(std::string account_id) {
  std::string query = "SELECT id, account_name, account_type FROM accounts WHERE id = '" + account_id + "'";
  auto result = _db.execute_query(query);

  if (result.empty()) {
    throw std::runtime_error("Account not found for id: " + account_id);
  }

  auto row = result[0];
  return account(
    row["account_name"].c_str(),
    string_to_account_type(row["account_type"].c_str())
  );
}

std::vector<account> account_db::get_all_accounts() {
  std::string query = "SELECT id, account_name, account_type FROM accounts";
  auto result = _db.execute_query(query);

  std::vector<account> accounts;
  for (const auto& row : result) {
    accounts.emplace_back(
      row["account_name"].c_str(),
      string_to_account_type(row["account_type"].c_str())
    );
  }

  return accounts;
}

std::vector<account> account_db::get_accounts(account_type account_type) {
  std::string query =
    "SELECT id, account_name, account_type FROM accounts WHERE account_type = '" +
    std::to_string(static_cast<int>(account_type)) + "'";

  auto result = _db.execute_query(query);

  std::vector<account> accounts;
  for (const auto& row : result) {
    accounts.emplace_back(
      row["account_name"].c_str(),
      string_to_account_type(row["account_type"].c_str())
    );
  }

  return accounts;
}