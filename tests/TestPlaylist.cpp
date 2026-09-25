#include <iostream>
#include <cassert>
#include "AlbumTrack.hpp"
#include "PodcastEpisode.hpp"
#include "ManualPlaylist.hpp"
#include "exceptions/LibraryExceptions.hpp"

int main()
{
    AlbumTrack track1("Bohemian Rhapsody", "Queen", 355.0, Genre::ROCK,
                       "A Night at the Opera", 11, 1975);
    AlbumTrack track2("Numb", "Linkin Park", 187.0, Genre::ROCK,
                       "Meteora", 4, 2003);
    PodcastEpisode ep("Is it worth it?", "Hristina", 400, Genre::OTHER,
                       "FMI sucks", 156, Date(10, 7, 2026));

    ManualPlaylist playlist("Road trip");

    // addTrack
    playlist.addTrack(&track1);
    playlist.addTrack(&track2);
    playlist.addTrack(&ep);
    assert(playlist.getTrackCount() == 3);
    std::cout << "addTrack: OK (" << playlist.getTrackCount() << " tracks)\n";

    // getTotalDuration
    double expected = track1.getDuration() + track2.getDuration() + ep.getDuration();
    assert(playlist.getTotalDuration() == expected);
    std::cout << "getTotalDuration: OK (" << playlist.getTotalDuration() << "s)\n";

    // getInfo / getTypeLabel
    std::cout << "getInfo: " << playlist.getInfo() << "\n";
    assert(playlist.getTypeLabel() == "Manual Playlist");
    std::cout << "getTypeLabel: OK (" << playlist.getTypeLabel() << ")\n";

    // removeTrack - съществуващ елемент
    playlist.removeTrack(&track2);
    assert(playlist.getTrackCount() == 2);
    std::cout << "removeTrack (existing): OK (" << playlist.getTrackCount() << " left)\n";

    // removeTrack - вече премахнат елемент -> трябва да хвърли exception
    try
    {
        playlist.removeTrack(&track2);
        std::cout << "removeTrack (missing): FAIL - no exception thrown\n";
        return 1;
    }
    catch (const SongNotFoundException &e)
    {
        std::cout << "removeTrack (missing): OK - caught: " << e.what() << "\n";
    }

    std::cout << "\nAll ManualPlaylist tests passed!\n";
    return 0;
}