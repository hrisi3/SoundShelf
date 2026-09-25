#include "Admin.hpp"

Admin::Admin(std::string username)
    :User(username)
{}

bool Admin::canManageLibrary() const
{
    return true;
}

bool Admin::canManageUsers() const
{
    return true;
}

std::string Admin::getRoleLabel() const
{
    return "Admin";
}
