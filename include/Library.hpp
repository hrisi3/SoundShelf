#ifndef LIBRARY_HPP
#define LIBRARY_HPP

#include <vector>
#include <memory>
#include "AudioItem.hpp"
#include "User.hpp"


class Library
{
public:
    void addSong(std::unique_ptr<AudioItem> song, const User &actor);
    void removeSong(const std::string &title, const std::string &creator, const User &actor);

    AudioItem *findSong(const std::string &title, const std::string &creator) const;
    std::vector<AudioItem *> search(const std::string &query) const;
    std::vector<AudioItem *> getAllItems() const;

    void addUser(std::unique_ptr<User> user,const User& actor);
    User *findUser(const std::string &username) const;

private:
    std::vector<std::unique_ptr<AudioItem>> songs;
    std::vector<std::unique_ptr<User>> users;
};

#endif