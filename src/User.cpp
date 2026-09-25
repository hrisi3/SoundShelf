#include "User.hpp"
#include <algorithm>
#include "exceptions/LibraryExceptions.hpp"

User::User(std::string username)
    :username(std::move(username))
{}

// с оператор[]-> достъпен user.getPlaylists()[0]->getName()
const std::vector<std::unique_ptr<Playlist>> &User::getPlaylists() const
{
    return playlists;
}

void User::addPlaylist(std::unique_ptr<Playlist> playlist)
{
    playlists.push_back(std::move(playlist));
}

void User::removePlaylist(const std::string &playlistName)
{
    auto iter = std::find_if(playlists.begin(), playlists.end(), [&](const std::unique_ptr<Playlist> &p)
                             { return p->getName() == playlistName; });
    if(iter == playlists.end())
        throw PlaylistNotFoundException("Playlist with name " + playlistName + " not found");
    playlists.erase(iter);
}
