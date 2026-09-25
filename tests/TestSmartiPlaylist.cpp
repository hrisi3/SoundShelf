#include <iostream>
#include <cassert>
#include "AlbumTrack.hpp"
#include "PodcastEpisode.hpp"
#include "SmartPlaylist.hpp"
#include "exceptions/LibraryExceptions.hpp"


int main()
{

    AlbumTrack track1("Bohemian Rhapsody", "Queen", 355.0, Genre::ROCK,
                      "A Night at the Opera", 11, 1975);
    AlbumTrack track2("Numb", "Linkin Park", 187.0, Genre::ROCK,
                      "Meteora", 4, 2003);
    PodcastEpisode ep("Is it worth it?", "Hristina", 400, Genre::OTHER,
                      "FMI sucks", 156, Date(10, 7, 2026));

    for (size_t i = 0; i < 2; i++)
    {
        track2.play();
    }

    for (size_t i = 0; i < 5; i++)
    {
        ep.play();
    }

    SmartPlaylist pl("myMix", SmartCriteria::MOST_PLAYED, Genre::OTHER, "", 2);
    std::vector<AudioItem *> source = {&track1, &track2, &ep};
    pl.refresh(source);



    std::cout << "getInfo: " << pl.getInfo() << "\n";
    assert(pl.getTypeLabel() == "Smart Playlist");
    std::cout << "getTypeLabel: OK (" << pl.getTypeLabel() << ")\n";

};
