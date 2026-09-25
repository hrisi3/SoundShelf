#ifndef SMART_PLAYLIST_HPP
#define SMART_PLAYLIST_HPP

#include "Playlist.hpp"

enum class SmartCriteria
{
    BY_GENRE, // всички песни от жанр( ползва genreFilter)
    BY_ARTIST, // всички песни от изпълбител ( ползва artistFilter)
    MOST_PLAYED // топ limit песни по брой пускания
};


// плейлист, който генерира автоматично по критерий
class SmartPlaylist : public Playlist
{
public:
    SmartPlaylist(std::string name, SmartCriteria criteria, Genre genreFilter = Genre::OTHER,
                  std::string artistFiler = "", int limit = 10);

    virtual std::string getTypeLabel() const override
    {
        return "Smart Playlist";
    }

    // забранени - плейлистът се управлява само чрез refresh
    virtual void addTrack(AudioItem *item) override;
    virtual void removeTrack(AudioItem *item) override;

    virtual void refresh(const std::vector<AudioItem *> &source) override;

private:
    SmartCriteria criteria;
    Genre genreFilter;
    std::string artistFiler;
    int limit;
};

#endif