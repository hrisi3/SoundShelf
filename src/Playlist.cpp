#include "Playlist.hpp"
#include "exceptions/LibraryExceptions.hpp"
#include <algorithm>

Playlist::Playlist(std::string name)
    :name(std::move(name))
{}

double Playlist::getTotalDuration() const
{
    double total = 0.0;
    for (const auto *track : tracks)
    {
        total += track->getDuration();
    }
    return total;
}

void Playlist::addTrack(AudioItem *item)
{
    tracks.push_back(item);
}

void Playlist::removeTrack(AudioItem *item)
{
    auto iter = std::find(tracks.begin(), tracks.end(), item);
    if(iter == tracks.end())
        throw SongNotFoundException("Track not found in playlist \"" + name + "\"");
    tracks.erase(iter);
}

std::string Playlist::getInfo() const
{
    return "[" + getTypeLabel() + "] " + name + " - " +
           std::to_string(getTrackCount()) + " tracks, " +
           std::to_string(getTotalDuration()) + "s total";
}
