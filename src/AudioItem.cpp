#include "AudioItem.hpp"
#include "utils.hpp"
#include <algorithm> // за std::transform
#include <cctype> // за ::tolower


AudioItem::AudioItem(std::string title, std::string creator, double duration, Genre genre)
    :title(title), creator(creator), duration(duration), genre(genre)
{}

 
// дали дадена песен "съвпада" с текст, който потребителят е въвел при търсене
bool AudioItem::matchesSearch(const std::string &query) const
{
    std::string lowerQuery = toLower(query);
    return toLower(title).find(lowerQuery) != std::string::npos ||
           toLower(creator).find(lowerQuery) != std::string::npos;
}
