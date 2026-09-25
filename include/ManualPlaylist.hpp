#ifndef MANUAL_PLAYLIST_HPP
#define MANUAL_PLAYLIST_HPP

#include "Playlist.hpp"

// Обикновен плейлист - потребителя сам добавя маха песни.
class ManualPlaylist : public Playlist
{
public:
    ManualPlaylist(std::string name);

    virtual std::string getTypeLabel() const override
    {
        return "Manual Playlist";
    }
};

#endif