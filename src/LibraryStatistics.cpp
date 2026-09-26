#include "LibraryStatistics.hpp"
#include <algorithm>

AudioItem *LibraryStatistics::getMostPlayed(const std::vector<AudioItem *> &source) const
{
    if(source.empty())
        return nullptr;

    auto iter = std::max_element(source.begin(), source.end(), [](AudioItem *a, AudioItem *b)
                                 { return a->getPlayCount() < b->getPlayCount(); });
    return *iter;
}

AudioItem *LibraryStatistics::getLeastPlayed(const std::vector<AudioItem *> &source) const
{
    if(source.empty())
        return nullptr;
    auto iter = std::min_element(source.begin(), source.end(), [](AudioItem *a, AudioItem *b)
                                 { return a->getPlayCount() < b->getPlayCount(); });
    return *iter;
}

std::vector<AudioItem *> LibraryStatistics::getByGenre(const std::vector<AudioItem *> &source, Genre genre) const
{
    std::vector<AudioItem *> result{};
    for(const auto &s : source)
    {
        if(s->getGenre() == genre)
            result.push_back(s);
    }
    return result;
}

int LibraryStatistics::getTotalPlayCount(const std::vector<AudioItem *> &source) const
{
    int total = 0;
    for(const auto &s : source)
    {
        total += s->getPlayCount();
    }
    /*  0 е началната стойност на сумата
    std::accumulate(source.begin(), source.end(),0,[](int sum,AudioItem*item)
                    {return sum + item->getPlayCount();});
    */
    return total;
}
