#pragma once

#include <models/user.h>
#include <database/database.h>
#include <pqxx/pqxx>
#include <utils/utils.h>

class user_db {
public:
    user_db(database &db)
    : _db(db) {};

    std::string add_user(user& usr);
    void delete_user(user& usr);
    void update_user(user& usr);
    user get_user(std::string user_id);
    std::vector<user> get_all_users();

private:
    database &_db;
};