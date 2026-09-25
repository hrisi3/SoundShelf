#include "RegularUser.hpp"

RegularUser::RegularUser(std::string username)
    :User(username)
{}

bool RegularUser::canManageLibrary() const
{
    return false;
}

bool RegularUser::canManageUsers() const
{
    return false;
}

std::string RegularUser::getRoleLabel() const
{
    return "Regular User";
}
