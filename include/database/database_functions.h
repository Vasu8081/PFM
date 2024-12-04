#pragma once

#include <pqxx/pqxx>
#include <iostream>
#include <vector>

void create_tables(std::unique_ptr<pqxx::connection> conn);