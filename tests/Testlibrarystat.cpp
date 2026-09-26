#include <iostream>
#include <cassert>
#include "LibraryStatistics.hpp"
#include "AlbumTrack.hpp"
#include "PodcastEpisode.hpp"

int main()
{
    LibraryStatistics stats;

    // empty
    std::vector<AudioItem *> empty;
    assert(stats.getMostPlayed(empty) == nullptr);
    assert(stats.getLeastPlayed(empty) == nullptr);
    assert(stats.getTotalPlayCount(empty) == 0);
    std::cout << "Empty edge cases: OK\n";

    AlbumTrack track1("Numb", "Linkin Park", 187.0, Genre::ROCK, "Meteora", 4, 2003);
    AlbumTrack track2("Bohemian Rhapsody", "Queen", 355.0, Genre::ROCK, "A Night at the Opera", 11, 1975);
    PodcastEpisode ep("Is it worth it?", "Hristina", 400, Genre::OTHER, "FMI sucks", 156, Date(10, 7, 2026));

    for (int i = 0; i < 5; i++)
        track1.play();
    for (int i = 0; i < 100; i++)
        track2.play();
    for (int i = 0; i < 2; i++)
        ep.play();

    std::vector<AudioItem *> source{&track1, &track2, &ep};

    // getMostPlayed
    AudioItem *most = stats.getMostPlayed(source);
    assert(most = &track2);
    std::cout << "getMostPlayed: OK , " << most->getTitle() << ", " << most->getPlayCount() << " plays\n";

    // getLeastPlayed
    AudioItem *least = stats.getLeastPlayed(source);
    assert(most = &ep);
    std::cout << "getLeastPlayed: OK , " << least->getTitle() << ", " << least->getPlayCount() << " plays\n";
    
    //getByGenre
    auto rockSongs = stats.getByGenre(source, Genre::ROCK);
    assert(rockSongs.size() == 2);
    std::cout << "getByGenre ROCK OK, " << rockSongs.size() << " tracks\n";

    auto metalSongs = stats.getByGenre(source, Genre::METAL);
    assert(metalSongs.empty());
    std::cout << "getByGenre (metal,none): OK, empty\n";

    //getTotalPlayCount
    int total = stats.getTotalPlayCount(source);
    assert(total == 5 + 100 + 2);
    std::cout << "getTotalPlayCount: OK, " << total << "\n";

    std::cout << "\nPassed!\n";

    return 0;
}