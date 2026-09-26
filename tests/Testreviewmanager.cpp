#include <iostream>
#include <cassert>
#include "ReviewManager.hpp"
#include "AlbumTrack.hpp"
#include "exceptions/LibraryExceptions.hpp"

int main()
{
    
    AlbumTrack song1("Numb", "Linkin Park", 187.0, Genre::ROCK, "Meteora", 4, 2003);
    AlbumTrack song2("Bohemian Rhapsody", "Queen", 355.0, Genre::ROCK,
                      "A Night at the Opera", 11, 1975);

    ReviewManager manager;

    // nevaliden rating
    try
    {
        Review bad("hrisi", 15, "great");
        std::cout << "Review (invalid rating): FAIL - no exception thrown\n";
        return 1;
    }
    catch(const InvalidRatingException &e)
    {
        std::cout << "Review (invalid rating): OK - caught: " << e.what() << "\n";

    }

    // песен без ревюта
    assert(manager.getReviews(&song1).empty());
    try
    {
        manager.getAverageRating(&song1);
        std::cout << "getAverageRating (no reviews): FAIL - no exception thrown \n";
        return 1;
    }
    catch(const InvalidOperationException &e)
    {
        std::cout << "getAverageRating (no reviews): OK - caught " << e.what() << "\n";
    }

    // addReview
    manager.addReview(&song1, Review("hrisi", 8, "mn dobre"));
    manager.addReview(&song1, Review("mama", 5, "hmm i dont know"));
    manager.addReview(&song1, Review("tooshkoo", 10, "masterpiece belissimo"));
    assert(manager.getReviews(&song1).size() == 3);
    std::cout << "addReview: OK ! \n";

    // getAverageRating 8 + 5 + 10 =23 / 3 = 7.66..
    double avg = manager.getAverageRating(&song1);
    assert(avg > 7.6 && avg < 7.7);
    std::cout << "getAverageRating: OK !\n";

    assert(manager.getReviews(&song2).empty());
    std::cout << "song 2 not affected!\n";

    std::cout << "ohh passed!\n";

    return 0;
}