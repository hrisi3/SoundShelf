#include <iostream>
#include <cassert>
#include <memory>
#include "Admin.hpp"
#include "RegularUser.hpp"
#include "ManualPlaylist.hpp"
#include "exceptions/LibraryExceptions.hpp"

int main()
{
    Admin admin("hrisi_admin");
    RegularUser user("hrisi_user");

    assert(admin.canManageLibrary() == true);
    assert(admin.canManageUsers() == true);
    assert(admin.getRoleLabel() == "Admin");
    std::cout << "admin role/rights: OK\n";

    assert(user.canManageLibrary() == false);
    assert(user.canManageUsers() == false);
    assert(user.getRoleLabel() == "Regular User");
    std::cout << "RegularUser role/rights: OK\n";

    // addPlaylist - собственост чрез unique_ptr
    user.addPlaylist(std::make_unique<ManualPlaylist>("Road trip"));
    user.addPlaylist(std::make_unique<ManualPlaylist>("Chill"));
    assert(user.getPlaylists().size() == 2);
    std::cout << "addPlaylist: OK (" << user.getPlaylists().size() << " playlists)\n";

    // removePlaylist
    user.removePlaylist("Road trip");
    assert(user.getPlaylists().size() == 1);
    assert(user.getPlaylists()[0]->getName() == "Chill");
    std::cout << "removePlaylist OK: (" << user.getPlaylists().size() << " left\n";

    // removePlaylist - несъществуваш
    try
    {
        user.removePlaylist("Road trip");// вече е премахнат
        std::cout << "removePlaylist: FAIL \n";
    }
    catch(const PlaylistNotFoundException &e)
    {
        std::cout << "removePlaylist (missing): OK - caught: " << e.what() << "\n";
    }

    std::cout << "\nAll user hierachy tests passed!\n";
    return 0;
}