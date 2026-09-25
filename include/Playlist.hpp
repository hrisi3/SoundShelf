#ifndef PLAYLIST_HPP
#define PLAYLIST_HPP

#include "AudioItem.hpp"
#include <string>
#include <vector>


class Playlist
{
public:
    Playlist(std::string name);
    virtual ~Playlist() = default;

    const std::string &getName() const { return name; }
    void setName(const std::string &newName) { name = newName; }

    const std::vector<AudioItem *> &getTracks() const { return tracks; }
    size_t getTrackCount() const { return tracks.size(); }
    double getTotalDuration() const;

    // Manual -> ги оставя както са, Smart -> override and throw exception
    virtual void addTrack(AudioItem* item);
    virtual void removeTrack(AudioItem* item);

    virtual std::string getInfo() const;
    virtual std::string getTypeLabel() const = 0;

    virtual void refresh(const std::vector<AudioItem *> &source) { (void)source; }

protected:
    std::string name;
    std::vector<AudioItem*> tracks; // non-owning
};


#endif