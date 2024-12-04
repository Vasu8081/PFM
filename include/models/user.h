#pragma once

#include <iostream>
#include <optional>

class user {
public:
    user(std::string name, std::string email, std::string password,
         std::optional<long> mobile = std::nullopt)
        : _name(name), _email(email), _password(password), _mobile(mobile) {}

    // Getters
    std::string get_name() const { return _name; }
    std::string get_email() const { return _email; }
    std::string get_password() const { return _password; }
    std::optional<long> get_mobile() const { return _mobile; }

    // Setters
    void set_name(const std::string& name) { _name = name; }
    void set_email(const std::string& email) { _email = email; }
    void set_password(const std::string& password) { _password = password; }
    void set_mobile(std::optional<long> mobile) { _mobile = mobile; }

private:
    std::string _name;
    std::string _email;
    std::string _password;
    std::optional<long> _mobile;
};
