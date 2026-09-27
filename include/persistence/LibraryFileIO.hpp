#ifndef LIBRARY_FILE_IO_HPP
#define LIBRARY_FILE_IO_HPP

#include <string>
#include <vector>
#include <memory>
#include "AudioItem.hpp"


class LibraryFileIO
{
public:
    static void saveSongs(const std::string &path, const std::vector<AudioItem *> &songs);
    static std::vector<std::unique_ptr<AudioItem>> loadSongs(const std::string &path);

private:
    static std::unique_ptr<AudioItem> parseAudioItem(const std::string &line);
};

#endif