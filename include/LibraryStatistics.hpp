#ifndef LIBRARY_STAT_HPP
#define LIBRARY_STAT_HPP

#include <vector>
#include "AudioItem.hpp"


class LibraryStatistics
{
public:
    AudioItem *getMostPlayed(const std::vector<AudioItem *> &source) const;
    AudioItem *getLeastPlayed(const std::vector<AudioItem *> &source) const;
    std::vector<AudioItem *> getByGenre(const std::vector<AudioItem *> &source, Genre genre) const;
    int getTotalPlayCount(const std::vector<AudioItem *> &source) const;
};

#endif