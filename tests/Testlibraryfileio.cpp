#include <iostream>
#include <cassert>
#include <memory>
#include "persistence/LibraryFileIO.hpp"
#include "AlbumTrack.hpp"
#include "PodcastEpisode.hpp"

int main()
{
    AlbumTrack original1("Numb", "Linkin Park", 187.0, Genre::ROCK, "Meteora", 4, 2003);
    PodcastEpisode original2("Is it worth it?", "Hristina", 400, Genre::OTHER,
                             "FMI sucks", 156, Date(10, 7, 2026));

    std::vector<AudioItem *> source{&original1, &original2};

    const std::string path = "test_songs.txt";

    //save
    LibraryFileIO::saveSongs(path, source);
    std::cout << "saveSong: OK (file written)\n";

    auto loaded = LibraryFileIO::loadSongs(path);
    assert(loaded.size() == 2);
    std::cout << "loadSongs: OK " << loaded.size() << " songs loaded\n";

    // проверка на албума
    assert(loaded[0]->getTypeLabel() == "Album Track");
    assert(loaded[0]->getTitle() == original1.getTitle());
    assert(loaded[0]->getCreator() == original1.getCreator());
    assert(loaded[0]->getDuration() == original1.getDuration());
    assert(loaded[0]->getGenre() == original1.getGenre());
    assert(loaded[0]->getInfo() == original1.getInfo());
    std::cout << "AlbumTracl OK\n";
    

    return 0;
};