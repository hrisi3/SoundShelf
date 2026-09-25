#include "AlbumTrack.hpp"
#include "utils.hpp"
#include <iostream>

AlbumTrack::AlbumTrack(std::string title, std::string creator, double duration, Genre genre, std::string albumName, int trackNum, int releaseY)
    :AudioItem(title,creator,duration,genre), albumName(albumName), trackNumber(trackNum), releaseYear(releaseY)
{}

void AlbumTrack::play()
{
    AudioItem::play();
    std::cout << "Playing \"" << getTitle() << "\" by " << getCreator() << "...\n";
}

std::string AlbumTrack::getInfo() const
{
    return getTitle() + " - " + getCreator() +
           " (Album: " + albumName + ", Track #" + std::to_string(trackNumber) + ", " + std::to_string(releaseYear) + ")";
}

std::string AlbumTrack::getTypeLabel() const
{
    return "Album Track";
}

bool AlbumTrack::matchesSearch(const std::string &query) const
{
    return AudioItem::matchesSearch(query) || toLower(albumName).find(toLower(query)) != std::string::npos;
}
