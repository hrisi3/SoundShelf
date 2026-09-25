#include <iostream>
#include <cassert>
#include <memory>
#include "Library.hpp"
#include "Admin.hpp"
#include "RegularUser.hpp"
#include "AlbumTrack.hpp"
#include "PodcastEpisode.hpp"
#include "exceptions/LibraryExceptions.hpp"


int main()
{
    Library library;
    Admin admin("admin1");
    RegularUser user("user1");

    // addSong - user nqma pravo
    try
    {
        library.addSong(std::make_unique<AlbumTrack>("Numb", "Linkin Park", 187.0, Genre::ROCK, "Meteora", 4, 2003), user);
        std::cout << "addSong (regular user): FAIL - no exception thrown\n";
        return 1;
    }
    catch(const InvalidOperationException &e)
    {
        std::cout << "addSong (regular user): OK - caught: " << e.what() << "\n";
    }

    // addSong - admin може
    library.addSong(std::make_unique<AlbumTrack>("Numb", "Linkin Park", 187.0, Genre::ROCK, "Meteora", 4, 2003), admin);
    library.addSong(std::make_unique<PodcastEpisode>("Is it worth it?", "Hristina", 400, Genre::OTHER, "Fmi sucks", 156, Date(10, 7, 2026)), admin);
    assert(library.getAllItems().size() == 2);
    std::cout << "addSong (admin): OK (" << library.getAllItems().size() << " songs\n";


    //addSong - дубликат
    try
    {
        library.addSong(std::make_unique<AlbumTrack>("Numb", "Linkin Park", 100.0, Genre::ROCK, "Other Album", 1, 2020), admin);
        std::cout << "addSong (duplicate): FAIL - no exception thrown\n";
        return 1;
    }
    catch(const DuplicateSongException& e)
    {
        std::cout << "addSong (duplicate): OK - caught: " << e.what() << "\n";
    }
    

    // findSong
    assert(library.findSong("Numb", "Linkin Park") != nullptr);
    assert(library.findSong("noexistent", "nobody") == nullptr);
    std::cout << "findSong: OK (existring + nullptr for missing)\n";

    // search
    auto result = library.search("fmi");
    assert(result.size() == 1);
    std::cout << "search: OK (" << result.size() << " match)\n";

    // removeSong - user nqma pravo
    try
    {
        library.removeSong("Numb", "Linkin park", user);
        std::cout << "removeSong (user): FAIL - no exception thrown\n";
        return 1;
    }
    catch(const InvalidOperationException& e)
    {
        std::cout << "remove Song (user): OK - caught: " << e.what() << "\n";
    }

    // removeSong - admin moje
    library.removeSong("Numb", "Linkin park", admin);
    assert(library.getAllItems().size() == 1);
    std::cout << "remove song (admin): OK (" << library.getAllItems().size() << " left\n";

     // removeSong - вече премахната песен
    try
    {
        library.removeSong("Numb", "Linkin Park", admin);
        std::cout << "removeSong (missing): FAIL - no exception thrown\n";
        return 1;
    }
    catch (const SongNotFoundException &e)
    {
        std::cout << "removeSong (missing): OK - caught: " << e.what() << "\n";
    }

    // addUser - RegularUser не може да управлява потребители
    try
    {
        library.addUser(std::make_unique<RegularUser>("newbie"), user);
        std::cout << "addUser (regular actor): FAIL - no exception thrown\n";
        return 1;
    }
    catch (const InvalidOperationException &e)
    {
        std::cout << "addUser (regular actor): OK - caught: " << e.what() << "\n";
    }
 
    // addUser - Admin може
    library.addUser(std::make_unique<RegularUser>("newbie"), admin);
    assert(library.findUser("newbie") != nullptr);
    std::cout << "addUser (admin actor): OK\n";

      // addUser - дублирано потребителско име
    try
    {
        library.addUser(std::make_unique<RegularUser>("newbie"), admin);
        std::cout << "addUser (duplicate username): FAIL - no exception thrown\n";
        return 1;
    }
    catch (const DuplicateUsernameException &e)
    {
        std::cout << "addUser (duplicate username): OK - caught: " << e.what() << "\n";
    }
 
    // findUser - несъществуващ
    assert(library.findUser("ghost") == nullptr);
    std::cout << "findUser (missing): OK (nullptr)\n";
 
    std::cout << "\nAll Library tests passed!\n";
    return 0;
}