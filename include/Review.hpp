#ifndef REVIEW_HPP
#define REVIEW_HPP

#include <string>

class Review
{
public:
    Review(std::string username, int rating, std::string text);

    const std::string &getUsername() const { return username; }
    int getRating() const { return rating; }
    const std::string &getText() const { return text; }

private:
    int rating; // 1-10
    std::string username;
    std::string text;
};

#endif