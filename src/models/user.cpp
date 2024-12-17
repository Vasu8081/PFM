#include <models/user.h>

// Constructors
user::user(std::string name, std::string email, std::string password, std::optional<long> mobile)
    : _name(name), _email(email), _password(password), _mobile(mobile) {}

user::user(std::string id, std::string name, std::string email, std::string password, std::optional<long> mobile)
    : _id(id), _name(name), _email(email), _password(password), _mobile(mobile) {}

user::user(const std::unordered_map<std::string, std::string>& fields) {
  set(fields);
}

// Getters
std::string user::id() const { return _id; }
std::string user::name() const { return _name; }
std::string user::email() const { return _email; }
std::string user::password() const { return _password; }
std::optional<long> user::mobile() const { return _mobile; }

// Setters
void user::id(std::string id) { _id = id; }
void user::name(const std::string& name) { _name = name; }
void user::email(const std::string& email) { _email = email; }
void user::password(const std::string& password) { _password = password; }
void user::mobile(std::optional<long> mobile) { _mobile = mobile; }

// DB specific methods
std::string user::table_name() const { return "users"; }

std::unordered_map<std::string, std::string> user::get() const {
    std::unordered_map<std::string, std::string> fields;
    fields["id"] = _id;
    fields["name"] = _name;
    fields["email"] = _email;
    fields["password"] = _password;
    fields["mobile"] = _mobile.has_value() ? std::to_string(_mobile.value()) : "NULL";
    return fields;
}

void user::set(const std::unordered_map<std::string, std::string>& fields) {
    if (!fields.contains("id")) {return;}
    _id = fields.at("id");
    _name = fields.at("name");
    _email = fields.at("email");
    _password = fields.at("password");
    if (fields.at("mobile") == "NULL") {
        _mobile = std::nullopt;
    } else {
        _mobile = std::stol(fields.at("mobile"));
    }
}

void user::save() {
    auto fields = this->get();
    if (id().empty()) {
        db->insert(fields, table_name());
    }
    db->update(fields, table_name());
    set(fields);
}

void user::load() {
    auto fields = this->get();
    db->fetch(fields, table_name());
    set(fields);
}

void user::print() const {
    std::cout << details() << std::endl;
}

std::string user::details() const {
    std::stringstream ss;
    ss << "ID: " << _id << std::endl;
    ss << "Name: " << _name << std::endl;
    ss << "Email: " << _email << std::endl;
    ss << "Password: " << _password << std::endl;
    ss << "Mobile: " << (_mobile.has_value() ? std::to_string(_mobile.value()) : "NULL");
    return ss.str();
}
