
#include "persistence/LibraryFileIO.hpp"
#include <fstream>
#include <sstream>
#include "exceptions/LibraryExceptions.hpp"
#include "AlbumTrack.hpp"
#include "Date.hpp"
#include "PodcastEpisode.hpp"

void LibraryFileIO::saveSongs(const std::string &path, const std::vector<AudioItem *> &songs)
{
    std::ofstream out(path); // отваря/създава файла за писане
    out << songs.size() << "\n"; // първи ред: брой песни
    for (const auto *song : songs)
        out << song->serialize() << "\n"; // всяка песен ->собствения си ред
}


std::unique_ptr<AudioItem> LibraryFileIO::parseAudioItem(const std::string &line)
{
    std::istringstream stream(line);
    std::string type, title, creator, durationStr, genreStr;

    std::getline(stream, type, '|');
    std::getline(stream, title, '|');
    std::getline(stream, creator, '|');
    std::getline(stream, durationStr, '|');
    std::getline(stream, genreStr, '|');

    double duration = std::stod(durationStr);
    Genre genre = static_cast<Genre>(std::stoi(genreStr));

    if(type == "ALBUM")
    {
        std::string albumName, trackNumStr, releaseYearStr;
        std::getline(stream, albumName, '|');
        std::getline(stream, trackNumStr, '|');
        std::getline(stream, releaseYearStr, '|');

        return std::make_unique<AlbumTrack>(title, creator, duration, genre, albumName, std::stoi(trackNumStr), std::stoi(releaseYearStr));
    }
    else if (type == "PODCAST")
    {
        std::string showName, episodeNumStr, dayStr, monthStr, yearStr;
        std::getline(stream,showName,'|');
        std::getline(stream,episodeNumStr,'|');
        std::getline(stream, dayStr, '|');
        std::getline(stream, monthStr, '|');
        std::getline(stream, yearStr, '|');

        Date releaseDate(std::stoi(dayStr), std::stoi(monthStr), std::stoi(yearStr));
        return std::make_unique<PodcastEpisode>(title, creator, duration, genre,
                                                showName, std::stoi(episodeNumStr), releaseDate);
    }

    throw InvalidOperationException("Unknown song type in file: " + type);
}

std::vector<std::unique_ptr<AudioItem>> LibraryFileIO::loadSongs(const std::string &path)
{
    std::ifstream in(path);
    std::vector<std::unique_ptr<AudioItem>> result;

    int count; // 2
    in >> count; // чете 2,но спира точно преди символа за нов ред-не взима "\n"
    in.ignore(); // изяжда "\n" преди getline

    for (int i = 0; i < count; i++)
    {
        std::string line;
        std::getline(in, line);
        result.push_back(parseAudioItem(line));
    }
    return result;
}

