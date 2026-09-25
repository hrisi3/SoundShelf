#ifndef ADMIN_HPP
#define ADMIN_HPP

#include "User.hpp"

class Admin : public User
{
public:
    Admin(std::string username);

    bool canManageLibrary() const override; // true
    bool canManageUsers() const override; // true
    std::string getRoleLabel() const override;
};

#endif