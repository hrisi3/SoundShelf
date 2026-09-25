#ifndef AUDIO_ITEM_HPP
#define AUDIO_ITEM_HPP

#include <string>

enum class Genre
{
    ROCK,
    POP,
    JAZZ,
    CLASSICAL,
    HIPHOP,
    ELECTRONIC,
    METAL,

    OTHER
};

class AudioItem
{
public:
    AudioItem(std::string title, std::string artist, double duration, Genre genre);
    virtual ~AudioItem() = default;

    double getDuration() const { return duration; }
    const std::string& getTitle() const { return title; }
    const std::string& getCreator() const { return creator; }
    const Genre getGenre() const { return genre; }
    int getPlayCount() const { return playCount; }

    // Полиморфно поведение при различните типове песни
    virtual void play() { playCount++; }
    virtual std::string getInfo() const = 0;
    virtual AudioItem *clone() const = 0;

    // връща "Album Track", "Podcast episode"
    virtual std::string getTypeLabel() const = 0;
    virtual bool matchesSearch(const std::string &query) const;

private:
    std::string title;
    std::string creator;
    double duration; // in seconds
    Genre genre;
    int playCount = 0; // брояч на пусканията, всеки Song обект си има собствен брояч
};

#endif