#include "ReviewManager.hpp"
#include "exceptions/LibraryExceptions.hpp"

void ReviewManager::addReview(AudioItem *song, const Review &review)
{
    reviewsBySong[song].push_back(review);
}

const std::vector<Review> &ReviewManager::getReviews(AudioItem *song) const
{
    auto iter = reviewsBySong.find(song);
    if(iter == reviewsBySong.end())
    {
        static const std::vector<Review> empty;
        return empty;
    }
    return iter->second;
}

double ReviewManager::getAverageRating(AudioItem *song) const
{
    const std::vector<Review> &reviews = getReviews(song);
    if(reviews.empty())
        throw InvalidOperationException("There is no reviews.");
    double sum = 0;
    for(const auto& r: reviews)
        sum += r.getRating();
    return sum / reviews.size();
}
