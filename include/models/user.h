#pragma once

#include <iostream>
#include <optional>

class user {
public:
    user(std::string name, std::string email, std::string password,
         std::optional<long> mobile = std::nullopt)
        : _name(name), _email(email), _password(password), _mobile(mobile) {}

    // Getters
    std::string id() const { return _name; }
    std::string name() const { return _name; }
    std::string email() const { return _email; }
    std::string password() const { return _password; }
    std::optional<long> mobile() const { return _mobile; }

    // Setters
    void id(int id) { _id = id; }
    void name(const std::string& name) { _name = name; }
    void email(const std::string& email) { _email = email; }
    void password(const std::string& password) { _password = password; }
    void mobile(std::optional<long> mobile) { _mobile = mobile; }

private:
  	std::string _id;
    std::string _name;
    std::string _email;
    std::string _password;
    std::optional<long> _mobile;
};
