#include <database/user_db.h>

std::string user_db::add_user(user& usr) {
  std::stringstream query;
  query << "INSERT INTO users (name, email, mobile, password) VALUES ('"
        << escape_sql(usr.name()) << "', '"
        << escape_sql(usr.email()) << "', ";

  if (usr.mobile()) {
    query << usr.mobile().value();
  } else {
    query << "NULL";
  }

  query << ", '" << escape_sql(usr.password()) << "') RETURNING id;";

  auto result = _db.execute_query(query.str());

  if (!result.empty()) {
    return result[0][0].c_str();
  }
  throw std::runtime_error("Failed to retrieve user_id");
}


void user_db::delete_user(user& user) {
  std::string query = "DELETE FROM users WHERE id = '" + user.id() + "'";
  _db.execute_query(query);
}

void user_db::update_user(user& usr) {
  std::stringstream query;
  query << "UPDATE users SET "
        << "name = '" << escape_sql(usr.name()) << "', "
        << "email = '" << escape_sql(usr.email()) << "', ";

  if (usr.mobile()) {
    query << "mobile = " << usr.mobile().value() << ", ";
  } else {
    query << "mobile = NULL, ";
  }

  query << "password = '" << escape_sql(usr.password()) << "' "
        << "WHERE id = '" << escape_sql(usr.id()) << "'";

  _db.execute_query(query.str());
}

user user_db::get_user(std::string user_id) {
  std::stringstream query;
  query << "SELECT id, name, email, mobile, password FROM users WHERE id = ";
  query << user_id;

  try {
    auto result = _db.execute_query(query.str());

    if (result.empty()) {
      throw std::runtime_error("User not found for id: " + user_id);
    }

    auto row = result[0];
    std::optional<long> mobile = row["mobile"].is_null() ? std::nullopt : std::make_optional(std::stol(row["mobile"].c_str()));
    return user(
        row["name"].c_str(),
        row["email"].c_str(),
        row["password"].c_str(),
        mobile
    );
  } catch (const std::exception& e) {
    throw std::runtime_error(std::string("Failed to retrieve user: ") + e.what());
  }
}


std::vector<user> user_db::get_all_users() {
  std::string query = "SELECT id, name, email, mobile, password FROM users";

  try {
    auto result = _db.execute_query(query);

    std::vector<user> users;
    for (const auto& row : result) {
      std::optional<long> mobile = row["mobile"].is_null()
                                     ? std::nullopt
                                     : std::make_optional(std::stol(row["mobile"].c_str()));
      users.emplace_back(
          row["name"].c_str(),
          row["email"].c_str(),
          row["password"].c_str(),
          mobile
      );
    }

    return users;
  } catch (const std::exception& e) {
    throw std::runtime_error(std::string("Failed to retrieve users: ") + e.what());
  }
}
