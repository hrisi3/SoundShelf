/*
Compile: g++ -std=c++17 -Iinclude src/*.cpp -o test
Iinclude -> проверява и в header-ите
*/

#include <iostream>
#include "AlbumTrack.hpp"
#include "Date.hpp"
#include <memory>

#include "PodcastEpisode.hpp"
#include "Playlist.hpp"

int main()
{
    //AlbumTrack работи
     std::unique_ptr<AudioItem> song = std::make_unique<AlbumTrack>(
          "Bohemian Rhapsody", "Queen", 355.0, Genre::ROCK,
          "A Night at the Opera", 11, 1975);

    //   song->play();
    //   std::cout << song->getInfo() << "\n";
    //   std::cout << "Type: " << song->getTypeLabel() << "\n";
    //   std::cout << "Play count: " << song->getPlayCount() << "\n";
    //   std::cout << "Matches 'queen': " << song->matchesSearch("queen") << "\n";
    //   std::cout << "Matches 'jazz': " << song->matchesSearch("jazz") << "\n";
  

    /* Date работи
      Date d(9, 5, 2003);
      std::cout << d.toString();
    */

    /* Podcast работи
    std::unique_ptr<PodcastEpisode> podcast = std::make_unique<PodcastEpisode>(
        "Is it worth it?", "Hristina", 400, Genre::OTHER, "FMI sucks", 156, Date(10, 7, 2026));
    podcast->play();
    std::cout << podcast->getInfo() << "\n";
    std::cout << "Type: " << podcast->getTypeLabel() << "\n";
    std::cout << "Play count: " << podcast->getPlayCount() << "\n";
    std::cout << "Matches fmi: " << podcast->matchesSearch("fmi") << "\n";
    */

    

    return 0;
}