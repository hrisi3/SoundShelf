#ifndef USER_HPP
#define USER_HPP

#include "AudioItem.hpp"
#include "Playlist.hpp"
#include <vector>
#include <string>
#include <memory>

class User
{
public:
    User(std::string username);
    virtual ~User() = default;

    const std::string &getUserName() const { return username; }
    
    // управление на собствените плейлисти - общо за всички роли
    const std::vector<std::unique_ptr<Playlist>> &getPlaylists() const;
    void addPlaylist(std::unique_ptr<Playlist> playlist);
    void removePlaylist(const std::string &playlistName);
    
    // права , различни по роля
    virtual bool canManageLibrary() const = 0;
    virtual bool canManageUsers() const = 0;
    virtual std::string getRoleLabel() const = 0;


private:
    std::string username;
    std::vector<std::unique_ptr<Playlist>> playlists;  // Playlist** playlists
};

#endif