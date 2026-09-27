#ifndef PODCAST_EPISODE_HPP
#define PODCAST_EPISODE_HPP
#include "AudioItem.hpp"
#include "Date.hpp"


class PodcastEpisode : public AudioItem
{
public:
    PodcastEpisode(std::string title, std::string artist, double duration, Genre genre,
                    std::string showName, int episodeNum, Date releaseD);
    virtual AudioItem *clone() const override { return new PodcastEpisode(*this); }

    virtual void play() override;
    virtual std::string getInfo() const override;
    virtual std::string getTypeLabel() const override;
    virtual bool matchesSearch(const std::string &query) const override;

    const std::string &getShowName() const { return showName; }
    int getEpisodeNumber() const { return episodeNumber; }
    Date getReleaseDate() const { return releaseDate; }

    virtual std::string serialize() const override;

private:
// host e creator
    std::string showName;
    int episodeNumber;
    Date releaseDate;
};

#endif