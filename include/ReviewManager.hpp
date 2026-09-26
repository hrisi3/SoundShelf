#ifndef REVIEW_MANAGER_HPP
#define REVIEW_MANAGER_HPP

#include <map>
#include <vector>
#include "Review.hpp"
#include "AudioItem.hpp"


class ReviewManager
{
public:
    void addReview(AudioItem *song, const Review &review);
    const std::vector<Review> &getReviews(AudioItem *song) const;
    double getAverageRating(AudioItem *song) const;

private:
    // ключ->коя песен, стойност->всички ревюта на тази песен
    std::map<AudioItem *, std::vector<Review>> reviewsBySong;
};

#endif