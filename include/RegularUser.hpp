#ifndef REGULAR_USER_HPP
#define REGULAR_USER_HPP

#include "User.hpp"

class RegularUser : public User
{
public:
    RegularUser(std::string username);

    bool canManageLibrary() const override; // false
    bool canManageUsers() const override;  // false
    std::string getRoleLabel() const override; 
};

#endif