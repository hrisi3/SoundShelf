#include "SmartPlaylist.hpp"
#include "exceptions/LibraryExceptions.hpp"
#include "utils.hpp"
#include "algorithm"

SmartPlaylist::SmartPlaylist(std::string name, SmartCriteria criteria, Genre genreFilter, std::string artistFiler, int limit)
    : Playlist(std::move(name)), criteria(criteria), genreFilter(genreFilter),
      artistFiler(std::move(artistFiler)), limit(limit)
{
}

void SmartPlaylist::addTrack(AudioItem *item)
{
    throw InvalidOperationException("Cannot manually add tracks to smart playlist \"" + name + "\"");
}

void SmartPlaylist::removeTrack(AudioItem *item)
{
    throw InvalidOperationException("Cannot manually remove tracks from smart playlist \"" + name + "\"");
}

void SmartPlaylist::refresh(const std::vector<AudioItem *> &source)
{
    tracks.clear();
    switch (criteria)
    {
    case SmartCriteria::BY_GENRE:
        for (auto *item : source)
            if (item->getGenre() == genreFilter)
                tracks.push_back(item);
        break;
    case SmartCriteria::BY_ARTIST:
        for (auto *item : source)
            if (toLower(item->getCreator()) == toLower(artistFiler))
                tracks.push_back(item);
    case SmartCriteria::MOST_PLAYED:
        tracks = source;
        std::sort(tracks.begin(), tracks.end(), [](AudioItem *a, AudioItem *b)
                  { return a->getPlayCount() > b->getPlayCount(); });
        if (static_cast<int>(tracks.size()) > limit)
            tracks.resize(limit);

        break;
    }
}
