#include "Library.hpp"
#include "exceptions/LibraryExceptions.hpp"
#include "utils.hpp"
#include "User.hpp"
#include <algorithm>

void Library::addSong(std::unique_ptr<AudioItem> song, const User &actor)
{
    if(!actor.canManageLibrary())
        throw InvalidOperationException("Regular User can't  add songs in library");
    //за дубликат
    for(const auto &s : songs)
    {
        if(toLower(s->getTitle()) == toLower(song->getTitle()) &&
            toLower(s->getCreator()) == toLower(song->getCreator()))
        {
            throw DuplicateSongException("Song already exists");
        }
    }
    songs.push_back(std::move(song));
}

void Library::removeSong(const std::string &title, const std::string &creator, const User &actor)
{
    if(!actor.canManageLibrary())
        throw InvalidOperationException("regular user can't remove songs from library");
    auto iter = std::find_if(songs.begin(), songs.end(), [&](const std::unique_ptr<AudioItem> &s)
                             { return toLower(s->getTitle()) == toLower(title) && toLower(s->getCreator()) == toLower(creator); });
    if(iter == songs.end())
        throw SongNotFoundException(title + " by " + creator + " not found");
    songs.erase(iter);
}

AudioItem *Library::findSong(const std::string &title, const std::string &creator) const
{
    auto iter = std::find_if(songs.begin(), songs.end(), [&](const std::unique_ptr<AudioItem> &s)
                             { return toLower(s->getTitle()) == toLower(title) && toLower(s->getCreator()) == toLower(creator); });
    return iter == songs.end() ? nullptr : iter->get();
    // iter сочи към unique_ptr<AudioItem>, трябва ->get(),за да извадиш суровия указател
}

std::vector<AudioItem *> Library::search(const std::string &query) const
{
    std::vector<AudioItem *> result{};
    for(const auto &s : songs)
    {
        if(s->matchesSearch(query))
            result.push_back(s.get());
    }
    return result;
}

std::vector<AudioItem *> Library::getAllItems() const
{
    std::vector<AudioItem *> result{};  // правя нов AudioItem**
    for(const auto &s : songs)      
    {
        result.push_back(s.get());        // вкарвам ги в резултата
    }
    return result;
}

void Library::addUser(std::unique_ptr<User> user,const User &actor)
{
    if(!actor.canManageUsers())
        throw InvalidOperationException("Only admin can add users");
    for(const auto &u : users)
    {
        if(toLower(u->getUserName()) == toLower(user->getUserName()))
            throw DuplicateUsernameException("Username already exists.");
    }

    users.push_back(std::move(user));
}

User *Library::findUser(const std::string &username) const
{
    auto iter = std::find_if(users.begin(), users.end(), [&](const std::unique_ptr<User> &u)
                             { return toLower(u->getUserName()) == toLower(username); });

    return iter == users.end() ? nullptr : iter->get();
}
