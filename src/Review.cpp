#include "Review.hpp"
#include "exceptions/LibraryExceptions.hpp"

Review::Review(std::string username, int rating, std::string text)
    :username(std::move(username)),rating(rating),text(std::move(text))
{
    if(rating < 1 || rating > 10)
        throw InvalidRatingException("Acceptable rating is between 1-10");
}