#ifndef ALBUM_TRACK_HPP
#define ALBUM_TRACK_HPP

#include "AudioItem.hpp"

class AlbumTrack : public AudioItem
{
public:
    AlbumTrack(std::string title, std::string artist, double duration, Genre genre,
               std::string albumName, int trackNum, int releaseY);

    AudioItem *clone() const override { return new AlbumTrack(*this); }
    virtual void play() override;
    virtual std::string getInfo() const override;

    virtual std::string getTypeLabel() const override;
    virtual bool matchesSearch(const std::string &query) const override;

    const std::string &getAlbumName() const { return albumName; }
    int getTrackNumber() const { return trackNumber; }
    int getReleaseYear() const { return releaseYear; }

    virtual std::string serialize() const override;

private:
    std::string albumName;
    int trackNumber; // позиция в албума
    int releaseYear;
};

#endif