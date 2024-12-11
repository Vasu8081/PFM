#include <utils/utils.h>

std::string escape_sql(const std::string& input) {
    std::string escaped;
    for (char c : input) {
        if (c == '\'') {
            escaped += "''";
        } else {
            escaped += c;
        }
    }
    return escaped;
}