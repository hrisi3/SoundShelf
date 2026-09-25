#include "PodcastEpisode.hpp"
#include <iostream>
#include "utils.hpp"

PodcastEpisode::PodcastEpisode(std::string title, std::string artist, double duration, Genre genre,  std::string showName, int episodeNum, Date releaseD)
    :AudioItem(title,artist,duration,genre), showName(showName), episodeNumber(episodeNum), releaseDate(releaseD)
{}

void PodcastEpisode::play()
{
    AudioItem::play();
    std::cout << "Playing episode " << getEpisodeNumber() << "# of " << getShowName() << "\n";
}

// Episode #42: The Future of AI - Hosted by John Doe (Show: Tech Talks)”
std::string PodcastEpisode::getInfo() const
{
    return "Episode #" + std::to_string(getEpisodeNumber()) + ": " + getTitle() + " - " + "Hosted by " + getCreator() + "(Show: " + getShowName() + ")";
}

std::string PodcastEpisode::getTypeLabel() const
{
    return "Podcast Episode";
}

bool PodcastEpisode::matchesSearch(const std::string &query) const
{
   return AudioItem::matchesSearch(query) || toLower(showName).find(toLower(query)) != std::string::npos;
}

