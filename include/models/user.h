#pragma once

#include <iostream>
#include <optional>
#include <string>
#include <unordered_map>
#include <database/entity.h>

class user : public virtual entity {
public:
    user(std::string name, std::string email, std::string password,
         std::optional<long> mobile = std::nullopt);

    user(std::string id, std::string name, std::string email, std::string password,
         std::optional<long> mobile = std::nullopt);

    user(const std::unordered_map<std::string, std::string>& fields);

    // Getters
    std::string id() const override;
    std::string name() const;
    std::string email() const;
    std::string password() const;
    std::optional<long> mobile() const;

    // Setters
    void id(std::string id) override;
    void name(const std::string& name);
    void email(const std::string& email);
    void password(const std::string& password);
    void mobile(std::optional<long> mobile);

    // DB specific methods
    std::string table_name() const override;
    std::unordered_map<std::string, std::string> get() const override;
    void set(const std::unordered_map<std::string, std::string>& fields) override;
    void save() override;
    void print() const override;

private:
    std::string _id;
    std::string _name;
    std::string _email;
    std::string _password;
    std::optional<long> _mobile;
};
